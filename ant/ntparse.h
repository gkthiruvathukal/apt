#ifndef ntparse_h
#define ntparse_h

#include "apttype.h"

enum SemanticPhases {
  P_XL
};

enum NonterminalDefinitions {
  NT_Goal = 0,
  NT_Items = 1,
  NT_File = 2,
  NT_ItemList = 3,
  NT_Item = 4,
  NT_Enum = 5,
  NT_Include = 6,
  NT_Node = 7,
  NT_Tags = 8,
  NT_SemiOpt = 9,
  NT_Elements = 10,
  NT_TagList = 11,
  NT_Tag = 12,
  NT_TagListTail = 13,
  NT_ElementList = 14,
  NT_Element = 15,
  NT_Slot = 16,
  NT_Decl = 17,
  NT_Decls = 18,
  NT_DeclList = 19,
  NT_NullOp = 20,
  NT_Specs = 21,
  NT_Vars = 22,
  NT_Semi = 23,
  NT_SpecList = 24,
  NT_ClassSpec = 25,
  NT_Spec = 26,
  NT_SpecListTail = 27,
  NT_TypeSpec = 28,
  NT_StClSpec = 29,
  NT_TypeQual = 30,
  NT_VarList = 31,
  NT_Var = 32,
  NT_VarListTail = 33,
  NT_Ptrs = 34,
  NT_Arrays = 35,
  NT_PtrList = 36,
  NT_ArrayList = 37,
  NT_Array = 38,
  NT_ArrayTail = 39,

  APT_NonterminalCount = 40
};

enum TerminalDefinitions {
  T_EoF = 40,
  T_enum = 41,
  T_ident = 42,
  T_lbrace = 43,
  T_rbrace = 44,
  T_include = 45,
  T_fileIdent = 46,
  T_node = 47,
  T_comma = 48,
  T_slot = 49,
  T_null = 50,
  T_struct = 51,
  T_union = 52,
  T_void = 53,
  T_char = 54,
  T_int = 55,
  T_float = 56,
  T_double = 57,
  T_short = 58,
  T_long = 59,
  T_signed = 60,
  T_unsigned = 61,
  T_typedef = 62,
  T_auto = 63,
  T_static = 64,
  T_extern = 65,
  T_const = 66,
  T_volatile = 67,
  T_deref = 68,
  T_lbrack = 69,
  T_integer = 70,
  T_rbrack = 71,
  T_semico = 72,

  APT_TerminalCount = 33
};

enum ActionDefinitions {
  A__Encode = 73,
  A__Q = 74,
  A__NQEnum = 75,
  A__NQInclude = 76,
  A__NQNode = 77,
  A__Enum = 78,
  A__Zap = 79,
  A__Node = 80,
  A__NQToken = 81,
  A__NQSlot = 82,
  A__Slot = 83,
  A__FakeToken = 84,
  A__NQVar = 85,

  APT_ActionCount = 13
};

#define NumberOfSymbols 86
#define NumberOfProductions 73
#define NumberOfPredictions 314

#define NonterminalBase 0
#define NonterminalLimit 39
#define TerminalBase 40
#define TerminalLimit 72
#define ActionBase 73
#define ActionLimit 85

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

#endif /* ntparse_h */
