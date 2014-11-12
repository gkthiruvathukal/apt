/******************************************************************
**
** BUFFER.C:
**
**    ADT Buffer Implementation
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
#include "buffer.h"
#include "deque.h"

/* ---------- Private Types */

#define BlockCode 101

typedef struct _Block {
  char text[BlockSize];
} _Block, *Block;

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE void BlockDispose(void*);
PRIVATE Block BlockNew(void);
#else
PRIVATE void BlockDispose();
PRIVATE Block BlockNew();
#endif

/* ---------- Functions */

/*
**
** BlockDispose
**
*/
PRIVATE
#ifdef __ANSI_C__
void BlockDispose(void *block)
#else
void BlockDispose(block)
void *block;
#endif
{
  Block b = block;
  if (b) free(b);
}

/*
**
** BlockNew
**
*/
PRIVATE
#ifdef __ANSI_C__
Block BlockNew(void)
#else
Block BlockNew()
#endif
{
  Block block;

  block = ((Block)Allocate(sizeof(_Block)));
  return (block);
}

/*
**
** BufferAddChar
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufferAddChar(Buffer buffer, char c)
#else
void BufferAddChar(buffer,c)
Buffer buffer;
char c;
#endif
{
  Block block;

  if (buffer->pos >= BlockSize) {
    buffer->pos = 0;
    block = BlockNew();
    if (block) {
      DequePut(buffer->data,block,BlockCode,Bottom);
      buffer->text = block->text;
    }
  }
#ifdef DEBUG_BUFFER
  printf("buffer @ %d = %c\n", buffer->pos, c);
#endif
  buffer->text[buffer->pos++] = c;
}

/*
**
** BufferAddString
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufferAddString(Buffer buffer, char *s)
#else
void BufferAddString(buffer,s)
Buffer buffer;
char *s;
#endif
{
  char *c;

  for (c=s; *c; c++) BufferAddChar(buffer,*c);
}

/*
**
** BufferDelChar
**
*/
PUBLIC
#ifdef __ANSI_C__
int BufferDelChar(Buffer buffer)
#else
int BufferDelChar(buffer)
Buffer buffer;
#endif
{
  Block block;
  DequeItem item;

  if (--buffer->pos >= 0) {
  } else {
    if (DequeSize(buffer->data) > 1) {
      BlockDispose(DequeGet(buffer->data,Bottom));
      item = DequeSide(buffer->data,Bottom);
      block = DequeItemElement(item);
      buffer->text = block->text;
      buffer->pos = BlockSize-1;
    } else {
      buffer->pos = 0;
      return (EOF);
    }
  }
  return (buffer->text[buffer->pos]);
}

/*
**
** BufferDispose
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufferDispose(Buffer buffer)
#else
void BufferDispose(buffer)
Buffer buffer;
#endif
{
  if (buffer) {
    DequeDispose(buffer->data,BlockDispose);
    free(buffer);
  }
}

/*
**
** BufferNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Buffer BufferNew(void)
#else
Buffer BufferNew()
#endif
{
  Block block;
  Buffer buffer;

  buffer = ((Buffer)Allocate(sizeof(_Buffer)));
  if (buffer) {
    buffer->data = DequeNew();
    buffer->pos = 0;
    block = BlockNew();
    if (block) {
      DequePut(buffer->data,block,BlockCode,Bottom);
      buffer->text = block->text;
    }
  }
  return (buffer);
}

/*
**
** BufferSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int BufferSize(Buffer buffer)
#else
int BufferSize(buffer)
Buffer buffer;
#endif
{
  if (buffer) return (DequeSize(buffer->data)-1)*BlockSize+buffer->pos;
  else return (0);
}

/*
**
** BufferToString
**
*/
PUBLIC
#ifdef __ANSI_C__
char *BufferToString(Buffer buffer)
#else
char *BufferToString(buffer)
Buffer buffer;
#endif
{
  Block block;
  int bytes;
  DequeItem DequeGetItem();
  int i;
  DequeItem item;
  char *string;
  int sum;

  bytes = (BufferSize(buffer)+1)*sizeof(char);
  string = ((char*)Allocate(bytes));
  sum = 0;
#ifdef DEBUG_BUFFER
  printf("Deque size = %d\n", DequeSize(buffer->data));
#endif
  if (DequeSize(buffer->data) > 1) {
    item = DequeSide(buffer->data,Top);
    for (;;) {
      if (item == DequeSide(buffer->data,Bottom))
        break;
      block = DequeItemElement(item);
      for (i=0; i<BlockSize; i++, sum++) {
        string[sum] = block->text[i];
#ifdef DEBUG_BUFFER
        printf("block @ %d = %c\n", i, block->text[i]);
#endif
      }
      item = DequeNext(item, Top);
    }
  }
  for (i=0; i<buffer->pos; i++, sum++) {
    string[sum] = buffer->text[i];
#ifdef DEBUG_BUFFER
    printf("buffer @ %d = %c\n", i, block->text[i]);
#endif
  }
  string[sum] = 0;
  return (string);
}

