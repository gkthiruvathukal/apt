/****************************************************************** 
**
** BUILD.H:
**
**    APT Internal Table Building
** 
** This file is part of Apt Parsing Tool (APT) 
** Copyright (c) 1991 -- Apt Technologies 
** All rights reserved 
** 
******************************************************************/ 

#ifndef BUILD_H
#define BUILD_H

/* ----------- Defines */

#define StartSymbol "Goal"
#define EOFSymbol "EoF"

/* ----------- Types */

typedef struct _ProductTableElem {
  short LHS;
  short lenRHS;
  short lenRHSA;
  short *RHS;
  short *RHSA;
} ProductTableElem;

typedef struct _SymTabElem {
  char *symbol;
  short type;
  short derives_lambda;
  short reachable;
  long min_len_ts;
} SymTabElem;

/* ----------- Exported Globals */

EXTERN int NonTerminalCount;
EXTERN ProductTableElem *ProductTab;
EXTERN int RHSLenCount;
EXTERN SymTabElem *SymTab;
EXTERN int TerminalCount;
EXTERN char **TypeTable;

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void BuildProductionTable(void);
void BuildSymbolTable(void);
void BuildTypeTable(void);
void BuildRemoveLists(void);
void ComputeCounts(void);
int LookupSymbol(char *symbol);
int LookupType(char *text);
#else
void BuildProductionTable();
void BuildSymbolTable();
void BuildTypeTable();
void BuildRemoveLists();
void ComputeCounts();
int LookupSymbol();
int LookupType();
#endif /* __ANSI_C__ */

#endif /* BUILD_H */
