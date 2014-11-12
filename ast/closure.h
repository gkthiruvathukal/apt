/******************************************************************
**
** CLOSURE.H:
**
**    AST Transitive Closure Routines
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef CLOSURE_H
#define CLOSURE_H

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void GKTSparseClosure(short**, short**, int);
void Warshall(short**, int);
#else
void GKTSparseClosure();
void Warshall();
#endif /* __ANSI_C__ */

#endif /* CLOSURE_H */
