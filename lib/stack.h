/******************************************************************
**
** STACK.H:
**
**    ADT Stack Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef STACK_H
#define STACK_H

/* ---------- Headers */

#include "apt.h"

/* ---------- Types */

typedef struct _StackItem {
  void *element;
  int type;
  struct _StackItem *next;
} _StackItem, *StackItem;

typedef struct _Stack {
  struct _StackItem *head;
  struct _StackItem *tail;
  int size;
} _Stack, *Stack;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
void StackApply(Stack, ApplyFunction);
void StackDispose(Stack, DisposeFunction);
void *StackFind(Stack, void*, ComparisonFunction);
StackItem StackHead(Stack);
void *StackItemElement(StackItem);
int StackItemType(StackItem);
void *StackLook(Stack);
Stack StackNew(void);
StackItem StackNext(StackItem);
void *StackPop(Stack);
void StackPush(Stack, void*, int);
void StackPushOnPriority(Stack, void*, int, ComparisonFunction);
int StackSize(Stack);
StackItem StackTail(Stack);
#else
void StackApply();
void StackDispose();
void *StackFind();
StackItem StackHead();
void *StackItemElement();
int StackItemType();
void *StackLook();
Stack StackNew();
StackItem StackNext();
void *StackPop();
void StackPush();
void StackPushOnPriority();
int StackSize();
StackItem StackTail();
#endif /* __ANSI_C__ */

#endif /* STACK_H */
