/******************************************************************
**
** ASTACK.C:
**
**    ADT Array Stack Implementation
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
#include "astack.h"

/* ---------- Functions */

/*
**
** AStackCheckByte
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackCheckByte(AStack s, int pos)
#else
int AStackCheckByte(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0)
      if (s->stack[pos].type == Byte) return (TRUE);
  }
  return (FALSE);
}

/*
**
** AStackCheckLongWord
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackCheckLongWord(AStack s, int pos)
#else
int AStackCheckLongWord(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0)
      if (s->stack[pos].type == LongWord) return (TRUE);
  }
  return (FALSE);
}

/*
**
** AStackCheckPointer
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackCheckPointer(AStack s, int pos)
#else
int AStackCheckPointer(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0)
      if (s->stack[pos].type == Pointer) return (TRUE);
  }
  return (FALSE);
}

/*
**
** AStackCheckType
**
*/
PUBLIC
#ifdef __ANSI_C__
AStackItemTypes AStackCheckType(AStack s, int pos)
#else
AStackItemTypes AStackCheckType(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0) return (s->stack[pos].type);
  }
  return (NoType);
}

/*
**
** AStackCheckWord
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackCheckWord(AStack s, int pos)
#else
int AStackCheckWord(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0)
      if (s->stack[pos].type == Word) return (TRUE);
  }
  return (FALSE);
}

/*
**
** AStackClearError
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackClearError(AStack s)
#else
void AStackClearError(s)
AStack s;
#endif
{
  s->error = AStackOK;
}

/*
**
** AStackDispose
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackDispose(AStack s, DisposeFunction f)
#else
void AStackDispose(s,f)
AStack s;
DisposeFunction f;
#endif
{
  if (s) {
    AStackSpill(s,s->max,f);  
    free(s->stack);
    free(s);
  }
}

/*
**
** AStackEmpty
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackEmpty(AStack s)
#else
int AStackEmpty(s)
AStack s;
#endif
{
  s->error = AStackOK;
  return (s->size == 0);
}

/*
**
** AStackError
**
*/
PUBLIC
#ifdef __ANSI_C__
AStackErrorTypes AStackError(AStack s)
#else
AStackErrorTypes AStackError(s)
AStack s;
#endif
{
  return (s->error);
}

/*
**
** AStackGetByte
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned char AStackGetByte(AStack s, int pos)
#else
unsigned char AStackGetByte(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0) {
      if (s->stack[pos].type == Byte) {
        s->error = AStackOK;
        return (s->stack[pos].u.b);
      } else s->error = AStackTypeMismatch;
    } else s->error = AStackRangeError;
  } else s->error = AStackBadDisplacement;
  return ((unsigned char)0);
}

/*
**
** AStackGetLongWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned long AStackGetLongWord(AStack s, int pos)
#else
unsigned long AStackGetLongWord(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0) {
      if (s->stack[pos].type == LongWord) {
        s->error = AStackOK;
        return (s->stack[pos].u.lw);
      } else s->error = AStackTypeMismatch;
    } else s->error = AStackRangeError;
  } else s->error = AStackBadDisplacement;
  return ((unsigned long)0);
}

/*
**
** AStackGetPointer
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AStackGetPointer(AStack s, int pos)
#else
void *AStackGetPointer(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0) {
      if (s->stack[pos].type == Pointer) {
        s->error = AStackOK;
        return (s->stack[pos].u.ptr);
      } else s->error = AStackTypeMismatch;
    } else s->error = AStackRangeError;
  } else s->error = AStackBadDisplacement;
  return ((void*)0);
}

/*
**
** AStackGetWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned short AStackGetWord(AStack s, int pos)
#else
unsigned short AStackGetWord(s,pos)
AStack s;
int pos;
#endif
{
  if (pos > 0) {
    pos = s->size - pos;
    if (pos >= 0) {
      if (s->stack[pos].type == Word) {
        s->error = AStackOK;
        return (s->stack[pos].u.w);
      } else s->error = AStackTypeMismatch;
    } else s->error = AStackRangeError;
  } else s->error = AStackBadDisplacement;
  return ((unsigned short)0);
}

/*
**
** AStackLookByte
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned char AStackLookByte(AStack s)
#else
unsigned char AStackLookByte(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Byte) {
      s->error = AStackOK;  
      return (s->stack[s->size-1].u.b);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned char)0);
}

/*
**
** AStackLookLongWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned long AStackLookLongWord(AStack s)
#else
unsigned long AStackLookLongWord(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == LongWord) {
      s->error = AStackOK;
      return (s->stack[s->size-1].u.lw);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned long)0);
}

/*
**
** AStackLookPointer
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AStackLookPointer(AStack s)
#else
void *AStackLookPointer(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Pointer) {
      s->error = AStackOK;
      return (s->stack[s->size-1].u.ptr);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((void*)0);
}

/*
**
** AStackLookType
**
*/
PUBLIC
#ifdef __ANSI_C__
AStackItemTypes AStackLookType(AStack s)
#else
AStackItemTypes AStackLookType(s)
AStack s;
#endif
{
  if (s->size > 0) return (s->stack[s->size-1].type);
  else return (NoType);
}

