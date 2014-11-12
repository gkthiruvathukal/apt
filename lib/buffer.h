/******************************************************************
**
** BUFFER.H:
**
**    ADT Buffer Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/*
** NB: This ADT, written in 1989, is similar to what Java provides
** today in the StringBuffer class.
*/

#ifndef BUFFER_H
#define BUFFER_H

/* ---------- Headers */

#include "apt.h"
#include "deque.h"

/* ---------- Defines */

#define BlockSize 16

/* ---------- Private Types */

typedef struct _Buffer {
  Deque data;
  int pos;
  char *text;
} _Buffer, *Buffer;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
void BufferAddChar(Buffer, char);
void BufferAddString(Buffer, char*);
int BufferDelChar(Buffer);
void BufferDispose(Buffer);
Buffer BufferNew(void);
int BufferSize(Buffer);
char *BufferToString(Buffer);
#else
void BufferAddChar();
void BufferAddString();
int BufferDelChar();
void BufferDispose();
Buffer BufferNew();
int BufferSize();
char *BufferToString();
#endif /* __ANSI_C__ */

#endif /* BUFFER_H */
