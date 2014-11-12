/******************************************************************
**
** ANALYZE.C:
**
**    Grammatical Analysis Module
**
** This file is part of Apt Parsing Tool (APT) for LL(1) Parsing
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ANALYZE_H
#define ANALYZE_H

/* ----------- Headers */

#include "apt.h"

/* ----------- Exported Prototypes */

#ifdef __ANSI_C__
void DeduceMinLenTermString( void );
void DeduceReachableSymbols( void );
void FindNullDerivingSymbols( void );
#else
void DeduceMinLenTermString();
void DeduceReachableSymbols();
void FindNullDerivingSymbols();
#endif /* __ANSI_C__ */

#endif /* ANALYZE_H */
