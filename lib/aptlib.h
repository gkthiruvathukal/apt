/******************************************************************
**
** APTLIB.H:
**
**    APT Runtime System Library
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTLIB_H
#define APTLIB_H

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "aptimp.h"
#include "apttype.h"

#include "astack.h"
#include "queue.h"

/* ----------- Defines */

#define GoalSymbolValue 0

#define PREDICTION_STACK_SIZE 256
#define SEMANTIC_STACK_SIZE 256

/* ----------- Types */

#define LowOption 0

typedef enum _ParseDebugOptions {
  DebugToken = LowOption,
  DebugPredictionStack,
  DebugSemanticStack,
  DebugSemanticAction,
  NumberOfParseDebugOptions
} ParseDebugOptions;

/* ----------- Exported Globals */

EXTERN AStack PredictionStack;
EXTERN AStack SemanticStack;

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
Queue BuildTokenQueue(FILE *, int);
void Parse(FILE*, VOID_FN_TOKEN);
void ParseEOPMIn(FILE*, VOID_FN_TOKEN, VOID_FN_CHAR);
void ParseEOPMOut(FILE*, FILE*, VOID_FN_TOKEN, INT_FN_TOKEN_ST);
void ParseEOPMOutQ(Queue, FILE*, VOID_FN_TOKEN, INT_FN_TOKEN_ST);
void ParseInitialize(void);
void ParseTerminate(void);
void ResetDebugOption(ParseDebugOptions);
void SetDebugOption(ParseDebugOptions);
#else
Queue BuildTokenQueue();
void Parse();
void ParseEOPMIn();
void ParseEOPMOut();
void ParseEOPMOutQ();
void ParseInitialize();
void ParseTerminate();
void ResetDebugOption();
void SetDebugOption();
#endif /* __ANSI_C__ */

#endif /* APTLIB_H */
