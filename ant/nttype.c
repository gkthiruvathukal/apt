/******************************************************************
**
** NTACTS.C:
**
**    NT Semantic Actions
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include <stdio.h>

/* ---------- Headers */

#include "allocate.h"
#include "nttype.h"

/* ----------- Allocation Functions */

/*
**
** DeclNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Decl DeclNew(Token nf, Queue specs, Queue ptrs, Token name, Queue arrays)
#else
Decl DeclNew(nf, specs, ptrs, name, arrays)
Token nf;
Queue specs;
Queue ptrs;
Token name;
Queue arrays;
#endif
{
  Decl newDecl = ((Decl)Allocate(sizeof(_Decl)));
  if (nf == NULL) newDecl->nullFlg = 0;
  else newDecl->nullFlg = 1;
  newDecl->specs = specs;
  newDecl->ptrs = ptrs;
  newDecl->name = name;
  newDecl->arrays = arrays;
  return (newDecl);
}

/*
**
** EnumNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Enum EnumNew(Token name, Queue tags)
#else
Enum EnumNew(name, tags)
Token name;
Queue tags;
#endif
{
  Enum newEnum = ((Enum)Allocate(sizeof(_Enum)));
  newEnum->name = name;
  newEnum->tags = tags;
  return (newEnum);
}

/*
**
** NodeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Node NodeNew(Token name, Queue slots, Queue decls)
#else
Node NodeNew(name, slots, decls)
Token name;
Queue slots;
Queue decls;
#endif
{
  Node newNode = ((Node)Allocate(sizeof(_Node)));
  newNode->name = name;
  newNode->slots = slots;
  newNode->decls = decls;
  return (newNode);
}

/*
**
** SlotNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Slot SlotNew(Token name, Queue decls)
#else
Slot SlotNew(name, decls)
Token name;
Queue decls;
#endif
{
  Slot newSlot = ((Slot)Allocate(sizeof(_Slot)));
  newSlot->name = name;
  newSlot->decls = decls;
  return (newSlot);
}
