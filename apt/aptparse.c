#ifndef aptparse_c
#define aptparse_c

#include "apt.h"
#include "aptacts.h"
#include "aptlib.h"
#include "astlib.h"
#include "aptparse.td"
#include "aptparse.h"
#include "aptparse.pt"
#include "apttext.h"

_SymbolTableElement SymbolTable[] = {
  "Goal", NonTerminal,
  "SectionList", NonTerminal,
  "LanguageSpec", NonTerminal,
  "Section", NonTerminal,
  "EoLSep", NonTerminal,
  "ProductionList", NonTerminal,
  "AliasList", NonTerminal,
  "PhaseIdList", NonTerminal,
  "ActionList", NonTerminal,
  "FiducialList", NonTerminal,
  "PhaseList", NonTerminal,
  "Production", NonTerminal,
  "RhsList", NonTerminal,
  "EoLs", NonTerminal,
  "PhaseId", NonTerminal,
  "PhaseIdListTail", NonTerminal,
  "Action", NonTerminal,
  "Parameters", NonTerminal,
  "Parameter", NonTerminal,
  "ParamTail", NonTerminal,
  "ParamNumber", NonTerminal,
  "Alias", NonTerminal,
  "Fiducial", NonTerminal,
  "Phase", NonTerminal,
  "EoLsTl", NonTerminal,
  "EoF", Terminal,
  "productions", Terminal,
  "aliases", Terminal,
  "actions", Terminal,
  "fiducials", Terminal,
  "phases", Terminal,
  "ident", Terminal,
  "<-", Terminal,
  "(", Terminal,
  ")", Terminal,
  ":", Terminal,
  ",", Terminal,
  "number", Terminal,
  "character", Terminal,
  "string", Terminal,
  "EoL", Terminal,
  "_BeginSpec", Action,
  "_EndSpec", Action,
  "_ListGroup", Action,
  "_ListEmpty", Action,
  "_BeginProductions", Action,
  "_EndProductions", Action,
  "_BeginAliases", Action,
  "_EndAliases", Action,
  "_BeginPhaseIds", Action,
  "_EndPhaseIds", Action,
  "_BeginActions", Action,
  "_EndActions", Action,
  "_BeginFiducials", Action,
  "_EndFiducials", Action,
  "_BeginPhases", Action,
  "_EndPhases", Action,
  "_DoProduction", Action,
  "_RhsIdent", Action,
  "_DoPhaseId", Action,
  "_DoAction", Action,
  "_ParamEnum", Action,
  "_ParamChar", Action,
  "_ParamString", Action,
  "_ParamStack", Action,
  "_ParamInt", Action,
  "_DoAlias", Action,
  "_DoFiducial", Action,
  "_DoPhase", Action,
  "_EatEoL", Action,
  NULL
};

short _RHS[] = {
  NT_LanguageSpec, T_EoF, 
  A__BeginSpec, NT_SectionList, A__EndSpec, 
  NT_Section, NT_SectionList, A__ListGroup, 
  A__ListEmpty, 
  T_productions, NT_EoLSep, A__BeginProductions, NT_ProductionList, A__EndProductions, 
  T_aliases, NT_EoLSep, A__BeginAliases, NT_AliasList, A__EndAliases, 
  T_actions, A__BeginPhaseIds, NT_PhaseIdList, A__EndPhaseIds, NT_EoLSep, A__BeginActions, NT_ActionList, A__EndActions, 
  T_fiducials, NT_EoLSep, A__BeginFiducials, NT_FiducialList, A__EndFiducials, 
  T_phases, NT_EoLSep, A__BeginPhases, NT_PhaseList, A__EndPhases, 
  NT_Production, NT_ProductionList, A__ListGroup, 
  A__ListEmpty, 
  T_ident, T_arrow, NT_RhsList, NT_EoLs, A__DoProduction, 
  T_ident, A__RhsIdent, NT_RhsList, A__ListGroup, 
  T_arrow, A__RhsIdent, NT_RhsList, A__ListGroup, 
  A__ListEmpty, 
  NT_PhaseId, NT_PhaseIdListTail, A__ListGroup, 
  NT_PhaseId, NT_PhaseIdListTail, A__ListGroup, 
  A__ListEmpty, 
  T_ident, A__DoPhaseId, 
  NT_Action, NT_ActionList, A__ListGroup, 
  A__ListEmpty, 
  T_ident, T_ident, T_lparen, NT_Parameters, T_rparen, T_colon, T_lparen, T_ident, T_comma, T_number, T_rparen, NT_EoLs, A__DoAction, 
  NT_Parameter, NT_ParamTail, A__ListGroup, 
  A__ListEmpty, 
  T_comma, NT_Parameter, A__ListGroup, NT_ParamTail, A__ListGroup, 
  A__ListEmpty, 
  T_number, NT_ParamNumber, 
  T_ident, A__ParamEnum, 
  T_character, A__ParamChar, 
  T_string, A__ParamString, 
  T_colon, T_ident, A__ParamStack, 
  A__ParamInt, 
  NT_Alias, NT_AliasList, A__ListGroup, 
  A__ListEmpty, 
  T_ident, T_ident, NT_EoLs, A__DoAlias, 
  NT_Fiducial, NT_FiducialList, A__ListGroup, 
  A__ListEmpty, 
  T_ident, NT_EoLs, A__DoFiducial, 
  NT_Phase, NT_PhaseList, A__ListGroup, 
  A__ListEmpty, 
  T_ident, NT_EoLs, A__DoPhase, 
  T_EoL, NT_EoLsTl, 
  T_EoL, A__EatEoL, NT_EoLsTl, 
  NT_EoLs, A__EatEoL, 
  0
};

