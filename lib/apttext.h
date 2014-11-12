/******************************************************************
**
** APTTEXT.H:
**
**    APT Runtime System Semantic Stack Functions
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTTEXT_H
#define APTTEXT_H

/*
**  Implementation note:
**
**  These routines must be defined after the semantic stack type is known. An
**  opaque definition is not suitable for the parser module, because a need to
**  reference fields of the semantic stack sse exists.
*/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "asttype.h"

#include "allocate.h"
#include "astack.h"
#include "gprintf.h"

/* ---------- Functions */

/*
**
** ActionAt
**
*/
PUBLIC
#ifdef __ANSI_C__
void (*ActionAt(int action)) ()
#else
void (*ActionAt(action)) ()
int action;
#endif
{
  return (ActionTable[action-ActionBase]);
}

/*
**
** CheckStackAt
**
*/
PUBLIC
#ifdef __ANSI_C__
void CheckStackAt(char *reference, AStack s, int position, int checkType)
#else
void CheckStackAt(reference,s,position,checkType)
char *reference;
AStack s;
int position;
int checkType;
#endif
{
  SemanticStackElement sse;

  sse = (SemanticStackElement)AStackGetPointer(s,position);
  if (sse == NULL) {
    gprintf(stdout,"\n%s: Stack check at position %d failed: NULL != %s\n",
      reference,position,SemanticStackTypeTable[checkType]);
    exit(1);
  }
  if (sse->type != checkType) {
    gprintf(stdout,"\n%s: Stack check at position %d failed: ",
      reference,position);
    gprintf(stdout,"%s does not match %s.\n",
      SemanticStackTypeTable[sse->type],SemanticStackTypeTable[checkType]);
    exit(1);
  }
}

/*
**
** DumpPredictionStack
**
*/
PUBLIC
#ifdef __ANSI_C__
void DumpPredictionStack(AStack s)
#else
void DumpPredictionStack(s)
AStack s;
#endif
{
  int cnt;

  gprintf(stdout,"PredictionStack %d:",s->size);
  for (cnt=1; cnt<s->size && cnt<10; cnt++) {
    gprintf(stdout," %s",SymbolTable[AStackGetWord(s,cnt)].text);
  }
  gprintf(stdout,"\n");
}

/*
**
** DumpSemanticStack
**
*/
PUBLIC
#ifdef __ANSI_C__
void DumpSemanticStack(AStack s)
#else
void DumpSemanticStack(s)
AStack s;
#endif
{
  int cnt;
  SemanticStackElement sse;
 
  gprintf(stdout,"SemanticStack %d:",s->size);
  for (cnt=1; cnt<=s->size && cnt<10; cnt++) {
    sse = (SemanticStackElement)AStackGetPointer(s,cnt);
    if (sse->type == SST_Token)
      if (sse->u.U_Token != NULL)
        gprintf(stdout," %s:%s",sse->u.U_Token->text,
           SemanticStackTypeTable[sse->type]);
      else gprintf(stdout," NULL:%s",SemanticStackTypeTable[sse->type]);
    else gprintf(stdout," %s",SemanticStackTypeTable[sse->type]);
  }
  gprintf(stdout,"\n");
}

/*
**
** SSEGet
**
*/
PUBLIC
SemanticStackElement SSEGet(s,n)
AStack s;
int n;
{
  return (SemanticStackElement)AStackGetPointer(s,n);
}

/*
**
** SSENew
**
*/
PUBLIC
#ifdef __ANSI_C__
SemanticStackElement SSENew(void)
#else
SemanticStackElement SSENew()
#endif
{
  return ((SemanticStackElement)Allocate(sizeof(struct _SemanticStackElement)));
}

/*
**
** SSTENew
**
*/
PUBLIC
#ifdef __ANSI_C__
SemanticStackElement SSTENew(Token token)
#else
SemanticStackElement SSTENew(token)
Token token;
#endif
{
  SemanticStackElement sse;

  sse = SSENew();
  if (sse) {
    sse->type = SST_Token;
    sse->u.U_Token = token;
  }
  return (sse);
}

#endif /* APTTEXT_H */
