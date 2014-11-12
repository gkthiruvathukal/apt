/******************************************************************
**
** DEBUG.C:
**
**    APT Debugging Routines
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- C Headers */

#include "cheaders.h"

/* ----------- Headers */

#include "apt.h"

#include "aptmain.h"
#include "aptparse.h"
#include "build.h"
#include "debug.h"

#include "aptlib.h"
#include "gprintf.h"

/* ----------- Functions */

void DisplayMessage( tab, s )
int tab;
char *s;
{
  for (; tab; tab--) gprintf(stderr,"\t");
  gprintf(stderr,s);
  gprintf(stderr,"\n");
}

void DumpProduction( id )
int id;
{
  int k;

  gprintf(errorFile,"  ");
  gprintf(errorFile,"[%d] %s --> ",id,SymTab[ProductTab[id].LHS].symbol);
  for (k=0; k < ProductTab[id].lenRHS; k++)
    gprintf(errorFile,"%s ",SymTab[ProductTab[id].RHS[k]].symbol);
  gprintf(errorFile,"\n");
}

void ReportMinLenTermString()
{
  int i, error = 0;

  for (i=0; i < NonTerminalCount + TerminalCount; i++)
    if (SymTab[i].type == NonTerminal)
      if (SymTab[i].min_len_ts >= INFINITY) {
        error++;
        gprintf(errorFile,"Error: '%s' cannot derive a finite sentence.\n",
            SymTab[i].symbol);
      }
  if (error) {
    gprintf(stderr,"Warning: See error file for a list of ");
    gprintf(stderr,"infinite-deriving nonterminals.\n");
  }
}

void ReportUnreachableSymbols()
{
  int i, error = 0;

  for (i=0; i < NonTerminalCount + TerminalCount; i++) {
    if (SymTab[i].reachable == 0) {
      error++;
      gprintf(errorFile,"Warning: '%s' is not reachable ",SymTab[i].symbol);
      gprintf(errorFile,"from the start symbol.\n");
    }
  }
  if (error) {
    gprintf(stderr,"Warning: See error file for a list of ");
    gprintf(stderr,"unreachable symbols.\n");
  }
}
