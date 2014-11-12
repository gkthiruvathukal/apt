/******************************************************************
**
** APTMAIN.C:
**
**    APT Main Module
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "analyze.h"
#include "aptacts.h"
#include "aptcgen.h"
#include "aptmain.h"
#include "build.h"
#include "closure.h"
#include "debug.h"
#include "listfile.h"
#include "matrix.h"
#include "predict.h"
#include "sets.h"
#include "version.h"

#include "aptlib.h"
#include "astlib.h"

#include "allocate.h"
#include "args.h"
#include "buffer.h"
#include "bufio.h"
#include "gprintf.h"
#include "sstring.h"

/* ----------- Defines */

#define codeFileSuffix ".apt"
#define grmFileSuffix ".grm"
#define errorFileSuffix ".err"
#define listFileSuffix ".lst"

/* ---------- Macros */
 
#define CloseFile(file) if (file != NULL) fclose(file)
 
#define OpenFile(fp,filename,mode) \
  if (!(fp = fopen(filename,mode))) {\
     fprintf(stderr,"Error: cannot open %s.",filename); \
     exit(1); \
  }

/* ----------- Exported Globals */

PUBLIC FILE *errorFile;
PUBLIC FILE *grmFile;
PUBLIC FILE *listFile;
PUBLIC ScanInfo scanInfo;

/* ----------- Private Globals */

PRIVATE char *AptActionFile;
PRIVATE int AptTDIncludeCount;
PRIVATE char **AptTDIncludes;
PRIVATE char *grmFilePrefix;

/* ----------- Command Line Stuff */

/*
**
** Command line options...
**
**   -a                 enable analysis (disables list & code)
**   -c                 enable/disable code generation
**   -i                 include file(s) of type definitions
**   -l                 enable/disable list file generation
**   -o                 write fake semantic actions
**   -s                 enable/disable semantic stack check code
**   -t                 enable/disable generation of terminal symbols
**   -w                 enable/disable code generator if warnings exist
**
*/

int AptFlags[AptOptionCount] = {
  FALSE,
  TRUE,
  FALSE,
  TRUE,
  FALSE,
  TRUE,
  TRUE,
};

OptionDescriptorBlock AptOptions  = {
  { AptOptAnalysis, "a", SwitchedFlag, TheSwitches, None },
  { AptOptCodeGen, "c", SwitchedFlag, TheSwitches, None },
  { AptOptInclude, "i", StraightFlag, NULL, Variable },
  { AptOptListFile, "l", SwitchedFlag, TheSwitches, None },
  { AptOptActionFile, "o", StraightFlag, NULL, 1 },
  { AptOptSemCheck, "s", SwitchedFlag, TheSwitches, None },
  { AptOptTermDefs, "t", SwitchedFlag, TheSwitches, None },
  { AptOptWarning, "w", SwitchedFlag, TheSwitches, None }
};

/* ----------- Private Prototypes */

#ifdef __ANSI_C__
static void CloseFiles(void);
static void CodeGen(void);
static void DisplayUsageInformation(void);
static void OpenFiles(void);
static void ParseAptCommandLine(int, OptionDescriptorBlock, int, char**);
#else
static void CloseFiles();
static void CodeGen();
static void DisplayUsageInformation();
static void OpenFiles();
static void ParseAptCommandLine();
#endif /* __ANSI_C__ */

/* ----------- Functions */

void PrintToken(Token t)
{
  fprintf(stderr,"Token %s line %d column %d\n",t->text, t->line, t->column);
}

