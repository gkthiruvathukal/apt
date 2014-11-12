/******************************************************************
**
** PREDICT.C:
**
**    APT Prediction Table Construction
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "aptacts.h"
#include "aptmain.h"
#include "build.h"
#include "debug.h"
#include "matrix.h"
#include "predict.h"
#include "sets.h"

#include "aptlib.h"
#include "gprintf.h"

/* ----------- Exported Globals */

PUBLIC short **ll_predict;
PUBLIC int PredictionCount;

/* ----------- Functions */

int ComputeLLPredictionTable()
{
  int i,j,k;
  int LHS;
  int RHSj;
  int warning = 0;

  /* -- Make each undefined entry of M equal to ERROR */
  ll_predict = imatrix(0,NonTerminalCount+TerminalCount,0,
    NonTerminalCount+TerminalCount);
  for (i=0; i < NonTerminalCount + TerminalCount; i++)
    for (j=0; j < NonTerminalCount + TerminalCount; j++)
      ll_predict[i][j] = ERROR;

  /* -- For each terminal k in FIRST(alpha), add A -> alpha to M[A,k] */
  for (i=0; i < ProductionCount; i++) {
    LHS = ProductTab[i].LHS;
    for (j=0; j < ProductTab[i].lenRHS; j++) {
      RHSj = ProductTab[i].RHS[j];
      for (k=0; k < NonTerminalCount + TerminalCount; k++)
        if (SymTab[k].type == Terminal)
          if (first[RHSj][k]) {
            if (ll_predict[LHS][k] != ERROR && ll_predict[LHS][k] != i) {
              warning = 1;
              gprintf(errorFile,"Warning: Prediction conflict (FIRST set)\n");
              gprintf(errorFile," Conflict at LL[%s][%s]:\n",
                SymTab[LHS].symbol,SymTab[k].symbol);
              DumpProduction(i);
              DumpProduction(ll_predict[LHS][k]);
              gprintf(errorFile,"\n");
            } else {
              ll_predict[LHS][k] = i;
              PredictionCount++;
            }
          }
      if (SymTab[RHSj].derives_lambda) continue;
      break;
    }

    /*
    ** -- If lambda is an element of FIRST(alpha), and A -> alpha to M[A,b],
    ** -- where b is an element of FOLLOW(A)
    */
    if (j == ProductTab[i].lenRHS)
      for (k=0; k < NonTerminalCount + TerminalCount; k++)
        if (SymTab[k].type == Terminal)
          if (follow[LHS][k]) {
            if (ll_predict[LHS][k] != ERROR && ll_predict[LHS][k] != i) {
              warning = 1;
              gprintf(errorFile,"Warning: Prediction conflict (FOLLOW set)\n");
              gprintf(errorFile," Conflict at LL[%s][%s]:\n",
                SymTab[LHS].symbol,SymTab[k].symbol);
              DumpProduction(i);
              DumpProduction(ll_predict[LHS][k]);
              gprintf(errorFile,"\n");
            } else {
              ll_predict[LHS][k] = i;
              PredictionCount++;
            }
          }
  }
  if (warning) {
    gprintf(stderr,"Warning: See error file for list ");
    gprintf(stderr,"of prediction table conflicts.\n");
  }
  return (warning);
}
