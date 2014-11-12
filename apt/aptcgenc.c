/******************************************************************
**
** APTCGEN-C.C:
**
**    APT Code Generation (C)
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

#include "aptacts.h"
#include "aptcgen.h"
#include "aptmain.h"
#include "build.h"
#include "predict.h"
#include "version.h"

#include "aptlib.h"

#include "allocate.h"
#include "avltree.h"
#include "gprintf.h"
#include "sstring.h"

/* ---------- Defines */

#define AltTypeDefFileSuffix "atd"
#define AptText "apttext.h"
#define AptFileName "apt.h"
#define AptParseLibFileName "aptlib.h"
#define AptScanLibFileName "astlib.h"
#define AptStackFileName "aptstack.h"
#define AptParseFileName "aptparse.h"
#define AptTypeFileName "apttype.h"
#define AuxParseFilePrefix "aptparse"
#define AuxParseFileSuffix "inc"
#define AuxStackFilePrefix "aptstack"
#define AuxStackFileSuffix "inc"
#define CodeFileSuffix "c"
#define HeaderFileSuffix "h"
#define PrototypeFileSuffix "pt"
#define TokenIdentifier "Token"
#define TypeDefFileSuffix "td"
#define VoidIdentifier "Void"

/* ---------- Exported Globals */

PUBLIC CGVersion version = CG_ANSI_C;

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__

void CCG_GenTypeDefFile(FILE *file, char *prefix, int AptTDIncludeCount, char **AptTDIncludes);
void CCG_GenTypeDefFileIncludes(FILE *file, int AptTDIncludeCount, char **AptTDIncludes);
void CCG_GenDefaultTypeDef(FILE *file);
void CCG_GenSemanticStackEnumType(FILE *file);
void CCG_GenSemanticStackType(FILE *file);
void CCG_GenSemanticStackTypeTable(FILE *file);
void CCG_GenProtoFile(FILE *file, char *prefix);
void CCG_GenProtoFileIncludes(FILE *file, char *grmFilePrefix);
void CCG_GenActionPrototypes(FILE *file);
void CCG_GenANSIAction(FILE *file, AVLTreeItem ActionList);
void CCG_GenANSIActionPrototypes(FILE *file,AVLTreeItem ActionList);
void CCG_GenOLDCActionPrototypes(FILE *file,AVLTreeItem ActionList);
void CCG_GenHeaderFile(FILE *file, char *prefix);
void CCG_GenPhaseEnumType(FILE *file);
void CCG_GenHeaderFileIncludes(FILE *file, char *grmFilePrefix);
void CCG_GenNonterminalEnumType(FILE *file, int *count);
void CCG_GenTerminalEnumType(FILE *file, int *count);
void CCG_GenTerminalEnumTypeNoDefs(FILE *file, int *count);
void CCG_GenActionEnumType(FILE *file, int *count);
void CCG_GenMiscInfo(FILE *file);
void CCG_GenSymbolLimits(FILE *file, int NTBase, int TBase, int ABase);
void CCG_GenLinkageInfo(FILE *file);
void CCG_GenActionFile(FILE *file, char *grmPrefix, char *prefix);
void CCG_GenActionFileIncludes(FILE *file, char *prefix);
void CCG_GenStubActions(FILE *file);
void CCG_GenCodeFile(FILE *file, char *prefix);
void CCG_GenCodeFileIncludes(FILE *file, char *grmFilePrefix);
void CCG_GenSymbolTable(FILE *file);
void CCG_GenProductionTable(FILE *file);
void CCG_GenRHSBuffer(FILE *file);
void CCG_GenProductTable(FILE *file);
void CCG_GenPredictionTable(FILE *file);
void CCG_GenPredictHelpTable(FILE *file);
void CCG_GenSemanticPhases(FILE *file);
void CCG_GenSemanticPhaseTable(FILE *file);
void CCG_GenSemanticPhaseNameTable(FILE *file);
void CCG_GenActions(FILE *file, char *phase);
void CCG_GenAction(FILE *file, char *ActName, char *phase);
void CCG_GenErrorBody(FILE *file);
void CCG_GenActionLocals(FILE *file);
void CCG_GenActionInvocationCode2(FILE *file, struct _ActionNode *ActPtr);
void CCG_GenActionInvocationCode1(FILE *file, struct _ActionNode *ActPtr);
void CCG_GenActionStackCheckCode(FILE *file, char *ActName, struct _ActionNode *ActPtr, char *phase);
void CCG_GenActionStackSpillCode(FILE *file, struct _ActionNode *ActPtr);
void CCG_GenActionPushLocals(FILE *file);
void CCG_GenActionLookupTable(FILE *file, char *phase);
void CCG_GenDefaultActionTable(FILE *file, char *phase);
void CCG_GenActionHeader(FILE *file,char *ActName, char *phase);
void CCG_GenActionFooter(FILE *file);
void CCG_GenFileHeader(FILE *fp, char *prefix, char *suffix);
void CCG_GenFileFooter(FILE *fp, char *prefix, char *suffix);
FILE *CCG_OpenOutFile(char *prefix, char *suffix);
int CCG_FileExists(char *prefix,char *suffix);
char *CCG_AliasFor(char *symbol);
void CCG_EmitSymbol(FILE *file, int index);
struct _ActionNode *CCG_FindAction(char *ActName, char *phase);
int CCG_FindPhase(PhaseNode *, char *);
void CCG_GenAuxStackFile(FILE *file, char *prefix);
void CCG_GenAuxParseFile(FILE *file, char *prefix);
int CCG_IsCIdent(char *symbol);

