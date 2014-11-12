/******************************************************************
**
** GPRINTF.H:
**
**    APT Printf() Functions
**
** This file is part of Apt Computing Tools (ACT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef GPRINTF_H
#define GPRINTF_H

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void gprintf(FILE*, char*, ...);
#else
void gprintf();
#endif /* __ANSI_C__ */

#endif /* GPRINTF_H */