_ProductionTableElement ProductionTable[] = {
  NT_Goal, 2, _RHS + 0,
  NT_LanguageSpec, 3, _RHS + 2,
  NT_SectionList, 3, _RHS + 5,
  NT_SectionList, 1, _RHS + 8,
  NT_Section, 5, _RHS + 9,
  NT_Section, 5, _RHS + 14,
  NT_Section, 8, _RHS + 19,
  NT_Section, 5, _RHS + 27,
  NT_Section, 5, _RHS + 32,
  NT_ProductionList, 3, _RHS + 37,
  NT_ProductionList, 1, _RHS + 40,
  NT_Production, 5, _RHS + 41,
  NT_RhsList, 4, _RHS + 46,
  NT_RhsList, 4, _RHS + 50,
  NT_RhsList, 1, _RHS + 54,
  NT_PhaseIdList, 3, _RHS + 55,
  NT_PhaseIdListTail, 3, _RHS + 58,
  NT_PhaseIdListTail, 1, _RHS + 61,
  NT_PhaseId, 2, _RHS + 62,
  NT_ActionList, 3, _RHS + 64,
  NT_ActionList, 1, _RHS + 67,
  NT_Action, 13, _RHS + 68,
  NT_Parameters, 3, _RHS + 81,
  NT_Parameters, 1, _RHS + 84,
  NT_ParamTail, 5, _RHS + 85,
  NT_ParamTail, 1, _RHS + 90,
  NT_Parameter, 2, _RHS + 91,
  NT_Parameter, 2, _RHS + 93,
  NT_Parameter, 2, _RHS + 95,
  NT_Parameter, 2, _RHS + 97,
  NT_ParamNumber, 3, _RHS + 99,
  NT_ParamNumber, 1, _RHS + 102,
  NT_AliasList, 3, _RHS + 103,
  NT_AliasList, 1, _RHS + 106,
  NT_Alias, 4, _RHS + 107,
  NT_FiducialList, 3, _RHS + 111,
  NT_FiducialList, 1, _RHS + 114,
  NT_Fiducial, 3, _RHS + 115,
  NT_PhaseList, 3, _RHS + 118,
  NT_PhaseList, 1, _RHS + 121,
  NT_Phase, 3, _RHS + 122,
  NT_EoLs, 2, _RHS + 125,
  NT_EoLsTl, 3, _RHS + 127,
  NT_EoLsTl, 0, _RHS + 130,
  NT_EoLSep, 2, _RHS + 130,
};

