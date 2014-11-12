/******************************************************************
**
** VERSION.H:
**
**    APT Code Generation Version
**
** This file is part of Apt Parsing Tool (APT)
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
   CG_UNIX_C,
   CG_Wirth_Modula_2,
   CG_Modern_Modula_2,
   CG_Pascal,
   CG_Icon,
   CG_Ada
} CGVersion;

/* ------------ Exported Globals */

EXTERN char *edition[];
EXTERN CGVersion version;

#endif /* VERSION_H */
