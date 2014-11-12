#include "apt.h"
#include "icnnodes.h"
#include "allocate.h"

/*
**
** CaseClauseDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
CaseClause CaseClauseDuplicate(CaseClause oldCaseClause)
#else
CaseClause CaseClauseDuplicate(oldCaseClause)
CaseClause oldCaseClause;
#endif
{
  CaseClause newCaseClause = (CaseClause)Allocate(sizeof(_CaseClause));
  newCaseClause->tag = oldCaseClause->tag;
  newCaseClause->e = oldCaseClause->e;
  return (newCaseClause);
}

/*
**
** CaseClauseNew
**
*/
PUBLIC
#ifdef __ANSI_C__
CaseClause CaseClauseNew(Expression tag,Expression e)
#else
CaseClause CaseClauseNew(tag,e)
Expression tag;
Expression e;
#endif
{
  CaseClause newCaseClause = (CaseClause)Allocate(sizeof(_CaseClause));
  newCaseClause->tag = tag;
  newCaseClause->e = e;
  return (newCaseClause);
}

/*
**
** CaseClauseUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
CaseClause CaseClauseUpdate(CaseClause oldCaseClause,Expression tag,Expression e)
#else
CaseClause CaseClauseUpdate(oldCaseClause,tag,e)
CaseClause oldCaseClause;
Expression tag;
Expression e;
#endif
{
  oldCaseClause->tag = tag;
  oldCaseClause->e = e;
  return (oldCaseClause);
}

/*
**
** EquivInfoDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
EquivInfo EquivInfoDuplicate(EquivInfo oldEquivInfo)
#else
EquivInfo EquivInfoDuplicate(oldEquivInfo)
EquivInfo oldEquivInfo;
#endif
{
  EquivInfo newEquivInfo = (EquivInfo)Allocate(sizeof(_EquivInfo));
  newEquivInfo->x = oldEquivInfo->x;
  newEquivInfo->y = oldEquivInfo->y;
  return (newEquivInfo);
}

/*
**
** EquivInfoNew
**
*/
PUBLIC
#ifdef __ANSI_C__
EquivInfo EquivInfoNew(Token x,Token y)
#else
EquivInfo EquivInfoNew(x,y)
Token x;
Token y;
#endif
{
  EquivInfo newEquivInfo = (EquivInfo)Allocate(sizeof(_EquivInfo));
  newEquivInfo->x = x;
  newEquivInfo->y = y;
  return (newEquivInfo);
}

