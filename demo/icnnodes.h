#ifndef icnnodes_h
#define icnnodes_h

#include "apt.h"
#include "asttype.h"
#include "queue.h"

/* BinOp Enumeration */

typedef enum {
  BinOpMultiply,
  BinOpDivide,
  BinOpMod,
  BinOpIntersect,
  BinOpAdd,
  BinOpSubtract,
  BinOpUnion,
  BinOpDifference,
  BinOpScan,
  BinOpAssign,
  BinOpConjoin,
  BinOpAlternate,
  BinOpMultiplyAssign,
  BinOpDivideAssign,
  BinOpModAssign,
  BinOpIntersectAssign,
  BinOpAddAssign,
  BinOpSubtractAssign,
  BinOpUnionAssign,
  BinOpDifferenceAssign,
  BinOpScanAssign,
  BinOpUndefined,
  BinOpCount
} BinOp;

/* LeafType Enumeration */

typedef enum {
  LeafTypeAny,
  LeafTypeInteger,
  LeafTypeReal,
  LeafTypeString,
  LeafTypeCset,
  LeafTypeVoid,
  LeafTypeUndefined,
  LeafTypeCount
} LeafType;

/* RangeType Enumeration */

typedef enum {
  RangeStandard,
  RangePlus,
  RangeMinus,
  RangeUndefined,
  RangeTypeCount
} RangeType;

/* RelOp Enumeration */

typedef enum {
  RelOpEqual,
  RelOpLessThan,
  RelOpLessThanEqual,
  RelOpGreaterThan,
  RelOpGreaterThanEqual,
  RelOpNotEqual,
  RelOpUndefined,
  RelOpCount
} RelOp;

/* Sides Enumeration */

typedef enum {
  Left,
  Right,
  SidesCount
} Sides;

/* TernaryOp Enumeration */

typedef enum {
  TernaryOpToBy,
  TernaryOpCount
} TernaryOp;

/* UnaryOp Enumeration */

typedef enum {
  UnaryOpNot,
  UnaryOpAlternate,
  UnaryOpGenerate,
  UnaryOpSizeOf,
  UnaryOpPlus,
  UnaryOpMinus,
  UnaryOpDereference,
  UnaryOpNull,
  UnaryOpEqual,
  UnaryOpScan,
  UnaryOpNotNull,
  UnaryOpCsetComplement,
  UnaryOpActivate,
  UnaryOpRefresh,
  UnaryOpUndefined,
  UnaryOpCount
} UnaryOp;

/* CaseClause Structure */

typedef struct _CaseClause {
  struct _Expression* tag;
  struct _Expression* e;
} _CaseClause, *CaseClause;

/* CaseClause Prototypes */

#ifdef __ANSI_C__
CaseClause CaseClauseDuplicate(CaseClause);
CaseClause CaseClauseNew(struct _Expression*,struct _Expression*);
CaseClause CaseClauseUpdate(CaseClause,struct _Expression*,struct _Expression*);
#else
CaseClause CaseClauseDuplicate();
CaseClause CaseClauseNew();
CaseClause CaseClauseUpdate();
#endif

/* EquivInfo Structure */

typedef struct _EquivInfo {
  Token x;
  Token y;
} _EquivInfo, *EquivInfo;

/* EquivInfo Prototypes */

#ifdef __ANSI_C__
EquivInfo EquivInfoDuplicate(EquivInfo);
EquivInfo EquivInfoNew(Token,Token);
EquivInfo EquivInfoUpdate(EquivInfo,Token,Token);
#else
EquivInfo EquivInfoDuplicate();
EquivInfo EquivInfoNew();
EquivInfo EquivInfoUpdate();
#endif

/* Type Enumeration */

typedef enum {
  TypeRecordTag,
  TypeUnionTag,
  TypeFieldTag,
  TypeIdTag,
  TypeLeafTag,
  TypeSetTag,
  TypeListTag,
  TypeTableTag,
  TypeProcedureTag,
  TypeRefTag,
  TypeTagCount
} TypeTags;

/* Type Slots */

struct _TypeRecord {
  Queue fields;
};

struct _TypeUnion {
  Queue fields;
};

struct _TypeField {
  Token name;
  struct _Type* type;
};

