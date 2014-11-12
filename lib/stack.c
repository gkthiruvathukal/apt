/******************************************************************
**
** STACK.C:
**
**    ADT Stack Implementation
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
#include "stack.h"

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE void StackDisposeItem(StackItem, DisposeFunction);
PRIVATE StackItem StackPopItem(Stack);
PRIVATE StackItem StackNewItem(void*, int);
PRIVATE void StackPushItem(Stack, StackItem);
#else
PRIVATE void StackDisposeItem();
PRIVATE StackItem StackPopItem();
PRIVATE StackItem StackNewItem();
PRIVATE void StackPushItem();
#endif

/* ---------- Functions */

/*
**
** StackApply
**
*/
PUBLIC
#ifdef __ANSI_C__
void StackApply(Stack s, ApplyFunction f)
#else
void StackApply(s,f)
Stack s;
ApplyFunction f;
#endif
{
  StackItem item;

  for (item = s->head; item != NULL; item = item->next) {
    (*f)(item->element);
  }
}

/*
**
** StackDispose
**
*/
PUBLIC 
#ifdef __ANSI_C__
void StackDispose(Stack s, DisposeFunction f)
#else
void StackDispose(s,f)
Stack s;
DisposeFunction f;
#endif
{
  StackItem item;
  StackItem next = NULL;

  for (item = s->head; item != NULL; item = next) {
    next = item->next;
    StackDisposeItem(item,f);
  }
  free(s);
}

/*
**
** StackDisposeItem
**
*/
PRIVATE
#ifdef __ANSI_C__
void StackDisposeItem(StackItem item, DisposeFunction f)
#else
void StackDisposeItem(item,f)
StackItem item;
DisposeFunction f;
#endif
{
  if (f) (*f)(item->element);
  free(item);
}

/*
**
** StackFind
**
*/
PUBLIC
#ifdef __ANSI_C__
void *StackFind(Stack s, void *element, ComparisonFunction f)
#else
void *StackFind(s,element,f)
Stack s;
void *element;
ComparisonFunction f;
#endif
{
  StackItem item;

  for (item = s->head; item != NULL; item = item->next) {
    if ((*f)(element,item->element) == 0) break;
  }
  return (item != NULL ? item->element : NULL);
}

/*
**
** StackHead
**
*/
PUBLIC
#ifdef __ANSI_C__
StackItem StackHead(Stack s)
#else
StackItem StackHead(s)
Stack s;
#endif
{
  return (s->head);
}

/*
**
** StackItemElement
**
*/
PUBLIC
#ifdef __ANSI_C__
void *StackItemElement(StackItem item)
#else
void *StackItemElement(item)
StackItem item;
#endif
{
  return (item->element);
}

/*
**
** StackItemType
**
*/
PUBLIC
#ifdef __ANSI_C__
int StackItemType(StackItem item)
#else
int StackItemType(item)
StackItem item;
#endif
{
  return (item->type);
}

/*
**
** StackLook
**
*/
PUBLIC
#ifdef __ANSI_C__
void *StackLook(Stack s)
#else
void *StackLook(s)
Stack s;
#endif
{
  StackItem item;

  item = s->head;
  return (item != NULL ? item->element : NULL);
}

/*
**
** StackNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Stack StackNew(void)
#else
Stack StackNew()
#endif
{
  Stack s;

  s = ((Stack)Allocate(sizeof(_Stack)));
  if (s) {
    s->head = s->tail = NULL;
    s->size = 0;
  }
  return (s);
}

/*
**
** StackNewItem
**
*/
PRIVATE
#ifdef __ANSI_C__
StackItem StackNewItem(void *element, int type)
#else
StackItem StackNewItem(element,type)
void *element;
int type;
#endif
{
  StackItem item;

  item = ((StackItem)Allocate(sizeof(_StackItem)));
  if (item) {
    item->element = element;
    item->type = type;
    item->next = NULL;
  }
  return (item);
}

/*
**
** StackNext
**
*/
PUBLIC
#ifdef __ANSI_C__
StackItem StackNext(StackItem item)
#else
StackItem StackNext(item)
StackItem item;
#endif
{
  return (item->next);
}

/*
**
** StackPop
**
*/
PUBLIC
#ifdef __ANSI_C__
void *StackPop(Stack s)
#else
void *StackPop(s)
Stack s;
#endif
{
  void *element;
  StackItem item;

  item = StackPopItem(s);
  if (item) {
    element = item->element;
    StackDisposeItem(item,NULL);
  }
  else element = NULL;
  return (element);
}

/*
**
** StackPopItem
**
*/
PRIVATE
#ifdef __ANSI_C__
StackItem StackPopItem(Stack s)
#else
StackItem StackPopItem(s)
Stack s;
#endif
{
  StackItem item;

  if (s->head) {
    item = s->head;
    s->head = s->head->next;
    s->size--;
  }
  else item = NULL;
  return (item);
}

/*
**
** StackPush
**
*/
PUBLIC
#ifdef __ANSI_C__
void StackPush(Stack s, void *element, int type)
#else
void StackPush(s,element,type)
Stack s;
void *element;
int type;
#endif
{
  StackItem item;

  item = StackNewItem(element,type);
  StackPushItem(s,item);
}

/*
**
** StackPushItem
**
*/
PRIVATE
#ifdef __ANSI_C__
void StackPushItem(Stack s, StackItem item)
#else
void StackPushItem(s,item)
Stack s;
StackItem item;
#endif
{
  if (s->head == NULL) {
    s->head = s->tail = item;
  } else {
    item->next = s->head;
    s->head = item;
  }
  s->size++;
}

/*
**
** StackPushOnPriority
**
*/
PUBLIC
#ifdef __ANSI_C__
void StackPushOnPriority(Stack s, void *element, int type,
                        ComparisonFunction f)
#else
void StackPushOnPriority(s,element,type,f)
Stack s;
void *element;
int type;
ComparisonFunction f;
#endif
{
  StackItem item;

  item = StackNewItem(element,type);
  if (f == NULL) StackPushItem(s,item);
  else {
    if (s->head == NULL) StackPushItem(s,item);
    else {
      StackItem p, lastp = NULL;
      for (p = s->head; p != NULL; p = p->next) {
        if ((*f)(element,p->element)) break;
        lastp = p;
      }
      if (p == s->head) {
        item->next = s->head;
        s->head = item;
      } else if (p == NULL) {
        s->tail->next = item;
        s->tail = s->tail->next;
      } else {
        item->next = p;
        lastp->next = item;
      }
      s->size++;
    }
  }
}

/*
**
** StackSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int StackSize(Stack s)
#else
int StackSize(s)
Stack s;
#endif
{
  return (s->size);
}

/*
**
** StackTail
**
*/
PUBLIC
#ifdef __ANSI_C__
StackItem StackTail(Stack s)
#else
StackItem StackTail(s)
Stack s;
#endif
{
  return (s->tail);
}

