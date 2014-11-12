/************************************************************/
/*                                                          */
/* -- Apt Scanning Tool (AST)                               */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- MENCODE.C - Apt Scanning Tool Modula 2 Code           */
/*                Generator                                 */
/*                                                          */
/************************************************************/

#include "ast.h"
#include "astlib.h"
#include "aptlib.h"
#include "cencode.h"
#include "convert.h"
#include "find.h"
#include "parse.h"
#include "clibrary.h"
#include "version.h"

int version = CG_Modern_Modula_2;

void codegen()
{
	genHeader();
	genCode();
}

void genHeader()
{
   FILE *headFile;
   struct state_arc_record *p;
   int i;

   headFileName = (char *)Allocate(StringLength(scanFilePrefix)+5);
   StringCopy(headFileName,scanFilePrefix);
   StringCatenate(headFileName,".def");
   headFile = fopen(headFileName,"w");
   if (headFile == NULL) {
      gprintf(stderr,"Error: Cannot open HeaderFile for output!\n");
      exit(0);
   }
   gprintf(headFile,"DEFINITION MODULE %s;\n",StringTokenize(headFileName,"."));
   gprintf(headFile,"\n");
   gprintf(headFile,"FROM AstLib IMPORT ScanInfoPtr;\n");
   gprintf(headFile,"FROM AstLib IMPORT TokenPtr;\n");
   for (p=actionList; p != NULL; p=p->next) {
      if (isBuiltIn(p->text)) continue;
      gprintf(headFile,"PROCEDURE %s(ScanInfo : ScanInfoPtr);\n",p->text);
   }
   gprintf(headFile,"\n");
   gprintf(headFile,"CONST\n");
   for (i=-1, p=stateList; p != NULL; p=p->next, i--)
      gprintf(headFile,"\tS_%s = %d;\n",p->text, i);
   gprintf(headFile,"\tS_Error = %d;\n",i--);
   gprintf(headFile,"\n");
   gprintf(headFile,"\tStateCount = %d;\n",states+1);
   gprintf(headFile,"\n");
   if (symbolFileName == NULL) {
      for (p=attributeList; p != NULL; p=p->next, i--)
         gprintf(headFile,"\tT_%s = %d;\n",p->text, i);
      gprintf(headFile,"\n");
      gprintf(headFile,"\tTerminalCount = %d;\n",attributes);
      gprintf(headFile,"\n");
   }
   gprintf(headFile,"VAR\n");
   gprintf(headFile,"\tScanInfo : ScanInfoPtr;\n");
   for (p=symbolList; p != NULL; p=p->next)
      if (p->text[0] != '\"' && !isIntrinsic(p->text)) {
         gprintf(headFile,"PROCEDURE %s(c : INTEGER) : INTEGER;\n",p->text);
      }
   gprintf(headFile,"\n");
	gprintf(headFile,"PROCEDURE Scan() : TokenPtr;\n");
   gprintf(headFile,"\n");
   gprintf(headFile,"END %s.\n",headFileName);
   fclose(headFile);
}

