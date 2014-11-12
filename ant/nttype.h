/******************************************************************
**
** NTTYPE.H:
**
**    NT Type Declaractions
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef NTTYPE_H
#define NTTYPE_H

/* ---------- Headers */

#include "apt.h"
#include "asttype.h"
#include "queue.h"

/* ---------- Types */

typedef struct _Decl {
  int nullFlg;
  Queue specs;
  Queue ptrs;
  Token name;
  Queue arrays;
} _Decl, *Decl;

typedef struct _Enum {
  Token name;
  Queue tags;
} _Enum, *Enum;

typedef struct _Node {
  Token name;
  Queue slots;
  Queue decls;
} _Node, *Node;

typedef struct _Slot {
  Token name;
  Queue decls;
} _Slot, *Slot;

/* ----------- Prototypes */

#ifdef __ANSI_C__
Decl DeclNew(Token,Queue,Queue,Token,Queue);
Enum EnumNew(Token,Queue);
Node NodeNew(Token,Queue,Queue);
Slot SlotNew(Token,Queue);
#else
Decl DeclNew();
Enum EnumNew();
Node NodeNew();
Slot SlotNew();
#endif

#endif /* NTTYPE_H */
