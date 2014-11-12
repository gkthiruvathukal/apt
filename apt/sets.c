/******************************************************************
**
** SETS.C:
**
**    APT Set (F/L/NT/FL) Construction
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- Headers */

#include "apt.h"
#include "aptacts.h"
#include "build.h"
#include "closure.h"
#include "matrix.h"
#include "sets.h"

/* ---------- Exported Globals */

PUBLIC short **first;
PUBLIC short **follow;
PUBLIC short **last;
PUBLIC short **nextto;

/* ---------- Functions */

void ConstructFirstLastSets()
{
#ifdef SparseClosure
  int afcol;
  int alcol;
  short **aux_first;
  short **aux_last;
#endif
  int cont;
  int i,j;
  int LHSi;
  int RHSij;

  first = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount);
  last = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount);

#ifdef SparseClosure
  aux_first = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount +1);
  aux_last = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount+1);
#endif

  for (i=0; i < ProductionCount; i++) {
    LHSi = ProductTab[i].LHS;
    for (j=0, cont=TRUE; cont && j < ProductTab[i].lenRHS; j++) {
      RHSij = ProductTab[i].RHS[j];
      first[LHSi][RHSij] = TRUE;
      if (!SymTab[RHSij].derives_lambda) cont = FALSE;
    }
    for (j=ProductTab[i].lenRHS-1, cont=TRUE; cont && j >= 0; j--) {
      RHSij = ProductTab[i].RHS[j];
      last[LHSi][RHSij] = TRUE;
      if (!SymTab[RHSij].derives_lambda) cont = FALSE;
    }
  }

#ifdef SparseClosure
  for (i=0; i < NonTerminalCount+TerminalCount; i++) {
    afcol=alcol=0;
    aux_first[i][afcol] = -1;
    aux_last[i][alcol] = -1;
    for (j=0; j < NonTerminalCount+TerminalCount; j++) {
      if (first[i][j]) {
        aux_first[i][afcol++] = j;
        aux_first[i][afcol] = -1;
      }
      if (last[i][j]) {
        aux_last[i][alcol++] = j;
        aux_last[i][alcol] = -1;
      }
    }
  }
  GKTSparseClosure(first,aux_first,NonTerminalCount+TerminalCount);
  GKTSparseClosure(last,aux_last,NonTerminalCount+TerminalCount);
  free_matrix(aux_first,0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount +1);
  free_matrix(aux_last,0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount+1);

#else
  Warshall(first,NonTerminalCount+TerminalCount);
  Warshall(last,NonTerminalCount+TerminalCount);
#endif

  for (i=0; i < NonTerminalCount+TerminalCount; i++) {
    first[i][i] = TRUE;
    last[i][i] = TRUE;
  }
}

void ConstructFollowSet()
{
  short **product;
  MATRIX t_cmp;

  Transpose(last,NonTerminalCount+TerminalCount);
  compress(last,NonTerminalCount+TerminalCount,&t_cmp);
  product = cmultiply(&t_cmp,nextto,NonTerminalCount+TerminalCount);
  free_cmp(&t_cmp);
  compress(product,NonTerminalCount+TerminalCount,&t_cmp);
  free_matrix(product,0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount);
  follow = cmultiply(&t_cmp,first,NonTerminalCount+TerminalCount);
  Transpose(last,NonTerminalCount+TerminalCount);
}

void ConstructNextToSet()
{
  int cont;
  int i,j,k;

  nextto = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount);

  for (i=0; i < ProductionCount; i++)
    for (j=0; j < ProductTab[i].lenRHS - 1; j++) {
      cont = TRUE;
      for (k = j + 1; cont && (k < ProductTab[i].lenRHS); k++) {
        nextto[ProductTab[i].RHS[j]][ProductTab[i].RHS[k]] = TRUE;
        if (!SymTab[ProductTab[i].RHS[k]].derives_lambda) cont = FALSE;
      }
    }
}
