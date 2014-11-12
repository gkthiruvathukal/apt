/******************************************************************
**
** LISTFILE.C:
**
**    APT Listing Output
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
#include "listfile.h"
#include "predict.h"
#include "sets.h"

#include "aptlib.h"
#include "gprintf.h"

/* ---------- Functions */

void listSet(caption,set)
char *caption;
short **set;
{
  int i,j;

  gprintf(listFile,"[ %s ]\n\n",caption);
  for (i=0; i < NonTerminalCount + TerminalCount; i++)
    if (SymTab[i].type == NonTerminal) {
      gprintf(listFile,"%s :: ",SymTab[i].symbol);
      for (j=0; j < NonTerminalCount + TerminalCount; j++)
        if (SymTab[j].type == Terminal && set[i][j])
          gprintf(listFile,"%s ",SymTab[j].symbol);
      gprintf(listFile,"\n");
    }
  gprintf(listFile,"\n");
}

void listSets()
{
  listSet("First Sets",first);
  listSet("Last Sets",last);
  listSet("Next To Sets",nextto);
  listSet("Follow Sets",follow);
}

void listSymbolTable()
{
  int i;

  gprintf(listFile,"[ Symbol Table ]\n\n");
  for (i=0; i < SymbolCount; i++) {
    gprintf(listFile,"%s :: ",SymTab[i].symbol);
    switch(SymTab[i].type) {
    case Terminal:
      gprintf(listFile,"Terminal ");
      break;
    case NonTerminal:
      gprintf(listFile,"Nonterminal ");
      break;
    case Action:
      gprintf(listFile,"Action ");
    }
    if (SymTab[i].derives_lambda)
      gprintf(listFile,"Null-deriving ");
    if (SymTab[i].type == NonTerminal) {
      if (SymTab[i].min_len_ts < INFINITY)
        gprintf(listFile,"Finite (%d) ",(int)SymTab[i].min_len_ts);
      else
        gprintf(listFile,"Infinite ");
    }
    gprintf(listFile,"\n");
  }
  gprintf(listFile,"\n");
}
