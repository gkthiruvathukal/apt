/******************************************************************
**
** APTTYPE.H:
**
**    APT Runtime System Types
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTTYPE_H
#define APTTYPE_H

/* ---------- Headers */

#include "apt.h"
#include "asttype.h"
/* ---------- Exported Types */

typedef enum _SymbolType {
  NonTerminal,
  Terminal,
  Action
} SymbolType;

#ifdef __ANSI_C__
typedef void (*VOID_FN_CHAR)(char*);
typedef int (*INT_FN_TOKEN_ST)(Token, SymbolType);
typedef void (*VOID_FN_TOKEN)(Token);
typedef void (*VOID_FN_VOID)(void);
#else
typedef void (*VOID_FN_CHAR)();
typedef int (*INT_FN_TOKEN_ST)();
typedef void (*VOID_FN_TOKEN)();
typedef void (*VOID_FN_VOID)();
#endif

typedef void (*_ActionTableType[])();

typedef void (**_ActionTablePtrType)();

typedef _ActionTablePtrType _PhaseTableType[];

typedef struct _PredictionTripleElement {
  int nonTerminal;
  int terminal;
  int production;
} _PredictionTripleElement, *PredictionTripleElement;

typedef struct _ProductionTableElement {
  short LHS;
  short lenRHS;
  short *RHS;
} _ProductionTableElement, *ProductionTableElement;

typedef struct _SymbolTableElement {
  char *text;
  short type;
} _SymbolTableElement, *SymbolTableElement;

typedef void Void;

#endif /* APTTYPE_H */
