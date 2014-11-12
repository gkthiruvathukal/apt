/******************************************************************
**
** ASTCLASS.H:
**
**    AST Token Classification Module.
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTCLASS_H
#define ASTCLASS_H

/* ----------- Headers */

#include "apt.h"
#include "astlib.h"

/* ----------- Exported Prototypes */

#ifdef __ANSI_C__
int Classify(Token, int);
#else
int Classify();
#endif /* __ANSI_C__ */

#endif /* ASTCLASS_H */