struct _TypeId {
  Token id;
};

struct _TypeLeaf {
  LeafType type;
};

struct _TypeSet {
  struct _Type* type;
};

struct _TypeList {
  struct _Type* type;
};

struct _TypeTable {
  struct _Type* index;
  struct _Type* type;
};

struct _TypeProcedure {
  Queue params;
  struct _Type* type;
};

struct _TypeRef {
  struct _Type* type;
};

typedef union {
  struct _TypeRecord RecordSlot;
  struct _TypeUnion UnionSlot;
  struct _TypeField FieldSlot;
  struct _TypeId IdSlot;
  struct _TypeLeaf LeafSlot;
  struct _TypeSet SetSlot;
  struct _TypeList ListSlot;
  struct _TypeTable TableSlot;
  struct _TypeProcedure ProcedureSlot;
  struct _TypeRef RefSlot;
} TypeUnion;

/* Type Structure */

typedef struct _Type {
  TypeTags tag;
  TypeUnion U;
} _Type, *Type;

/* Type Macros */

#define TypeRecordSlot(n) (n->U.RecordSlot)
#define TypeUnionSlot(n) (n->U.UnionSlot)
#define TypeFieldSlot(n) (n->U.FieldSlot)
#define TypeIdSlot(n) (n->U.IdSlot)
#define TypeLeafSlot(n) (n->U.LeafSlot)
#define TypeSetSlot(n) (n->U.SetSlot)
#define TypeListSlot(n) (n->U.ListSlot)
#define TypeTableSlot(n) (n->U.TableSlot)
#define TypeProcedureSlot(n) (n->U.ProcedureSlot)
#define TypeRefSlot(n) (n->U.RefSlot)

/* Type Prototypes */

#ifdef __ANSI_C__
Type TypeRecordDuplicate(Type);
Type TypeRecordNew(Queue);
Type TypeRecordUpdate(Type,Queue);
Type TypeUnionDuplicate(Type);
Type TypeUnionNew(Queue);
Type TypeUnionUpdate(Type,Queue);
Type TypeFieldDuplicate(Type);
Type TypeFieldNew(Token,struct _Type*);
Type TypeFieldUpdate(Type,Token,struct _Type*);
Type TypeIdDuplicate(Type);
Type TypeIdNew(Token);
Type TypeIdUpdate(Type,Token);
Type TypeLeafDuplicate(Type);
Type TypeLeafNew(LeafType);
Type TypeLeafUpdate(Type,LeafType);
Type TypeSetDuplicate(Type);
Type TypeSetNew(struct _Type*);
Type TypeSetUpdate(Type,struct _Type*);
Type TypeListDuplicate(Type);
Type TypeListNew(struct _Type*);
Type TypeListUpdate(Type,struct _Type*);
Type TypeTableDuplicate(Type);
Type TypeTableNew(struct _Type*,struct _Type*);
Type TypeTableUpdate(Type,struct _Type*,struct _Type*);
Type TypeProcedureDuplicate(Type);
Type TypeProcedureNew(Queue,struct _Type*);
Type TypeProcedureUpdate(Type,Queue,struct _Type*);
Type TypeRefDuplicate(Type);
Type TypeRefNew(struct _Type*);
Type TypeRefUpdate(Type,struct _Type*);
#else
Type TypeRecordDuplicate();
Type TypeRecordNew();
Type TypeRecordUpdate();
Type TypeUnionDuplicate();
Type TypeUnionNew();
Type TypeUnionUpdate();
Type TypeFieldDuplicate();
Type TypeFieldNew();
Type TypeFieldUpdate();
Type TypeIdDuplicate();
Type TypeIdNew();
Type TypeIdUpdate();
Type TypeLeafDuplicate();
Type TypeLeafNew();
Type TypeLeafUpdate();
Type TypeSetDuplicate();
Type TypeSetNew();
Type TypeSetUpdate();
Type TypeListDuplicate();
Type TypeListNew();
Type TypeListUpdate();
Type TypeTableDuplicate();
Type TypeTableNew();
Type TypeTableUpdate();
Type TypeProcedureDuplicate();
Type TypeProcedureNew();
Type TypeProcedureUpdate();
Type TypeRefDuplicate();
Type TypeRefNew();
Type TypeRefUpdate();
#endif

