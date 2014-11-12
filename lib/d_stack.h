/******************************************************************
**
** D_STACK.H:
**
**    ADT Deques as Stacks Macros
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef D_STACK_H
#define D_STACK_H

/* ---------- Headers */

#include "apt.h"
#include "deque.h"

/* ---------- Exported Types */

typedef struct _DequeItem _StackItem, *StackItem;
typedef struct _Deque _Stack, *Stack;

/* ---------- Translation Macros */

#define StackApply(q,f) DequeApply(q,Top,f)

#define StackDispose(q,f) DequeDispose(q,f)

#define StackDisposeItem(item,f) DequeDisposeItem(item,f)

#define StackFind(q,element,f) DequeFind(q,element,Top,f)

#define StackHead(q) DequeSide(q,Top)

#define StackItemElement(item) DequeItemElement(item)

#define StackItemType(item) DequeItemType(item)

#define StackNew() DequeNew()

#define StackNewItem(element,type) DequeNewItem(element,type)

#define StackNext(item,Top) DequeNext(item,Top)

#define StackPop(q) DequeGet(q,Top)

#define StackPopItem(q) DequeGetItem(q,Top)

#define StackPush(q,element,type) DequePut(q,element,type,Top)

#define StackPushItem(q,item) DequePut(q,item,Top)

#define StackPutOnPriority(q,element,type,f) \
        DequePutOnPriority(q,element,type,Bottom,f)

#define StackSize(q) DequeSize(q)

#define StackTail(q) DequeSide(q,Bottom)

#endif /* D_STACK_H */
