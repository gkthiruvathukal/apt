/******************************************************************
**
** APTCLASS.H:
**
**    APT Token Classification Module.
**
**    Scanner calls classify to potentially map a token into
**    another token.  A common use is to map identifiers to keywords.
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTCLASS_H
#define APTCLASS_H

#include "astlib.h"

#ifdef __ANSI_C__
int Classify(Token, int);
#else
int Classify();
#endif /* __ANSI_C__ */

#endif /* APTCLASS_H */