/* Expression Enumeration */

typedef enum {
  ExpressionUnaryTag,
  ExpressionBinaryTag,
  ExpressionTernaryTag,
  ExpressionRelOpTag,
  ExpressionProcCallTag,
  ExpressionSubscriptTag,
  ExpressionCastTag,
  ExpressionFieldRefTag,
  ExpressionRepeatTag,
  ExpressionWhileTag,
  ExpressionUntilTag,
  ExpressionEveryTag,
  ExpressionIfTag,
  ExpressionCaseTag,
  ExpressionNextTag,
  ExpressionBreakTag,
  ExpressionReturnTag,
  ExpressionSuspendTag,
  ExpressionFailTag,
  ExpressionCreateTag,
  ExpressionListConsTag,
  ExpressionRangeTag,
  ExpressionSequenceTag,
  ExpressionConstIntTag,
  ExpressionConstRealTag,
  ExpressionConstCsetTag,
  ExpressionConstStringTag,
  ExpressionVarTag,
  ExpressionConvertTag,
  ExpressionTagCount
} ExpressionTags;

/* Expression Slots */

struct _ExpressionUnary {
  UnaryOp op;
  struct _Expression* e;
};

struct _ExpressionBinary {
  BinOp op;
  struct _Expression* e1;
  struct _Expression* e2;
};

struct _ExpressionTernary {
  TernaryOp op;
  struct _Expression* e1;
  struct _Expression* e2;
  struct _Expression* e3;
};

struct _ExpressionRelOp {
  RelOp op;
  struct _Expression* e1;
  struct _Expression* e2;
};

struct _ExpressionProcCall {
  struct _Expression* proc;
  Queue params;
};

struct _ExpressionSubscript {
  struct _Expression* array;
  struct _Expression* subscript;
};

struct _ExpressionCast {
  struct _Expression* e;
  Type t;
};

struct _ExpressionFieldRef {
  struct _Expression* e;
  Token field;
};

struct _ExpressionRepeat {
  struct _Expression* e;
};

struct _ExpressionWhile {
  struct _Expression* e;
  struct _Expression* body;
};

struct _ExpressionUntil {
  struct _Expression* e;
  struct _Expression* body;
};

struct _ExpressionEvery {
  struct _Expression* e;
  struct _Expression* body;
};

struct _ExpressionIf {
  struct _Expression* cond;
  struct _Expression* e_true;
  struct _Expression* e_false;
};

struct _ExpressionCase {
  struct _Expression* cond;
  Queue cases;
};

struct _ExpressionNext {
  char AptParsingTools;
};

struct _ExpressionBreak {
  struct _Expression* e;
};

struct _ExpressionReturn {
  struct _Expression* e;
};

struct _ExpressionSuspend {
  struct _Expression* e;
};

struct _ExpressionFail {
  char AptParsingTools;
};

struct _ExpressionCreate {
  struct _Expression* e;
};

struct _ExpressionListCons {
  Queue elements;
};

struct _ExpressionRange {
  RangeType rt;
  struct _Expression* low;
  struct _Expression* high;
};

struct _ExpressionSequence {
  Queue elements;
};

struct _ExpressionConstInt {
  signed long int value;
};

struct _ExpressionConstReal {
  double value;
};

struct _ExpressionConstCset {
  char *value;
};

struct _ExpressionConstString {
  char *value;
};

struct _ExpressionVar {
  Token id;
  int location;
};

struct _ExpressionConvert {
  Type srcType;
  Type dstType;
  struct _Expression* e;
};

