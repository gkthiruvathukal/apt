/******************************************************************
**
** ASTMAIN.C:
**
**    AST Main Module
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- C Headers */

/* ----------- Headers */

#include "apt.h"

#include "analysis.h"
#include "astcgen.h"
#include "astmain.h"
#include "astparse.h"
#include "astscan.h"
#include "convert.h"
#include "find.h"
#include "mold.h"
#include "version.h"

#include "astlib.h"

#include "allocate.h"
#include "args.h"
#include "buffer.h"
#include "bufio.h"
#include "gprintf.h"
#include "sstring.h"

#ifdef __ANSI_C__
int main(int argc, char *argv[]);
struct state_arc_record *newSymbol(char *);
int inList(struct state_arc_record *,char *);
struct state_arc_record *insertSymbol(struct state_arc_record *,char *);
struct transition_record *insertTransition(struct transition_record *,struct transition_record *);
struct transition_record *newTransition(char *, char *, char *, char *, char *);
int findSymbolinList(struct state_arc_record *,char *);
int **newMatrix(int,int);
int isIntrinsic(char *);
int isBuiltIn(char *);
char *actionAt(int);
char *symbolAt(int);
char *stateAt(int);
int lenList(struct state_arc_record *);
void codegen();
void genHeader();
void genCode();
void BuildTransitionMatrix();
void BuildReachesMatrix();
void Warshall(int **,int);
void checkForErrors(void);
void DisplayUsageInformation(void);
void ParseAstCommandLine(int, OptionDescriptorBlock, int, char *[]);
#else
int main();
struct state_arc_record *newSymbol();
int inList();
struct state_arc_record *insertSymbol();
struct transition_record *insertTransition();
struct transition_record *newTransition();
int findSymbolinList();
int **newMatrix();
int isIntrinsic();
int isBuiltIn();
char *actionAt();
char *symbolAt();
char *stateAt();
int lenList();
void codegen();
void genHeader();
void genCode();
void BuildTransitionMatrix();
void BuildReachesMatrix();
void Warshall();
void checkForErrors();
void DisplayUsageInformation();
void ParseAstCommandLine();

#endif
/* driver */
FILE *file;
char *NameOfStartState;
char *scanFileName, *scanFilePrefix, *codeFileName, *headFileName, **symbolFileNames;
int symbolFileCount;

ScanInfo scanInfo;

OptionDescriptorBlock AstOptions = {
  { AstOptInclude, "i", StraightFlag, NULL, Variable },
  { AstOptAnalyze, "a", StraightFlag, NULL, None },
  { AstOptTerminals, "t", StraightFlag, NULL, None }
};

int AstFlags[] = { 0, 0, 1 };

#define AstOptionCount 3

int main(argc,argv)
int argc;
char *argv[];
{
  gprintf(stderr,"Apt Scanning Tool 3.0\n");
  gprintf(stderr,"Copyright (c) 1991 -- Apt Technologies\n");
  gprintf(stderr,"\n");

  ParseAstCommandLine(AstOptionCount, AstOptions, argc, argv);
  if (scanFileName == NULL) DisplayUsageInformation();

  gprintf(stderr,"AST Phases:\n");

  scanFilePrefix = StringTokenize(StringDuplicate(scanFileName),".");
  file = fopen(scanFileName,"r");
  if (file == NULL) {
    gprintf(stderr,"Error: File %s cannot be opened.\n",scanFileName);
    exit(1);
  }
  BufIOInitialize();

  ScanStateInit(&scanInfo,file);

  gprintf(stderr," * List Construction\n");
  AstParse();

  gprintf(stderr," * Analysis of DFA\n");
  checkForErrors();

  gprintf(stderr," * Table Construction\n");
  BuildTransitionMatrix();

  if (!AstFlags[AstOptAnalyze]) {
    gprintf(stderr," * Code Generation\n");
    codegen();
  }
  exit(0);
}

void DisplayUsageInformation()
{
  gprintf(stderr,"Apt Scanning Tool -- %s Language Edition\n",edition[version]);
  gprintf(stderr,"\n");
  gprintf(stderr,"An AST command line uses the following syntax:\n\n");
  gprintf(stderr,"%% ast <file-name> <options>\n\n");
  gprintf(stderr,"where:\n\n");
  gprintf(stderr,"  <file-name> ::= <file-prefix>.scn\n");
  gprintf(stderr,"  <options> ::= { <option> }\n");
  gprintf(stderr,"  <option> ::= -a  (Analyze FSA only)\n");
  gprintf(stderr,"  <option> ::= -i <header-prefix-list>  ");
  gprintf(stderr,"(Use Alternative token definition files)\n");
  gprintf(stderr,"\n");
  exit(1);
}

void ParseAstCommandLine(optionCount,options,argc,argv)
int optionCount;
OptionDescriptorBlock options;
int argc;
char **argv;
{
  MatchDescriptorList matchList;
  MatchDescriptorPtr matchElem;
  int OptionMatched, OptionCode;

  matchList = ParseCommandLine(optionCount, options, argc, argv);
  for (matchElem = matchList; matchElem != NULL; matchElem=matchElem->next)
  {
    OptionMatched = matchElem->OptionMatched;
    if (matchElem->OptionMatched >= 0) {
      OptionCode = options[OptionMatched].OptionCode;
      switch(OptionCode) {
      case AstOptInclude:
        symbolFileNames = matchElem->Arguments;
        symbolFileCount = matchElem->ArgumentCount;
        break;
      case AstOptAnalyze:
        AstFlags[AstOptAnalyze] = 1;
        break;
      case AstOptTerminals:
        AstFlags[AstOptTerminals] = 0;
        break;
      }
    } else {
      if (scanFileName == NULL)
        if (matchElem->ArgumentCount > 0) {
          scanFileName = StringDuplicate(matchElem->Arguments[0]);
          scanFilePrefix = StringTokenize(StringDuplicate(scanFileName),".");
        }
    }
  }
}