_PredictionTripleElement PredictionTriple[] = {
  /* 0 */ NT_Goal, T_EoF, 0,
  /* 1 */ NT_Goal, T_productions, 0,
  /* 2 */ NT_Goal, T_aliases, 0,
  /* 3 */ NT_Goal, T_actions, 0,
  /* 4 */ NT_Goal, T_fiducials, 0,
  /* 5 */ NT_Goal, T_phases, 0,
  /* 6 */ NT_SectionList, T_EoF, 3,
  /* 7 */ NT_SectionList, T_productions, 2,
  /* 8 */ NT_SectionList, T_aliases, 2,
  /* 9 */ NT_SectionList, T_actions, 2,
  /* 10 */ NT_SectionList, T_fiducials, 2,
  /* 11 */ NT_SectionList, T_phases, 2,
  /* 12 */ NT_LanguageSpec, T_EoF, 1,
  /* 13 */ NT_LanguageSpec, T_productions, 1,
  /* 14 */ NT_LanguageSpec, T_aliases, 1,
  /* 15 */ NT_LanguageSpec, T_actions, 1,
  /* 16 */ NT_LanguageSpec, T_fiducials, 1,
  /* 17 */ NT_LanguageSpec, T_phases, 1,
  /* 18 */ NT_Section, T_productions, 4,
  /* 19 */ NT_Section, T_aliases, 5,
  /* 20 */ NT_Section, T_actions, 6,
  /* 21 */ NT_Section, T_fiducials, 7,
  /* 22 */ NT_Section, T_phases, 8,
  /* 23 */ NT_EoLSep, T_EoL, 44,
  /* 24 */ NT_ProductionList, T_EoF, 10,
  /* 25 */ NT_ProductionList, T_productions, 10,
  /* 26 */ NT_ProductionList, T_aliases, 10,
  /* 27 */ NT_ProductionList, T_actions, 10,
  /* 28 */ NT_ProductionList, T_fiducials, 10,
  /* 29 */ NT_ProductionList, T_phases, 10,
  /* 30 */ NT_ProductionList, T_ident, 9,
  /* 31 */ NT_AliasList, T_EoF, 33,
  /* 32 */ NT_AliasList, T_productions, 33,
  /* 33 */ NT_AliasList, T_aliases, 33,
  /* 34 */ NT_AliasList, T_actions, 33,
  /* 35 */ NT_AliasList, T_fiducials, 33,
  /* 36 */ NT_AliasList, T_phases, 33,
  /* 37 */ NT_AliasList, T_ident, 32,
  /* 38 */ NT_PhaseIdList, T_ident, 15,
  /* 39 */ NT_ActionList, T_EoF, 20,
  /* 40 */ NT_ActionList, T_productions, 20,
  /* 41 */ NT_ActionList, T_aliases, 20,
  /* 42 */ NT_ActionList, T_actions, 20,
  /* 43 */ NT_ActionList, T_fiducials, 20,
  /* 44 */ NT_ActionList, T_phases, 20,
  /* 45 */ NT_ActionList, T_ident, 19,
  /* 46 */ NT_FiducialList, T_EoF, 36,
  /* 47 */ NT_FiducialList, T_productions, 36,
  /* 48 */ NT_FiducialList, T_aliases, 36,
  /* 49 */ NT_FiducialList, T_actions, 36,
  /* 50 */ NT_FiducialList, T_fiducials, 36,
  /* 51 */ NT_FiducialList, T_phases, 36,
  /* 52 */ NT_FiducialList, T_ident, 35,
  /* 53 */ NT_PhaseList, T_EoF, 39,
  /* 54 */ NT_PhaseList, T_productions, 39,
  /* 55 */ NT_PhaseList, T_aliases, 39,
  /* 56 */ NT_PhaseList, T_actions, 39,
  /* 57 */ NT_PhaseList, T_fiducials, 39,
  /* 58 */ NT_PhaseList, T_phases, 39,
  /* 59 */ NT_PhaseList, T_ident, 38,
  /* 60 */ NT_Production, T_ident, 11,
  /* 61 */ NT_RhsList, T_ident, 12,
  /* 62 */ NT_RhsList, T_arrow, 13,
  /* 63 */ NT_RhsList, T_EoL, 14,
  /* 64 */ NT_EoLs, T_EoL, 41,
  /* 65 */ NT_PhaseId, T_ident, 18,
  /* 66 */ NT_PhaseIdListTail, T_ident, 16,
  /* 67 */ NT_PhaseIdListTail, T_EoL, 17,
  /* 68 */ NT_Action, T_ident, 21,
  /* 69 */ NT_Parameters, T_ident, 22,
  /* 70 */ NT_Parameters, T_rparen, 23,
  /* 71 */ NT_Parameters, T_number, 22,
  /* 72 */ NT_Parameters, T_character, 22,
  /* 73 */ NT_Parameters, T_string, 22,
  /* 74 */ NT_Parameter, T_ident, 27,
  /* 75 */ NT_Parameter, T_number, 26,
  /* 76 */ NT_Parameter, T_character, 28,
  /* 77 */ NT_Parameter, T_string, 29,
  /* 78 */ NT_ParamTail, T_rparen, 25,
  /* 79 */ NT_ParamTail, T_comma, 24,
  /* 80 */ NT_ParamNumber, T_rparen, 31,
  /* 81 */ NT_ParamNumber, T_colon, 30,
  /* 82 */ NT_ParamNumber, T_comma, 31,
  /* 83 */ NT_Alias, T_ident, 34,
  /* 84 */ NT_Fiducial, T_ident, 37,
  /* 85 */ NT_Phase, T_ident, 40,
  /* 86 */ NT_EoLsTl, T_EoF, 43,
  /* 87 */ NT_EoLsTl, T_productions, 43,
  /* 88 */ NT_EoLsTl, T_aliases, 43,
  /* 89 */ NT_EoLsTl, T_actions, 43,
  /* 90 */ NT_EoLsTl, T_fiducials, 43,
  /* 91 */ NT_EoLsTl, T_phases, 43,
  /* 92 */ NT_EoLsTl, T_ident, 43,
  /* 93 */ NT_EoLsTl, T_EoL, 42,
  0
};