typedef union {
  struct _ExpressionUnary UnarySlot;
  struct _ExpressionBinary BinarySlot;
  struct _ExpressionTernary TernarySlot;
  struct _ExpressionRelOp RelOpSlot;
  struct _ExpressionProcCall ProcCallSlot;
  struct _ExpressionSubscript SubscriptSlot;
  struct _ExpressionCast CastSlot;
  struct _ExpressionFieldRef FieldRefSlot;
  struct _ExpressionRepeat RepeatSlot;
  struct _ExpressionWhile WhileSlot;
  struct _ExpressionUntil UntilSlot;
  struct _ExpressionEvery EverySlot;
  struct _ExpressionIf IfSlot;
  struct _ExpressionCase CaseSlot;
  struct _ExpressionNext NextSlot;
  struct _ExpressionBreak BreakSlot;
  struct _ExpressionReturn ReturnSlot;
  struct _ExpressionSuspend SuspendSlot;
  struct _ExpressionFail FailSlot;
  struct _ExpressionCreate CreateSlot;
  struct _ExpressionListCons ListConsSlot;
  struct _ExpressionRange RangeSlot;
  struct _ExpressionSequence SequenceSlot;
  struct _ExpressionConstInt ConstIntSlot;
  struct _ExpressionConstReal ConstRealSlot;
  struct _ExpressionConstCset ConstCsetSlot;
  struct _ExpressionConstString ConstStringSlot;
  struct _ExpressionVar VarSlot;
  struct _ExpressionConvert ConvertSlot;
} ExpressionUnion;

/* Expression Structure */

typedef struct _Expression {
  ExpressionTags tag;
  ExpressionUnion U;
  Sides side;
  Type type;
} _Expression, *Expression;

/* Expression Macros */

#define ExpressionUnarySlot(n) (n->U.UnarySlot)
#define ExpressionBinarySlot(n) (n->U.BinarySlot)
#define ExpressionTernarySlot(n) (n->U.TernarySlot)
#define ExpressionRelOpSlot(n) (n->U.RelOpSlot)
#define ExpressionProcCallSlot(n) (n->U.ProcCallSlot)
#define ExpressionSubscriptSlot(n) (n->U.SubscriptSlot)
#define ExpressionCastSlot(n) (n->U.CastSlot)
#define ExpressionFieldRefSlot(n) (n->U.FieldRefSlot)
#define ExpressionRepeatSlot(n) (n->U.RepeatSlot)
#define ExpressionWhileSlot(n) (n->U.WhileSlot)
#define ExpressionUntilSlot(n) (n->U.UntilSlot)
#define ExpressionEverySlot(n) (n->U.EverySlot)
#define ExpressionIfSlot(n) (n->U.IfSlot)
#define ExpressionCaseSlot(n) (n->U.CaseSlot)
#define ExpressionNextSlot(n) (n->U.NextSlot)
#define ExpressionBreakSlot(n) (n->U.BreakSlot)
#define ExpressionReturnSlot(n) (n->U.ReturnSlot)
#define ExpressionSuspendSlot(n) (n->U.SuspendSlot)
#define ExpressionFailSlot(n) (n->U.FailSlot)
#define ExpressionCreateSlot(n) (n->U.CreateSlot)
#define ExpressionListConsSlot(n) (n->U.ListConsSlot)
#define ExpressionRangeSlot(n) (n->U.RangeSlot)
#define ExpressionSequenceSlot(n) (n->U.SequenceSlot)
#define ExpressionConstIntSlot(n) (n->U.ConstIntSlot)
#define ExpressionConstRealSlot(n) (n->U.ConstRealSlot)
#define ExpressionConstCsetSlot(n) (n->U.ConstCsetSlot)
#define ExpressionConstStringSlot(n) (n->U.ConstStringSlot)
#define ExpressionVarSlot(n) (n->U.VarSlot)
#define ExpressionConvertSlot(n) (n->U.ConvertSlot)

/* Expression Prototypes */

