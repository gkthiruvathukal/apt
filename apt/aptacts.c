/******************************************************************
**
** APTACTS.C:
**
**    APT Semantic Actions Module
**
** This file is part of Apt Parsing Tool (APT) for LL(1) Parsing
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

/* ---------- Headers */

#include "apt.h"

#include "aptacts.h"
#include "aptmain.h"
#include "aptlib.h"
#include "astlib.h"

#include "allocate.h"
#include "avltree.h"
#include "sstring.h"

/* ---------- Exported Globals */

int ActionCount = 0;
ActionNode *ActionList = NULL;
ActionNode *ActionListPtr = NULL;
AVLTree ActionTree = NULL;

int AliasCount = 0;
AliasNode *AliasList = NULL;
AliasNode *AliasListPtr = NULL;

AVLTree EOPTree = NULL;

int FiducialCount = 0;
FiducialNode *FiducialList = NULL;
FiducialNode *FiducialListPtr = NULL;

int ParamCount = 0;
ParamNode *ParamList = NULL;
ParamNode *ParamListPtr = NULL;

int PhaseCount = 0;
PhaseNode *PhaseList = NULL;
PhaseNode *PhaseListPtr = NULL;

int PhaseIdCount = 0;
PhaseNode *PhaseIdList = NULL;
PhaseNode *PhaseIdListPtr = NULL;

int ProductionCount = 0;
ProductionNode *ProductionList = NULL;
ProductionNode *ProductionListPtr = NULL;

int RHSCount = 0;
RHSNode *RHSList = NULL;
RHSNode *RHSListPtr = NULL;

int SymbolCount = 0;
SymbolNode *SymbolList = NULL;
SymbolNode *SymbolListPtr = NULL;

int TypeCount = 0;
TypeNode *TypeList = NULL;
TypeNode *TypeListPtr = NULL;

/* ---------- Functions */

int CompareOnFunction(itemA,itemB)
void *itemA;
void *itemB;
{
  ActionNode *nodeA,*nodeB;

  nodeA = (ActionNode*)itemA;
  nodeB = (ActionNode*)itemB;
  return (StringCompare(nodeA->function,nodeB->function));
}

int CompareOnSymbol(itemA,itemB)
void *itemA;
void *itemB;
{
  ActionNode *nodeA,*nodeB;

  nodeA = (ActionNode*)itemA;
  nodeB = (ActionNode*)itemB;
  return (StringCompare(nodeA->symbol->text,nodeB->symbol->text));
}

void disposeActionNode(actionNode)
ActionNode *actionNode;
{
  free(actionNode->function);
  free(actionNode->type);
  free(actionNode);
}

void disposeAliasNode(aliasNode)
AliasNode *aliasNode;
{
  free(aliasNode->alias);
  free(aliasNode);
}

void disposeFiducialNode(fiducialNode)
FiducialNode *fiducialNode;
{
  free(fiducialNode);
}

void disposeParamNode(paramNode)
ParamNode *paramNode;
{
  free(paramNode);
}

void disposePhaseNode(phaseNode)
PhaseNode *phaseNode;
{
  free(phaseNode->text);
  free(phaseNode);
}

void disposeProductionList()
{
  ProductionNode *s,*t = ProductionList->next;
  for (s=ProductionList; s != NULL; s=t) {
    t = s->next;
    disposeProductionNode(s);
  }
}

void disposeProductionNode(productionNode)
ProductionNode *productionNode;
{
  disposeRHS(productionNode->rhs);
  free(productionNode);
}

void disposeRHS(rhs)
RHSNode *rhs;
{
  RHSNode *p,*q = NULL;

  for (p=rhs; p != NULL; p=q) {
    q = p->next;
    disposeRHSNode(p);
  }
}

void disposeRHSNode(rhsNode)
RHSNode *rhsNode;
{
  disposeSymbolNode(rhsNode->symbol);
  free(rhsNode);
}

void disposeSymbolList()
{
  SymbolNode *s,*t = SymbolList->next;
  for (s=SymbolList; s != NULL; s=t) {
    t = s->next;
    disposeSymbolNode(s);
  }
}

void disposeSymbolNode(symbolNode)
SymbolNode *symbolNode;
{
  free(symbolNode->text);
  free(symbolNode);
}

void disposeTypeNode(typeNode)
TypeNode *typeNode;
{
  free(typeNode->text);
  free(typeNode);
}

void disposeTypeList()
{
  TypeNode *s,*t = TypeList->next;
  for (s=TypeList; s != NULL; s=t) {
    t = s->next;
    disposeTypeNode(s);
  }
}