/*
**
** AStackLookWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned short AStackLookWord(AStack s)
#else
unsigned short AStackLookWord(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Word) {
      s->error = AStackOK;
      return (s->stack[s->size-1].u.w);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned short)0);
}

/*
**
** AStackNew
**
*/
PUBLIC
#ifdef __ANSI_C__
AStack AStackNew(int max)
#else
AStack AStackNew(max)
int max;
#endif
{
  AStack s;

  s = ((AStack)Allocate(sizeof(_AStack)));
  if (s) {
    s->size = 0;
    s->max = max;
    s->error = AStackOK;
    s->stack = ((AStackItem)Allocate(max*sizeof(_AStackItem)));
  }
  return (s);
}

/*
**
** AStackNotEmpty
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackNotEmpty(AStack s)
#else
int AStackNotEmpty(s)
AStack s;
#endif
{
  s->error = AStackOK;
  return (s->size != 0);
}

/*
**
** AStackPopByte
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned char AStackPopByte(AStack s)
#else
unsigned char AStackPopByte(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Byte) {
      unsigned char b = s->stack[s->size-1].u.b;
      s->size--;
      s->error = AStackOK;  
      return (b);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned char)0);
}

/*
**
** AStackPopLongWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned long AStackPopLongWord(AStack s)
#else
unsigned long AStackPopLongWord(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == LongWord) {
      unsigned long lw = s->stack[s->size-1].u.lw;
      s->size--;
      s->error = AStackOK;
      return (lw);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned long)0);
}

/*
**
** AStackPopPointer
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AStackPopPointer(AStack s)
#else
void *AStackPopPointer(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Pointer) {
      void *ptr = s->stack[s->size-1].u.ptr;
      s->size--;
      s->error = AStackOK;
      return (ptr);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((void*)0);
}

/*
**
** AStackPopWord
**
*/
PUBLIC
#ifdef __ANSI_C__
unsigned short AStackPopWord(AStack s)
#else
unsigned short AStackPopWord(s)
AStack s;
#endif
{
  if (s->size > 0) {
    if (s->stack[s->size-1].type == Word) {
      unsigned short w = s->stack[s->size-1].u.w;
      s->size--;
      s->error = AStackOK;
      return (w);
    } else s->error = AStackTypeMismatch;
  } else s->error = AStackUnderflow;
  return ((unsigned short)0);
}

/*
**
** AStackPushByte
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackPushByte(AStack s, unsigned char b)
#else
void AStackPushByte(s,b)
AStack s;
unsigned char b;
#endif
{
  if (s->size < s->max) {
    s->stack[s->size].u.b = b;
    s->stack[s->size].type = Byte;
    s->size++;
    s->error = AStackOK;
  } else s->error = AStackOverflow;
}

/*
**
** AStackPushLongWord
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackPushLongWord(AStack s, unsigned long lw)
#else
void AStackPushLongWord(s,lw)
AStack s;
unsigned long lw;
#endif
{
  if (s->size < s->max) {
    s->stack[s->size].u.lw = lw;
    s->stack[s->size].type = LongWord;
    s->size++;
    s->error = AStackOK;
  } else s->error = AStackOverflow;
}

/*
**
** AStackPushPointer
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackPushPointer(AStack s, void *ptr)
#else
void AStackPushPointer(s,ptr)
AStack s;
void *ptr;
#endif
{
  if (s->size < s->max) {
    s->stack[s->size].u.ptr = ptr;
    s->stack[s->size].type = Pointer;
    s->size++;
    s->error = AStackOK;
  } else s->error = AStackOverflow;
}

/*
**
** AStackPushWord
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackPushWord(AStack s, unsigned short w)
#else
void AStackPushWord(s,w)
AStack s;
unsigned short w;
#endif
{
  if (s->size < s->max) {
    s->stack[s->size].u.w = w;
    s->stack[s->size].type = Word;
    s->size++;
    s->error = AStackOK;
  } else s->error = AStackOverflow;
}

/*
**
** AStackSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int AStackSize(AStack s)
#else
int AStackSize(s)
AStack s;
#endif
{
  s->error = AStackOK;
  return (s->size);
}

/*
**
** AStackSpill
**
*/
PUBLIC
#ifdef __ANSI_C__
void AStackSpill(AStack s, int count, DisposeFunction f)
#else
void AStackSpill(s,count,f)
AStack s;
int count;
DisposeFunction f;
#endif
{
  for ( ; AStackError(s) == AStackOK && count > 0; count--)
    switch(AStackLookType(s)) {
    case Byte:
      AStackPopByte(s);
      break;
    case LongWord:
      AStackPopLongWord(s);
      break;
    case Pointer:
      if (f) (*f)(AStackPopPointer(s));
      else AStackPopPointer(s);
      break;
    case Word:
      AStackPopWord(s);
      break;
    }
}

