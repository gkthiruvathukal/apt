/******************************************************************
**
** HASHTBL.H:
**
**    ADT Symbol Table Manager - Hash Table Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/
#ifndef HASHTBL_H
#define HASHTBL_H

/* ---------- Headers */
#include "queue.h"


/* ---------- Defines */

#define OneToOne 1
#define OneToMany 2
#define DEFAULT_TYPE 30000


/* ---------- Types */
#ifdef __ANSI_C__
typedef long int (*HashFunction) (void *);
#else
typedef long int (*HashFunction) ();

#endif

typedef struct _HashTable {
  int size;
  HashFunction hash;
  ComparisonFunction compare;
  DisposeFunction dispose;
  AVLTree *bucket;
  struct _HashTable *scopeLink;
} _HashTable, *HashTable;

/* ---------- Prototypes */

#ifdef __ANSI_C__

int CompareStrings(void *, void *);
long int StringHash1(void *);
HashTable HashTableNew(int,HashFunction,ComparisonFunction,HashTable);
HashTable HashTableGetScopeLink(HashTable);
void HashTableDispose(HashTable);
void *HashTableLookUpFirst(HashTable, void *);
void *HashTableLookUpFirstScoped(HashTable, void *);
void *HashTableLookUpTypedFirst(HashTable, void *, int);
void *HashTableLookUpTypedFirstScoped(HashTable, void *, int);
Queue HashTableLookUpAll(HashTable, void *);
Queue HashTableLookUpAllScoped(HashTable, void *);
Queue HashTableLookUpTypedAll(HashTable, void *, int);
Queue HashTableLookUpTypedAllScoped(HashTable, void *, int);
void *HashTableInsert(HashTable, void *, void *);
void *HashTableInsertTyped(HashTable, void *, void *, int);
void *HashTableDeleteFirst(HashTable, void *);
void *HashTableDeleteTypedFirst(HashTable, void *, int);
Queue HashTableDeleteTypedAll(HashTable, void *, int);
Queue HashTableDeleteAll(HashTable, void *);

#else

int CompareStrings();
long int StringHash1();
HashTable HashTableNew();
HashTable HashTableGetScopeLink();
void HashTableDispose();
void *HashTableLookUpFirst();
void *HashTableLookUpFirstScoped();
void *HashTableLookUpTypedFirst();
void *HashTableLookUpTypedFirstScoped();
Queue HashTableLookUpAll();
Queue HashTableLookUpAllScoped();
Queue HashTableLookUpTypedAll();
Queue HashTableLookUpTypedAllScoped();
void *HashTableInsert();
void *HashTableInsertTyped();
void *HashTableDeleteFirst();
void *HashTableDeleteTypedFirst();
Queue HashTableDeleteTypedAll();
Queue HashTableDeleteAll();

#endif /* __ANSI_C__ */

#endif /* HASHTBL_H */


