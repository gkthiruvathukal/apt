/******************************************************************
**
** ANALYZE.C:
**
**    Grammatical Analysis Module
**
** This file is part of Apt Parsing Tool (APT) for LL(1) Parsing
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- Headers */

#include "apt.h"

#include "analyze.h"
#include "aptacts.h"
#include "build.h"

/* ---------- Functions */

void DeduceMinLenTermString()
{
  int done = FALSE;
  int i, j;
  long length;

  for (i=0; i < NonTerminalCount + TerminalCount; i++)
    SymTab[i].min_len_ts = SymTab[i].type == Terminal ? 1 : INFINITY;
  while (!done) {
    done = TRUE;
    for (i=0; i < ProductionCount; i++) {
      length = 0L;
      for (j=0; j < ProductTab[i].lenRHS; j++) {
        length += SymTab[ProductTab[i].RHS[j]].min_len_ts;
        if (length >= SymTab[ProductTab[i].LHS].min_len_ts) break;
      }
      if (length < SymTab[ProductTab[i].LHS].min_len_ts) {
        SymTab[ProductTab[i].LHS].min_len_ts = length;
        done = FALSE;
      }
    }
  }
}

void DeduceReachableSymbols()
{
  int done = FALSE;
  int i, j, k;

  SymTab[0].reachable = 1;
  while (!done) {
    done = TRUE;
    for (i=0; i < NonTerminalCount + TerminalCount; i++)
      if (SymTab[i].reachable)
        for (j=0; j < ProductionCount; j++)
          if (ProductTab[j].LHS == i)
            for (k=0; k < ProductTab[j].lenRHS; k++)
              if (SymTab[ProductTab[j].RHS[k]].reachable == 0) {
                SymTab[ProductTab[j].RHS[k]].reachable = 1;
                done = FALSE;
              }
  }
}

void FindNullDerivingSymbols()
{
  int derives_lambda;
  int done = FALSE;
  int i, j;

  while (!done) {
    done = TRUE;
    for (i=0; i < ProductionCount; i++)
      if (!SymTab[ProductTab[i].LHS].derives_lambda) {
        derives_lambda = TRUE;
        for (j=0; j < ProductTab[i].lenRHS; j++)
          derives_lambda &= SymTab[ProductTab[i].RHS[j]].derives_lambda;
        if (derives_lambda) {
          SymTab[ProductTab[i].LHS].derives_lambda = TRUE;
          done = FALSE;
        }
      }
  }
}
