/******************************************************************
**
** NTCGEN.H:
**
**    NT Code Generation
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef _NTCGEN_H_
#define _NTCGEN_H_

/* ---------- Headers */

#include "queue.h"


#ifdef __ANSI_C__
void CG(Queue,Queue,Queue);
#else
void CG();
#endif

#endif
