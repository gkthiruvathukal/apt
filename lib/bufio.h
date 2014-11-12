/******************************************************************
**
** BUFIO.C:
**
**    ADT Buffered I/O Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef BUFIO_H
#define BUFIO_H

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
int BufIOBufferSize(FILE *file);
int BufIOGetChar(FILE *file);
char *BufIOGetString(FILE *file);
void BufIOInitialize(void);
void BufIOTerminate(void);
void BufIOUnGetChar(int ch, FILE *file);
#else
int BufIOBufferSize();
int BufIOGetChar();
char *BufIOGetString();
void BufIOInitialize();
void BufIOTerminate();
void BufIOUnGetChar();
#endif /* __ANSI_C__ */

#endif /* BUFIO_H */
