/******************************************************************
**
** DEQUE.C:
**
**    ADT Deque Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "allocate.h"
#include "deque.h"

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE void DequeDisposeItem(DequeItem, DisposeFunction);
PRIVATE DequeItem DequeGetItem(Deque, DequeLinkTypes);
PRIVATE DequeItem DequeNewItem(void*, int);
PRIVATE void DequePutItem(Deque, DequeItem, DequeLinkTypes);
#else
PRIVATE void DequeDisposeItem();
PRIVATE DequeItem DequeGetItem();
PRIVATE DequeItem DequeNewItem();
PRIVATE void DequePutItem();
#endif

/* ---------- Functions */

/*
**
** DequeApply
**
*/
PUBLIC
#ifdef __ANSI_C__
void DequeApply(Deque q, DequeLinkTypes side, ApplyFunction f)
#else
void DequeApply(q,side,f)
Deque q;
DequeLinkTypes side;
ApplyFunction f;
#endif
{
  DequeItem item;
 
  if (q && f) {
    if (side <= NoLink || side >= NumberOfLinks) return;
    for (item = q->link[side]; item != NULL; item = item->next[side]) {
      (*f)(item->element);
    }
  }
}

/*
**
** DequeDispose
**
*/
PUBLIC
#ifdef __ANSI_C__
void DequeDispose(Deque q, DisposeFunction f)
#else
void DequeDispose(q,f)
Deque q;
DisposeFunction f;
#endif
{
  DequeItem item;
  DequeItem next = NULL;

  if (q) {
    for (item = q->link[Top]; item != NULL; item = next) {
      next = item->next[Top];
      DequeDisposeItem(item,f);
    }
    free(q);
  }
}

/*
**
** DequeDisposeItem
**
*/
PRIVATE
#ifdef __ANSI_C__
void DequeDisposeItem(DequeItem item, DisposeFunction f)
#else
void DequeDisposeItem(item,f)
DequeItem item;
DisposeFunction f;
#endif
{
  if (item) {
    if (f) (*f)(item->element);
    free(item);
  }
}

/*
**
** DequeFind
**
*/
PUBLIC
#ifdef __ANSI_C__
void *DequeFind(Deque q, void *element, DequeLinkTypes side,
                ComparisonFunction f)
#else
void *DequeFind(q,element,side,f)
Deque q;
void *element;
DequeLinkTypes side;
ComparisonFunction f;
#endif
{
  DequeItem item;

  if (q) {
    if (side <= NoLink || side >= NumberOfLinks) return (NULL);
    for (item = q->link[side]; item != NULL; item = item->next[side]) {
      if ((*f)(element,item->element) == 0) break;
    }
    if (item) return (item->element);
  }
  return (NULL);
}

/*
**
** DequeGet
**
*/
PUBLIC
#ifdef __ANSI_C__
void *DequeGet(Deque q, DequeLinkTypes side)
#else
void *DequeGet(q,side)
Deque q;
DequeLinkTypes side;
#endif
{
  void *element;
  DequeItem item;

  item = DequeGetItem(q,side);
  if (item) {
    element = item->element;
    DequeDisposeItem(item,NULL);
  }
  else element = NULL;
  return (element);
}

/*
**
** DequeGetItem
**
*/
PRIVATE
#ifdef __ANSI_C__
DequeItem DequeGetItem(Deque q, DequeLinkTypes side)
#else
DequeItem DequeGetItem(q,side)
Deque q;
DequeLinkTypes side;
#endif
{
  DequeItem item;

  if (side <= NoLink || side >= NumberOfLinks) return (NULL);
  if (q->link[side]) {
    item = q->link[side];
    if (q->link[side] == q->link[1-side])
      q->link[side] = q->link[1-side] = NULL;
    else q->link[side] = q->link[side]->next[side];
    q->size--;
  }
  else item = NULL;
  return (item);
}

/*
**
** DequeItemElement
**
*/
PUBLIC
#ifdef __ANSI_C__
void *DequeItemElement(DequeItem item)
#else
void *DequeItemElement(item)
DequeItem item;
#endif
{
  return (item->element);
}

/*
**
** DequeItemType
**
*/
PUBLIC
#ifdef __ANSI_C__
int DequeItemType(DequeItem item)
#else
int DequeItemType(item)
DequeItem item;
#endif
{
  return (item->type);
}