#else

void CCG_GenTypeDefFile();
void CCG_GenTypeDefFileIncludes();
void CCG_GenDefaultTypeDef();
void CCG_GenSemanticStackEnumType();
void CCG_GenSemanticStackType();
void CCG_GenSemanticStackTypeTable();
void CCG_GenProtoFile();
void CCG_GenProtoFileIncludes();
void CCG_GenActionPrototypes();
void CCG_GenANSIAction();
void CCG_GenANSIActionPrototypes();
void CCG_GenOLDCActionPrototypes();
void CCG_GenHeaderFile();
void CCG_GenPhaseEnumType();
void CCG_GenHeaderFileIncludes();
void CCG_GenNonterminalEnumType();
void CCG_GenTerminalEnumType();
void CCG_GenTerminalEnumTypeNoDefs();
void CCG_GenActionEnumType();
void CCG_GenMiscInfo();
void CCG_GenSymbolLimits();
void CCG_GenLinkageInfo();
void CCG_GenActionFile();
void CCG_GenActionFileIncludes();
void CCG_GenStubActions();
void CCG_GenCodeFile();
void CCG_GenCodeFileIncludes();
void CCG_GenSymbolTable();
void CCG_GenProductionTable();
void CCG_GenRHSBuffer();
void CCG_GenProductTable();
void CCG_GenPredictionTable();
void CCG_GenPredictHelpTable();
void CCG_GenSemanticPhases();
void CCG_GenSemanticPhaseTable();
void CCG_GenSemanticPhaseNameTable();
void CCG_GenActions();
void CCG_GenAction();
void CCG_GenErrorBody();
void CCG_GenActionLocals();
void CCG_GenActionInvocationCode2();
void CCG_GenActionInvocationCode1();
void CCG_GenActionStackCheckCode();
void CCG_GenActionStackSpillCode();
void CCG_GenActionPushLocals();
void CCG_GenActionLookupTable();
void CCG_GenDefaultActionTable();
void CCG_GenActionHeader();
void CCG_GenActionFooter();
void CCG_GenFileHeader();
void CCG_GenFileFooter();
FILE *CCG_OpenOutFile();
int CCG_FileExists();
char *CCG_AliasFor();
void CCG_EmitSymbol();
struct _ActionNode *CCG_FindAction();
int CCG_FindPhase();
void CCG_GenAuxStackFile();
void CCG_GenAuxParseFile();
int CCG_IsCIdent();

#endif
/* ---------- Main Function */
/* ---------- Main Function */

void CG(grmFilePrefix,AptTDIncludeCount,AptTDIncludes,AptActionFile)
char *grmFilePrefix;
int AptTDIncludeCount;
char **AptTDIncludes;
char *AptActionFile;
{
  FILE *AFile;
  FILE *CFile;
  FILE *HFile;
  FILE *PTFile;
  FILE *TDFile;

  CFile  = CCG_OpenOutFile(grmFilePrefix,CodeFileSuffix);
  HFile  = CCG_OpenOutFile(grmFilePrefix,HeaderFileSuffix);
  PTFile = CCG_OpenOutFile(grmFilePrefix,PrototypeFileSuffix);
  TDFile = CCG_OpenOutFile(grmFilePrefix,TypeDefFileSuffix);

  CCG_GenCodeFile(CFile,grmFilePrefix);
  CCG_GenHeaderFile(HFile,grmFilePrefix);
  CCG_GenProtoFile(PTFile,grmFilePrefix);
  CCG_GenTypeDefFile(TDFile,grmFilePrefix,AptTDIncludeCount,AptTDIncludes);

  if (AptFlags[AptOptActionFile]) {
    AFile = CCG_OpenOutFile(AptActionFile,CodeFileSuffix);
    CCG_GenActionFile(AFile,grmFilePrefix,AptActionFile);
    fclose(AFile);
  }

  fclose(TDFile);
  fclose(PTFile);
  fclose(HFile);
  fclose(CFile);
}

/* ----------- C Code Generation Functions */

void CCG_GenAuxParseFile(file,prefix)
FILE *file;
char *prefix;
{
  CCG_GenFileHeader(file,AuxParseFilePrefix,AuxParseFileSuffix);
  gprintf(file,"#include \"%s\"\n",AptFileName);
  gprintf(file,"#include \"%s\"\n",AptParseFileName);
  gprintf(file,"#include \"%s.%s\"\n",prefix,HeaderFileSuffix);
  gprintf(file,"#include \"%s\"\n",AptTypeFileName);
  gprintf(file,"#include \"%s\"\n",AptStackFileName);
  gprintf(file,"\n");
  CCG_GenFileFooter(file,AuxParseFilePrefix,AuxParseFileSuffix);
}

