/******************************************************************
**
** BUILD.C:
**
**    APT Internal Table Building
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- Headers */

#include "apt.h"

#include "aptacts.h"
#include "build.h"

#include "aptlib.h"

#include "allocate.h"
#include "sstring.h"

/* ----------- Exported Globals */

PUBLIC int NonTerminalCount;
PUBLIC int RHSLenCount;
PUBLIC ProductTableElem *ProductTab;
PUBLIC SymTabElem *SymTab;
PUBLIC int TerminalCount;
PUBLIC char **TypeTable;

/* ----------- Functions */

void BuildProductionTable()
{
  int i,j,k,LHS,index;
  ProductionNode *p;
  RHSNode *s;

  ProductionCount++;
  ProductTab = (ProductTableElem *)
      /**/ Allocate(ProductionCount * sizeof(ProductTableElem));
  ProductTab[0].LHS = LookupSymbol(StartSymbol);
  ProductTab[0].RHS = (short *)Allocate(2 * sizeof(short));
  ProductTab[0].RHSA = (short *)Allocate(2 * sizeof(short));
  ProductTab[0].lenRHS = ProductTab[0].lenRHSA = 2;
  ProductTab[0].RHS[0] = ProductTab[0].RHSA[0] =
    LookupSymbol(ProductionList->symbol->text);
  ProductTab[0].RHS[1] = ProductTab[0].RHSA[1] = LookupSymbol(EOFSymbol);
  RHSLenCount = ProductTab[0].lenRHSA;
  for (i=1, p=ProductionList; p != NULL; i++,p=p->next) {
    LHS = LookupSymbol(p->symbol->text);
    ProductTab[i].LHS = LHS;
    ProductTab[i].RHS = (short *)Allocate(p->length * sizeof(short));
    ProductTab[i].RHSA = (short *)Allocate(p->length * sizeof(short));
    for (j=k=0, s=p->rhs; s != NULL; k++, s=s->next) {
      index = LookupSymbol(s->symbol->text);
      if (SymTab[index].type == Action) ProductTab[i].RHSA[k] = index;
      else ProductTab[i].RHSA[k] = ProductTab[i].RHS[j++] = index;
    }
    ProductTab[i].lenRHS = j;
    ProductTab[i].lenRHSA = k;
    RHSLenCount += ProductTab[i].lenRHSA;
  }
}

void BuildSymbolTable()
{
  SymbolNode *s;
  int i;

  SymbolCount += 2;
  SymTab = (SymTabElem *)
      Allocate(SymbolCount*sizeof(SymTabElem));
  SymTab[0].symbol = StringDuplicate(StartSymbol);
  SymTab[0].type = NonTerminal;
  SymTab[0].derives_lambda = FALSE;
  SymTab[0].reachable = FALSE;
  for (i=1, s=SymbolList; s != NULL; s=s->next)
    if (s->type == NonTerminal) {
      SymTab[i].symbol = StringDuplicate(s->text);
      SymTab[i].type = s->type;
      SymTab[i].derives_lambda = FALSE;
      SymTab[i].reachable = FALSE;
      i++;
    }
  SymTab[i].symbol = StringDuplicate(EOFSymbol);
  SymTab[i].type = Terminal;
  SymTab[i].derives_lambda = FALSE;
  SymTab[i].reachable = FALSE;
  for (i++, s=SymbolList; s != NULL; s=s->next)
    if (s->type == Terminal) {
      SymTab[i].symbol = StringDuplicate(s->text);
      SymTab[i].type = s->type;
      SymTab[i].derives_lambda = FALSE;
      SymTab[i].reachable = FALSE;
      i++;
    }
  for (s=SymbolList; s != NULL; s=s->next)
    if (s->type == Action) {
      SymTab[i].symbol = StringDuplicate(s->text);
      SymTab[i].type = s->type;
      SymTab[i].derives_lambda = FALSE;
      SymTab[i].reachable = FALSE;
      i++;
    }
}

void BuildTypeTable()
{
  TypeNode *t;
  int count;

  TypeTable = (char **)Allocate(TypeCount * sizeof(char *));
  for (count=0, t=TypeList; t != NULL; t=t->next, count++)
    TypeTable[count] = StringDuplicate(t->text);

}

void BuildRemoveLists()
{
  disposeSymbolList();
  disposeProductionList();
  disposeTypeList();
}

void ComputeCounts()
{
  int symbol;
  NonTerminalCount = 0;
  TerminalCount = 0;
  for (symbol=0; symbol < SymbolCount; symbol++) {
    switch (SymTab[symbol].type) {
    case NonTerminal:  
      NonTerminalCount++; 
      break;
    case Terminal: 
      TerminalCount++;  
      break;
    }
  }
}

int LookupSymbol( symbol )
char *symbol;
{
  int i;

  for (i=0; i < SymbolCount; i++)
    if (StringCompare(SymTab[i].symbol,symbol) == 0) return i;
  return -1; /* this should not happen anyway */
}

int LookupType( text )
char *text;
{
  int count;

  for (count=0; count < TypeCount; count++)
    if (StringCompare(TypeTable[count],text) == 0) return count;
  return -1;
}