/*
**
** EquivInfoUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
EquivInfo EquivInfoUpdate(EquivInfo oldEquivInfo,Token x,Token y)
#else
EquivInfo EquivInfoUpdate(oldEquivInfo,x,y)
EquivInfo oldEquivInfo;
Token x;
Token y;
#endif
{
  oldEquivInfo->x = x;
  oldEquivInfo->y = y;
  return (oldEquivInfo);
}

/*
**
** TypeRecordDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRecordDuplicate(Type oldType)
#else
Type TypeRecordDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeRecord *slot = &newType->U.RecordSlot;
  struct _TypeRecord *oldslot = &oldType->U.RecordSlot;
  newType->tag = TypeRecordTag;
  slot->fields = oldslot->fields;
  return (newType);
}

/*
**
** TypeUnionDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeUnionDuplicate(Type oldType)
#else
Type TypeUnionDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeUnion *slot = &newType->U.UnionSlot;
  struct _TypeUnion *oldslot = &oldType->U.UnionSlot;
  newType->tag = TypeUnionTag;
  slot->fields = oldslot->fields;
  return (newType);
}

/*
**
** TypeFieldDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeFieldDuplicate(Type oldType)
#else
Type TypeFieldDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeField *slot = &newType->U.FieldSlot;
  struct _TypeField *oldslot = &oldType->U.FieldSlot;
  newType->tag = TypeFieldTag;
  slot->name = oldslot->name;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeIdDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeIdDuplicate(Type oldType)
#else
Type TypeIdDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeId *slot = &newType->U.IdSlot;
  struct _TypeId *oldslot = &oldType->U.IdSlot;
  newType->tag = TypeIdTag;
  slot->id = oldslot->id;
  return (newType);
}

/*
**
** TypeLeafDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeLeafDuplicate(Type oldType)
#else
Type TypeLeafDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeLeaf *slot = &newType->U.LeafSlot;
  struct _TypeLeaf *oldslot = &oldType->U.LeafSlot;
  newType->tag = TypeLeafTag;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeSetDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeSetDuplicate(Type oldType)
#else
Type TypeSetDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeSet *slot = &newType->U.SetSlot;
  struct _TypeSet *oldslot = &oldType->U.SetSlot;
  newType->tag = TypeSetTag;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeListDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeListDuplicate(Type oldType)
#else
Type TypeListDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeList *slot = &newType->U.ListSlot;
  struct _TypeList *oldslot = &oldType->U.ListSlot;
  newType->tag = TypeListTag;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeTableDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeTableDuplicate(Type oldType)
#else
Type TypeTableDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeTable *slot = &newType->U.TableSlot;
  struct _TypeTable *oldslot = &oldType->U.TableSlot;
  newType->tag = TypeTableTag;
  slot->index = oldslot->index;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeProcedureDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeProcedureDuplicate(Type oldType)
#else
Type TypeProcedureDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeProcedure *slot = &newType->U.ProcedureSlot;
  struct _TypeProcedure *oldslot = &oldType->U.ProcedureSlot;
  newType->tag = TypeProcedureTag;
  slot->params = oldslot->params;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeRefDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRefDuplicate(Type oldType)
#else
Type TypeRefDuplicate(oldType)
Type oldType;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeRef *slot = &newType->U.RefSlot;
  struct _TypeRef *oldslot = &oldType->U.RefSlot;
  newType->tag = TypeRefTag;
  slot->type = oldslot->type;
  return (newType);
}

/*
**
** TypeRecordNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRecordNew(Queue fields)
#else
Type TypeRecordNew(fields)
Queue fields;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeRecord *slot = &newType->U.RecordSlot;
  newType->tag = TypeRecordTag;
  slot->fields = fields;
  return (newType);
}

/*
**
** TypeUnionNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeUnionNew(Queue fields)
#else
Type TypeUnionNew(fields)
Queue fields;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeUnion *slot = &newType->U.UnionSlot;
  newType->tag = TypeUnionTag;
  slot->fields = fields;
  return (newType);
}

/*
**
** TypeFieldNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeFieldNew(Token name,Type type)
#else
Type TypeFieldNew(name,type)
Token name;
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeField *slot = &newType->U.FieldSlot;
  newType->tag = TypeFieldTag;
  slot->name = name;
  slot->type = type;
  return (newType);
}

/*
**
** TypeIdNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeIdNew(Token id)
#else
Type TypeIdNew(id)
Token id;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeId *slot = &newType->U.IdSlot;
  newType->tag = TypeIdTag;
  slot->id = id;
  return (newType);
}

/*
**
** TypeLeafNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeLeafNew(LeafType type)
#else
Type TypeLeafNew(type)
LeafType type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeLeaf *slot = &newType->U.LeafSlot;
  newType->tag = TypeLeafTag;
  slot->type = type;
  return (newType);
}

/*
**
** TypeSetNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeSetNew(Type type)
#else
Type TypeSetNew(type)
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeSet *slot = &newType->U.SetSlot;
  newType->tag = TypeSetTag;
  slot->type = type;
  return (newType);
}

/*
**
** TypeListNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeListNew(Type type)
#else
Type TypeListNew(type)
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeList *slot = &newType->U.ListSlot;
  newType->tag = TypeListTag;
  slot->type = type;
  return (newType);
}

/*
**
** TypeTableNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeTableNew(Type index,Type type)
#else
Type TypeTableNew(index,type)
Type index;
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeTable *slot = &newType->U.TableSlot;
  newType->tag = TypeTableTag;
  slot->index = index;
  slot->type = type;
  return (newType);
}

/*
**
** TypeProcedureNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeProcedureNew(Queue params,Type type)
#else
Type TypeProcedureNew(params,type)
Queue params;
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeProcedure *slot = &newType->U.ProcedureSlot;
  newType->tag = TypeProcedureTag;
  slot->params = params;
  slot->type = type;
  return (newType);
}

/*
**
** TypeRefNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRefNew(Type type)
#else
Type TypeRefNew(type)
Type type;
#endif
{
  Type newType = (Type)Allocate(sizeof(_Type));
  struct _TypeRef *slot = &newType->U.RefSlot;
  newType->tag = TypeRefTag;
  slot->type = type;
  return (newType);
}

/*
**
** TypeRecordUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRecordUpdate(Type oldType,Queue fields)
#else
Type TypeRecordUpdate(oldType,fields)
Type oldType;
Queue fields;
#endif
{
  struct _TypeRecord *slot = &oldType->U.RecordSlot;
  oldType->tag = TypeRecordTag;
  slot->fields = fields;
  return (oldType);
}

/*
**
** TypeUnionUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeUnionUpdate(Type oldType,Queue fields)
#else
Type TypeUnionUpdate(oldType,fields)
Type oldType;
Queue fields;
#endif
{
  struct _TypeUnion *slot = &oldType->U.UnionSlot;
  oldType->tag = TypeUnionTag;
  slot->fields = fields;
  return (oldType);
}

/*
**
** TypeFieldUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeFieldUpdate(Type oldType,Token name,Type type)
#else
Type TypeFieldUpdate(oldType,name,type)
Type oldType;
Token name;
Type type;
#endif
{
  struct _TypeField *slot = &oldType->U.FieldSlot;
  oldType->tag = TypeFieldTag;
  slot->name = name;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeIdUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeIdUpdate(Type oldType,Token id)
#else
Type TypeIdUpdate(oldType,id)
Type oldType;
Token id;
#endif
{
  struct _TypeId *slot = &oldType->U.IdSlot;
  oldType->tag = TypeIdTag;
  slot->id = id;
  return (oldType);
}

/*
**
** TypeLeafUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeLeafUpdate(Type oldType,LeafType type)
#else
Type TypeLeafUpdate(oldType,type)
Type oldType;
LeafType type;
#endif
{
  struct _TypeLeaf *slot = &oldType->U.LeafSlot;
  oldType->tag = TypeLeafTag;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeSetUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeSetUpdate(Type oldType,Type type)
#else
Type TypeSetUpdate(oldType,type)
Type oldType;
Type type;
#endif
{
  struct _TypeSet *slot = &oldType->U.SetSlot;
  oldType->tag = TypeSetTag;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeListUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeListUpdate(Type oldType,Type type)
#else
Type TypeListUpdate(oldType,type)
Type oldType;
Type type;
#endif
{
  struct _TypeList *slot = &oldType->U.ListSlot;
  oldType->tag = TypeListTag;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeTableUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeTableUpdate(Type oldType,Type index,Type type)
#else
Type TypeTableUpdate(oldType,index,type)
Type oldType;
Type index;
Type type;
#endif
{
  struct _TypeTable *slot = &oldType->U.TableSlot;
  oldType->tag = TypeTableTag;
  slot->index = index;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeProcedureUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeProcedureUpdate(Type oldType,Queue params,Type type)
#else
Type TypeProcedureUpdate(oldType,params,type)
Type oldType;
Queue params;
Type type;
#endif
{
  struct _TypeProcedure *slot = &oldType->U.ProcedureSlot;
  oldType->tag = TypeProcedureTag;
  slot->params = params;
  slot->type = type;
  return (oldType);
}

/*
**
** TypeRefUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Type TypeRefUpdate(Type oldType,Type type)
#else
Type TypeRefUpdate(oldType,type)
Type oldType;
Type type;
#endif
{
  struct _TypeRef *slot = &oldType->U.RefSlot;
  oldType->tag = TypeRefTag;
  slot->type = type;
  return (oldType);
}

/*
**
** ExpressionUnaryDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUnaryDuplicate(Expression oldExpression)
#else
Expression ExpressionUnaryDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionUnary *slot = &newExpression->U.UnarySlot;
  struct _ExpressionUnary *oldslot = &oldExpression->U.UnarySlot;
  newExpression->tag = ExpressionUnaryTag;
  slot->op = oldslot->op;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionBinaryDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBinaryDuplicate(Expression oldExpression)
#else
Expression ExpressionBinaryDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionBinary *slot = &newExpression->U.BinarySlot;
  struct _ExpressionBinary *oldslot = &oldExpression->U.BinarySlot;
  newExpression->tag = ExpressionBinaryTag;
  slot->op = oldslot->op;
  slot->e1 = oldslot->e1;
  slot->e2 = oldslot->e2;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionTernaryDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionTernaryDuplicate(Expression oldExpression)
#else
Expression ExpressionTernaryDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionTernary *slot = &newExpression->U.TernarySlot;
  struct _ExpressionTernary *oldslot = &oldExpression->U.TernarySlot;
  newExpression->tag = ExpressionTernaryTag;
  slot->op = oldslot->op;
  slot->e1 = oldslot->e1;
  slot->e2 = oldslot->e2;
  slot->e3 = oldslot->e3;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionRelOpDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRelOpDuplicate(Expression oldExpression)
#else
Expression ExpressionRelOpDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRelOp *slot = &newExpression->U.RelOpSlot;
  struct _ExpressionRelOp *oldslot = &oldExpression->U.RelOpSlot;
  newExpression->tag = ExpressionRelOpTag;
  slot->op = oldslot->op;
  slot->e1 = oldslot->e1;
  slot->e2 = oldslot->e2;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionProcCallDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionProcCallDuplicate(Expression oldExpression)
#else
Expression ExpressionProcCallDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionProcCall *slot = &newExpression->U.ProcCallSlot;
  struct _ExpressionProcCall *oldslot = &oldExpression->U.ProcCallSlot;
  newExpression->tag = ExpressionProcCallTag;
  slot->proc = oldslot->proc;
  slot->params = oldslot->params;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionSubscriptDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSubscriptDuplicate(Expression oldExpression)
#else
Expression ExpressionSubscriptDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSubscript *slot = &newExpression->U.SubscriptSlot;
  struct _ExpressionSubscript *oldslot = &oldExpression->U.SubscriptSlot;
  newExpression->tag = ExpressionSubscriptTag;
  slot->array = oldslot->array;
  slot->subscript = oldslot->subscript;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionCastDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCastDuplicate(Expression oldExpression)
#else
Expression ExpressionCastDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCast *slot = &newExpression->U.CastSlot;
  struct _ExpressionCast *oldslot = &oldExpression->U.CastSlot;
  newExpression->tag = ExpressionCastTag;
  slot->e = oldslot->e;
  slot->t = oldslot->t;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionFieldRefDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFieldRefDuplicate(Expression oldExpression)
#else
Expression ExpressionFieldRefDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionFieldRef *slot = &newExpression->U.FieldRefSlot;
  struct _ExpressionFieldRef *oldslot = &oldExpression->U.FieldRefSlot;
  newExpression->tag = ExpressionFieldRefTag;
  slot->e = oldslot->e;
  slot->field = oldslot->field;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionRepeatDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRepeatDuplicate(Expression oldExpression)
#else
Expression ExpressionRepeatDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRepeat *slot = &newExpression->U.RepeatSlot;
  struct _ExpressionRepeat *oldslot = &oldExpression->U.RepeatSlot;
  newExpression->tag = ExpressionRepeatTag;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionWhileDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionWhileDuplicate(Expression oldExpression)
#else
Expression ExpressionWhileDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionWhile *slot = &newExpression->U.WhileSlot;
  struct _ExpressionWhile *oldslot = &oldExpression->U.WhileSlot;
  newExpression->tag = ExpressionWhileTag;
  slot->e = oldslot->e;
  slot->body = oldslot->body;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionUntilDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUntilDuplicate(Expression oldExpression)
#else
Expression ExpressionUntilDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionUntil *slot = &newExpression->U.UntilSlot;
  struct _ExpressionUntil *oldslot = &oldExpression->U.UntilSlot;
  newExpression->tag = ExpressionUntilTag;
  slot->e = oldslot->e;
  slot->body = oldslot->body;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionEveryDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionEveryDuplicate(Expression oldExpression)
#else
Expression ExpressionEveryDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionEvery *slot = &newExpression->U.EverySlot;
  struct _ExpressionEvery *oldslot = &oldExpression->U.EverySlot;
  newExpression->tag = ExpressionEveryTag;
  slot->e = oldslot->e;
  slot->body = oldslot->body;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionIfDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionIfDuplicate(Expression oldExpression)
#else
Expression ExpressionIfDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionIf *slot = &newExpression->U.IfSlot;
  struct _ExpressionIf *oldslot = &oldExpression->U.IfSlot;
  newExpression->tag = ExpressionIfTag;
  slot->cond = oldslot->cond;
  slot->e_true = oldslot->e_true;
  slot->e_false = oldslot->e_false;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionCaseDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCaseDuplicate(Expression oldExpression)
#else
Expression ExpressionCaseDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCase *slot = &newExpression->U.CaseSlot;
  struct _ExpressionCase *oldslot = &oldExpression->U.CaseSlot;
  newExpression->tag = ExpressionCaseTag;
  slot->cond = oldslot->cond;
  slot->cases = oldslot->cases;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionNextDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionNextDuplicate(Expression oldExpression)
#else
Expression ExpressionNextDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  newExpression->tag = ExpressionNextTag;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionBreakDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBreakDuplicate(Expression oldExpression)
#else
Expression ExpressionBreakDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionBreak *slot = &newExpression->U.BreakSlot;
  struct _ExpressionBreak *oldslot = &oldExpression->U.BreakSlot;
  newExpression->tag = ExpressionBreakTag;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionReturnDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionReturnDuplicate(Expression oldExpression)
#else
Expression ExpressionReturnDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionReturn *slot = &newExpression->U.ReturnSlot;
  struct _ExpressionReturn *oldslot = &oldExpression->U.ReturnSlot;
  newExpression->tag = ExpressionReturnTag;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionSuspendDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSuspendDuplicate(Expression oldExpression)
#else
Expression ExpressionSuspendDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSuspend *slot = &newExpression->U.SuspendSlot;
  struct _ExpressionSuspend *oldslot = &oldExpression->U.SuspendSlot;
  newExpression->tag = ExpressionSuspendTag;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionFailDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFailDuplicate(Expression oldExpression)
#else
Expression ExpressionFailDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  newExpression->tag = ExpressionFailTag;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionCreateDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCreateDuplicate(Expression oldExpression)
#else
Expression ExpressionCreateDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCreate *slot = &newExpression->U.CreateSlot;
  struct _ExpressionCreate *oldslot = &oldExpression->U.CreateSlot;
  newExpression->tag = ExpressionCreateTag;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionListConsDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionListConsDuplicate(Expression oldExpression)
#else
Expression ExpressionListConsDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionListCons *slot = &newExpression->U.ListConsSlot;
  struct _ExpressionListCons *oldslot = &oldExpression->U.ListConsSlot;
  newExpression->tag = ExpressionListConsTag;
  slot->elements = oldslot->elements;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionRangeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRangeDuplicate(Expression oldExpression)
#else
Expression ExpressionRangeDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRange *slot = &newExpression->U.RangeSlot;
  struct _ExpressionRange *oldslot = &oldExpression->U.RangeSlot;
  newExpression->tag = ExpressionRangeTag;
  slot->rt = oldslot->rt;
  slot->low = oldslot->low;
  slot->high = oldslot->high;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionSequenceDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSequenceDuplicate(Expression oldExpression)
#else
Expression ExpressionSequenceDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSequence *slot = &newExpression->U.SequenceSlot;
  struct _ExpressionSequence *oldslot = &oldExpression->U.SequenceSlot;
  newExpression->tag = ExpressionSequenceTag;
  slot->elements = oldslot->elements;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionConstIntDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstIntDuplicate(Expression oldExpression)
#else
Expression ExpressionConstIntDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstInt *slot = &newExpression->U.ConstIntSlot;
  struct _ExpressionConstInt *oldslot = &oldExpression->U.ConstIntSlot;
  newExpression->tag = ExpressionConstIntTag;
  slot->value = oldslot->value;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionConstRealDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstRealDuplicate(Expression oldExpression)
#else
Expression ExpressionConstRealDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstReal *slot = &newExpression->U.ConstRealSlot;
  struct _ExpressionConstReal *oldslot = &oldExpression->U.ConstRealSlot;
  newExpression->tag = ExpressionConstRealTag;
  slot->value = oldslot->value;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionConstCsetDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstCsetDuplicate(Expression oldExpression)
#else
Expression ExpressionConstCsetDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstCset *slot = &newExpression->U.ConstCsetSlot;
  struct _ExpressionConstCset *oldslot = &oldExpression->U.ConstCsetSlot;
  newExpression->tag = ExpressionConstCsetTag;
  slot->value = oldslot->value;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionConstStringDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstStringDuplicate(Expression oldExpression)
#else
Expression ExpressionConstStringDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstString *slot = &newExpression->U.ConstStringSlot;
  struct _ExpressionConstString *oldslot = &oldExpression->U.ConstStringSlot;
  newExpression->tag = ExpressionConstStringTag;
  slot->value = oldslot->value;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionVarDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionVarDuplicate(Expression oldExpression)
#else
Expression ExpressionVarDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionVar *slot = &newExpression->U.VarSlot;
  struct _ExpressionVar *oldslot = &oldExpression->U.VarSlot;
  newExpression->tag = ExpressionVarTag;
  slot->id = oldslot->id;
  slot->location = oldslot->location;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionConvertDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConvertDuplicate(Expression oldExpression)
#else
Expression ExpressionConvertDuplicate(oldExpression)
Expression oldExpression;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConvert *slot = &newExpression->U.ConvertSlot;
  struct _ExpressionConvert *oldslot = &oldExpression->U.ConvertSlot;
  newExpression->tag = ExpressionConvertTag;
  slot->srcType = oldslot->srcType;
  slot->dstType = oldslot->dstType;
  slot->e = oldslot->e;
  newExpression->side = oldExpression->side;
  newExpression->type = oldExpression->type;
  return (newExpression);
}

/*
**
** ExpressionUnaryNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUnaryNew(UnaryOp op,Expression e)
#else
Expression ExpressionUnaryNew(op,e)
UnaryOp op;
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionUnary *slot = &newExpression->U.UnarySlot;
  newExpression->tag = ExpressionUnaryTag;
  slot->op = op;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionBinaryNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBinaryNew(BinOp op,Expression e1,Expression e2)
#else
Expression ExpressionBinaryNew(op,e1,e2)
BinOp op;
Expression e1;
Expression e2;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionBinary *slot = &newExpression->U.BinarySlot;
  newExpression->tag = ExpressionBinaryTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionTernaryNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionTernaryNew(TernaryOp op,Expression e1,Expression e2,Expression e3)
#else
Expression ExpressionTernaryNew(op,e1,e2,e3)
TernaryOp op;
Expression e1;
Expression e2;
Expression e3;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionTernary *slot = &newExpression->U.TernarySlot;
  newExpression->tag = ExpressionTernaryTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  slot->e3 = e3;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionRelOpNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRelOpNew(RelOp op,Expression e1,Expression e2)
#else
Expression ExpressionRelOpNew(op,e1,e2)
RelOp op;
Expression e1;
Expression e2;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRelOp *slot = &newExpression->U.RelOpSlot;
  newExpression->tag = ExpressionRelOpTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionProcCallNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionProcCallNew(Expression proc,Queue params)
#else
Expression ExpressionProcCallNew(proc,params)
Expression proc;
Queue params;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionProcCall *slot = &newExpression->U.ProcCallSlot;
  newExpression->tag = ExpressionProcCallTag;
  slot->proc = proc;
  slot->params = params;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionSubscriptNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSubscriptNew(Expression array,Expression subscript)
#else
Expression ExpressionSubscriptNew(array,subscript)
Expression array;
Expression subscript;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSubscript *slot = &newExpression->U.SubscriptSlot;
  newExpression->tag = ExpressionSubscriptTag;
  slot->array = array;
  slot->subscript = subscript;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionCastNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCastNew(Expression e,Type t)
#else
Expression ExpressionCastNew(e,t)
Expression e;
Type t;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCast *slot = &newExpression->U.CastSlot;
  newExpression->tag = ExpressionCastTag;
  slot->e = e;
  slot->t = t;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionFieldRefNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFieldRefNew(Expression e,Token field)
#else
Expression ExpressionFieldRefNew(e,field)
Expression e;
Token field;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionFieldRef *slot = &newExpression->U.FieldRefSlot;
  newExpression->tag = ExpressionFieldRefTag;
  slot->e = e;
  slot->field = field;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionRepeatNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRepeatNew(Expression e)
#else
Expression ExpressionRepeatNew(e)
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRepeat *slot = &newExpression->U.RepeatSlot;
  newExpression->tag = ExpressionRepeatTag;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionWhileNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionWhileNew(Expression e,Expression body)
#else
Expression ExpressionWhileNew(e,body)
Expression e;
Expression body;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionWhile *slot = &newExpression->U.WhileSlot;
  newExpression->tag = ExpressionWhileTag;
  slot->e = e;
  slot->body = body;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionUntilNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUntilNew(Expression e,Expression body)
#else
Expression ExpressionUntilNew(e,body)
Expression e;
Expression body;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionUntil *slot = &newExpression->U.UntilSlot;
  newExpression->tag = ExpressionUntilTag;
  slot->e = e;
  slot->body = body;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionEveryNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionEveryNew(Expression e,Expression body)
#else
Expression ExpressionEveryNew(e,body)
Expression e;
Expression body;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionEvery *slot = &newExpression->U.EverySlot;
  newExpression->tag = ExpressionEveryTag;
  slot->e = e;
  slot->body = body;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionIfNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionIfNew(Expression cond,Expression e_true,Expression e_false)
#else
Expression ExpressionIfNew(cond,e_true,e_false)
Expression cond;
Expression e_true;
Expression e_false;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionIf *slot = &newExpression->U.IfSlot;
  newExpression->tag = ExpressionIfTag;
  slot->cond = cond;
  slot->e_true = e_true;
  slot->e_false = e_false;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionCaseNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCaseNew(Expression cond,Queue cases)
#else
Expression ExpressionCaseNew(cond,cases)
Expression cond;
Queue cases;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCase *slot = &newExpression->U.CaseSlot;
  newExpression->tag = ExpressionCaseTag;
  slot->cond = cond;
  slot->cases = cases;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionNextNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionNextNew(void)
#else
Expression ExpressionNextNew()
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  newExpression->tag = ExpressionNextTag;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionBreakNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBreakNew(Expression e)
#else
Expression ExpressionBreakNew(e)
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionBreak *slot = &newExpression->U.BreakSlot;
  newExpression->tag = ExpressionBreakTag;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionReturnNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionReturnNew(Expression e)
#else
Expression ExpressionReturnNew(e)
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionReturn *slot = &newExpression->U.ReturnSlot;
  newExpression->tag = ExpressionReturnTag;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionSuspendNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSuspendNew(Expression e)
#else
Expression ExpressionSuspendNew(e)
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSuspend *slot = &newExpression->U.SuspendSlot;
  newExpression->tag = ExpressionSuspendTag;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionFailNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFailNew(void)
#else
Expression ExpressionFailNew()
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  newExpression->tag = ExpressionFailTag;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionCreateNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCreateNew(Expression e)
#else
Expression ExpressionCreateNew(e)
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionCreate *slot = &newExpression->U.CreateSlot;
  newExpression->tag = ExpressionCreateTag;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionListConsNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionListConsNew(Queue elements)
#else
Expression ExpressionListConsNew(elements)
Queue elements;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionListCons *slot = &newExpression->U.ListConsSlot;
  newExpression->tag = ExpressionListConsTag;
  slot->elements = elements;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionRangeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRangeNew(RangeType rt,Expression low,Expression high)
#else
Expression ExpressionRangeNew(rt,low,high)
RangeType rt;
Expression low;
Expression high;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionRange *slot = &newExpression->U.RangeSlot;
  newExpression->tag = ExpressionRangeTag;
  slot->rt = rt;
  slot->low = low;
  slot->high = high;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionSequenceNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSequenceNew(Queue elements)
#else
Expression ExpressionSequenceNew(elements)
Queue elements;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionSequence *slot = &newExpression->U.SequenceSlot;
  newExpression->tag = ExpressionSequenceTag;
  slot->elements = elements;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionConstIntNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstIntNew(signed long int value)
#else
Expression ExpressionConstIntNew(value)
signed long int value;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstInt *slot = &newExpression->U.ConstIntSlot;
  newExpression->tag = ExpressionConstIntTag;
  slot->value = value;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionConstRealNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstRealNew(double value)
#else
Expression ExpressionConstRealNew(value)
double value;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstReal *slot = &newExpression->U.ConstRealSlot;
  newExpression->tag = ExpressionConstRealTag;
  slot->value = value;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionConstCsetNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstCsetNew(char *value)
#else
Expression ExpressionConstCsetNew(value)
char *value;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstCset *slot = &newExpression->U.ConstCsetSlot;
  newExpression->tag = ExpressionConstCsetTag;
  slot->value = value;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionConstStringNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstStringNew(char *value)
#else
Expression ExpressionConstStringNew(value)
char *value;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConstString *slot = &newExpression->U.ConstStringSlot;
  newExpression->tag = ExpressionConstStringTag;
  slot->value = value;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionVarNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionVarNew(Token id)
#else
Expression ExpressionVarNew(id)
Token id;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionVar *slot = &newExpression->U.VarSlot;
  newExpression->tag = ExpressionVarTag;
  slot->id = id;
  slot->location = (int)0;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionConvertNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConvertNew(Type srcType,Type dstType,Expression e)
#else
Expression ExpressionConvertNew(srcType,dstType,e)
Type srcType;
Type dstType;
Expression e;
#endif
{
  Expression newExpression = (Expression)Allocate(sizeof(_Expression));
  struct _ExpressionConvert *slot = &newExpression->U.ConvertSlot;
  newExpression->tag = ExpressionConvertTag;
  slot->srcType = srcType;
  slot->dstType = dstType;
  slot->e = e;
  newExpression->side = (Sides)0;
  newExpression->type = (Type)0;
  return (newExpression);
}

/*
**
** ExpressionUnaryUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUnaryUpdate(Expression oldExpression,UnaryOp op,Expression e)
#else
Expression ExpressionUnaryUpdate(oldExpression,op,e)
Expression oldExpression;
UnaryOp op;
Expression e;
#endif
{
  struct _ExpressionUnary *slot = &oldExpression->U.UnarySlot;
  oldExpression->tag = ExpressionUnaryTag;
  slot->op = op;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionBinaryUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBinaryUpdate(Expression oldExpression,BinOp op,Expression e1,Expression e2)
#else
Expression ExpressionBinaryUpdate(oldExpression,op,e1,e2)
Expression oldExpression;
BinOp op;
Expression e1;
Expression e2;
#endif
{
  struct _ExpressionBinary *slot = &oldExpression->U.BinarySlot;
  oldExpression->tag = ExpressionBinaryTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  return (oldExpression);
}

/*
**
** ExpressionTernaryUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionTernaryUpdate(Expression oldExpression,TernaryOp op,Expression e1,Expression e2,Expression e3)
#else
Expression ExpressionTernaryUpdate(oldExpression,op,e1,e2,e3)
Expression oldExpression;
TernaryOp op;
Expression e1;
Expression e2;
Expression e3;
#endif
{
  struct _ExpressionTernary *slot = &oldExpression->U.TernarySlot;
  oldExpression->tag = ExpressionTernaryTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  slot->e3 = e3;
  return (oldExpression);
}

/*
**
** ExpressionRelOpUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRelOpUpdate(Expression oldExpression,RelOp op,Expression e1,Expression e2)
#else
Expression ExpressionRelOpUpdate(oldExpression,op,e1,e2)
Expression oldExpression;
RelOp op;
Expression e1;
Expression e2;
#endif
{
  struct _ExpressionRelOp *slot = &oldExpression->U.RelOpSlot;
  oldExpression->tag = ExpressionRelOpTag;
  slot->op = op;
  slot->e1 = e1;
  slot->e2 = e2;
  return (oldExpression);
}

/*
**
** ExpressionProcCallUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionProcCallUpdate(Expression oldExpression,Expression proc,Queue params)
#else
Expression ExpressionProcCallUpdate(oldExpression,proc,params)
Expression oldExpression;
Expression proc;
Queue params;
#endif
{
  struct _ExpressionProcCall *slot = &oldExpression->U.ProcCallSlot;
  oldExpression->tag = ExpressionProcCallTag;
  slot->proc = proc;
  slot->params = params;
  return (oldExpression);
}

/*
**
** ExpressionSubscriptUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSubscriptUpdate(Expression oldExpression,Expression array,Expression subscript)
#else
Expression ExpressionSubscriptUpdate(oldExpression,array,subscript)
Expression oldExpression;
Expression array;
Expression subscript;
#endif
{
  struct _ExpressionSubscript *slot = &oldExpression->U.SubscriptSlot;
  oldExpression->tag = ExpressionSubscriptTag;
  slot->array = array;
  slot->subscript = subscript;
  return (oldExpression);
}

/*
**
** ExpressionCastUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCastUpdate(Expression oldExpression,Expression e,Type t)
#else
Expression ExpressionCastUpdate(oldExpression,e,t)
Expression oldExpression;
Expression e;
Type t;
#endif
{
  struct _ExpressionCast *slot = &oldExpression->U.CastSlot;
  oldExpression->tag = ExpressionCastTag;
  slot->e = e;
  slot->t = t;
  return (oldExpression);
}

/*
**
** ExpressionFieldRefUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFieldRefUpdate(Expression oldExpression,Expression e,Token field)
#else
Expression ExpressionFieldRefUpdate(oldExpression,e,field)
Expression oldExpression;
Expression e;
Token field;
#endif
{
  struct _ExpressionFieldRef *slot = &oldExpression->U.FieldRefSlot;
  oldExpression->tag = ExpressionFieldRefTag;
  slot->e = e;
  slot->field = field;
  return (oldExpression);
}

/*
**
** ExpressionRepeatUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRepeatUpdate(Expression oldExpression,Expression e)
#else
Expression ExpressionRepeatUpdate(oldExpression,e)
Expression oldExpression;
Expression e;
#endif
{
  struct _ExpressionRepeat *slot = &oldExpression->U.RepeatSlot;
  oldExpression->tag = ExpressionRepeatTag;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionWhileUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionWhileUpdate(Expression oldExpression,Expression e,Expression body)
#else
Expression ExpressionWhileUpdate(oldExpression,e,body)
Expression oldExpression;
Expression e;
Expression body;
#endif
{
  struct _ExpressionWhile *slot = &oldExpression->U.WhileSlot;
  oldExpression->tag = ExpressionWhileTag;
  slot->e = e;
  slot->body = body;
  return (oldExpression);
}

/*
**
** ExpressionUntilUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionUntilUpdate(Expression oldExpression,Expression e,Expression body)
#else
Expression ExpressionUntilUpdate(oldExpression,e,body)
Expression oldExpression;
Expression e;
Expression body;
#endif
{
  struct _ExpressionUntil *slot = &oldExpression->U.UntilSlot;
  oldExpression->tag = ExpressionUntilTag;
  slot->e = e;
  slot->body = body;
  return (oldExpression);
}

/*
**
** ExpressionEveryUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionEveryUpdate(Expression oldExpression,Expression e,Expression body)
#else
Expression ExpressionEveryUpdate(oldExpression,e,body)
Expression oldExpression;
Expression e;
Expression body;
#endif
{
  struct _ExpressionEvery *slot = &oldExpression->U.EverySlot;
  oldExpression->tag = ExpressionEveryTag;
  slot->e = e;
  slot->body = body;
  return (oldExpression);
}

/*
**
** ExpressionIfUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionIfUpdate(Expression oldExpression,Expression cond,Expression e_true,Expression e_false)
#else
Expression ExpressionIfUpdate(oldExpression,cond,e_true,e_false)
Expression oldExpression;
Expression cond;
Expression e_true;
Expression e_false;
#endif
{
  struct _ExpressionIf *slot = &oldExpression->U.IfSlot;
  oldExpression->tag = ExpressionIfTag;
  slot->cond = cond;
  slot->e_true = e_true;
  slot->e_false = e_false;
  return (oldExpression);
}

/*
**
** ExpressionCaseUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCaseUpdate(Expression oldExpression,Expression cond,Queue cases)
#else
Expression ExpressionCaseUpdate(oldExpression,cond,cases)
Expression oldExpression;
Expression cond;
Queue cases;
#endif
{
  struct _ExpressionCase *slot = &oldExpression->U.CaseSlot;
  oldExpression->tag = ExpressionCaseTag;
  slot->cond = cond;
  slot->cases = cases;
  return (oldExpression);
}

/*
**
** ExpressionNextUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionNextUpdate(Expression oldExpression)
#else
Expression ExpressionNextUpdate(oldExpression)
Expression oldExpression;
#endif
{
  oldExpression->tag = ExpressionNextTag;
  return (oldExpression);
}

/*
**
** ExpressionBreakUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionBreakUpdate(Expression oldExpression,Expression e)
#else
Expression ExpressionBreakUpdate(oldExpression,e)
Expression oldExpression;
Expression e;
#endif
{
  struct _ExpressionBreak *slot = &oldExpression->U.BreakSlot;
  oldExpression->tag = ExpressionBreakTag;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionReturnUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionReturnUpdate(Expression oldExpression,Expression e)
#else
Expression ExpressionReturnUpdate(oldExpression,e)
Expression oldExpression;
Expression e;
#endif
{
  struct _ExpressionReturn *slot = &oldExpression->U.ReturnSlot;
  oldExpression->tag = ExpressionReturnTag;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionSuspendUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSuspendUpdate(Expression oldExpression,Expression e)
#else
Expression ExpressionSuspendUpdate(oldExpression,e)
Expression oldExpression;
Expression e;
#endif
{
  struct _ExpressionSuspend *slot = &oldExpression->U.SuspendSlot;
  oldExpression->tag = ExpressionSuspendTag;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionFailUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionFailUpdate(Expression oldExpression)
#else
Expression ExpressionFailUpdate(oldExpression)
Expression oldExpression;
#endif
{
  oldExpression->tag = ExpressionFailTag;
  return (oldExpression);
}

/*
**
** ExpressionCreateUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionCreateUpdate(Expression oldExpression,Expression e)
#else
Expression ExpressionCreateUpdate(oldExpression,e)
Expression oldExpression;
Expression e;
#endif
{
  struct _ExpressionCreate *slot = &oldExpression->U.CreateSlot;
  oldExpression->tag = ExpressionCreateTag;
  slot->e = e;
  return (oldExpression);
}

/*
**
** ExpressionListConsUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionListConsUpdate(Expression oldExpression,Queue elements)
#else
Expression ExpressionListConsUpdate(oldExpression,elements)
Expression oldExpression;
Queue elements;
#endif
{
  struct _ExpressionListCons *slot = &oldExpression->U.ListConsSlot;
  oldExpression->tag = ExpressionListConsTag;
  slot->elements = elements;
  return (oldExpression);
}

/*
**
** ExpressionRangeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionRangeUpdate(Expression oldExpression,RangeType rt,Expression low,Expression high)
#else
Expression ExpressionRangeUpdate(oldExpression,rt,low,high)
Expression oldExpression;
RangeType rt;
Expression low;
Expression high;
#endif
{
  struct _ExpressionRange *slot = &oldExpression->U.RangeSlot;
  oldExpression->tag = ExpressionRangeTag;
  slot->rt = rt;
  slot->low = low;
  slot->high = high;
  return (oldExpression);
}

/*
**
** ExpressionSequenceUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionSequenceUpdate(Expression oldExpression,Queue elements)
#else
Expression ExpressionSequenceUpdate(oldExpression,elements)
Expression oldExpression;
Queue elements;
#endif
{
  struct _ExpressionSequence *slot = &oldExpression->U.SequenceSlot;
  oldExpression->tag = ExpressionSequenceTag;
  slot->elements = elements;
  return (oldExpression);
}

/*
**
** ExpressionConstIntUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstIntUpdate(Expression oldExpression,signed long int value)
#else
Expression ExpressionConstIntUpdate(oldExpression,value)
Expression oldExpression;
signed long int value;
#endif
{
  struct _ExpressionConstInt *slot = &oldExpression->U.ConstIntSlot;
  oldExpression->tag = ExpressionConstIntTag;
  slot->value = value;
  return (oldExpression);
}

/*
**
** ExpressionConstRealUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstRealUpdate(Expression oldExpression,double value)
#else
Expression ExpressionConstRealUpdate(oldExpression,value)
Expression oldExpression;
double value;
#endif
{
  struct _ExpressionConstReal *slot = &oldExpression->U.ConstRealSlot;
  oldExpression->tag = ExpressionConstRealTag;
  slot->value = value;
  return (oldExpression);
}

/*
**
** ExpressionConstCsetUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstCsetUpdate(Expression oldExpression,char *value)
#else
Expression ExpressionConstCsetUpdate(oldExpression,value)
Expression oldExpression;
char *value;
#endif
{
  struct _ExpressionConstCset *slot = &oldExpression->U.ConstCsetSlot;
  oldExpression->tag = ExpressionConstCsetTag;
  slot->value = value;
  return (oldExpression);
}

/*
**
** ExpressionConstStringUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConstStringUpdate(Expression oldExpression,char *value)
#else
Expression ExpressionConstStringUpdate(oldExpression,value)
Expression oldExpression;
char *value;
#endif
{
  struct _ExpressionConstString *slot = &oldExpression->U.ConstStringSlot;
  oldExpression->tag = ExpressionConstStringTag;
  slot->value = value;
  return (oldExpression);
}

/*
**
** ExpressionVarUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionVarUpdate(Expression oldExpression,Token id)
#else
Expression ExpressionVarUpdate(oldExpression,id)
Expression oldExpression;
Token id;
#endif
{
  struct _ExpressionVar *slot = &oldExpression->U.VarSlot;
  oldExpression->tag = ExpressionVarTag;
  slot->id = id;
  return (oldExpression);
}

/*
**
** ExpressionConvertUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Expression ExpressionConvertUpdate(Expression oldExpression,Type srcType,Type dstType,Expression e)
#else
Expression ExpressionConvertUpdate(oldExpression,srcType,dstType,e)
Expression oldExpression;
Type srcType;
Type dstType;
Expression e;
#endif
{
  struct _ExpressionConvert *slot = &oldExpression->U.ConvertSlot;
  oldExpression->tag = ExpressionConvertTag;
  slot->srcType = srcType;
  slot->dstType = dstType;
  slot->e = e;
  return (oldExpression);
}

/*
**
** MiscParameterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscParameterDuplicate(Misc oldMisc)
#else
Misc MiscParameterDuplicate(oldMisc)
Misc oldMisc;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscParameter *slot = &newMisc->U.ParameterSlot;
  struct _MiscParameter *oldslot = &oldMisc->U.ParameterSlot;
  newMisc->tag = MiscParameterTag;
  slot->refFlag = oldslot->refFlag;
  slot->name = oldslot->name;
  slot->type = oldslot->type;
  return (newMisc);
}

/*
**
** MiscProcHeadDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscProcHeadDuplicate(Misc oldMisc)
#else
Misc MiscProcHeadDuplicate(oldMisc)
Misc oldMisc;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscProcHead *slot = &newMisc->U.ProcHeadSlot;
  struct _MiscProcHead *oldslot = &oldMisc->U.ProcHeadSlot;
  newMisc->tag = MiscProcHeadTag;
  slot->name = oldslot->name;
  slot->parameters = oldslot->parameters;
  slot->refFlag = oldslot->refFlag;
  slot->retType = oldslot->retType;
  return (newMisc);
}

/*
**
** MiscTypePairDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscTypePairDuplicate(Misc oldMisc)
#else
Misc MiscTypePairDuplicate(oldMisc)
Misc oldMisc;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscTypePair *slot = &newMisc->U.TypePairSlot;
  struct _MiscTypePair *oldslot = &oldMisc->U.TypePairSlot;
  newMisc->tag = MiscTypePairTag;
  slot->t1 = oldslot->t1;
  slot->t2 = oldslot->t2;
  return (newMisc);
}

/*
**
** MiscParameterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscParameterNew(int refFlag,Token name,Type type)
#else
Misc MiscParameterNew(refFlag,name,type)
int refFlag;
Token name;
Type type;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscParameter *slot = &newMisc->U.ParameterSlot;
  newMisc->tag = MiscParameterTag;
  slot->refFlag = refFlag;
  slot->name = name;
  slot->type = type;
  return (newMisc);
}

/*
**
** MiscProcHeadNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscProcHeadNew(Token name,Queue parameters,int refFlag,Type retType)
#else
Misc MiscProcHeadNew(name,parameters,refFlag,retType)
Token name;
Queue parameters;
int refFlag;
Type retType;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscProcHead *slot = &newMisc->U.ProcHeadSlot;
  newMisc->tag = MiscProcHeadTag;
  slot->name = name;
  slot->parameters = parameters;
  slot->refFlag = refFlag;
  slot->retType = retType;
  return (newMisc);
}

/*
**
** MiscTypePairNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscTypePairNew(Type t1,Type t2)
#else
Misc MiscTypePairNew(t1,t2)
Type t1;
Type t2;
#endif
{
  Misc newMisc = (Misc)Allocate(sizeof(_Misc));
  struct _MiscTypePair *slot = &newMisc->U.TypePairSlot;
  newMisc->tag = MiscTypePairTag;
  slot->t1 = t1;
  slot->t2 = t2;
  return (newMisc);
}

/*
**
** MiscParameterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscParameterUpdate(Misc oldMisc,int refFlag,Token name,Type type)
#else
Misc MiscParameterUpdate(oldMisc,refFlag,name,type)
Misc oldMisc;
int refFlag;
Token name;
Type type;
#endif
{
  struct _MiscParameter *slot = &oldMisc->U.ParameterSlot;
  oldMisc->tag = MiscParameterTag;
  slot->refFlag = refFlag;
  slot->name = name;
  slot->type = type;
  return (oldMisc);
}

/*
**
** MiscProcHeadUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscProcHeadUpdate(Misc oldMisc,Token name,Queue parameters,int refFlag,Type retType)
#else
Misc MiscProcHeadUpdate(oldMisc,name,parameters,refFlag,retType)
Misc oldMisc;
Token name;
Queue parameters;
int refFlag;
Type retType;
#endif
{
  struct _MiscProcHead *slot = &oldMisc->U.ProcHeadSlot;
  oldMisc->tag = MiscProcHeadTag;
  slot->name = name;
  slot->parameters = parameters;
  slot->refFlag = refFlag;
  slot->retType = retType;
  return (oldMisc);
}

/*
**
** MiscTypePairUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Misc MiscTypePairUpdate(Misc oldMisc,Type t1,Type t2)
#else
Misc MiscTypePairUpdate(oldMisc,t1,t2)
Misc oldMisc;
Type t1;
Type t2;
#endif
{
  struct _MiscTypePair *slot = &oldMisc->U.TypePairSlot;
  oldMisc->tag = MiscTypePairTag;
  slot->t1 = t1;
  slot->t2 = t2;
  return (oldMisc);
}

/*
**
** SymNodeTypeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeTypeDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeTypeDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeType *slot = &newSymNode->U.TypeSlot;
  struct _SymNodeType *oldslot = &oldSymNode->U.TypeSlot;
  newSymNode->tag = SymNodeTypeTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeGlobalDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeGlobalDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeGlobalDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeGlobal *slot = &newSymNode->U.GlobalSlot;
  struct _SymNodeGlobal *oldslot = &oldSymNode->U.GlobalSlot;
  newSymNode->tag = SymNodeGlobalTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeExternalDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeExternalDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeExternalDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeExternal *slot = &newSymNode->U.ExternalSlot;
  struct _SymNodeExternal *oldslot = &oldSymNode->U.ExternalSlot;
  newSymNode->tag = SymNodeExternalTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeLocalStaticDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalStaticDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeLocalStaticDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalStatic *slot = &newSymNode->U.LocalStaticSlot;
  struct _SymNodeLocalStatic *oldslot = &oldSymNode->U.LocalStaticSlot;
  newSymNode->tag = SymNodeLocalStaticTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeLocalAutoDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalAutoDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeLocalAutoDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalAuto *slot = &newSymNode->U.LocalAutoSlot;
  struct _SymNodeLocalAuto *oldslot = &oldSymNode->U.LocalAutoSlot;
  newSymNode->tag = SymNodeLocalAutoTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeLocalDynamicDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalDynamicDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeLocalDynamicDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalDynamic *slot = &newSymNode->U.LocalDynamicSlot;
  struct _SymNodeLocalDynamic *oldslot = &oldSymNode->U.LocalDynamicSlot;
  newSymNode->tag = SymNodeLocalDynamicTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeParameterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeParameterDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeParameterDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeParameter *slot = &newSymNode->U.ParameterSlot;
  struct _SymNodeParameter *oldslot = &oldSymNode->U.ParameterSlot;
  newSymNode->tag = SymNodeParameterTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->type = oldslot->type;
  return (newSymNode);
}

/*
**
** SymNodeProcedureDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeProcedureDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeProcedureDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeProcedure *slot = &newSymNode->U.ProcedureSlot;
  struct _SymNodeProcedure *oldslot = &oldSymNode->U.ProcedureSlot;
  newSymNode->tag = SymNodeProcedureTag;
  slot->line = oldslot->line;
  slot->column = oldslot->column;
  slot->parameters = oldslot->parameters;
  slot->retType = oldslot->retType;
  return (newSymNode);
}

/*
**
** SymNodeUndefinedDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeUndefinedDuplicate(SymNode oldSymNode)
#else
SymNode SymNodeUndefinedDuplicate(oldSymNode)
SymNode oldSymNode;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  newSymNode->tag = SymNodeUndefinedTag;
  return (newSymNode);
}

/*
**
** SymNodeTypeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeTypeNew(int line,int column,Type type)
#else
SymNode SymNodeTypeNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeType *slot = &newSymNode->U.TypeSlot;
  newSymNode->tag = SymNodeTypeTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeGlobalNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeGlobalNew(int line,int column,Type type)
#else
SymNode SymNodeGlobalNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeGlobal *slot = &newSymNode->U.GlobalSlot;
  newSymNode->tag = SymNodeGlobalTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeExternalNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeExternalNew(int line,int column,Type type)
#else
SymNode SymNodeExternalNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeExternal *slot = &newSymNode->U.ExternalSlot;
  newSymNode->tag = SymNodeExternalTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeLocalStaticNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalStaticNew(int line,int column,Type type)
#else
SymNode SymNodeLocalStaticNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalStatic *slot = &newSymNode->U.LocalStaticSlot;
  newSymNode->tag = SymNodeLocalStaticTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeLocalAutoNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalAutoNew(int line,int column,Type type)
#else
SymNode SymNodeLocalAutoNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalAuto *slot = &newSymNode->U.LocalAutoSlot;
  newSymNode->tag = SymNodeLocalAutoTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeLocalDynamicNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalDynamicNew(int line,int column,Type type)
#else
SymNode SymNodeLocalDynamicNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeLocalDynamic *slot = &newSymNode->U.LocalDynamicSlot;
  newSymNode->tag = SymNodeLocalDynamicTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeParameterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeParameterNew(int line,int column,Type type)
#else
SymNode SymNodeParameterNew(line,column,type)
int line;
int column;
Type type;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeParameter *slot = &newSymNode->U.ParameterSlot;
  newSymNode->tag = SymNodeParameterTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (newSymNode);
}

/*
**
** SymNodeProcedureNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeProcedureNew(int line,int column,Queue parameters,Type retType)
#else
SymNode SymNodeProcedureNew(line,column,parameters,retType)
int line;
int column;
Queue parameters;
Type retType;
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  struct _SymNodeProcedure *slot = &newSymNode->U.ProcedureSlot;
  newSymNode->tag = SymNodeProcedureTag;
  slot->line = line;
  slot->column = column;
  slot->parameters = parameters;
  slot->retType = retType;
  return (newSymNode);
}

/*
**
** SymNodeUndefinedNew
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeUndefinedNew(void)
#else
SymNode SymNodeUndefinedNew()
#endif
{
  SymNode newSymNode = (SymNode)Allocate(sizeof(_SymNode));
  newSymNode->tag = SymNodeUndefinedTag;
  return (newSymNode);
}

/*
**
** SymNodeTypeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeTypeUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeTypeUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeType *slot = &oldSymNode->U.TypeSlot;
  oldSymNode->tag = SymNodeTypeTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeGlobalUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeGlobalUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeGlobalUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeGlobal *slot = &oldSymNode->U.GlobalSlot;
  oldSymNode->tag = SymNodeGlobalTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeExternalUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeExternalUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeExternalUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeExternal *slot = &oldSymNode->U.ExternalSlot;
  oldSymNode->tag = SymNodeExternalTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeLocalStaticUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalStaticUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeLocalStaticUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeLocalStatic *slot = &oldSymNode->U.LocalStaticSlot;
  oldSymNode->tag = SymNodeLocalStaticTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeLocalAutoUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalAutoUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeLocalAutoUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeLocalAuto *slot = &oldSymNode->U.LocalAutoSlot;
  oldSymNode->tag = SymNodeLocalAutoTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeLocalDynamicUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeLocalDynamicUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeLocalDynamicUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeLocalDynamic *slot = &oldSymNode->U.LocalDynamicSlot;
  oldSymNode->tag = SymNodeLocalDynamicTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeParameterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeParameterUpdate(SymNode oldSymNode,int line,int column,Type type)
#else
SymNode SymNodeParameterUpdate(oldSymNode,line,column,type)
SymNode oldSymNode;
int line;
int column;
Type type;
#endif
{
  struct _SymNodeParameter *slot = &oldSymNode->U.ParameterSlot;
  oldSymNode->tag = SymNodeParameterTag;
  slot->line = line;
  slot->column = column;
  slot->type = type;
  return (oldSymNode);
}

/*
**
** SymNodeProcedureUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeProcedureUpdate(SymNode oldSymNode,int line,int column,Queue parameters,Type retType)
#else
SymNode SymNodeProcedureUpdate(oldSymNode,line,column,parameters,retType)
SymNode oldSymNode;
int line;
int column;
Queue parameters;
Type retType;
#endif
{
  struct _SymNodeProcedure *slot = &oldSymNode->U.ProcedureSlot;
  oldSymNode->tag = SymNodeProcedureTag;
  slot->line = line;
  slot->column = column;
  slot->parameters = parameters;
  slot->retType = retType;
  return (oldSymNode);
}

/*
**
** SymNodeUndefinedUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
SymNode SymNodeUndefinedUpdate(SymNode oldSymNode)
#else
SymNode SymNodeUndefinedUpdate(oldSymNode)
SymNode oldSymNode;
#endif
{
  oldSymNode->tag = SymNodeUndefinedTag;
  return (oldSymNode);
}

