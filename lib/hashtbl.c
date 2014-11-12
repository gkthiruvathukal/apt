/******************************************************************
**
** HASHTBL.C:
**
**    ADT Symbol Table Manager - Hash Table Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "adterror.h"
#include "allocate.h"
#include "queue.h"
#include "avltree.h"
#include "hashtbl.h"

/* ---------- Private Types */

typedef struct _HashTableElement {
  void *key;
  int tag;
  int type;
  union {
    void *dataPtr;
    Queue qPtr;
  } u;
} _HashTableElement, *HashTableElement;

/* ---------- Private Vars */
PUBLIC DisposeFunction elementDisposeFn;
PRIVATE ComparisonFunction currentHashCompareFunction;


/* ---------- Private Macros */

/* ---------- Private Prototypes */
#ifdef __ANSI_C__
PRIVATE int CompareKey(void *, void *);
PRIVATE void DisposeHashTableElement(void *);
PRIVATE void HashTableElementDispose(void *element);
#else
PRIVATE int CompareKey();
PRIVATE void DisposeHashTableElement();
PRIVATE void HashTableElementDispose();

#endif

/* ---------- Functions */

/*
**
** HashTableElementNew
**
*/
PRIVATE
#ifdef __ANSI_C__
HashTableElement HashTableElementNew(void *key, void *elementDataPtr, int type)
#else
HashTableElement HashTableElementNew(key,elementDataPtr,type)
void *key;
void *elementDataPtr;
int type;
#endif
{
  HashTableElement new = (HashTableElement)Allocate(sizeof(HashTableElement));
  if (new) {
    new->key = key;
    new->tag = OneToOne;
    new->type = type;
    new->u.dataPtr = elementDataPtr;
  }
  return new;
}


/*
**
** FindFirstItemWithTypeFromQueue
**
*/
PRIVATE 
#ifdef __ANSI_C__
void *FindFirstItemWithTypeFromQueue(Queue q, int type)
#else
void *FindFirstItemWithTypeFromQueue(q,type)
Queue q;
int type;
#endif
{

  QueueItem qItem;

  qItem = QueueHead(q);
  while (qItem && (QueueItemType(qItem) != type))
    qItem = QueueNext(qItem);
  if (qItem)
    return QueueItemElement(qItem);
  else
    return NULL;
}


/*
**
** FindThruBucketAVL
**
*/
PRIVATE
#ifdef __ANSI_C__
HashTableElement FindThruBucketAVL(HashTable table, void *key)
#else
HashTableElement FindThruBucketAVL(table, key)
HashTable table;
void *key;
#endif
{
  AVLTree t0;
  void *t1;
  HashTableElement r;

  currentHashCompareFunction = table->compare;

  t0 = table->bucket[(*table->hash)(key) % (table->size)];
  t1 = HashTableElementNew(key, NULL, DEFAULT_TYPE);
  r = AVLTreeFind(t0,t1,(ComparisonFunction)CompareKey);
  HashTableElementDispose(t1);
  return r;
}



PRIVATE 
#ifdef __ANSI_C__
void HashTableElementDispose(void *element)
#else
void HashTableElementDispose(element)
void *element;
#endif
{
  (*elementDisposeFn)(element);
}


PRIVATE
#ifdef __ANSI_C__
void QDisposeFnTyped(void *ptr)
#else
void QDisposeFnTyped(ptr)
void *ptr;
#endif
{
  free(ptr);
}




PUBLIC 
#ifdef __ANSI_C__
HashTable HashTableNew(int size, HashFunction hash, ComparisonFunction compare,
HashTable scopeLink)
#else
HashTable HashTableNew(size, hash, compare, scopeLink)
int size;
HashFunction hash;
ComparisonFunction compare;
HashTable scopeLink;
#endif
{
  HashTable newPtr = (HashTable) Allocate(sizeof(HashTable));

  if (newPtr) {
    newPtr->size = size;
    newPtr->hash = hash;
    newPtr->compare = compare;
    newPtr->dispose = DisposeHashTableElement;
    ;
    newPtr->scopeLink = scopeLink;
    if (size > 0) {
      if (newPtr->bucket = (AVLTree *) Allocate(size * sizeof(AVLTree)))
      {
        while (size-- > 0)
          if (!(newPtr->bucket[size] = AVLTreeNew())) return NULL;
      }
      else 
        return NULL;
    }
  }
  return newPtr;
}