void CCG_GenAuxStackFile(file,prefix)
FILE *file;
char *prefix;
{
  CCG_GenFileHeader(file,AuxStackFilePrefix,AuxStackFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,TypeDefFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,HeaderFileSuffix);
  gprintf(file,"\n");
  CCG_GenFileFooter(file,AuxStackFilePrefix,AuxStackFileSuffix);
}

/*
** ANSI C Code Generator
** Code to generate Type Definitions File
*/

void CCG_GenTypeDefFile(file,prefix,AptTDIncludeCount,AptTDIncludes)
FILE *file;
int AptTDIncludeCount;
char *prefix, **AptTDIncludes;
{
  CCG_GenFileHeader(file,prefix,TypeDefFileSuffix);
  CCG_GenTypeDefFileIncludes(file,AptTDIncludeCount,AptTDIncludes);
  if (!AptTDIncludes) CCG_GenDefaultTypeDef(file);
  CCG_GenSemanticStackEnumType(file);
  CCG_GenSemanticStackType(file);
  CCG_GenFileFooter(file,prefix,TypeDefFileSuffix);
}

void CCG_GenTypeDefFileIncludes(file,AptTDIncludeCount,AptTDIncludes)
FILE *file;
int AptTDIncludeCount;
char **AptTDIncludes;
{
  int i;

  gprintf(file,"#include \"%s\"\n",AptParseLibFileName);
  gprintf(file,"#include \"%s\"\n",AptScanLibFileName);
  for (i=0; i < AptTDIncludeCount; i++)
    gprintf(file,"#include \"%s.h\"\n",AptTDIncludes[i]);
  gprintf(file,"\n");
}

void CCG_GenDefaultTypeDef(file)
FILE *file;
{
  int i;

  for (i=0; i < TypeCount; i++)
    if (StringCompare(TypeTable[i],VoidIdentifier) != 0 &&
        StringCompare(TypeTable[i],TokenIdentifier) != 0)
      gprintf(file,"typedef void *%s;\n",TypeTable[i]);
  gprintf(file,"\n");
}

