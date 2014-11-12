#ifndef test_h
#define test_h

#include "apttype.h"

enum SemanticPhases {
  P_A
};

enum NonterminalDefinitions {
  NT_Goal = 0,
  NT_SectionList = 1,
  NT_LanguageSpec = 2,
  NT_Section = 3,
  NT_EoLSep = 4,
  NT_ProductionList = 5,
  NT_AliasList = 6,
  NT_PhaseIdList = 7,
  NT_ActionList = 8,
  NT_FiducialList = 9,
  NT_PhaseList = 10,
  NT_Production = 11,
  NT_RhsList = 12,
  NT_EoLs = 13,
  NT_PhaseId = 14,
  NT_PhaseIdListTail = 15,
  NT_Action = 16,
  NT_Parameters = 17,
  NT_Parameter = 18,
  NT_ParamTail = 19,
  NT_ParamNumber = 20,
  NT_Alias = 21,
  NT_Fiducial = 22,
  NT_Phase = 23,
  NT_EoLsTl = 24,

  APT_NonterminalCount = 25
};

enum TerminalDefinitions {
  T_EoF = 25,
  T_productions = 26,
  T_aliases = 27,
  T_actions = 28,
  T_fiducials = 29,
  T_phases = 30,
  T_ident = 31,
  T_arrow = 32,
  T_lparen = 33,
  T_rparen = 34,
  T_colon = 35,
  T_comma = 36,
  T_number = 37,
  T_character = 38,
  T_string = 39,
  T_EoL = 40,

  APT_TerminalCount = 16
};

enum ActionDefinitions {
  A__BeginSpec = 41,
  A__EndSpec = 42,
  A__ListGroup = 43,
  A__ListEmpty = 44,
  A__BeginProductions = 45,
  A__EndProductions = 46,
  A__BeginAliases = 47,
  A__EndAliases = 48,
  A__BeginPhaseIds = 49,
  A__EndPhaseIds = 50,
  A__BeginActions = 51,
  A__EndActions = 52,
  A__BeginFiducials = 53,
  A__EndFiducials = 54,
  A__BeginPhases = 55,
  A__EndPhases = 56,
  A__DoProduction = 57,
  A__RhsIdent = 58,
  A__DoPhaseId = 59,
  A__DoAction = 60,
  A__ParamEnum = 61,
  A__ParamChar = 62,
  A__ParamString = 63,
  A__ParamStack = 64,
  A__ParamInt = 65,
  A__DoAlias = 66,
  A__DoFiducial = 67,
  A__DoPhase = 68,
  A__EatEoL = 69,

  APT_ActionCount = 29
};

#define NumberOfSymbols 70
#define NumberOfProductions 45
#define NumberOfPredictions 94

#define NonterminalBase 0
#define NonterminalLimit 24
#define TerminalBase 25
#define TerminalLimit 40
#define ActionBase 41
#define ActionLimit 69

#define IsNonterminal(x) ((x) >= NonterminalBase && (x) <= NonterminalLimit)
#define IsTerminal(x) ((x) >= TerminalBase && (x) <= TerminalLimit)
#define IsAction(x) ((x) >= ActionBase && (x) <= ActionLimit)

extern _ActionTablePtrType ActionTable;
extern _PhaseTableType PhaseTable;
extern struct _PredictionTripleElement PredictionTriple[];
extern short PredictIndexTable[];
extern struct _ProductionTableElement ProductionTable[];
extern struct _SymbolTableElement SymbolTable[];
extern char *SemanticStackTypeTable[];
extern char *PhaseName[];

#endif /* test_h */
