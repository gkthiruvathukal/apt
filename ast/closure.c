/****************************************************************** 
**
** CLOSURE.C:
**
**    AST Transitive Closure Routines
** 
** This file is part of Apt Scanning Tool (AST) 
** Copyright (c) 1991 -- Apt Technologies 
** All rights reserved 
** 
******************************************************************/

/* ----------- Headers */

#include "apt.h"
#include "closure.h"

/* ---------- Functions */

void GKTSparseClosure( matrix, auxMatrix, nbrSymbols )
short **matrix;
short **auxMatrix;
int nbrSymbols;
{
  int i, j, k;
  int t;
  int m;
  int p;
  int done = FALSE;

  while (!done) {
    done = TRUE;
    for (i=0; i < nbrSymbols; i++)
      for (j=0; auxMatrix[i][j] >= 0; j++) {
        t = auxMatrix[i][j];
        for (k=0; auxMatrix[t][k] >= 0; k++) {
          m = auxMatrix[t][k];
          if (!matrix[i][m]) {
            for (p=0; auxMatrix[i][p] >= 0; p++) ;
            auxMatrix[i][p++] = m;
            auxMatrix[i][p] = -1;
            matrix[i][m] = TRUE;
            done = FALSE;
          }
        }
      }
  }
}

void Warshall( matrix, nbrSymbols )
short **matrix;
int nbrSymbols;
{
  int i, j, k;

  for (k=0; k < nbrSymbols; k++)
    for (i=0; i < nbrSymbols; i++)
      for (j=0; j < nbrSymbols; j++)
        if (matrix[i][j] == FALSE)
          matrix[i][j] = matrix[i][k] && matrix[k][j];
}
