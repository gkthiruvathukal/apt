/******************************************************************
**
** DEQUE.H:
**
**    ADT Deque Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

/* ---------- Headers */

#include "apt.h"

/* ---------- Types */

typedef enum _DequeLinkTypes {
  NoLink = -1, Top, Bottom, NumberOfLinks
} DequeLinkTypes;

typedef struct _DequeItem {
  void *element;
  int type;
  struct _DequeItem *next[NumberOfLinks];
} _DequeItem, *DequeItem;

typedef struct _Deque {
  struct _DequeItem *link[NumberOfLinks];
  int size;
} _Deque, *Deque;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
void DequeApply(Deque, DequeLinkTypes, ApplyFunction);
void DequeDispose(Deque, DisposeFunction);
void *DequeFind(Deque, void*, DequeLinkTypes, ComparisonFunction);
void *DequeGet(Deque, DequeLinkTypes);
void *DequeItemElement(DequeItem);
int DequeItemType(DequeItem);
Deque DequeNew(void);
DequeItem DequeNext(DequeItem, DequeLinkTypes);
void DequePut(Deque, void*, int, DequeLinkTypes);
void DequePutOnPriority(Deque, void*, int, DequeLinkTypes, ComparisonFunction);
DequeItem DequeSide(Deque, DequeLinkTypes);
int DequeSize(Deque);
#else
void DequeApply();
void DequeDispose();
void *DequeFind();
void *DequeGet();
void *DequeItemElement();
int DequeItemType();
Deque DequeNew();
DequeItem DequeNext();
void DequePut();
void DequePutOnPriority();
DequeItem DequeSide();
int DequeSize();
#endif /* __ANSI_C__ */

#endif /* DEQUE_H */