PUBLIC
#ifdef __ANSI_C__
void HashTableDispose(HashTable ptr)
#else
void HashTableDispose(ptr)
HashTable ptr;
#endif
{
  int i;

  if (ptr) {
    i = ptr->size;
    elementDisposeFn = ptr->dispose;
    while (i-- > 0) AVLTreeDispose(ptr->bucket[i], 
        HashTableElementDispose);
#if 0
    free(ptr->hash);
    free(ptr->compare);
    free(ptr->dispose);
#endif
    ptr = ptr->scopeLink;
  }
}


PUBLIC
#ifdef __ANSI_C__
HashTable HashTableGetScopeLink(HashTable table)
#else
HashTable HashTableGetScopeLink(table)
HashTable table;
#endif
{
  return table->scopeLink;
}


PUBLIC 
#ifdef __ANSI_C__
void *HashTableLookUpFirst(HashTable table, void *key)
#else
void *HashTableLookUpFirst(table, key)
HashTable table;
void *key;
#endif
{
  HashTableElement itemPtr;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if (itemPtr->tag == OneToOne)
      return itemPtr->u.dataPtr;
    else
      return QueueLook(itemPtr->u.qPtr);
  }
  else
    return NULL;
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableLookUpTypedFirst(HashTable table, void *key, int type)
#else
void *HashTableLookUpTypedFirst(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  HashTableElement itemPtr;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if (itemPtr->tag == OneToOne) {
      if (itemPtr->type == type)
        return itemPtr->u.dataPtr;
      else 
        return NULL;
    }
    else
      return FindFirstItemWithTypeFromQueue(itemPtr->u.qPtr, type);
  }
  else
    return NULL;
}


PUBLIC
#ifdef __ANSI_C__
Queue HashTableLookUpAll(HashTable table, void *key)
#else
Queue HashTableLookUpAll(table, key)
HashTable table;
void *key;
#endif
{
  Queue ptrToQueue;
  HashTableElement itemPtr;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if (itemPtr->tag == OneToOne) {
      ptrToQueue = QueueNew();
      QueuePut(ptrToQueue, itemPtr->u.dataPtr, itemPtr->type);
      return ptrToQueue;
    }
    else
      return itemPtr->u.qPtr;
  }
  else
    return NULL;
}