/*
**
** main
**
*/
PUBLIC
#ifdef __ANSI_C__
int main(int argc, char **argv)
#else
int main(argc,argv)
int argc;
char *argv[];
#endif
{
  int warnings;

  gprintf(stderr,"Apt Parsing Tool 3.0\n");
  gprintf(stderr,"Copyright (c) 1991 -- Apt Technologies\n");
  gprintf(stderr,"\n");

  ParseAptCommandLine(AptOptionCount,AptOptions,argc,argv);
  if (!grmFilePrefix) DisplayUsageInformation();

  DisplayMessage(0,"APT Phases:");

  OpenFiles();
  BufIOInitialize();

  DisplayMessage(0," * List Construction");
  ScanStateInit(&scanInfo,grmFile);
  ParseInitialize();
  Parse(grmFile, PrintToken);

  DisplayMessage(0," * Table Construction");
  BuildSymbolTable();
  BuildProductionTable();
  BuildTypeTable();
  ComputeCounts();

  DisplayMessage(0," * Grammar Analysis");
  FindNullDerivingSymbols();
  DeduceMinLenTermString();
  ReportMinLenTermString();
  DeduceReachableSymbols();
  ReportUnreachableSymbols();

  DisplayMessage(0," * Parse Table Construction");
  ConstructFirstLastSets();
  ConstructNextToSet();
  ConstructFollowSet();

  warnings = ComputeLLPredictionTable();
  if (AptFlags[AptOptCodeGen]) {
    if ((AptFlags[AptOptWarning] && warnings) || !warnings) {
      DisplayMessage(0," * Code Generation");
      CodeGen();
    }
  }

  if (AptFlags[AptOptListFile]) {
    DisplayMessage(0," * List File Generation");
    listSymbolTable();
    listSets();
  }

  CloseFiles();
  exit(0);
}

/*
**
** CloseFiles
**
*/
PRIVATE
#ifdef __ANSI_C__
void CloseFiles(void)
#else
void CloseFiles()
#endif
{
  CloseFile(grmFile);
  if (AptFlags[AptOptListFile]) CloseFile(listFile);
  CloseFile(errorFile);
}
      
/*
**
** CodeGen
**
*/
PRIVATE
#ifdef __ANSI_C__
void CodeGen(void)
#else
void CodeGen()
#endif
{
  CG(grmFilePrefix,AptTDIncludeCount,AptTDIncludes,AptActionFile);
}

/*
**
** DisplayUsageInformation
**
*/
PRIVATE
#ifdef __ANSI_C__
void DisplayUsageInformation(void)
#else
void DisplayUsageInformation()
#endif
{
  gprintf(stderr,"Apt Parsing Tool -- %s Language Edition\n",edition[version]);
  gprintf(stderr,"\n");
  gprintf(stderr,"An APT command line uses the following syntax:\n\n");
  gprintf(stderr,"%% apt <file-name> <options>\n\n");
  gprintf(stderr,"where:\n\n");
  gprintf(stderr,"  <file-name> ::= <file-prefix>.grm\n");
  gprintf(stderr,"  <options> ::= { <option> }\n");
  gprintf(stderr,"  <option> ::= -a<switch>  ");
  gprintf(stderr,"(Analyze grammar only (-c- and -l- are implicit))\n");
  gprintf(stderr,"  <option> ::= -c<switch>  ");
  gprintf(stderr,"(Code generation (default enabled))\n");
  gprintf(stderr,"  <option> ::= -i <header-prefix-list>  ");
  gprintf(stderr,"(Include type files)\n");
  gprintf(stderr,"  <option> ::= -l<switch>  ");
  gprintf(stderr,"(List file (default enabled))\n");
  gprintf(stderr,"  <option> ::= -o <code-prefix>  ");
  gprintf(stderr,"(Generate stub actions)\n");
  gprintf(stderr,"  <option> ::= -s<switch>  ");
  gprintf(stderr,"(Semantic stack checks (default enabled))\n");
  gprintf(stderr,"  <option> ::= -t<switch>  ");
  gprintf(stderr,"(Terminal symbols (default enabled))\n");
  gprintf(stderr,"  <option> ::= -w<switch>  ");
  gprintf(stderr,"(Generate code on warnings (default disabled))\n");
  gprintf(stderr,"  <switch> ::= + | - | null\n\n");
  exit(1);
}