#ifdef __ANSI_C__
Expression ExpressionUnaryDuplicate(Expression);
Expression ExpressionUnaryNew(UnaryOp,struct _Expression*);
Expression ExpressionUnaryUpdate(Expression,UnaryOp,struct _Expression*);
Expression ExpressionBinaryDuplicate(Expression);
Expression ExpressionBinaryNew(BinOp,struct _Expression*,struct _Expression*);
Expression ExpressionBinaryUpdate(Expression,BinOp,struct _Expression*,struct _Expression*);
Expression ExpressionTernaryDuplicate(Expression);
Expression ExpressionTernaryNew(TernaryOp,struct _Expression*,struct _Expression*,struct _Expression*);
Expression ExpressionTernaryUpdate(Expression,TernaryOp,struct _Expression*,struct _Expression*,struct _Expression*);
Expression ExpressionRelOpDuplicate(Expression);
Expression ExpressionRelOpNew(RelOp,struct _Expression*,struct _Expression*);
Expression ExpressionRelOpUpdate(Expression,RelOp,struct _Expression*,struct _Expression*);
Expression ExpressionProcCallDuplicate(Expression);
Expression ExpressionProcCallNew(struct _Expression*,Queue);
Expression ExpressionProcCallUpdate(Expression,struct _Expression*,Queue);
Expression ExpressionSubscriptDuplicate(Expression);
Expression ExpressionSubscriptNew(struct _Expression*,struct _Expression*);
Expression ExpressionSubscriptUpdate(Expression,struct _Expression*,struct _Expression*);
Expression ExpressionCastDuplicate(Expression);
Expression ExpressionCastNew(struct _Expression*,Type);
Expression ExpressionCastUpdate(Expression,struct _Expression*,Type);
Expression ExpressionFieldRefDuplicate(Expression);
Expression ExpressionFieldRefNew(struct _Expression*,Token);
Expression ExpressionFieldRefUpdate(Expression,struct _Expression*,Token);
Expression ExpressionRepeatDuplicate(Expression);
Expression ExpressionRepeatNew(struct _Expression*);
Expression ExpressionRepeatUpdate(Expression,struct _Expression*);
Expression ExpressionWhileDuplicate(Expression);
Expression ExpressionWhileNew(struct _Expression*,struct _Expression*);
Expression ExpressionWhileUpdate(Expression,struct _Expression*,struct _Expression*);
Expression ExpressionUntilDuplicate(Expression);
Expression ExpressionUntilNew(struct _Expression*,struct _Expression*);
Expression ExpressionUntilUpdate(Expression,struct _Expression*,struct _Expression*);
Expression ExpressionEveryDuplicate(Expression);
Expression ExpressionEveryNew(struct _Expression*,struct _Expression*);
Expression ExpressionEveryUpdate(Expression,struct _Expression*,struct _Expression*);
Expression ExpressionIfDuplicate(Expression);
Expression ExpressionIfNew(struct _Expression*,struct _Expression*,struct _Expression*);
Expression ExpressionIfUpdate(Expression,struct _Expression*,struct _Expression*,struct _Expression*);
Expression ExpressionCaseDuplicate(Expression);
Expression ExpressionCaseNew(struct _Expression*,Queue);
Expression ExpressionCaseUpdate(Expression,struct _Expression*,Queue);
Expression ExpressionNextDuplicate(Expression);
Expression ExpressionNextNew(void);
Expression ExpressionNextUpdate(Expression);
Expression ExpressionBreakDuplicate(Expression);
Expression ExpressionBreakNew(struct _Expression*);
Expression ExpressionBreakUpdate(Expression,struct _Expression*);
Expression ExpressionReturnDuplicate(Expression);
Expression ExpressionReturnNew(struct _Expression*);
Expression ExpressionReturnUpdate(Expression,struct _Expression*);
Expression ExpressionSuspendDuplicate(Expression);
Expression ExpressionSuspendNew(struct _Expression*);
Expression ExpressionSuspendUpdate(Expression,struct _Expression*);
Expression ExpressionFailDuplicate(Expression);
Expression ExpressionFailNew(void);
Expression ExpressionFailUpdate(Expression);
Expression ExpressionCreateDuplicate(Expression);
Expression ExpressionCreateNew(struct _Expression*);
Expression ExpressionCreateUpdate(Expression,struct _Expression*);
Expression ExpressionListConsDuplicate(Expression);
Expression ExpressionListConsNew(Queue);
Expression ExpressionListConsUpdate(Expression,Queue);
Expression ExpressionRangeDuplicate(Expression);
Expression ExpressionRangeNew(RangeType,struct _Expression*,struct _Expression*);
Expression ExpressionRangeUpdate(Expression,RangeType,struct _Expression*,struct _Expression*);
Expression ExpressionSequenceDuplicate(Expression);
Expression ExpressionSequenceNew(Queue);
Expression ExpressionSequenceUpdate(Expression,Queue);
Expression ExpressionConstIntDuplicate(Expression);
Expression ExpressionConstIntNew(signed long int);
Expression ExpressionConstIntUpdate(Expression,signed long int);
Expression ExpressionConstRealDuplicate(Expression);
Expression ExpressionConstRealNew(double);
Expression ExpressionConstRealUpdate(Expression,double);
Expression ExpressionConstCsetDuplicate(Expression);
Expression ExpressionConstCsetNew(char*);
Expression ExpressionConstCsetUpdate(Expression,char*);
Expression ExpressionConstStringDuplicate(Expression);
Expression ExpressionConstStringNew(char*);
Expression ExpressionConstStringUpdate(Expression,char*);
Expression ExpressionVarDuplicate(Expression);
Expression ExpressionVarNew(Token);
Expression ExpressionVarUpdate(Expression,Token);
Expression ExpressionConvertDuplicate(Expression);
Expression ExpressionConvertNew(Type,Type,struct _Expression*);
Expression ExpressionConvertUpdate(Expression,Type,Type,struct _Expression*);
#else
Expression ExpressionUnaryDuplicate();
Expression ExpressionUnaryNew();
Expression ExpressionUnaryUpdate();
Expression ExpressionBinaryDuplicate();
Expression ExpressionBinaryNew();
Expression ExpressionBinaryUpdate();
Expression ExpressionTernaryDuplicate();
Expression ExpressionTernaryNew();
Expression ExpressionTernaryUpdate();
Expression ExpressionRelOpDuplicate();
Expression ExpressionRelOpNew();
Expression ExpressionRelOpUpdate();
Expression ExpressionProcCallDuplicate();
Expression ExpressionProcCallNew();
Expression ExpressionProcCallUpdate();
Expression ExpressionSubscriptDuplicate();
Expression ExpressionSubscriptNew();
Expression ExpressionSubscriptUpdate();
Expression ExpressionCastDuplicate();
Expression ExpressionCastNew();
Expression ExpressionCastUpdate();
Expression ExpressionFieldRefDuplicate();
Expression ExpressionFieldRefNew();
Expression ExpressionFieldRefUpdate();
Expression ExpressionRepeatDuplicate();
Expression ExpressionRepeatNew();
Expression ExpressionRepeatUpdate();
Expression ExpressionWhileDuplicate();
Expression ExpressionWhileNew();
Expression ExpressionWhileUpdate();
Expression ExpressionUntilDuplicate();
Expression ExpressionUntilNew();
Expression ExpressionUntilUpdate();
Expression ExpressionEveryDuplicate();
Expression ExpressionEveryNew();
Expression ExpressionEveryUpdate();
Expression ExpressionIfDuplicate();
Expression ExpressionIfNew();
Expression ExpressionIfUpdate();
Expression ExpressionCaseDuplicate();
Expression ExpressionCaseNew();
Expression ExpressionCaseUpdate();
Expression ExpressionNextDuplicate();
Expression ExpressionNextNew();
Expression ExpressionNextUpdate();
Expression ExpressionBreakDuplicate();
Expression ExpressionBreakNew();
Expression ExpressionBreakUpdate();
Expression ExpressionReturnDuplicate();
Expression ExpressionReturnNew();
Expression ExpressionReturnUpdate();
Expression ExpressionSuspendDuplicate();
Expression ExpressionSuspendNew();
Expression ExpressionSuspendUpdate();
Expression ExpressionFailDuplicate();
Expression ExpressionFailNew();
Expression ExpressionFailUpdate();
Expression ExpressionCreateDuplicate();
Expression ExpressionCreateNew();
Expression ExpressionCreateUpdate();
Expression ExpressionListConsDuplicate();
Expression ExpressionListConsNew();
Expression ExpressionListConsUpdate();
Expression ExpressionRangeDuplicate();
Expression ExpressionRangeNew();
Expression ExpressionRangeUpdate();
Expression ExpressionSequenceDuplicate();
Expression ExpressionSequenceNew();
Expression ExpressionSequenceUpdate();
Expression ExpressionConstIntDuplicate();
Expression ExpressionConstIntNew();
Expression ExpressionConstIntUpdate();
Expression ExpressionConstRealDuplicate();
Expression ExpressionConstRealNew();
Expression ExpressionConstRealUpdate();
Expression ExpressionConstCsetDuplicate();
Expression ExpressionConstCsetNew();
Expression ExpressionConstCsetUpdate();
Expression ExpressionConstStringDuplicate();
Expression ExpressionConstStringNew();
Expression ExpressionConstStringUpdate();
Expression ExpressionVarDuplicate();
Expression ExpressionVarNew();
Expression ExpressionVarUpdate();
Expression ExpressionConvertDuplicate();
Expression ExpressionConvertNew();
Expression ExpressionConvertUpdate();
#endif