PhaseNode *findPhaseNode(PhaseList,text)
PhaseNode *PhaseList;
char *text;
{
  PhaseNode *phaseNode;

  for (phaseNode=PhaseList; phaseNode != NULL; phaseNode = phaseNode->next)
    if (StringCompare(phaseNode->text,text) == 0) return phaseNode;
  return NULL;
}

ActionNode *newActionNode(symbol,function,paramNumber,params,type,
                           popNumber,phases)
SymbolNode *symbol;
char *function;
int paramNumber;
ParamNode *params;
char *type;
int popNumber;
PhaseNode *phases;
{
  ActionNode *actionNode;

  actionNode = (ActionNode *) Allocate(sizeof(ActionNode));
  if (actionNode == NULL) Error(1,2,"newActionNode","");
  actionNode->symbol = symbol;
  actionNode->function = (char *) Allocate(sizeof(char)*(strlen(function)+1));
  if (actionNode->function == NULL)
    Error(1,2,"newActionNode","");
  StringCopy(actionNode->function,function);
  actionNode->paramNumber = paramNumber;
  actionNode->params = params;
  actionNode->type = (char *) Allocate(sizeof(char)*(strlen(type)+1));
  if (actionNode->type == NULL) Error(1,2,"newActionNode","");
  StringCopy(actionNode->type,type);
  actionNode->popNumber = popNumber;
  actionNode->phases = phases;
  actionNode->next = NULL;
  return (actionNode);
}

AliasNode *newAliasNode(symbol,alias)
SymbolNode *symbol;
char *alias;
{
  AliasNode *aliasNode;

  aliasNode = (AliasNode *) Allocate(sizeof(AliasNode));
  if (aliasNode == NULL) Error(1,2,"newAliasNode","");
  aliasNode->symbol = symbol;
  aliasNode->alias = (char *) Allocate(sizeof(char)*(strlen(alias)+1));
  if (aliasNode->alias == NULL) Error(1,2,"newAliasNode","");
  StringCopy(aliasNode->alias,alias);
  aliasNode->next = NULL;
  return (aliasNode);
}

FiducialNode *newFiducialNode(symbol)
SymbolNode *symbol;
{
  FiducialNode *fiducialNode;

  fiducialNode = (FiducialNode *) Allocate(sizeof(FiducialNode));
  if (fiducialNode == NULL) Error(1,2,"newFiducialNode","");
  fiducialNode->symbol = symbol;
  fiducialNode->next = NULL;
  return (fiducialNode);
}

ParamNode *newParamNode(offset,type)
int offset;
char *type;
{
  ParamNode *paramNode;

  paramNode = (ParamNode *) Allocate(sizeof(ParamNode));
  if (paramNode == NULL) Error(1,2,"newParamNode","");
  paramNode->offset = offset;
  paramNode->type = (char *) Allocate(sizeof(char) * (strlen(type)+1));
  if (paramNode->type == NULL) Error(1,2,"newParamNode","");
  StringCopy(paramNode->type,type);
  paramNode->next = NULL;
  return (paramNode);
}

PhaseNode *newPhaseNode(text)
char *text;
{
  PhaseNode *phaseNode;

  phaseNode = (PhaseNode *) Allocate(sizeof(PhaseNode));
  phaseNode->text = text;
  phaseNode->next = NULL;
  return (phaseNode);
}

ProductionNode *newProductionNode(symbol,length,rhs)
SymbolNode *symbol;
int length;
RHSNode *rhs;
{
  ProductionNode *productionNode;

  productionNode = (ProductionNode *) Allocate(sizeof(ProductionNode));
  if (productionNode == NULL)
    Error(1,2,"newProductionNode","");
  productionNode->symbol = symbol;
  productionNode->length = length;
  productionNode->rhs = rhs;
  productionNode->next = NULL;
  return (productionNode);
}

RHSNode *newRhsNode(symbol)
SymbolNode *symbol;
{
  RHSNode *rhsNode;

  rhsNode = (RHSNode *) Allocate(sizeof(RHSNode));
  if (rhsNode == NULL) Error(1,2,"newRHSNode","");
  rhsNode->symbol = symbol;
  rhsNode->next = NULL;
  return (rhsNode);
}