PUBLIC
#ifdef __ANSI_C__
Queue HashTableLookUpTypedAll(HashTable table, void *key, int type)
#else
Queue HashTableLookUpTypedAll(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  Queue ptrToQueue;
  QueueItem qItem;
  HashTableElement itemPtr;
  int i;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if (itemPtr->tag == OneToOne) {
      if (itemPtr->type == type) {
        ptrToQueue = QueueNew();
        QueuePut(ptrToQueue, itemPtr->u.dataPtr, itemPtr->type);
      }
      else
        return NULL;
    }
    else {
      ptrToQueue = QueueNew();
      qItem = QueueHead(itemPtr->u.qPtr);
      for (i=0; i < QueueSize(itemPtr->u.qPtr); i++) {
        if (QueueItemType(qItem) == type)
          QueuePut(ptrToQueue, QueueItemElement(qItem),
              QueueItemType(qItem));
        qItem = QueueNext(qItem);
      }
      if (QueueSize(ptrToQueue) > 0)
        return ptrToQueue;
      else
        return NULL;
    }
  }
  else
    return NULL;
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableLookUpFirstScoped(HashTable table, void *key)
#else
void *HashTableLookUpFirstScoped(table, key)
HashTable table;
void *key;
#endif
{
  void *ptr;
  HashTable scopePtr = table;

  while (((ptr = HashTableLookUpFirst(scopePtr, key)) == NULL) &&
      ((scopePtr = HashTableGetScopeLink(scopePtr)) != NULL));
  return ptr;
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableLookUpTypedFirstScoped(HashTable table, void *key, int type)
#else
void *HashTableLookUpTypedFirstScoped(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  void *ptr;
  HashTable scopePtr = table;

  while (((ptr = HashTableLookUpTypedFirst(scopePtr, key, type)) == NULL)
      && ((scopePtr = HashTableGetScopeLink(scopePtr)) != NULL));
  return ptr;
}


PUBLIC
#ifdef __ANSI_C__
Queue HashTableLookUpAllScoped(HashTable table, void *key)
#else
Queue HashTableLookUpAllScoped(table, key)
HashTable table;
void *key;
#endif
{
  Queue ptr;
  HashTable scopePtr = table;

  while (((ptr = HashTableLookUpAll(scopePtr, key)) == NULL) &&
      ((scopePtr = HashTableGetScopeLink(scopePtr)) != NULL));
  return ptr;
}


PUBLIC
#ifdef __ANSI_C__
Queue HashTableLookUpTypedAllScoped(HashTable table, void *key, int type)
#else
Queue HashTableLookUpTypedAllScoped(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  Queue ptr;
  HashTable scopePtr = table;

  while (((ptr = HashTableLookUpTypedAll(scopePtr, key, type))
      == NULL) &&
      ((scopePtr = HashTableGetScopeLink(scopePtr)) != NULL));
  return ptr;
}


PRIVATE
#ifdef __ANSI_C__
int CompareKey(void *rec1, void *rec2)
#else
int CompareKey(rec1, rec2)
void *rec1, *rec2;
#endif
{
  HashTableElement h1, h2;

  h1 = (HashTableElement) rec1;
  h2 = (HashTableElement) rec2;
  return (*currentHashCompareFunction)(h1->key, h2->key);
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableInsertTyped(HashTable table,void *key,void *value,int type)
#else
void *HashTableInsertTyped(table,key,value,type)
HashTable table;
void *key;
void *value;
int type;
#endif
{
  void *tempDataPtr;
  HashTableElement itemPtr, newItemPtr;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if (itemPtr->tag == OneToMany)
      QueuePut(itemPtr->u.qPtr, value, type);
    else {
      tempDataPtr = itemPtr->u.dataPtr;
      itemPtr->tag = OneToMany;
      itemPtr->u.qPtr = QueueNew();
      QueuePut(itemPtr->u.qPtr, tempDataPtr, itemPtr->type);
      QueuePut(itemPtr->u.qPtr, value, type);
    }
    return itemPtr;
  }
  else {
    currentHashCompareFunction = table->compare;
    newItemPtr = HashTableElementNew(key, value, type);
    AVLTreeInsert(table->bucket[(*(table->hash))(key) %
                                                (table->size)],
        newItemPtr,
        type,
        (ComparisonFunction)CompareKey);
    return newItemPtr;
  }
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableInsert(HashTable table, void *key, void *value)
#else
void *HashTableInsert(table, key, value)
HashTable table;
void *key;
void *value;
#endif
{
  return HashTableInsertTyped(table, key, value, DEFAULT_TYPE);
}


PUBLIC
#ifdef __ANSI_C__
void *HashTableDeleteTypedFirst(HashTable table, void *key, int type)
#else
void *HashTableDeleteTypedFirst(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  HashTableElement itemPtr;
  void *ptrToData;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    if ((itemPtr->tag == OneToOne) && (itemPtr->type == type)) {
      ptrToData = itemPtr->u.dataPtr;
      currentHashCompareFunction = table->compare;
      elementDisposeFn = table->dispose;
      AVLTreeDelete(table->bucket[(*table->hash)(key) %
                                            table->size],

          HashTableElementNew(key, NULL, type),         
          CompareKey, HashTableElementDispose);
      return ptrToData;
    }
    else if (itemPtr->tag == OneToMany) {
      ptrToData = QueueFindAndRemoveType(itemPtr->u.qPtr, NULL, NULL, type);
      if (QueueSize(itemPtr->u.qPtr) <2) {
        itemPtr->tag = OneToOne;
        itemPtr->u.dataPtr = QueueLook(itemPtr->u.qPtr);
        itemPtr->type = QueueItemType(QueueHead(itemPtr->u.qPtr));
      }
      return ptrToData;
    }
    else
      return NULL;
  }
  else
    return NULL;
}

PUBLIC
#ifdef __ANSI_C__
Queue HashTableDeleteTypedAll(HashTable table, void *key, int type)
#else
Queue HashTableDeleteTypedAll(table, key, type)
HashTable table;
void *key;
int type;
#endif
{
  HashTableElement itemPtr;
  Queue ptrToQueue, ptrToDeletedQueue;
  QueueItem qItem;
  int i;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    ptrToDeletedQueue = QueueNew();
    if ((itemPtr->tag == OneToOne) && (itemPtr->type == type)) {
      QueuePut(ptrToDeletedQueue, itemPtr->u.dataPtr, type);
      currentHashCompareFunction = table->compare;
      elementDisposeFn = table->dispose;
      AVLTreeDelete(table->bucket[(*table->hash)(key) %
                                            table->size],
          HashTableElementNew(key, NULL, type),
          CompareKey, HashTableElementDispose);
    }
    else if (itemPtr->tag == OneToMany) {
      ptrToQueue = QueueNew();
      qItem = QueueHead(itemPtr->u.qPtr);
      for (i = 0; i < QueueSize(itemPtr->u.qPtr); i++) {
        if (QueueItemType(qItem) != type)
          QueuePut(ptrToQueue, QueueItemElement(qItem),
              QueueItemType(qItem));
        else
          QueuePut(ptrToDeletedQueue, QueueItemElement(qItem), 
              QueueItemType(qItem));
        qItem = QueueNext(qItem);
      }
      QueueDispose(itemPtr->u.qPtr, (DisposeFunction)QDisposeFnTyped);
      if (QueueSize(ptrToQueue) < 2) {
        itemPtr->tag = OneToOne;
        itemPtr->u.dataPtr = QueueLook(ptrToQueue);
        itemPtr->type = QueueItemType(QueueHead(ptrToQueue));
      }
      else {
        itemPtr->u.qPtr = ptrToQueue;
      }
    }
    return ptrToDeletedQueue;
  }
  else
    return NULL;
}