/* Misc Enumeration */

typedef enum {
  MiscParameterTag,
  MiscProcHeadTag,
  MiscTypePairTag,
  MiscTagCount
} MiscTags;

/* Misc Slots */

struct _MiscParameter {
  int refFlag;
  Token name;
  Type type;
};

struct _MiscProcHead {
  Token name;
  Queue parameters;
  int refFlag;
  Type retType;
};

struct _MiscTypePair {
  Type t1;
  Type t2;
};

typedef union {
  struct _MiscParameter ParameterSlot;
  struct _MiscProcHead ProcHeadSlot;
  struct _MiscTypePair TypePairSlot;
} MiscUnion;

/* Misc Structure */

typedef struct _Misc {
  MiscTags tag;
  MiscUnion U;
} _Misc, *Misc;

/* Misc Macros */

#define MiscParameterSlot(n) (n->U.ParameterSlot)
#define MiscProcHeadSlot(n) (n->U.ProcHeadSlot)
#define MiscTypePairSlot(n) (n->U.TypePairSlot)

/* Misc Prototypes */

#ifdef __ANSI_C__
Misc MiscParameterDuplicate(Misc);
Misc MiscParameterNew(int,Token,Type);
Misc MiscParameterUpdate(Misc,int,Token,Type);
Misc MiscProcHeadDuplicate(Misc);
Misc MiscProcHeadNew(Token,Queue,int,Type);
Misc MiscProcHeadUpdate(Misc,Token,Queue,int,Type);
Misc MiscTypePairDuplicate(Misc);
Misc MiscTypePairNew(Type,Type);
Misc MiscTypePairUpdate(Misc,Type,Type);
#else
Misc MiscParameterDuplicate();
Misc MiscParameterNew();
Misc MiscParameterUpdate();
Misc MiscProcHeadDuplicate();
Misc MiscProcHeadNew();
Misc MiscProcHeadUpdate();
Misc MiscTypePairDuplicate();
Misc MiscTypePairNew();
Misc MiscTypePairUpdate();
#endif

