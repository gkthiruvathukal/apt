/******************************************************************
**
** ASTPARSE.C:
**
**    AST Parser Module
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTPARSE_H
#define ASTPARSE_H

/* ----------- Headers */

#include "apt.h"

/* ----------- Exported Globals */

EXTERN struct state_arc_record *actionList;
EXTERN int actions;
EXTERN struct state_arc_record *attributeList;
EXTERN int attributes;
EXTERN int defaultPos;
EXTERN int lambdaPos;
EXTERN struct state_arc_record *stateList;
EXTERN int states;
EXTERN struct state_arc_record *symbolList;
EXTERN int symbols;
EXTERN struct transition_record *transitionList;

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void AstParse(void);
#else
void AstParse();
#endif /* __ANSI_C__ */

#endif /* ASTPARSE_H */