PUBLIC 
#ifdef __ANSI_C__
Queue HashTableDelete(HashTable table, void *key)
#else
Queue HashTableDelete(table, key)
HashTable table;
void *key;
#endif
{
  return HashTableDeleteTypedAll(table, key, DEFAULT_TYPE);
}


PUBLIC
#ifdef __ANSI_C__
Queue HashTableDeleteAll(HashTable table, void *key)
#else
Queue HashTableDeleteAll(table, key)
HashTable table;
void *key;
#endif
{
  HashTableElement itemPtr;
  Queue ptrToQueue;
  QueueItem qItem;
  int i;

  itemPtr = FindThruBucketAVL(table, key);
  if (itemPtr) {
    ptrToQueue = QueueNew();
    if (itemPtr->tag == OneToOne)
      QueuePut(ptrToQueue, itemPtr->u.dataPtr, itemPtr->type);
    else {
      qItem = QueueHead(itemPtr->u.qPtr);
      for (i = 1; i < QueueSize(itemPtr->u.qPtr); i++) {
        QueuePut(ptrToQueue, QueueItemElement(qItem), QueueItemType(qItem));
        qItem = QueueNext(qItem);
      }
    }
    currentHashCompareFunction = table->compare;
    elementDisposeFn = table->dispose;
    AVLTreeDelete(table->bucket[(*table->hash)(key) %
                                         table->size],
        HashTableElementNew(key, NULL, 
        DEFAULT_TYPE),
        CompareKey, HashTableElementDispose);
    return ptrToQueue;
  }
  else
    return NULL;
}


PUBLIC 
#ifdef __ANSI_C__
int CompareStrings(void *s1, void *s2)
#else
int CompareStrings(s1,s2)
void *s1, *s2;
#endif
{
  char *st1, *st2;

  st1 = (char *)s1;
  st2 = (char *)s2;
  return strcmp(st1, st2);
}


PUBLIC 
#ifdef __ANSI_C__
long int StringHash1(void *s)
#else
long int StringHash1(s)
void *s;
#endif
{
  char *st;
  long int hashval;

  st = (char *)s;
  for (hashval=0; *st != '\0'; st++)
    hashval = *st + 31*hashval;
  return hashval;
}


PRIVATE
#ifdef __ANSI_C__
void DisposeQueueElement(void *element)
#else
void DisposeQueueElement(element)
void *element;
#endif
{
  free(element);
}

PRIVATE
#ifdef __ANSI_C__
void DisposeHashTableElement(void *element)
#else
void DisposeHashTableElement(element)
void *element;
#endif
{
  HashTableElement ptr = element;

  if (ptr) {
    if (ptr->tag == OneToMany)
      QueueDispose(ptr->u.qPtr, NULL);
    free(ptr);
  }
}
