/******************************************************************
**
** APTACTS.H:
**
**    APT Semantic Actions Module
**
** This file is part of Apt Parsing Tool (APT) for LL(1) Parsing
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTACTS_H
#define APTACTS_H

/* ---------- Headers */

#include "apt.h"
#include "aptlib.h"
#include "astlib.h"
#include "avltree.h"

/* ---------- Types */

typedef struct _ActionNode {
  struct _SymbolNode *symbol;
  char *function;
  int paramNumber;
  struct _ParamNode *params;
  char *type;
  int popNumber;
  struct _PhaseNode *phases;
  struct _ActionNode *next;
} ActionNode;

typedef struct _AliasNode {
  struct _SymbolNode *symbol;
  char *alias;
  struct _AliasNode *next;
} AliasNode;

typedef struct _FiducialNode {
  struct _SymbolNode *symbol;
  struct _FiducialNode *next;
} FiducialNode;

typedef struct _ParamNode {
  int offset;
  char *type;
  struct _ParamNode *next;
} ParamNode;

typedef struct _PhaseNode {
  char *text;
  struct _PhaseNode *next;
} PhaseNode;

typedef struct _ProductionNode {
  struct _SymbolNode *symbol;
  int length;
  struct _RHSNode *rhs;
  struct _ProductionNode *next;
} ProductionNode;

typedef struct _RHSNode {
  struct _SymbolNode *symbol;
  struct _RHSNode *next;
} RHSNode;

typedef struct _SymbolNode {
  char *text;
  enum _SymbolType type;
  struct _SymbolNode *next;
} SymbolNode;

typedef struct _TypeNode {
  char *text;
  struct _TypeNode *next;
} TypeNode;

/* ---------- Exported Globals */

EXTERN int ActionCount;
EXTERN ActionNode *ActionList;
EXTERN AVLTree ActionTree;
EXTERN int AliasCount;
EXTERN AliasNode *AliasList;
EXTERN AVLTree EOPTree;
EXTERN int FiducialCount;
EXTERN FiducialNode *FiducialList;
EXTERN int ParamCount;
EXTERN ParamNode *ParamList;
EXTERN int PhaseCount;
EXTERN PhaseNode *PhaseList;
EXTERN int ProductionCount;
EXTERN ProductionNode *ProductionList;
EXTERN int SymbolCount;
EXTERN SymbolNode *SymbolList;
EXTERN int TypeCount;
EXTERN TypeNode *TypeList;

/* ---------- Prototypes */

#ifdef __ANSI_C__
void disposeActionNode(ActionNode *actionNode);
void disposeAliasNode(AliasNode *aliasNode);
void disposeFiducialNode(FiducialNode *fiducialNode);
void disposeParamNode(ParamNode *paramNode);
void disposePhaseNode(PhaseNode *phaseNode);
void disposeProductionList(void);
void disposeProductionNode(ProductionNode *productionNode);
void disposeRHS(RHSNode *rhsNode);
void disposeRHSNode(RHSNode *rhsNode);
void disposeSymbolList(void);
void disposeSymbolNode(SymbolNode *symbolNode);
void disposeTypeList(void);
void disposeTypeNode(TypeNode *typeNode);
PhaseNode *findPhaseNode(PhaseNode *,char *);
ActionNode *newActionNode(SymbolNode *symbol, char *function, int paramNumber, ParamNode *params, char *type, int popNumber, PhaseNode *phases);
AliasNode *newAliasNode(SymbolNode *symbol, char *alias);
FiducialNode *newFiducialNode(SymbolNode *symbol);
ParamNode *newParamNode(int offset, char *type);
PhaseNode *newPhaseNode(char *text);
ProductionNode *newProductionNode(SymbolNode *symbol, int length, RHSNode *rhs);
RHSNode *newRhsNode(SymbolNode *symbol);
SymbolNode *newSymbolNode(char *text);
TypeNode *newTypeNode(char *text);
Token semBeginActions(void);
Token semBeginAliases(void);
Token semBeginFiducials(void);
Token semBeginPhaseIds(void);
Token semBeginPhases(void);
Token semBeginProductions(void);
Token semBeginSpec(void);
Token semDoAction(Token actToken, Token funToken, Token typToken, Token popToken);
Token semDoAlias(Token idToken, Token aliasToken);
Token semDoFiducial(Token fidToken);
Token semDoPhase(Token phaseToken);
Token semDoPhaseId(Token phaseToken);
Token semDoProduction(Token lhsToken);
Void semEatEoL(void);
Token semEndActions(void);
Token semEndAliases(void);
Token semEndFiducials(void);
Token semEndPhaseIds(void);
Token semEndPhases(void);
Token semEndProductions(void);
Token semEndSpec(void);
Token semListEmpty(void);
Token semListGroup(void);
Token semParamChar(Token paramToken);
Token semParamEnum(Token paramToken);
Token semParamInt(Token paramToken);
Token semParamString(Token paramToken);
Token semParamStack(Token ofsToken, Token typToken);
Token semRhsIdent(Token idToken);
SymbolNode *symbolListAdd(char *symbol, int type);
void typeListAdd(char *type);
#else
void disposeActionNode();
void disposeAliasNode();
void disposeFiducialNode();
void disposeParamNode();
void disposePhaseNode();
void disposeProductionList();
void disposeProductionNode();
void disposeRHS();
void disposeRHSNode();
void disposeSymbolList();
void disposeSymbolNode();
void disposeTypeNode();
void disposeTypeList();
PhaseNode *findPhaseNode();
ActionNode *newActionNode();
AliasNode *newAliasNode();
FiducialNode *newFiducialNode();
ParamNode *newParamNode();
PhaseNode *newPhaseNode();
ProductionNode *newProductionNode();
RHSNode *newRhsNode();
SymbolNode *newSymbolNode();
TypeNode *newTypeNode();
Token semBeginActions();
Token semBeginAliases();
Token semBeginFiducials();
Token semBeginPhaseIds();
Token semBeginPhases();
Token semBeginProductions();
Token semBeginSpec();
Token semDoAction();
Token semDoAlias();
Token semDoFiducial();
Token semDoPhase();
Token semDoPhaseId();
Token semDoProduction();
Void semEatEoL();
Token semEndAliases();
Token semEndFiducials();
Token semEndActions();
Token semEndPhaseIds();
Token semEndPhases();
Token semEndProductions();
Token semEndSpec();
Token semListEmpty();
Token semListGroup();
Token semParamChar();
Token semParamEnum();
Token semParamInt();
Token semParamString();
Token semParamStack();
Token semRhsIdent();
SymbolNode *symbolListAdd();
void typeListAdd();
#endif /* __ANSI_C__ */

#endif /* APTACTS_H */