/*
**
** Error
**
*/
PUBLIC
#ifdef __ANSI_C__
void Error(int code, int cnt, char *p1, char* p2)
#else
void Error(code,cnt,p1,p2)
int code;
int cnt;
char *p1;
char* p2;
#endif
{
}

/*
**
** OpenFiles
**
*/
PRIVATE
#ifdef __ANSI_C__
void OpenFiles(void)
#else
void OpenFiles()
#endif
{
  char *errorFileName;
  char *grmFileName;
  char *listFileName;

  errorFileName = (char*)Allocate(StringLength(grmFilePrefix)+
    StringLength(errorFileSuffix)+1);
  StringCopy(errorFileName,grmFilePrefix);
  StringCatenate(errorFileName,errorFileSuffix);
  OpenFile(errorFile,errorFileName,"w");
  Free(errorFileName);

  grmFileName = (char*)Allocate(StringLength(grmFilePrefix)+
    StringLength(grmFileSuffix)+1);
  StringCopy(grmFileName,grmFilePrefix);
  StringCatenate(grmFileName,grmFileSuffix);
  OpenFile(grmFile,grmFileName,"r");
  Free(grmFileName);

  if (AptFlags[AptOptListFile]) {
    listFileName = (char*)Allocate(StringLength(grmFilePrefix)+
      StringLength(listFileSuffix)+1);
    StringCopy(listFileName,grmFilePrefix);
    StringCatenate(listFileName,listFileSuffix);
    OpenFile(listFile,listFileName,"w");
    Free(listFileName);
  }
}

/*
**
** ParseAptCommandLine
**
*/
PRIVATE
#ifdef __ANSI_C__
void ParseAptCommandLine(int optionCount, OptionDescriptorBlock options,
                         int argc, char **argv)
#else
void ParseAptCommandLine(optionCount,options,argc,argv)
int optionCount;
OptionDescriptorBlock options;
int argc;
char **argv;
#endif
{
  char *grmFileName;
  MatchDescriptorPtr matchElem;
  MatchDescriptorList matchList;
  int OptionCode;
  int OptionMatched;
  int SwitchSetting;

  grmFileName = grmFilePrefix = NULL;
  matchList = ParseCommandLine(optionCount,options,argc,argv);
  for (matchElem = matchList; matchElem != NULL; matchElem=matchElem->next)
  {
    OptionMatched = matchElem->OptionMatched;
    SwitchSetting = matchElem->SwitchSetting;
    if (matchElem->OptionMatched >= 0) {
      OptionCode = options[OptionMatched].OptionCode;
      switch (OptionCode) {
      case AptOptAnalysis:
        AptFlags[OptionCode] = SwitchSetting == EOS || SwitchSetting == '+'
          ? TRUE : FALSE;
        if (AptFlags[OptionCode]) {
          AptFlags[AptOptCodeGen] = !AptFlags[AptOptAnalysis];
          AptFlags[AptOptListFile] = !AptFlags[AptOptAnalysis];
        }
        break;
      case AptOptCodeGen:
      case AptOptListFile:
      case AptOptSemCheck:
      case AptOptTermDefs:
        AptFlags[OptionCode] = SwitchSetting == EOS || SwitchSetting == '-'
          ? FALSE : TRUE;
        break;
      case AptOptWarning:
        AptFlags[OptionCode] = SwitchSetting == EOS || SwitchSetting == '+'
          ? TRUE : FALSE;
        break;
      case AptOptInclude:
        AptTDIncludes = matchElem->Arguments;
        AptTDIncludeCount = matchElem->ArgumentCount;
        break;
      case AptOptActionFile:
        if (matchElem->ArgumentCount > 0) {
          AptActionFile = matchElem->Arguments[0];
          AptFlags[OptionCode] = TRUE;
        }
        break;
      }
    } else if (!grmFileName)
      if (matchElem->ArgumentCount > 0) {
        grmFileName = StringDuplicate(matchElem->Arguments[0]);
        grmFilePrefix = StringTokenize(grmFileName,".");
      }
  }
}
