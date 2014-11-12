/************************************************************/
/*                                                          */
/* -- Apt Scanning Tool (AST)                               */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- CONVERT.C - Apt Scanning Tool List Conversion         */
/*                Definition Module                         */
/*                                                          */
/************************************************************/
#ifndef CONVERT_H
#define CONVERT_H

extern short **Shift, **ActionM, **Attribute, **reaches;
/* Prototype declarations for CONVERT.C */

#ifdef __ANSI_C__
void BuildReachesMatrix(void);
void BuildTransitionMatrix(void);
#else
void BuildReachesMatrix();
void BuildTransitionMatrix();
#endif

#endif
