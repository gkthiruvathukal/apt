/******************************************************************
**
** ASTIMP.H:
**
**    AST Runtime System Expected Imports
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTIMP_H
#define ASTIMP_H

/* ----------- Headers */

#include "asttype.h"

/* ----------- Imported Functions */

#ifdef __ANSI_C__
int Classify(Token, int);
Token Scan(FILE *);
#else
int Classify();
Token Scan();
#endif /* __ANSI_C__ */

#endif /* ASTIMP_H */
