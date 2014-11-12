/******************************************************************
**
** AVLTBL.C:
**
**    ADT Symbol Table Manager
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
#include "avltbl.h"
#include "avltree.h"
#include "sstring.h"

/* ---------- Private Macros */

#define HasQueue(item) ((item)->type == AVLTableQueueCode)

/* ---------- Private Prototypes */

#ifdef __ANSI_C__
PRIVATE void AVLTableItemDispose(AVLTableItem);
PRIVATE AVLTableItem AVLTableItemNew(char*,void*,enum ValueTags);
PRIVATE void AVLTableItemUpdate(AVLTableItem,void*,enum ValueTags);
PRIVATE int CompareOnKeyField(AVLTableItem,AVLTableItem);
#else
PRIVATE void AVLTableItemDispose();
PRIVATE AVLTableItem AVLTableItemNew();
PRIVATE void AVLTableItemUpdate();
PRIVATE int CompareOnKeyField();
#endif

/* ---------- Functions */

/*
**
** AVLTableFind
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTableFind(AVLTable table, char *key, int type)
#else
void *AVLTableFind(table,key,type)
AVLTable table;
char *key;
int type;
#endif
{
  AVLTableItem entry;
  _AVLTableItem find;

  if (table == NULL || key == NULL) return (NULL);
  find.key = key;
  entry = AVLTreeFind(table->Space,&find,(ComparisonFunction)CompareOnKeyField);
  if (entry == NULL) return (NULL);
  if (HasQueue(entry)) return (QueueFindType(entry->element,type));
  else return (entry->element);
}

/*
**
** AVLTableFindAll
**
*/
PUBLIC
#ifdef __ANSI_C__
Queue AVLTableFindAll(AVLTable table, char *key)
#else
Queue AVLTableFindAll(table,key)
AVLTable table;
char *key;
#endif
{
  AVLTableItem entry;
  _AVLTableItem find;

  if (table == NULL || key == NULL) return (NULL);
  find.key = key;
  entry = AVLTreeFind(table->Space,&find,(ComparisonFunction)CompareOnKeyField);
  if (entry == NULL) return (NULL);
  if (HasQueue(entry)) return (entry->element);
  else {
    Queue q = QueueNew();
    QueuePut(q,entry->element,entry->type);
    return (q);
  }
}

/*
**
** AVLTableGet
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTableGet(AVLTable table, char *key, int type)
#else
void *AVLTableGet(table,key,type)
AVLTable table;
char *key;
int type;
#endif
{
  AVLTableItem entry;
  _AVLTableItem find;
  void *element;

  if (table == NULL || key == NULL) return (NULL);
  find.key = key;
  entry = AVLTreeFind(table->Space,&find,(ComparisonFunction)CompareOnKeyField);
  if (entry == NULL) return (NULL);
  if (HasQueue(entry))
    return (QueueFindTypeAndRemove(entry->element,type));
  else {
    if (entry->type != type) return (NULL);
    element = entry->element;
    AVLTreeDelete(table->Space,&find,(ComparisonFunction)CompareOnKeyField,
      (DisposeFunction)AVLTableItemDispose);
    return (element);
  }
}

/*
**
** AVLTableGetAll
**
*/
PUBLIC
#ifdef __ANSI_C__
Queue AVLTableGetAll(AVLTable table, char *key)
#else
Queue AVLTableGetAll(table,key)
AVLTable table;
char *key;
#endif
{
  void *element;
  AVLTableItem entry;
  _AVLTableItem find;

  if (table == NULL || key == NULL) return (NULL);
  find.key = key;
  entry = AVLTreeFind(table->Space,&find,(ComparisonFunction)CompareOnKeyField);
  if (entry == NULL) return (NULL);
  if (HasQueue(entry)) element = entry->element;
  else {
    Queue q = QueueNew();
    QueuePut(q,entry->element,entry->type);
    element = q;
  }
  AVLTreeDelete(table->Space,&find,(ComparisonFunction)CompareOnKeyField,
    (DisposeFunction)AVLTableItemDispose);
  return element;
}

/*
**
** AVLTableItemDispose
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTableItemDispose(AVLTableItem item)
#else
void AVLTableItemDispose(item)
AVLTableItem item;
#endif
{
  if (item == NULL) return;
  if (HasQueue(item)) QueueDispose(item->element,NULL);
  free(item);
}

/*
**
** AVLTableItemNew
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTableItem AVLTableItemNew(char *key, void *element, enum ValueTags type)
#else
AVLTableItem AVLTableItemNew(key,element,type)
char *key;
void *element;
enum ValueTags type;
#endif
{
  AVLTableItem newItem = (AVLTableItem)Allocate(sizeof(_AVLTableItem));
  if (newItem) {
    newItem->key = key;
    newItem->element = element;
    newItem->type = type;
  }
  return (newItem);
}

/*
**
** AVLTableNew
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTable AVLTableNew(AVLTable ScopeLink)
#else
AVLTable AVLTableNew(ScopeLink)
AVLTable ScopeLink;
#endif
{
  AVLTable newAVLTable = (AVLTable)Allocate(sizeof(_AVLTable));
  if (newAVLTable) {
    newAVLTable->ScopeLink = ScopeLink;
    newAVLTable->Space = AVLTreeNew();
  }
  return (newAVLTable);
}

/*
**
** AVLTableScopeLink
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTable AVLTableScopeLink(AVLTable Table)
#else
AVLTable AVLTableScopeLink(Table)
AVLTable Table;
#endif
{
  return Table->ScopeLink;
}

/*
**
** AVLTableItemUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTableItemUpdate(AVLTableItem item, void *element, enum ValueTags type)
#else
void AVLTableItemUpdate(item,element,type)
AVLTableItem item;
void *element;
enum ValueTags type;
#endif
{
  if (item == NULL) return;
  if (HasQueue(item)) QueuePut(item->element,element,type);
  else {
    Queue q = QueueNew();
    QueuePut(q,item->element,item->type);
    QueuePut(q,element,type);
    item->element = q;
    item->type = AVLTableQueueCode;
  }
}

/*
**
** AVLTablePut
**
*/
PUBLIC
#ifdef __ANSI_C__
void AVLTablePut(AVLTable table, char *key, void *info, enum ValueTags type)
#else
void AVLTablePut(table,key,info,type)
AVLTable table;
char *key;
void *info;
int type;
#endif
{
  AVLTableItem entry;
  _AVLTableItem find;

  if (table == NULL || key == NULL) return;
  find.key = key;
  entry = AVLTreeFind(table->Space,&find,(ComparisonFunction)CompareOnKeyField);
  if (entry != NULL) AVLTableItemUpdate(entry,info,type);
  else {
    entry = AVLTableItemNew(key,info,type);
    AVLTreeInsert(table->Space,entry,0,(ComparisonFunction)CompareOnKeyField);
  }
}

/*
**
** CompareOnKeyField
**
*/
PRIVATE
#ifdef __ANSI_C__
int CompareOnKeyField(AVLTableItem e1, AVLTableItem e2)
#else
int CompareOnKeyField(e1,e2)
AVLTableItem e1;
AVLTableItem e2;
#endif
{
  return (StringCompare(e1->key,e2->key));
}
