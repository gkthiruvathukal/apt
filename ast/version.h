/******************************************************************
**
** VERSION.H:
**
**    AST Code Generation Version
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef VERSION_H
#define VERSION_H

/* ----------- Headers */

#include "apt.h"

/* ----------- Types */

typedef enum _CGVersion {
   CG_ANSI_C,
   CG_JAVA
} CGVersion;

/* ------------ Exported Globals */

EXTERN char *edition[];
EXTERN CGVersion version;

#endif /* VERSION_H */