/* SymNode Enumeration */

typedef enum {
  SymNodeTypeTag,
  SymNodeGlobalTag,
  SymNodeExternalTag,
  SymNodeLocalStaticTag,
  SymNodeLocalAutoTag,
  SymNodeLocalDynamicTag,
  SymNodeParameterTag,
  SymNodeProcedureTag,
  SymNodeUndefinedTag,
  SymNodeTagCount
} SymNodeTags;

/* SymNode Slots */

struct _SymNodeType {
  int line;
  int column;
  Type type;
};

struct _SymNodeGlobal {
  int line;
  int column;
  Type type;
};

struct _SymNodeExternal {
  int line;
  int column;
  Type type;
};

struct _SymNodeLocalStatic {
  int line;
  int column;
  Type type;
};

struct _SymNodeLocalAuto {
  int line;
  int column;
  Type type;
};

struct _SymNodeLocalDynamic {
  int line;
  int column;
  Type type;
};

struct _SymNodeParameter {
  int line;
  int column;
  Type type;
};

struct _SymNodeProcedure {
  int line;
  int column;
  Queue parameters;
  Type retType;
};

struct _SymNodeUndefined {
  char AptParsingTools;
};

typedef union {
  struct _SymNodeType TypeSlot;
  struct _SymNodeGlobal GlobalSlot;
  struct _SymNodeExternal ExternalSlot;
  struct _SymNodeLocalStatic LocalStaticSlot;
  struct _SymNodeLocalAuto LocalAutoSlot;
  struct _SymNodeLocalDynamic LocalDynamicSlot;
  struct _SymNodeParameter ParameterSlot;
  struct _SymNodeProcedure ProcedureSlot;
  struct _SymNodeUndefined UndefinedSlot;
} SymNodeUnion;

