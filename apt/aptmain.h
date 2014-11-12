/******************************************************************
**
** APTMAIN.H:
**
**    APT Main Module
**
** This file is part of Apt Parsing Tool (APT) for LL(1) Parsing
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef APTMAIN_H
#define APTMAIN_H

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "asttype.h"

/* ---------- Defines */

#define TheSwitches "+-"

/* ----------- Exported Types */

enum AptOptionCodes {
  AptOptAnalysis,
  AptOptCodeGen,
  AptOptInclude,
  AptOptListFile,
  AptOptActionFile,
  AptOptSemCheck,
  AptOptTermDefs,
  AptOptWarning,
  AptOptionCount
};

/* ---------- Exported Globals */

EXTERN int AptFlags[];
EXTERN FILE *codeFile;
EXTERN FILE *errorFile;
EXTERN FILE *grmFile;
EXTERN FILE *listFile;
EXTERN ScanInfo scanInfo;

/* ---------- Exported Prototypes */

#ifdef __ANSI_C__ 
void Error(int, int, char*, char*);
#else 
void Error();
#endif  /* __ANSI_C__ */

#endif /* APTMAIN_H */
