/******************************************************************
**
** D_QUEUE.H:
**
**    ADT Deques as Queues Macros 
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef D_QUEUE_H
#define D_QUEUE_H

/* ---------- Headers */

#include "apt.h"
#include "deque.h"

/* ---------- Exported Types */

typedef struct _DequeItem _QueueItem, *QueueItem;

typedef struct _Deque _Queue, *Queue;

/* ---------- Translation Macros */

#define QueueApply(q,f) DequeApply(q,Top,f)

#define QueueDispose(q,f) DequeDispose(q,f)

#define QueueDisposeItem(item,f) DequeDisposeItem(item,f)

#define QueueFind(q,element,f) DequeFind(q,element,Top,f)

#define QueueGet(q) DequeGet(q,Top)

#define QueueGetItem(q) DequeGetItem(q,Top)

#define QueueHead(q) DequeSide(q,Top)

#define QueueItemElement(item) DequeItemElement(item)

#define QueueItemType(item) DequeItemType(item)

#define QueueNew() DequeNew()

#define QueueNewItem(element,type) DequeNewItem(element,type)

#define QueueNext(item) DequeNext(item,Top)

#define QueuePut(q,element,type) DequePut(q,element,type,Bottom)

#define QueuePutItem(q,item) DequePutItem(q,item,Bottom)

#define QueuePutOnPriority(q,element,type,f) \
        DequePutOnPriority(q,element,type,Top,f)

#define QueueSize(q) DequeSize(q)

#define QueueTail(q) DequeSide(q,Bottom)

#endif /* D_QUEUE_H */