SymbolNode *newSymbolNode(text)
char *text;
{
  SymbolNode *symbolNode;

  symbolNode = (SymbolNode *) Allocate(sizeof(SymbolNode));
  if (symbolNode == NULL) Error(1,2,"newSymbolNode","");
  symbolNode->text = (char *) Allocate(sizeof(char) * (strlen(text)+1));
  if (symbolNode->text == NULL) Error(1,2,"newSymbolNode","");
  StringCopy(symbolNode->text,text);
  symbolNode->type = Terminal;
  symbolNode->next = NULL;
  return (symbolNode);
}

TypeNode *newTypeNode(text)
char *text;
{
  TypeNode *typeNode;

  typeNode = (TypeNode *) Allocate(sizeof(TypeNode));
  typeNode->text = text;
  typeNode->next = NULL;
  return (typeNode);
}

Token semBeginActions()
{
  return TokenNew("BeginActions",0,0,0);
}

Token semBeginAliases()
{
  return TokenNew("BeginAliases",0,0,0);
}

Token semBeginFiducials()
{
  return TokenNew("BeginFiducials",0,0,0);
}

Token semBeginPhaseIds()
{
  PhaseIdList = PhaseIdListPtr = NULL;
  PhaseIdCount = 0;
  return TokenNew("BeginPhaseIds",0,0,0);
}

Token semBeginPhases()
{
  return TokenNew("BeginPhases",0,0,0);
}

Token semBeginProductions()
{
  return TokenNew("BeginProductions",0,0,0);
}

Token semBeginSpec()
{
  return TokenNew("BeginSpec",0,0,0);
}

Token semDoAction(actToken,funToken,typToken,popToken)
Token actToken;
Token funToken;
Token typToken;
Token popToken;
{
  SymbolNode *symbol;

  typeListAdd(typToken->text);
  symbol = symbolListAdd(actToken->text,Action);
  if (ActionList == NULL) {
    ActionList = newActionNode(symbol,funToken->text,ParamCount,
        ParamList,typToken->text,atoi(popToken->text),PhaseIdList);
    ActionListPtr = ActionList;
  } else {
    ActionListPtr->next = newActionNode(symbol,funToken->text,ParamCount,
        ParamList,typToken->text,atoi(popToken->text),PhaseIdList);
    ActionListPtr = ActionListPtr->next;
  }
  /* ActionListPtr points to the CURRENT ActionNode */
  if (EOPTree == NULL) EOPTree = AVLTreeNew();
  if (ActionTree == NULL) ActionTree = AVLTreeNew();
  AVLTreeInsert(EOPTree,ActionListPtr,0,CompareOnSymbol);
  AVLTreeInsert(ActionTree,ActionListPtr,0,CompareOnFunction);
  ActionCount++;
  ParamCount = 0; 
  ParamList = NULL;
  return TokenNew("DoAction",0,0,0);
}

Token semDoAlias(idToken,aliasToken)
Token idToken;
Token aliasToken;
{
  SymbolNode *symbol;

  symbol = symbolListAdd(idToken->text,Terminal);
  if (AliasList == NULL) {
    AliasList = newAliasNode(symbol,aliasToken->text);
    AliasListPtr = AliasList;
  } else {
    AliasListPtr->next = newAliasNode(symbol,aliasToken->text);
    AliasListPtr = AliasListPtr->next;
  }
  AliasCount++;
  return TokenNew("Alias",0,0,0);
}

Token semDoFiducial(fidToken)
Token fidToken;
{
  SymbolNode *symbol;

  symbol = symbolListAdd(fidToken->text,Terminal);
  if (FiducialList == NULL) {
    FiducialList = newFiducialNode(symbol);
    FiducialListPtr = FiducialList;
  } else {
    FiducialListPtr->next = newFiducialNode(symbol);
    FiducialListPtr = FiducialListPtr->next;
  }
  FiducialCount++;
  return TokenNew("Fiducial",0,0,0);
}

Token semDoPhase(phaseToken)
Token phaseToken;
{
  if (findPhaseNode(PhaseList,phaseToken->text) == NULL) {
    if (PhaseList == NULL) {
      PhaseList = newPhaseNode(phaseToken->text);
      PhaseListPtr = PhaseList;
    } else {
      PhaseListPtr->next = newPhaseNode(phaseToken->text);
      PhaseListPtr = PhaseListPtr->next;
    }
    PhaseCount++;
  }
  return TokenNew("DoPhase",0,0,0);
}

Token semDoPhaseId(phaseToken)
Token phaseToken;
{
  Token junk;

  junk = semDoPhase(phaseToken);
  if (PhaseIdList == NULL) {
    PhaseIdList = newPhaseNode(phaseToken->text);
    PhaseIdListPtr = PhaseIdList;
  } else {
    PhaseIdListPtr->next = newPhaseNode(phaseToken->text);
    PhaseIdListPtr = PhaseIdListPtr->next;
  }
  PhaseIdCount++;
  return junk;
}

