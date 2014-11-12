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

PUBLIC CGVersion version = CG_ANSI_C;

/* ---------- Functions */

void codegen()
{
  genHeader();
  genCode();
}

void genHeader()
{
  FILE *headFile;
  struct state_arc_record *p;

  headFileName = (char*)Allocate(StringLength(scanFilePrefix)+4);
  StringCopy(headFileName,scanFilePrefix);
  StringCatenate(headFileName,".h");
  headFile = fopen(headFileName,"w");

  gprintf(headFile,"#ifndef %s_h\n",scanFilePrefix);
  gprintf(headFile,"#define %s_h\n",scanFilePrefix);
  gprintf(headFile,"\n");
  gprintf(headFile,"#include \"apt.h\"\n");
  gprintf(headFile,"\n");
  if (symbolFileNames != NULL) {
    int i;
    for (i=0; i<symbolFileCount; i++)
      gprintf(headFile,"#include \"%s\"\n",symbolFileNames[i]);
    gprintf(headFile,"\n");
  }
  gprintf(headFile,"EXTERN ScanInfo scanInfo;\n");
  gprintf(headFile,"\n");
  for (p=actionList; p != NULL; p=p->next) {
    if (isBuiltIn(p->text)) continue;
    gprintf(headFile,"#ifdef __ANSI_C__\n");
    gprintf(headFile,"void %s(ScanInfo);\n",p->text);
    gprintf(headFile,"#else\n");
    gprintf(headFile,"void %s();\n",p->text);
    gprintf(headFile,"#endif\n\n");
  }

  gprintf(headFile,"enum States {\n");
  for (p=stateList; p != NULL; p=p->next)
    gprintf(headFile,"\tS_%s,\n",p->text);
  gprintf(headFile,"\tS_Error\n");
  gprintf(headFile,"};\n\n");
  if (AstFlags[AstOptTerminals]) {
    gprintf(headFile,"enum TerminalDefinitions {\n");
    for (p=attributeList; p != NULL; p=p->next)
      gprintf(headFile,"\tT_%s,\n",p->text);
    gprintf(headFile,"\tTerminalCount\n");
    gprintf(headFile,"};\n\n");
  }
  for (p=symbolList; p != NULL; p=p->next)
    if (p->text[0] != '\"' && !isIntrinsic(p->text)) {
      gprintf(headFile,"#ifdef __ANSI_C__\n");
      gprintf(headFile,"int %s(int c);\n",p->text);
      gprintf(headFile,"#else\n");
      gprintf(headFile,"int %s();\n",p->text);
      gprintf(headFile,"#endif\n\n");
    }
  gprintf(headFile,"#define StateCount S_Error\n\n");
  gprintf(headFile,"#endif /* %s_h */\n",scanFilePrefix);
  fclose(headFile);
}

void genCode()
{
  int i, j, once;
  FILE *codeFile;

  /* finalStateIndex = findSymbolinList(stateList,NameOfFinalState); */

  codeFileName = (char*)Allocate(StringLength(scanFilePrefix)+4);
  StringCopy(codeFileName,scanFilePrefix);
  StringCatenate(codeFileName,".c");
  codeFile = fopen(codeFileName,"w");
  if (codeFile == NULL) {
    gprintf(stderr,"Error 2.\n");
    exit(1);
  }

  gprintf(codeFile,"#include <stdio.h>\n");
  gprintf(codeFile,"#include <stdlib.h>\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"#include \"apt.h\"\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"#include \"%s\"\n",headFileName);
  gprintf(codeFile,"\n");
  gprintf(codeFile,"#include \"astlib.h\"\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"#include \"buffer.h\"\n");
  gprintf(codeFile,"#include \"bufio.h\"\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"PUBLIC ScanInfo scanInfo;\n");
  gprintf(codeFile,"\n");
  gprintf(codeFile,"Token Scan(file)\n");
  gprintf(codeFile,"FILE *file;\n");
  gprintf(codeFile,"{\n");
  gprintf(codeFile,"\tint CurrentChar = 0;\n\n");

  gprintf(codeFile,"\tSetScanFile(scanInfo,file);\n");
  gprintf(codeFile,"\tSetScanState(scanInfo,S_%s);\n",stateAt(states-1));
  gprintf(codeFile,"\tSetScanAttribute(scanInfo,-1);\n");
  gprintf(codeFile,"\tSetScanBuffer(scanInfo,BufferNew());\n");
  gprintf(codeFile,"\tIgnore(scanInfo);\n");
  gprintf(codeFile,"\tfor (;;) {\n");
  gprintf(codeFile,"\t\tCurrentChar = GetScanChar(scanInfo);\n");
  gprintf(codeFile,"\t\tswitch(GetScanState(scanInfo)) {\n");
  for (i=0; i < states; i++) {
    gprintf(codeFile,"\t\t\tcase S_%s:\n",stateAt(i));
    once = 0;
    for (j=0; j < symbols; j++) {
      if (Shift[i][j] + 1) {
	if (symbolAt(j)[0] == '\"')
	  gprintf(codeFile,"\t\t\t\t%sif (CharInString(CurrentChar,%s)) {\n",once ? "else " :
		  "",symbolAt(j));
	else
	  gprintf(codeFile,"\t\t\t\t%sif (%s(CurrentChar)) {\n",once ? "else " : "",symbolAt(j));
	once = 1;
	gprintf(codeFile,"\t\t\t\t\t%s(scanInfo);\n",actionAt(ActionM[i][j]));
	if (Shift[i][j] != i) {
	  /*
	    if (StringCompare(shift_state,ReturnToken) == 0)
	    gprintf(codeFile,"\t\t\t\t\treturn (MakeToken(scanInfo));\n");
	    else if (StringCompare(shift_state,ReturnErrorToken) == 0)
	    gprintf(codeFile,"\t\t\t\t\treturn (MakeErrorToken(scanInfo,-1));\n");
	    else
	  */
	  gprintf(codeFile,"\t\t\t\t\tSetScanState(scanInfo,S_%s);\n",stateAt(Shift[i][j]));
	}
	if (Attribute[i][j] + 1) {
	  gprintf(codeFile,"\t\t\t\t\tSetScanAttribute(scanInfo,T_%s);\n",attributeAt(Attribute[i][j]));
	  gprintf(codeFile,"\t\t\t\t\treturn (MakeToken(scanInfo));\n");
	}
	gprintf(codeFile,"\t\t\t\t}\n");
      }
    }
    gprintf(codeFile,"\t\t\t\tbreak;\n");
  }
  gprintf(codeFile,"\t\t\tdefault:\n");
  gprintf(codeFile,"\t\t\t\tgprintf(stderr,\"Illegal State Encountered.\\\\n\");\n");
  gprintf(codeFile,"\t\t\t\texit(1);\n");
  gprintf(codeFile,"\t\t}\n");
  gprintf(codeFile,"\t}\n");
  gprintf(codeFile,"}\n");
  fclose(codeFile);
}


