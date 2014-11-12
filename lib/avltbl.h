/******************************************************************
**
** AVLTBL.H:
**
**    ADT Symbol Table Manager
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef AVLTBL_H
#define AVLTBL_H

/* ---------- Headers */

#include "apt.h"
#include "avltree.h"
#include "queue.h"

/* ---------- Defines */

#define AVLTableQueueCode (-1)
enum ValueTags { V_Queue, V_Void };

/* ---------- Types */

typedef struct _AVLTable {
  struct _AVLTable *ScopeLink;
  AVLTree Space;
} _AVLTable, *AVLTable;
 
typedef struct _AVLTableItem {
  char *key;
  void *element;
  int type;
} _AVLTableItem, *AVLTableItem;

/* ---------- Prototypes */

#ifdef __ANSI_C__
void *AVLTableFind(AVLTable,char*,int);
Queue AVLTableFindAll(AVLTable,char*);
void *AVLTableGet(AVLTable,char*,int);
Queue AVLTableGetAll(AVLTable,char*);
AVLTable AVLTableNew(AVLTable);
void AVLTablePut(AVLTable,char*,void*,enum ValueTags);
AVLTable AVLTableScopeLink(AVLTable);
#else
void *AVLTableFind();
Queue AVLTableFindAll();
void *AVLTableGet();
Queue AVLTableGetAll();
AVLTable AVLTableNew();
void AVLTablePut();
AVLTable AVLTableScopeLink();
#endif /* __ANSI_C__ */

#endif /* AVLTBL_H */