void CCG_GenSemanticStackEnumType(file)
FILE *file;
{
  int i;

  gprintf(file,"enum _SemanticStackTypes {\n");
  for (i=0; i < TypeCount; i++)
    if (StringCompare(TypeTable[i],TokenIdentifier) != 0 && 
        StringCompare(TypeTable[i],VoidIdentifier) != 0)
      gprintf(file,"   SST_%s,\n",TypeTable[i]);
  gprintf(file,"   SST_%s,\n",TokenIdentifier);
  gprintf(file,"   SST_%s\n",VoidIdentifier);
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenSemanticStackTypeTable(file)
FILE *file;
{
  int i;

  gprintf(file,"char *SemanticStackTypeTable[] = {\n");
  for (i=0; i < TypeCount; i++)
    if (StringCompare(TypeTable[i],TokenIdentifier) != 0 &&
        StringCompare(TypeTable[i],VoidIdentifier) != 0)
      gprintf(file,"  \"%s\",\n",TypeTable[i]);
  gprintf(file,"  \"%s\",\n",TokenIdentifier);
  gprintf(file,"  \"%s\"\n",VoidIdentifier);
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenSemanticStackType(file)
FILE *file;
{
  int i;
  gprintf(file,"struct _SemanticStackElement {\n");
  gprintf(file,"   enum _SemanticStackTypes type;\n");
  gprintf(file,"   union _SemanticStackElementUnion {\n");
  for (i=0; i < TypeCount; i++)
    if (StringCompare(TypeTable[i],TokenIdentifier) != 0 &&
        StringCompare(TypeTable[i],VoidIdentifier) != 0)
      gprintf(file,"      %s U_%s;\n",TypeTable[i],TypeTable[i]);
  gprintf(file,"      %s U_%s;\n",TokenIdentifier,TokenIdentifier);
  gprintf(file,"   } u;\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

/*
 * ANSI C Code Generator
 * Code to generate Prototypes File
 */

void CCG_GenProtoFile(file,prefix)
FILE *file;
char *prefix;
{
  CCG_GenFileHeader(file,prefix,PrototypeFileSuffix);
  CCG_GenProtoFileIncludes(file,prefix);
  CCG_GenActionPrototypes(file);
  CCG_GenFileFooter(file,prefix,PrototypeFileSuffix);
}

void CCG_GenProtoFileIncludes(file,prefix)
FILE *file;
char *prefix;
{
  gprintf(file,"#include \"%s.%s\"\n",prefix,TypeDefFileSuffix);
  gprintf(file,"\n");
}

void PrintAction(action)
void *action;
{
  ActionNode *ActPtr = action;

  gprintf(stderr,"act -> %s\n",ActPtr->function);
}

void CCG_GenActionPrototypes(file)
FILE *file;
{
  gprintf(file,"#ifdef __ANSI_C__\n");
  if (ActionTree != NULL) CCG_GenANSIActionPrototypes(file,ActionTree->root);
  gprintf(file,"#else\n");
  if (ActionTree != NULL) CCG_GenOLDCActionPrototypes(file,ActionTree->root);
  gprintf(file,"#endif /* __ANSI_C__ */\n");
  gprintf(file,"\n");
}

void CCG_GenANSIActionPrototypes(file,ActionList)
FILE *file;
AVLTreeItem ActionList;
{
  ActionNode *ActPtr;
  ParamNode *ParPtr;

  if (ActionList != NULL) {
    CCG_GenANSIActionPrototypes(file,ActionList->left);
    ActPtr = ActionList->element;
    gprintf(file,"%s %s(",ActPtr->type,ActPtr->function);
    if (ActPtr->params == NULL)
      gprintf(file,"void");
    else
      for (ParPtr=ActPtr->params; ParPtr != NULL; ParPtr = ParPtr->next)
        gprintf(file,"%s%s",ParPtr->type,ParPtr->next == NULL ? "" : ", ");
    gprintf(file,");\n");
    CCG_GenANSIActionPrototypes(file,ActionList->right);
  }
}

void CCG_GenOLDCActionPrototypes(file,ActionList)
FILE *file;
AVLTreeItem ActionList;
{
  ActionNode *ActPtr;

  if (ActionList != NULL) {
    CCG_GenOLDCActionPrototypes(file,ActionList->left);
    ActPtr = ActionList->element;
    gprintf(file,"%s %s();\n",ActPtr->type,ActPtr->function);
    CCG_GenOLDCActionPrototypes(file,ActionList->right);
  }
}

/*
 * ANSI C Code Generator
 * Code to generate Header File
 */

void CCG_GenHeaderFile(file,prefix)
FILE *file;
char *prefix;
{
  int NonTermBase, TermBase, ActionBase, Count = 0;

  CCG_GenFileHeader(file,prefix,HeaderFileSuffix);
  CCG_GenHeaderFileIncludes(file,prefix);
  CCG_GenPhaseEnumType(file);
  NonTermBase = Count;
  CCG_GenNonterminalEnumType(file,&Count);
  TermBase = Count;
  if (AptFlags[AptOptTermDefs])
    CCG_GenTerminalEnumType(file,&Count);
  else
    CCG_GenTerminalEnumTypeNoDefs(file,&Count);
  ActionBase = Count;
  CCG_GenActionEnumType(file,&Count);
  CCG_GenMiscInfo(file);
  CCG_GenSymbolLimits(file,NonTermBase,TermBase,ActionBase);
  CCG_GenLinkageInfo(file);
  CCG_GenFileFooter(file,prefix,HeaderFileSuffix);
}

void CCG_GenPhaseEnumType(file)
FILE *file;
{
  PhaseNode *phaseNode;

  gprintf(file,"enum SemanticPhases {\n");
  for (phaseNode=PhaseList; phaseNode != NULL; phaseNode = phaseNode->next) {
    if (phaseNode != PhaseList) gprintf(file,",\n");
    gprintf(file,"  P_%s",phaseNode->text);
  }
  gprintf(file,"\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenLinkageInfo(file)
FILE *file;
{
  gprintf(file,"extern _ActionTablePtrType ActionTable;\n");
  gprintf(file,"extern _PhaseTableType PhaseTable;\n");
  gprintf(file,"extern struct _PredictionTripleElement PredictionTriple[];\n");
  gprintf(file,"extern short PredictIndexTable[];\n");
  gprintf(file,"extern struct _ProductionTableElement ProductionTable[];\n");
  gprintf(file,"extern struct _SymbolTableElement SymbolTable[];\n");
  gprintf(file,"extern char *SemanticStackTypeTable[];\n");
  gprintf(file,"extern char *PhaseName[];\n");
  gprintf(file,"\n");
}


void CCG_GenNonterminalEnumType(file,count)
FILE *file;
int *count;
{
  int i, LocalCount;

  gprintf(file,"enum NonterminalDefinitions {\n");
  for (LocalCount=i=0; i < SymbolCount; i++)
    if (SymTab[i].type == NonTerminal) {
      if (!CCG_IsCIdent(CCG_AliasFor(SymTab[i].symbol)))
        gprintf(stderr,"Warning: Nonterminal symbol %s is not a C identifier.\n", CCG_AliasFor(SymTab[i].symbol));
      gprintf(file,"  ");
      CCG_EmitSymbol(file,i);
      gprintf(file," = %d,\n",*count+LocalCount);
      LocalCount++;
    }
  gprintf(file,"\n");
  gprintf(file,"  APT_NonterminalCount = %d\n",LocalCount);
  gprintf(file,"};\n");
  gprintf(file,"\n");
  *count += LocalCount;
}

void CCG_GenTerminalEnumType(file,count)
FILE *file;
int *count;
{
  int i, LocalCount;

  gprintf(file,"enum TerminalDefinitions {\n");
  for (LocalCount=i=0; i < SymbolCount; i++)

    if (SymTab[i].type == Terminal) {
      if (!CCG_IsCIdent(CCG_AliasFor(SymTab[i].symbol)))
        gprintf(stderr,"Warning: Terminal symbol %s is not a C identifier.\n", CCG_AliasFor(SymTab[i].symbol));
      gprintf(file,"  ");
      CCG_EmitSymbol(file,i);
      gprintf(file," = %d,\n",*count+LocalCount);
      LocalCount++;
    }
  gprintf(file,"\n");
  gprintf(file,"  APT_TerminalCount = %d\n",LocalCount);
  gprintf(file,"};\n");
  gprintf(file,"\n");
  *count += LocalCount;
}

void CCG_GenTerminalEnumTypeNoDefs(file,count)
FILE *file;
int *count;
{
  int i, LocalCount;

  for (LocalCount=i=0; i < SymbolCount; i++)
    if (SymTab[i].type == Terminal) {
      LocalCount++;
    }
  gprintf(file,"#define TerminalCount %d\n",LocalCount);
  gprintf(file,"\n");
  *count += LocalCount;
}

void CCG_GenActionEnumType(file,count)
FILE *file;
int *count;
{
  int i, LocalCount;

  gprintf(file,"enum ActionDefinitions {\n");
  for (LocalCount=i=0; i < SymbolCount; i++)
    if (SymTab[i].type == Action) {
      if (!CCG_IsCIdent(CCG_AliasFor(SymTab[i].symbol)))
        gprintf(stderr,"Warning: Action symbol %s is not a C identifier.\n", CCG_AliasFor(SymTab[i].symbol));
      gprintf(file,"  ");
      CCG_EmitSymbol(file,i);
      gprintf(file," = %d,\n",*count+LocalCount);
      LocalCount++;
    }
  gprintf(file,"\n");
  gprintf(file,"  APT_ActionCount = %d\n",LocalCount);
  gprintf(file,"};\n");
  gprintf(file,"\n");
  *count += LocalCount;
}

void CCG_GenMiscInfo(file)
FILE *file;
{
  gprintf(file,"#define NumberOfSymbols %d\n",SymbolCount);
  gprintf(file,"#define NumberOfProductions %d\n",ProductionCount);
  gprintf(file,"#define NumberOfPredictions %d\n",PredictionCount);
  gprintf(file,"\n");
}

void CCG_GenSymbolLimits(file,NTBase,TBase,ABase)
FILE *file;
int NTBase, TBase, ABase;
{
  gprintf(file,"#define NonterminalBase %d\n",NTBase);
  gprintf(file,"#define NonterminalLimit %d\n",NTBase + NonTerminalCount-1);
  gprintf(file,"#define TerminalBase %d\n",TBase);
  gprintf(file,"#define TerminalLimit %d\n",TBase + TerminalCount-1);
  gprintf(file,"#define ActionBase %d\n",ABase);
  gprintf(file,"#define ActionLimit %d\n",ABase + ActionCount-1);
  gprintf(file,"\n");
  gprintf(file,"#define IsNonterminal(x) ((x) >= NonterminalBase && (x) <= NonterminalLimit)\n");
  gprintf(file,"#define IsTerminal(x) ((x) >= TerminalBase && (x) <= TerminalLimit)\n");
  gprintf(file,"#define IsAction(x) ((x) >= ActionBase && (x) <= ActionLimit)\n");
  gprintf(file,"\n");
}

void CCG_GenActionFile(file,grmPrefix,prefix)
FILE *file;
char *grmPrefix, *prefix;
{
  CCG_GenFileHeader(file,prefix,CodeFileSuffix);
  CCG_GenActionFileIncludes(file,grmPrefix);
  CCG_GenStubActions(file);
  CCG_GenFileFooter(file,prefix,CodeFileSuffix);
}

void CCG_GenActionFileIncludes(file,prefix)
FILE *file;
char *prefix;
{
  gprintf(file,"#include \"%s\"\n",AptFileName);
  gprintf(file,"#include \"%s\"\n",AptScanLibFileName);
  gprintf(file,"#include \"%s\"\n",AptParseLibFileName);
  gprintf(file,"#include \"%s\"\n",AptTypeFileName);
  gprintf(file,"#include \"%s.%s\"\n",prefix,TypeDefFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,HeaderFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,PrototypeFileSuffix);
  gprintf(file,"\n");
}

void CCG_GenStubActions(file)
FILE *file;
{
  if (ActionTree) CCG_GenANSIAction(file,ActionTree->root);
}

void CCG_GenANSIAction(file,ActionList)
FILE *file;
AVLTreeItem ActionList;
{
  ActionNode *ActPtr;
  ParamNode *ParPtr;
  int ParNo;

  if (ActionList != NULL) {
    CCG_GenANSIAction(file,ActionList->left);
    ActPtr = ActionList->element;

    gprintf(file,"/*\n");
    gprintf(file,"**\n");
    gprintf(file,"** %s\n",ActPtr->function);
    gprintf(file,"**\n");
    gprintf(file,"*/\n");
    gprintf(file,"PUBLIC\n");
    gprintf(file,"#ifdef __ANSI_C__\n");
    gprintf(file,"%s %s(",ActPtr->type,ActPtr->function);
    if (ActPtr->params == NULL)
      gprintf(file,"void");
    else
      for (ParNo=1,ParPtr=ActPtr->params; ParPtr != NULL; ParPtr = ParPtr->next, ParNo++)
        gprintf(file,"%s P%d%s",ParPtr->type,ParNo,ParPtr->next == NULL ? "" : ", ");
    gprintf(file,")\n");
    gprintf(file,"#else\n");
    gprintf(file,"%s %s(",ActPtr->type,ActPtr->function);
    for (ParNo=1,ParPtr=ActPtr->params; ParPtr != NULL; ParPtr = ParPtr->next, ParNo++)
        gprintf(file,"P%d%s",ParNo,ParPtr->next == NULL ? "" : ", ");
    gprintf(file,")\n");
    for (ParNo=1,ParPtr=ActPtr->params; ParPtr != NULL; ParPtr = ParPtr->next, ParNo++)
      gprintf(file,"%s P%d;\n",ParPtr->type,ParNo);
    gprintf(file,"#endif\n");

    gprintf(file,"{\n");
    if (StringCompare(ActPtr->type,VoidIdentifier) != 0)
      gprintf(file,"  return ((%s)NULL);\n",ActPtr->type);
    else
      gprintf(file,"  return;\n");
    gprintf(file,"}\n\n");
    CCG_GenANSIAction(file,ActionList->right);
  }
}

/*
 * ANSI C Code Generator
 * Code to generate Code File
 */

void CCG_GenCodeFile(file,prefix)
FILE *file;
char *prefix;
{
  CCG_GenFileHeader(file,prefix,CodeFileSuffix);
  CCG_GenCodeFileIncludes(file,prefix);
  CCG_GenSymbolTable(file);
  CCG_GenProductionTable(file);
  CCG_GenPredictionTable(file);
  CCG_GenPredictHelpTable(file);
  CCG_GenSemanticStackTypeTable(file);
  CCG_GenSemanticPhases(file);
  CCG_GenSemanticPhaseTable(file);
  CCG_GenSemanticPhaseNameTable(file);
  CCG_GenFileFooter(file,prefix,CodeFileSuffix);
}

void CCG_GenCodeFileIncludes(file,prefix)
FILE *file;
char *prefix;
{
  gprintf(file,"#include \"%s\"\n",AptFileName);
  gprintf(file,"#include \"%s\"\n",AptParseLibFileName);
  gprintf(file,"#include \"%s\"\n",AptScanLibFileName);
  gprintf(file,"#include \"%s.%s\"\n",prefix,TypeDefFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,HeaderFileSuffix);
  gprintf(file,"#include \"%s.%s\"\n",prefix,PrototypeFileSuffix);
  gprintf(file,"#include \"%s\"\n",AptText);
  gprintf(file,"\n");
}

/*
** Generate code for the default semantic phase and all named
** phases thereafter.  The default phase eop markers are named as specified
** in the specification file, while named phase eop markers are named as 
** specified with an appropriate prefix (for obvious reasons).
*/

void CCG_GenSemanticPhases(file)
FILE *file;
{
  PhaseNode *phaseNode;

  for (phaseNode=PhaseList; phaseNode != NULL; phaseNode=phaseNode->next) {
    CCG_GenActions(file,phaseNode->text);
    CCG_GenActionLookupTable(file,phaseNode->text);
    if (phaseNode == PhaseList)
      CCG_GenDefaultActionTable(file,phaseNode->text);
  }
}

void CCG_GenSemanticPhaseTable(file)
FILE *file;
{
  PhaseNode *phaseNode;

  gprintf(file,"_PhaseTableType PhaseTable = {\n");
  for (phaseNode=PhaseList; phaseNode != NULL; phaseNode=phaseNode->next) {
    gprintf(file,"  %s_ActionTable,\n",phaseNode->text);
  }
  gprintf(file,"  NULL\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenSemanticPhaseNameTable(file)
FILE *file;
{
  PhaseNode *phaseNode;

  gprintf(file,"char *PhaseName[] = {\n");
  for (phaseNode=PhaseList; phaseNode != NULL; phaseNode=phaseNode->next) {
    gprintf(file,"  \"%s\",\n",phaseNode->text);
  }
  gprintf(file,"  NULL\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenPredictHelpTable(file)
FILE *file;
{
  int i, j, sum = 0;

  gprintf(file,"short PredictIndexTable[] = {\n");
  for (i=0; i < NonTerminalCount; i++) {
    gprintf(file,"  %d,\n",sum);
    if (SymTab[i].type == NonTerminal)
      for (j=0; j < NonTerminalCount+TerminalCount; j++)
        sum += SymTab[j].type == Terminal && ll_predict[i][j] >= 0;
  }
  gprintf(file,"  %d\n",sum);
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenHeaderFileIncludes(file,prefix)
FILE *file;
char *prefix;
{
  gprintf(file,"#include \"%s\"\n",AptTypeFileName);
  gprintf(file,"\n");
}


void CCG_GenSymbolTable(file)
FILE *file;
{
  int i;

  gprintf(file,"_SymbolTableElement SymbolTable[] = {\n");
  for (i=0; i < SymbolCount; i++) {
    gprintf(file,"  \"%s\", ",SymTab[i].symbol);
    switch(SymTab[i].type) {
    case NonTerminal:
      gprintf(file,"NonTerminal");
      break;
    case Terminal:
      gprintf(file,"Terminal");
      break;
    case Action:
      gprintf(file,"Action");
      break;
    }
    gprintf(file,",\n");
  }
  gprintf(file,"  NULL\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenProductionTable(file)
FILE *file;
{
  CCG_GenRHSBuffer(file);
  CCG_GenProductTable(file);
}

void CCG_GenRHSBuffer(file)
FILE *file;
{
  int i,j;

  gprintf(file,"short _RHS[] = {\n");
  for (i=0; i < ProductionCount; i++) {
    if (ProductTab[i].lenRHSA > 0) {
      gprintf(file,"  ");
      for (j=0; j < ProductTab[i].lenRHSA; j++) {
        CCG_EmitSymbol(file,ProductTab[i].RHSA[j]);
        gprintf(file,", ");
      }
      gprintf(file,"\n");
    }
  }
  gprintf(file,"  0\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenProductTable(file)
FILE *file;
{
  int i, SumOfRHS;

  gprintf(file,"_ProductionTableElement ProductionTable[] = {\n");
  for (SumOfRHS=i=0; i < ProductionCount; i++) {
    gprintf(file,"  ");
    CCG_EmitSymbol(file,ProductTab[i].LHS);
    gprintf(file,", ");
    gprintf(file,"%d",ProductTab[i].lenRHSA);
    gprintf(file,", ");
    gprintf(file,"_RHS + %d",SumOfRHS);
    SumOfRHS += ProductTab[i].lenRHSA;
    gprintf(file,",");
    gprintf(file,"\n");
  }
  gprintf(file,"  0\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenPredictionTable(file)
FILE *file;
{
  int i, j;
  int sum = 0;
  gprintf(file,"_PredictionTripleElement PredictionTriple[] = {\n");
  for (i=0; i < NonTerminalCount+TerminalCount; i++)
    if (SymTab[i].type == NonTerminal)
      for (j=0; j < NonTerminalCount+TerminalCount; j++)
        if (SymTab[j].type == Terminal && ll_predict[i][j] >= 0) {
          gprintf(file,"  /* %d */ ",sum++);
          CCG_EmitSymbol(file,i);
          gprintf(file,", ");
          CCG_EmitSymbol(file,j);
          gprintf(file,", ");
          gprintf(file,"%d,\n",ll_predict[i][j]);
        }
  gprintf(file,"  0\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}

void CCG_GenActions(file,phase)
FILE *file;
char *phase;
{
  int action;

  for (action = NonTerminalCount+TerminalCount; action < SymbolCount; action++)
    CCG_GenAction(file,SymTab[action].symbol,phase);
}

void CCG_GenAction(file,ActName,phase)
FILE *file;
char *ActName;
char *phase;
{
  ActionNode *ActPtr;

  ActPtr = CCG_FindAction(ActName,phase);      /* check phase */
  if (ActPtr == NULL) {
    gprintf(stderr,"Error: No definition for EOPM %s in phase %s.\n",ActName,phase);
    CCG_GenActionHeader(file,ActName,phase);
    CCG_GenErrorBody(file);
    CCG_GenActionFooter(file);
  } else {
    CCG_GenActionHeader(file,ActName,phase);
    if (StringCompare(ActPtr->type,VoidIdentifier) == 0) {
      if (AptFlags[AptOptSemCheck])
        CCG_GenActionStackCheckCode(file,ActName,ActPtr,phase);
      CCG_GenActionInvocationCode1(file,ActPtr);
      CCG_GenActionStackSpillCode(file,ActPtr);
    } else {
      CCG_GenActionLocals(file);
      if (AptFlags[AptOptSemCheck])
        CCG_GenActionStackCheckCode(file,ActName,ActPtr,phase);
      CCG_GenActionInvocationCode2(file,ActPtr);
      CCG_GenActionStackSpillCode(file,ActPtr);
      CCG_GenActionPushLocals(file);
    }
    CCG_GenActionFooter(file);
  }
  gprintf(file,"\n");
}

void CCG_GenActionHeader(file,ActName,phase)
FILE *file;
char *ActName;
char *phase;
{
  gprintf(file,"void %s_%s()\n",ActName,phase);
  gprintf(file,"{\n");
}

void CCG_GenActionFooter(file)
FILE *file;
{
  gprintf(file,"}\n");
}

void CCG_GenErrorBody(file)
FILE *file;
{
  gprintf(file,"  exit(1);\n");
}

void CCG_GenActionLocals(file)
FILE *file;
{
  gprintf(file,"  SemanticStackElement AttIn;\n");
  gprintf(file,"\n");
}

void CCG_GenActionStackCheckCode(file,ActName,ActPtr,phase)
FILE *file;
char *ActName;
ActionNode *ActPtr;
char *phase;
{
  ParamNode *p;

  gprintf(file,"#ifdef SemanticErrorCheckOn\n");
  for (p=ActPtr->params; p != NULL; p=p->next)
    gprintf(file,"  CheckStackAt(\"%s_%s\",SemanticStack,%d,SST_%s);\n",ActName,phase,p->offset,p->type);
  gprintf(file,"#endif\n");
  gprintf(file,"\n");
}

void CCG_GenActionInvocationCode2(file,ActPtr)
FILE *file;
ActionNode *ActPtr;
{
  ParamNode *p;

  gprintf(file,"  AttIn = SSENew();\n");
  gprintf(file,"  AttIn->type = SST_%s;\n",ActPtr->type);
  gprintf(file,"  AttIn->u.U_%s = %s(",ActPtr->type,ActPtr->function);
  if (ActPtr->params == NULL) gprintf(file,");\n");
  for (p=ActPtr->params; p != NULL; p=p->next) {
    gprintf(file,"SSEGet(SemanticStack,%d)->u.U_%s",p->offset,p->type);
    gprintf(file,p->next == NULL ? ");\n" : ",\n      ");
  }
}

void CCG_GenActionInvocationCode1(file,ActPtr)
FILE *file;
ActionNode *ActPtr;
{
  ParamNode *p;

  gprintf(file,"  %s(",ActPtr->function);
  if (ActPtr->params == NULL)
    gprintf(file,");\n");
  for (p=ActPtr->params; p != NULL; p=p->next) {
    gprintf(file,"SSEGet(SemanticStack,%d)->u.U_%s",p->offset,p->type);
    gprintf(file,p->next == NULL ? ");\n" : ",\n      ");
  }
}

void CCG_GenActionStackSpillCode(file,ActPtr)
FILE *file;
ActionNode *ActPtr;
{
  gprintf(file,"  AStackSpill(SemanticStack,%d,NULL);\n",ActPtr->popNumber);
}

void CCG_GenActionPushLocals(file)
FILE *file;
{
  gprintf(file,"  AStackPushPointer(SemanticStack,AttIn);\n");
}

void CCG_GenActionLookupTable(file,phase)
FILE *file;
char *phase;
{
  int action;

  gprintf(file,"_ActionTableType %s_ActionTable = {\n",phase);
  for (action = NonTerminalCount+TerminalCount; action < SymbolCount; action++) {
    gprintf(file,"  %s_%s",SymTab[action].symbol,phase);
    gprintf(file,",\n");
  }
  gprintf(file,"  NULL\n");
  gprintf(file,"};\n");
  gprintf(file,"\n");
}


void CCG_GenDefaultActionTable(file,phase)
FILE *file;
char *phase;
{
  gprintf(file,"_ActionTablePtrType ActionTable = %s_ActionTable;\n",phase);
  gprintf(file,"\n");
}

/*
 * Support Routines
 */

void CCG_GenFileHeader(fp,prefix,suffix)
FILE *fp;
char *prefix, *suffix;
{
  gprintf(fp,"#ifndef %s_%s\n",prefix,suffix);
  gprintf(fp,"#define %s_%s\n",prefix,suffix);
  gprintf(fp,"\n");
}

void CCG_GenFileFooter(fp,prefix,suffix)
FILE *fp;
char *prefix, *suffix;
{
  gprintf(fp,"#endif /* %s_%s */\n",prefix,suffix);
}

int CCG_FileExists(prefix,suffix)
char *prefix, *suffix;
{
  char *filename;
  FILE *fp;
  int exists;

  filename = (char *)Allocate(strlen(prefix)+strlen(suffix)+1);
  StringCatenate(filename,prefix);
  StringCatenate(filename,".");
  StringCatenate(filename,suffix);
  fp = fopen(filename,"r");
  exists = fp != NULL;
  if (fp != NULL) fclose(fp);
  free(filename);
  return exists;
}

FILE *CCG_OpenOutFile(prefix,suffix)
char *prefix;
char *suffix;
{
  char *filename;
  FILE *fp;

  filename = ((char *)Allocate(strlen(prefix)+strlen(suffix)+2));
  StringCatenate(filename,prefix);
  StringCatenate(filename,".");
  StringCatenate(filename,suffix);
  fp = fopen(filename,"w");
  free(filename);
  return (fp);
}

int CCG_IsCIdent(symbol)
char *symbol;
{
  char *p;
  int first = 1;

  if (symbol == NULL) return 0;
  for (p=symbol; *p; p++) {
    if (first && !isalpha(*p) && *p != '_')
      return 0;
    if (!isalpha(*p) && !isdigit(*p) && *p != '_')
      return 0;
    first = 0;
  }
  return 1;
}


char *CCG_AliasFor(symbol)
char *symbol;
{
  AliasNode *p;

  for (p=AliasList; p != NULL; p=p->next)
    if (StringCompare(p->symbol->text,symbol) == 0)
      return p->alias;
  return symbol;
}

void CCG_EmitSymbol(file,index)
FILE *file;
int index;
{
  switch(SymTab[index].type) {
  case NonTerminal:
    gprintf(file,"NT_");
    break;
  case Terminal:
    gprintf(file,"T_");
    break;
  case Action:
    gprintf(file,"A_");
  }
  gprintf(file,CCG_AliasFor(SymTab[index].symbol));
}

ActionNode *CCG_FindAction(ActName, phase)
char *ActName;
char *phase;
{
  ActionNode *p;

  for (p=ActionList; p != NULL; p=p->next)
    if (StringCompare(ActName,p->symbol->text) == 0) {
      if (CCG_FindPhase(p->phases,phase))
        return p;
    }
  return NULL;
}

int CCG_FindPhase(phaseList, phase)
PhaseNode *phaseList;
char *phase;
{
  PhaseNode *phaseNode;

  /* default phases have empty phase lists */

  for (phaseNode = phaseList; phaseNode != NULL; phaseNode = phaseNode->next)
    if (StringCompare(phaseNode->text,phase) == 0)
      return 1;
  return 0;
}