short PredictIndexTable[] = {
  0,
  6,
  12,
  18,
  23,
  24,
  31,
  38,
  39,
  46,
  53,
  60,
  61,
  64,
  65,
  66,
  68,
  69,
  74,
  78,
  80,
  83,
  84,
  85,
  86,
  94
};

char *SemanticStackTypeTable[] = {
  "Token",
  "Void"
};

void _BeginSpec_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginSpec();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndSpec_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndSpec();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ListGroup_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semListGroup();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ListEmpty_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semListEmpty();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginProductions_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginProductions();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndProductions_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndProductions();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginAliases_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginAliases();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndAliases_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndAliases();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginPhaseIds_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginPhaseIds();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndPhaseIds_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndPhaseIds();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginActions_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginActions();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndActions_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndActions();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginFiducials_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginFiducials();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndFiducials_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndFiducials();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BeginPhases_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semBeginPhases();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EndPhases_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semEndPhases();
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoProduction_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoProduction_A",SemanticStack,4,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoProduction(SSEGet(SemanticStack,4)->u.U_Token);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _RhsIdent_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RhsIdent_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semRhsIdent(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoPhaseId_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoPhaseId_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoPhaseId(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoAction_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoAction_A",SemanticStack,12,SST_Token);
  CheckStackAt("_DoAction_A",SemanticStack,11,SST_Token);
  CheckStackAt("_DoAction_A",SemanticStack,5,SST_Token);
  CheckStackAt("_DoAction_A",SemanticStack,3,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoAction(SSEGet(SemanticStack,12)->u.U_Token,
      SSEGet(SemanticStack,11)->u.U_Token,
      SSEGet(SemanticStack,5)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Token);
  AStackSpill(SemanticStack,12,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ParamEnum_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ParamEnum_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semParamEnum(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ParamChar_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ParamChar_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semParamChar(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ParamString_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ParamString_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semParamString(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ParamStack_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ParamStack_A",SemanticStack,3,SST_Token);
  CheckStackAt("_ParamStack_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semParamStack(SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ParamInt_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ParamInt_A",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semParamInt(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoAlias_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoAlias_A",SemanticStack,3,SST_Token);
  CheckStackAt("_DoAlias_A",SemanticStack,2,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoAlias(SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,2)->u.U_Token);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoFiducial_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoFiducial_A",SemanticStack,2,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoFiducial(SSEGet(SemanticStack,2)->u.U_Token);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DoPhase_A()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DoPhase_A",SemanticStack,2,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = semDoPhase(SSEGet(SemanticStack,2)->u.U_Token);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EatEoL_A()
{
#ifdef SemanticErrorCheckOn
#endif

  semEatEoL();
  AStackSpill(SemanticStack,1,NULL);
}

_ActionTableType A_ActionTable = {
  _BeginSpec_A,
  _EndSpec_A,
  _ListGroup_A,
  _ListEmpty_A,
  _BeginProductions_A,
  _EndProductions_A,
  _BeginAliases_A,
  _EndAliases_A,
  _BeginPhaseIds_A,
  _EndPhaseIds_A,
  _BeginActions_A,
  _EndActions_A,
  _BeginFiducials_A,
  _EndFiducials_A,
  _BeginPhases_A,
  _EndPhases_A,
  _DoProduction_A,
  _RhsIdent_A,
  _DoPhaseId_A,
  _DoAction_A,
  _ParamEnum_A,
  _ParamChar_A,
  _ParamString_A,
  _ParamStack_A,
  _ParamInt_A,
  _DoAlias_A,
  _DoFiducial_A,
  _DoPhase_A,
  _EatEoL_A,
  NULL
};

_ActionTablePtrType ActionTable = A_ActionTable;

_PhaseTableType PhaseTable = {
  A_ActionTable,
  NULL
};

char *PhaseName[] = {
  "A",
  NULL
};

#endif /* aptparse_c */
