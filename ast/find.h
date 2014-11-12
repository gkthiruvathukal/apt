/************************************************************/
/*                                                          */
/* -- Apt Scanning Tool (AST)                               */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- Find.c - Routines to lookup elements in lists, etc.   */
/************************************************************/
#ifndef FIND_H
#define FIND_H

#include "apt.h"
#include "astmain.h"

/* Prototype declarations for FIND.C */

#ifdef __ANSI_C__
int inList(struct state_arc_record *list, char *name);
int findSymbolinList(struct state_arc_record *list, char *name);
int isBuiltIn(char *symbol);
int isIntrinsic(char *symbol);
int lenList(struct state_arc_record *list);
char *stateAt(int i);
char *symbolAt(int i);
char *actionAt(int i);
char *attributeAt(int i);
#else
int inList();
int findSymbolinList();
int isBuiltIn();
int isIntrinsic();
int lenList();
char *stateAt();
char *symbolAt();
char *actionAt();
char *attributeAt();
#endif

#endif
