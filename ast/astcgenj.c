/******************************************************************
**
** ASTCGEN-C.C:
**
**    AST C Code Generation Module
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- Headers */

#include "apt.h"

#include "astcgen.h"
#include "astmain.h"
#include "astparse.h"
#include "convert.h"
#include "find.h"
#include "version.h"

#include "aptlib.h"
#include "astlib.h"

#include "allocate.h"
#include "gprintf.h"
#include "sstring.h"

/* ---------- Exported Globals */

PUBLIC CGVersion version = CG_JAVA;

/* ---------- Functions */

void codegen()
{
  genCode();
}

void genHeader() 
{
  /* Nop */
}

void genConstants(FILE* headFile)
{
  struct state_arc_record *p;
  int enumCount;

  /* I need to think what to do if user wants to define own actions.
   * For Java version, we'll not allow it for now.
   */

  /*
   * States are emitted as public static final int S_<statename> = enumCount++
   */

  for (enumCount=0, p=stateList; p != NULL; p=p->next, enumCount++)
    gprintf(headFile,"\tpublic static final int S_%s = %d;\n",p->text, enumCount);
  gprintf(headFile,"\tpublic static final int S_Error = %d;\n",enumCount);
  gprintf(headFile,"\tpublic static final int NumberOfStates = %d;\n\n",
	  enumCount);

  if (AstFlags[AstOptTerminals]) {
    for (enumCount=0, p=attributeList; p != NULL; p=p->next, enumCount++)
      gprintf(headFile,"\tpublic static final int T_%s = %d;\n",p->text, enumCount);
    gprintf(headFile,"\tpublic static final int NumberOfTerminals = %d;\n", enumCount);
    gprintf(headFile,"\tpublic static final int NumberOfTokens = %d;\n", enumCount);
  }

#if 0
  for (p=symbolList; p != NULL; p=p->next)
    if (p->text[0] != '\"' && !isIntrinsic(p->text)) {
      gprintf(headFile,"#ifdef __ANSI_C__\n");
      gprintf(headFile,"int %s(int c);\n",p->text);
      gprintf(headFile,"#else\n");
      gprintf(headFile,"int %s();\n",p->text);
      gprintf(headFile,"#endif\n\n");
    }
#endif

}


void genCode()
{
  int i, j, once;
  FILE *codeFile;

  /* finalStateIndex = findSymbolinList(stateList,NameOfFinalState); */

  scanFilePrefix[0] = toupper(scanFilePrefix[0]);
  codeFileName = (char*)Allocate(StringLength(scanFilePrefix)+
				 StringLength("Scanner.java")+1);
  StringCopy(codeFileName,"Scanner");
  StringCatenate(codeFileName,scanFilePrefix);
  StringCatenate(codeFileName,".java");
  codeFile = fopen(codeFileName,"w");
  if (codeFile == NULL) {
    gprintf(stderr,"Error 2.\n");
    exit(1);
  }

  gprintf(codeFile,"import org.jhpc.apt.*;\n");
  gprintf(codeFile,"import java.io.*;\n");
  gprintf(codeFile,"import java.util.*;\n");
  gprintf(codeFile,"public class Scanner%s {\n", scanFilePrefix);
  gprintf(codeFile,"\n");
  
  genConstants(codeFile);

  gprintf(codeFile,"\tpublic Scanner%s(Reader file) {\n", scanFilePrefix);
  gprintf(codeFile,"\t\tscanInfo = new ScanInfo(file);\n");
  gprintf(codeFile,"\t}\n\n");

  gprintf(codeFile,"\tprivate ScanInfo scanInfo;\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"\tpublic Token Scan() throws AstException\n");
  gprintf(codeFile,"\t{\n");
  gprintf(codeFile,"\t\tchar CurrentChar = 0;\n\n");

  gprintf(codeFile,"\t\tscanInfo.setState(S_%s);\n",stateAt(states-1));
  gprintf(codeFile,"\t\tscanInfo.setAttribute(-1);\n");
  gprintf(codeFile,"\t\tscanInfo.clearTokenBuffer();\n");
  gprintf(codeFile,"\t\tscanInfo.Ignore();\n");
  gprintf(codeFile,"\t\tfor (;;) {\n");
  gprintf(codeFile,"\t\t\tCurrentChar = scanInfo.getNextChar();\n");
  gprintf(codeFile,"\t\t\tswitch(scanInfo.getState()) {\n");
  for (i=0; i < states; i++) {
    gprintf(codeFile,"\t\t\t\tcase S_%s:\n",stateAt(i));
    once = 0;
    for (j=0; j < symbols; j++) {
      if (Shift[i][j] + 1) {
	if (symbolAt(j)[0] == '\"')
	  gprintf(codeFile,"\t\t\t\t\t%sif (scanInfo.cins(%s)) {\n",once ? "else " :
		  "",symbolAt(j));
	else
	  gprintf(codeFile,"\t\t\t\t\t%sif (scanInfo.%s()) {\n",once ? "else " : "",symbolAt(j));
	once = 1;
	gprintf(codeFile,"\t\t\t\t\t\tscanInfo.%s();\n",actionAt(ActionM[i][j]));
	if (Shift[i][j] != i) {
	  /*
	    if (StringCompare(shift_state,ReturnToken) == 0)
	    gprintf(codeFile,"\t\t\t\t\t\treturn (MakeToken(scanInfo));\n");
	    else if (StringCompare(shift_state,ReturnErrorToken) == 0)
	    gprintf(codeFile,"\t\t\t\t\t\treturn (MakeErrorToken(scanInfo,-1));\n");
	    else
	  */
	  gprintf(codeFile,"\t\t\t\t\t\tscanInfo.setState(S_%s);\n",stateAt(Shift[i][j]));
	}
	if (Attribute[i][j] + 1) {
	  gprintf(codeFile,"\t\t\t\t\t\tscanInfo.setAttribute(T_%s);\n",attributeAt(Attribute[i][j]));
	  gprintf(codeFile,"\t\t\t\t\t\treturn (scanInfo.asToken());\n");
	}
	gprintf(codeFile,"\t\t\t\t\t}\n");
      }
    }
    gprintf(codeFile,"\t\t\t\t\tbreak;\n");
  }
  gprintf(codeFile,"\t\t\t\tdefault:\n");
  gprintf(codeFile,"\t\t\t\t\tthrow new AstException(\"State Encountered\");\n");
  gprintf(codeFile,"\t\t\t}\n");
  gprintf(codeFile,"\t\t}\n");
  gprintf(codeFile,"\t}\n");
  gprintf(codeFile,"}\n");
  fclose(codeFile);
}


