/******************************************************************
**
** APTIMP.H:
**
**    APT RTS Expected Imports
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTIMP_H
#define APTIMP_H

/* ----------- Headers */

#include "apt.h"

#include "apttype.h"
#include "asttype.h"

#include "astack.h"

/* ----------- Imported Types */

typedef int SemanticStackTypes;
typedef struct _SemanticStackElement *SemanticStackElement;

/* ----------- Imported Globals */

EXTERN _ActionTablePtrType ActionTable;
EXTERN char *PhaseName[];
EXTERN _PhaseTableType PhaseTable;
EXTERN short PredictIndexTable[];
EXTERN _PredictionTripleElement PredictionTriple[];
EXTERN _SymbolTableElement SymbolTable[];
EXTERN char *SemanticStackTypeTable[];
EXTERN _ProductionTableElement ProductionTable[];

/* ----------- Imported Functions */

#ifdef __ANSI_C__
VOID_FN_VOID ActionAt(int);
void CheckStackAt(char*,AStack,int,int);
void DumpPredictionStack(AStack);
void DumpSemanticStack(AStack);
SemanticStackElement SSEGet(AStack,int);
SemanticStackElement SSENew(void);
SemanticStackElement SSTENew(Token);
#else
VOID_FN_VOID ActionAt();
void CheckStackAt();
void DumpPredictionStack();
void DumpSemanticStack();
SemanticStackElement SSEGet();
SemanticStackElement SSENew();
SemanticStackElement SSTENew();
#endif

#endif /* APTIMP_H */
