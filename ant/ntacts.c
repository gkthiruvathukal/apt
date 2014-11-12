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

#include "apt.h"
#include "astlib.h"
#include "aptlib.h"
#include "apttype.h"
#include "ntcgen.h"
#include "ntparse.td"
#include "ntparse.h"
#include "ntparse.pt"

/* ---------- Private Types */
 
enum QueueTypes {
  QT_Decl,
  QT_Enum,
  QT_Node,
  QT_Slot,
  QT_Token
};

/* ----------- Action Functions */

/*
**
** doEncode
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doEncode(Queue P1, Queue P2, Queue P3)
#else
Void doEncode(P1, P2, P3)
Queue P1;
Queue P2;
Queue P3;
#endif
{
  CG(P1,P2,P3);
  return;
}

/*
**
** doEnum
**
*/
PUBLIC
#ifdef __ANSI_C__
Enum doEnum(Token P1, Queue P2)
#else
Enum doEnum(P1, P2)
Token P1;
Queue P2;
#endif
{
  return (EnumNew(P1,P2));
}

/*
**
** doFakeToken
**
*/
PUBLIC
#ifdef __ANSI_C__
Token doFakeToken(void)
#else
Token doFakeToken()
#endif
{
  return ((Token)NULL); 
}

/*
**
** doNQEnum
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQEnum(Queue P1, Enum P2)
#else
Void doNQEnum(P1, P2)
Queue P1;
Enum P2;
#endif
{
  QueuePut(P1,P2,QT_Enum);
}

/*
**
** doNQInclude
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQInclude(Queue P1, Token P2)
#else
Void doNQInclude(P1, P2)
Queue P1;
Token P2;
#endif
{
  QueuePut(P1,P2,QT_Token);
}

/*
**
** doNQNode
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQNode(Queue P1, Node P2)
#else
Void doNQNode(P1, P2)
Queue P1;
Node P2;
#endif
{
  QueuePut(P1,P2,QT_Node);
}

/*
**
** doNQSlot
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQSlot(Queue P1, Slot P2)
#else
Void doNQSlot(P1, P2)
Queue P1;
Slot P2;
#endif
{
  QueuePut(P1,P2,QT_Slot);
}

/*
**
** doNQToken
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQToken(Queue P1, Token P2)
#else
Void doNQToken(P1, P2)
Queue P1;
Token P2;
#endif
{
  QueuePut(P1,P2,QT_Token);
}

/*
**
** doNQVar
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNQVar(Queue P1, Token P2, Queue P3, Queue P4, Token P5, Queue P6)
#else
Void doNQVar(P1, P2, P3, P4, P5, P6)
Queue P1;
Token P2;
Queue P3;
Queue P4;
Token P5;
Queue P6;
#endif
{
  Decl decl;

  decl = DeclNew(P2,P3,P4,P5,P6); 
  QueuePut(P1,decl,QT_Decl);
}

/*
**
** doNode
**
*/
PUBLIC
#ifdef __ANSI_C__
Node doNode(Token P1, Queue P2, Queue P3)
#else
Node doNode(P1, P2, P3)
Token P1;
Queue P2;
Queue P3;
#endif
{
  return (NodeNew(P1,P2,P3));
}

/*
**
** doNothing
**
*/
PUBLIC
#ifdef __ANSI_C__
Void doNothing(void)
#else
Void doNothing()
#endif
{
  return;
}

/*
**
** doQ
**
*/
PUBLIC
#ifdef __ANSI_C__
Queue doQ(void)
#else
Queue doQ()
#endif
{
  return (QueueNew());
}

/*
**
** doSlot
**
*/
PUBLIC
#ifdef __ANSI_C__
Slot doSlot(Token P1, Queue P2)
#else
Slot doSlot(P1, P2)
Token P1;
Queue P2;
#endif
{
  return (SlotNew(P1,P2));
}