/* SymNode Structure */

typedef struct _SymNode {
  SymNodeTags tag;
  SymNodeUnion U;
} _SymNode, *SymNode;

/* SymNode Macros */

#define SymNodeTypeSlot(n) (n->U.TypeSlot)
#define SymNodeGlobalSlot(n) (n->U.GlobalSlot)
#define SymNodeExternalSlot(n) (n->U.ExternalSlot)
#define SymNodeLocalStaticSlot(n) (n->U.LocalStaticSlot)
#define SymNodeLocalAutoSlot(n) (n->U.LocalAutoSlot)
#define SymNodeLocalDynamicSlot(n) (n->U.LocalDynamicSlot)
#define SymNodeParameterSlot(n) (n->U.ParameterSlot)
#define SymNodeProcedureSlot(n) (n->U.ProcedureSlot)
#define SymNodeUndefinedSlot(n) (n->U.UndefinedSlot)

/* SymNode Prototypes */

#ifdef __ANSI_C__
SymNode SymNodeTypeDuplicate(SymNode);
SymNode SymNodeTypeNew(int,int,Type);
SymNode SymNodeTypeUpdate(SymNode,int,int,Type);
SymNode SymNodeGlobalDuplicate(SymNode);
SymNode SymNodeGlobalNew(int,int,Type);
SymNode SymNodeGlobalUpdate(SymNode,int,int,Type);
SymNode SymNodeExternalDuplicate(SymNode);
SymNode SymNodeExternalNew(int,int,Type);
SymNode SymNodeExternalUpdate(SymNode,int,int,Type);
SymNode SymNodeLocalStaticDuplicate(SymNode);
SymNode SymNodeLocalStaticNew(int,int,Type);
SymNode SymNodeLocalStaticUpdate(SymNode,int,int,Type);
SymNode SymNodeLocalAutoDuplicate(SymNode);
SymNode SymNodeLocalAutoNew(int,int,Type);
SymNode SymNodeLocalAutoUpdate(SymNode,int,int,Type);
SymNode SymNodeLocalDynamicDuplicate(SymNode);
SymNode SymNodeLocalDynamicNew(int,int,Type);
SymNode SymNodeLocalDynamicUpdate(SymNode,int,int,Type);
SymNode SymNodeParameterDuplicate(SymNode);
SymNode SymNodeParameterNew(int,int,Type);
SymNode SymNodeParameterUpdate(SymNode,int,int,Type);
SymNode SymNodeProcedureDuplicate(SymNode);
SymNode SymNodeProcedureNew(int,int,Queue,Type);
SymNode SymNodeProcedureUpdate(SymNode,int,int,Queue,Type);
SymNode SymNodeUndefinedDuplicate(SymNode);
SymNode SymNodeUndefinedNew(void);
SymNode SymNodeUndefinedUpdate(SymNode);
#else
SymNode SymNodeTypeDuplicate();
SymNode SymNodeTypeNew();
SymNode SymNodeTypeUpdate();
SymNode SymNodeGlobalDuplicate();
SymNode SymNodeGlobalNew();
SymNode SymNodeGlobalUpdate();
SymNode SymNodeExternalDuplicate();
SymNode SymNodeExternalNew();
SymNode SymNodeExternalUpdate();
SymNode SymNodeLocalStaticDuplicate();
SymNode SymNodeLocalStaticNew();
SymNode SymNodeLocalStaticUpdate();
SymNode SymNodeLocalAutoDuplicate();
SymNode SymNodeLocalAutoNew();
SymNode SymNodeLocalAutoUpdate();
SymNode SymNodeLocalDynamicDuplicate();
SymNode SymNodeLocalDynamicNew();
SymNode SymNodeLocalDynamicUpdate();
SymNode SymNodeParameterDuplicate();
SymNode SymNodeParameterNew();
SymNode SymNodeParameterUpdate();
SymNode SymNodeProcedureDuplicate();
SymNode SymNodeProcedureNew();
SymNode SymNodeProcedureUpdate();
SymNode SymNodeUndefinedDuplicate();
SymNode SymNodeUndefinedNew();
SymNode SymNodeUndefinedUpdate();
#endif

#endif /* icnnodes_h */
