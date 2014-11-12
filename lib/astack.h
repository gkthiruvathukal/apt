/******************************************************************
**
** ASTACK.H:
**
**    ADT Array Stack Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTACK_H
#define ASTACK_H

/* ---------- Headers */

#include "apt.h"

/* ---------- Types */

typedef enum _AStackErrorTypes {
  AStackOK,
  AStackOverflow,
  AStackUnderflow,
  AStackRangeError,
  AStackTypeMismatch,
  AStackBadDisplacement
} AStackErrorTypes;

typedef enum _AStackItemTypes {
  NoType, Byte, LongWord, Pointer, Word
} AStackItemTypes;

typedef struct _AStackItem {
  enum _AStackItemTypes type;
  union {
    unsigned char b;
    unsigned short w;
    unsigned long lw;
    void *ptr;
  } u;
} _AStackItem, *AStackItem;

typedef struct _AStack {
  int size;
  int max;
  enum _AStackErrorTypes error;
  struct _AStackItem *stack;
} _AStack, *AStack;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
int AStackCheckByte(AStack, int);
int AStackCheckLongWord(AStack, int);
int AStackCheckPointer(AStack, int);
AStackItemTypes AStackCheckType(AStack, int);
int AStackCheckWord(AStack, int);
void AStackClearError(AStack);
void AStackDispose(AStack, DisposeFunction);
int AStackEmpty(AStack);
AStackErrorTypes AStackError(AStack);
unsigned char AStackGetByte(AStack, int);
unsigned long AStackGetLongWord(AStack, int);
void *AStackGetPointer(AStack, int);
unsigned short AStackGetWord(AStack, int);
unsigned char AStackLookByte(AStack);
unsigned long AStackLookLongWord(AStack);
void *AStackLookPointer(AStack);
AStackItemTypes AStackLookType(AStack);
unsigned short AStackLookWord(AStack);
AStack AStackNew(int);
int AStackNotEmpty(AStack);
unsigned char AStackPopByte(AStack);
unsigned long AStackPopLongWord(AStack);
void *AStackPopPointer(AStack);
unsigned short AStackPopWord(AStack);
void AStackPushByte(AStack, unsigned char);
void AStackPushLongWord(AStack, unsigned long);
void AStackPushPointer(AStack, void*);
void AStackPushWord(AStack, unsigned short);
int AStackSize(AStack);
void AStackSpill(AStack, int, DisposeFunction);
#else
int AStackCheckByte();
int AStackCheckLongWord();
int AStackCheckPointer();
AStackItemTypes AStackCheckType();
int AStackCheckWord();
void AStackClearError();
void AStackDispose();
int AStackEmpty();
AStackErrorTypes AStackError();
unsigned char AStackGetByte();
unsigned long AStackGetLongWord();
void *AStackGetPointer();
unsigned short AStackGetWord();
unsigned char AStackLookByte();
unsigned long AStackLookLongWord();
void *AStackLookPointer();
AStackItemTypes AStackLookType();
unsigned short AStackLookWord();
AStack AStackNew();
int AStackNotEmpty();
unsigned char AStackPopByte();
unsigned long AStackPopLongWord();
void *AStackPopPointer();
unsigned short AStackPopWord();
void AStackPushByte();
void AStackPushLongWord();
void AStackPushPointer();
void AStackPushWord();
int AStackSize();
void AStackSpill();
#endif /* __ANSI_C__ */

#endif /* ASTACK_H */