/*
**
** DequeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Deque DequeNew(void)
#else
Deque DequeNew()
#endif
{
  Deque q;
  int side;

  q = ((Deque)Allocate(sizeof(_Deque)));
  if (q) {
    for (side = 0; side < NumberOfLinks; side++) q->link[side] = NULL;
    q->size = 0;
  }
  return (q);
}

/*
**
** DequeNewItem
**
*/
PRIVATE
#ifdef __ANSI_C__
DequeItem DequeNewItem(void *element, int type)
#else
DequeItem DequeNewItem(element,type)
void *element;
int type;
#endif
{
  DequeItem item;
  int side;

  item = ((DequeItem)Allocate(sizeof(_DequeItem)));
  if (item) {
    item->element = element;
    item->type = type;
    for (side = 0; side < NumberOfLinks; side++) item->next[side] = NULL;
  }
  return (item);
}

/*
**
** DequeNext
**
*/
PUBLIC
#ifdef __ANSI_C__
DequeItem DequeNext(DequeItem item, DequeLinkTypes side)
#else
DequeItem DequeNext(item,side)
DequeItem item;
DequeLinkTypes side;
#endif
{
  if (side <= NoLink || side >= NumberOfLinks) return (NULL);
  return (item->next[side]);
}

/*
**
** DequePut
**
*/
PUBLIC
#ifdef __ANSI_C__
void DequePut(Deque q, void *element, int type, DequeLinkTypes side)
#else
void DequePut(q,element,type,side)
Deque q;
void *element;
int type;
DequeLinkTypes side;
#endif
{
  DequeItem item;

  if (side <= NoLink || side >= NumberOfLinks) return;
  item = DequeNewItem(element,type);
  DequePutItem(q,item,side);
}

/*
**
** DequePutItem
**
*/
PRIVATE
#ifdef __ANSI_C__
void DequePutItem(Deque q, DequeItem item, DequeLinkTypes side)
#else
void DequePutItem(q,item,side)
Deque q;
DequeItem item;
DequeLinkTypes side;
#endif
{
  if (side <= NoLink || side >= NumberOfLinks) return;
  if (q->link[side] == NULL) {
    q->link[side] = q->link[1-side] = item;
  } else {
    q->link[side]->next[1-side] = item;
    q->link[side]->next[1-side]->next[side] = q->link[side];
    q->link[side] = q->link[side]->next[1-side];
  }
  q->size++;
}

/*
**
** DequePutOnPriority
**
*/
PUBLIC
#ifdef __ANSI_C__
void DequePutOnPriority(Deque q, void *element, int type,
                        DequeLinkTypes side, ComparisonFunction f)
#else
void DequePutOnPriority(q,element,type,side,f)
Deque q;
void *element;
int type;
DequeLinkTypes side;
ComparisonFunction f;
#endif
{
  DequeItem item;

  if (side <= NoLink || side >= NumberOfLinks) return;
  item = DequeNewItem(element,type);
  if (f == NULL) DequePutItem(q,item,side);
  else {
    if (q->link[side] == NULL) DequePutItem(q,item,side);
    else {
      DequeItem p, lastp = NULL;
      for (p = q->link[side]; p != NULL; p=p->next[side]) {
        if ((*f)(element,p->element)) break;
        lastp = p;
      }
      if (p == q->link[side]) {
        q->link[side]->next[1-side] = item;
        item->next[side] = q->link[side];
        q->link[side] = item;
      } else if (p == NULL) {
        item->next[1-side] = q->link[1-side];
        q->link[1-side]->next[side] = item;
        q->link[1-side] = item;
      } else {
        item->next[side] = p;
        item->next[1-side] = lastp;
        p->next[1-side] = item;
        lastp->next[side] = item;
      }
      q->size++;
    }
  }
}

/*
**
** DequeSide
**
*/
PUBLIC
#ifdef __ANSI_C__
DequeItem DequeSide(Deque q, DequeLinkTypes side)
#else
DequeItem DequeSide(q,side)
Deque q;
DequeLinkTypes side;
#endif
{
  if (side <= NoLink || side >= NumberOfLinks) return (NULL);
  return (q->link[side]);
}

/*
**
** DequeSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int DequeSize(Deque q)
#else
int DequeSize(q)
Deque q;
#endif
{
  return (q->size);
}