void genCode()
{
	int i, j, once;
   FILE *codeFile;
   /*
   finalStateIndex = findSymbolinList(stateList,NameOfFinalState);
   */
   codeFileName = (char *)Allocate(StringLength(scanFilePrefix)+5);
   StringCopy(codeFileName,scanFilePrefix);
   StringCatenate(codeFileName,".mod");
   codeFile = fopen(codeFileName,"w");
   if (codeFile == NULL) {
      gprintf(stderr,"Error: Cannot open CodeFile for output!\n");
      exit(0);
   }

   gprintf(codeFile,"IMPLEMENTATION MODULE %s;\n",headFileName);
   gprintf(codeFile,"\n");
   gprintf(codeFile,"IMPORT AstLib;\n");
   if (symbolFileName != NULL) {
      gprintf(codeFile,"IMPORT %s;\n",symbolFileName);
      gprintf(codeFile,"\n");
   }
   gprintf(codeFile,"FROM FIO IMPORT File;\n");
   gprintf(codeFile,"FROM BufferModule IMPORT InitBuffer;\n");
   gprintf(codeFile,"\n");
	gprintf(codeFile,"PROCEDURE Scan() : TokenPtr;\n");
   gprintf(codeFile,"VAR\n");
   gprintf(codeFile,"\tCurrentChar : CHAR;\n");
	gprintf(codeFile,"BEGIN\n");
   gprintf(codeFile,"\tCurrentChar := 0C;\n\n");
   gprintf(codeFile,"\tAstLib.SetScanState(ScanInfo,S_%s);\n",stateAt(states-1));
   gprintf(codeFile,"\tAstLib.SetScanAttribute(ScanInfo,-1);\n");
   gprintf(codeFile,"\tAstLib.SetScanBuffer(ScanInfo,InitBuffer(NIL));\n");
   gprintf(codeFile,"\tAstLib.Ignore(ScanInfo);\n");
	gprintf(codeFile,"\tLOOP\n");
   gprintf(codeFile,"\t\tCurrentChar := AstLib.GetScanChar(ScanInfo);\n");
	gprintf(codeFile,"\t\tCASE AstLib.GetScanState(ScanInfo) OF\n");
	for (i=0; i < states; i++) {
		if (i) 
         gprintf(codeFile,"\t\t\t| S_%s:\n",stateAt(i));
      else
         gprintf(codeFile,"\t\t\t  S_%s:\n",stateAt(i));
		once = 0;
		for (j=0; j < symbols; j++) {
			if (Shift[i][j] + 1) {
				if (symbolAt(j)[0] == '\"')
					gprintf(codeFile,"\t\t\t\t%sIF AstLib.CharInString(CurrentChar,%s) THEN\n",once ? "ELS" : "",symbolAt(j));
				else {
               if (isIntrinsic(symbolAt(j))) 
   					gprintf(codeFile,"\t\t\t\t%sIF AstLib.%s(CurrentChar) THEN\n",once ? "ELS" : "",symbolAt(j));
               else
   					gprintf(codeFile,"\t\t\t\t%sIF %s(CurrentChar) THEN\n",once ? "ELS" : "",symbolAt(j));
            }
				once = 1;
            if (isBuiltIn(actionAt(Action[i][j])))
   				gprintf(codeFile,"\t\t\t\t\tAstLib.%s(ScanInfo);\n",actionAt(Action[i][j]));
            else
   				gprintf(codeFile,"\t\t\t\t\t%s(ScanInfo);\n",actionAt(Action[i][j]));
            if (Attribute[i][j] + 1) {
               if (symbolFileName == NULL)
                  gprintf(codeFile,"\t\t\t\t\tAstLib.SetScanAttribute(ScanInfo,T_%s);\n",attributeAt(Attribute[i][j]));
               else
                  gprintf(codeFile,"\t\t\t\t\tAstLib.SetScanAttribute(ScanInfo,%s.T_%s);\n",symbolFileName,attributeAt(Attribute[i][j]));
            }
            if (Shift[i][j] != i) {
/*
               char *shift_state;
               shift_state = stateAt(Shift[i][j]);
               if (StringCompare(shift_state,ReturnToken) == 0)
                  gprintf(codeFile,"\t\t\t\t\tRETURN AstLib.NewToken(ScanInfo);\n");
               else if (StringCompare(shift_state,ReturnErrorToken) == 0)
                  gprintf(codeFile,"\t\t\t\t\tRETURN AstLib.NewErrorToken(ScanInfo,-1);\n");
               else
*/
                  gprintf(codeFile,"\t\t\t\t\tAstLib.SetScanState(ScanInfo,S_%s);\n",stateAt(Shift[i][j]));
            }
            if (Attribute[i][j] + 1) {
               gprintf(codeFile,"\t\t\t\t\tRETURN AstLib.NewToken(ScanInfo);\n");
            }
			}
		}
      if (once) gprintf(codeFile,"\t\t\t\tEND;\n");
	}
	gprintf(codeFile,"\t\tEND;\n");
	gprintf(codeFile,"\tEND;\n");
	gprintf(codeFile,"END Scan;\n");
   gprintf(codeFile,"\n");
   gprintf(codeFile,"END %s.\n",headFileName);
   fclose(codeFile);
}