Token semDoProduction(lhsToken)
Token lhsToken;
{
  SymbolNode *symbol;

  symbol = symbolListAdd(lhsToken->text,NonTerminal);
  if (ProductionList == NULL) {
    ProductionList = newProductionNode(symbol,RHSCount,RHSList);
    ProductionListPtr = ProductionList;
  } else {
    ProductionListPtr->next = newProductionNode(symbol,RHSCount,RHSList);
    ProductionListPtr = ProductionListPtr->next;
  }
  ProductionCount++;
  RHSCount = 0; 
  RHSList = NULL;
  return TokenNew("DoProduction",0,0,0);
}

Void semEatEoL()
{
}

Token semEndActions()
{
  return TokenNew("EndActions",0,0,0);
}

Token semEndAliases()
{
  return TokenNew("EndAliases",0,0,0);
}

Token semEndFiducials()
{
  return TokenNew("EndFiducials",0,0,0);
}

Token semEndPhaseIds()
{
  return TokenNew("EndPhaseIds",0,0,0);
}

Token semEndPhases()
{
  return TokenNew("EndPhases",0,0,0);
}

Token semEndProductions()
{
  return TokenNew("EndProductions",0,0,0);
}

Token semEndSpec()
{
  return TokenNew("EndSpec",0,0,0);
}

Token semListEmpty()
{
  return TokenNew("ListEmpty",0,0,0);
}

Token semListGroup()
{
  return TokenNew("ListGroup",0,0,0);
}

Token semParamChar(paramToken)
Token paramToken;
{
  return TokenNew("ParamChar",0,0,0);
}

Token semParamEnum(paramToken)
Token paramToken;
{
  return TokenNew("ParamEnum",0,0,0);
}

Token semParamInt(paramToken)
Token paramToken;
{
  return TokenNew("ParamInt",0,0,0);
}

Token semParamStack(ofsToken,typToken)
Token ofsToken;
Token typToken;
{
  typeListAdd(typToken->text);
  if (ParamList == NULL) {
    ParamList = newParamNode(atoi(ofsToken->text),typToken->text);
    ParamListPtr = ParamList;
  } else {
    ParamListPtr->next = newParamNode(atoi(ofsToken->text),typToken->text);
    ParamListPtr = ParamListPtr->next;
  }
  ParamCount++;
  return TokenNew("ParamStack",0,0,0);
}

Token semParamString(paramToken)
Token paramToken;
{
  return TokenNew("ParamString",0,0,0);
}

Token semRhsIdent(idToken)
Token idToken;
{
  SymbolNode *symbol;

  symbol = symbolListAdd(idToken->text,Terminal);
  if (RHSList == NULL) {
    RHSList = newRhsNode(symbol);
    RHSListPtr = RHSList;
  } else {
    RHSListPtr->next = newRhsNode(symbol);
    RHSListPtr = RHSListPtr->next;
  }
  RHSCount++;
  return TokenNew("RhsIdent",0,0,0);
}

SymbolNode *symbolListAdd(symbol,type)
char *symbol;
int type;
{
  SymbolNode *ptr = SymbolList;

  while (ptr != NULL) {
    if (StringCompare(symbol,ptr->text) == 0) break;
    ptr = ptr->next;
  }
  if (ptr == NULL) {
    if (SymbolList == NULL) {
      SymbolList = newSymbolNode(symbol);
      SymbolListPtr = SymbolList;
    } else {
      SymbolListPtr->next = newSymbolNode(symbol);
      SymbolListPtr = SymbolListPtr->next;
    }
    if (type == NonTerminal || type == Action) SymbolListPtr->type = type;
    SymbolCount++;
    return (SymbolListPtr);
  } else {
    if (type == NonTerminal || type == Action) ptr->type = type;
    return (ptr);
  }
}

void typeListAdd(type)
char *type;
{
  TypeNode *ptr = TypeList;

  while (ptr != NULL) {
    if (StringCompare(type,ptr->text) == 0) break;
    ptr = ptr->next;
  }
  if (ptr == NULL) {
    if (TypeList == NULL) {
      TypeList = newTypeNode(type);
      TypeListPtr = TypeList;
    } else {
      TypeListPtr->next = newTypeNode(type);
      TypeListPtr = TypeListPtr->next;
    }
    TypeCount++;
  }
}
