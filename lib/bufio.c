/******************************************************************
**
** BUFIO.C:
**
**    ADT Buffered I/O Implementation
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
#include "avltree.h"
#include "buffer.h"
#include "bufio.h"

/* ---------- Private Types */

#define FileBufferCode 102

typedef struct _FileBuffer {
  FILE *file;
  Buffer buffer;
} _FileBuffer, *FileBuffer;

/* ---------- Private Globals */

PRIVATE AVLTree BufferTree = NULL;

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE int CompareOnFile(void*, void*);
PRIVATE void FileBufferDispose(void*);
PRIVATE FileBuffer FileBufferNew(FILE*, Buffer);
PRIVATE Buffer LookupBuffer(FILE*);
#else
PRIVATE int CompareOnFile();
PRIVATE void FileBufferDispose();
PRIVATE FileBuffer FileBufferNew();
PRIVATE Buffer LookupBuffer();
#endif

/* ---------- Functions */

/*
**
** BufIOBufferSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int BufIOBufferSize(FILE *file)
#else
int BufIOBufferSize(file)
FILE *file;
#endif
{
  Buffer buffer;

  buffer = LookupBuffer(file);
  return (buffer != NULL ? BufferSize(buffer) : 0);
}

/*
**
** BufIOGetChar
**
*/
PUBLIC
#ifdef __ANSI_C__
int BufIOGetChar(FILE *file)
#else
int BufIOGetChar(file)
FILE *file;
#endif
{
  Buffer buffer;
  int c;

  buffer = LookupBuffer(file);
  if (buffer != NULL) {
    c = BufferDelChar(buffer);
    if (c != EOF) {
      return (c);
    }
  }
  c = getc(file);
  return (c);
}

/*
**
** BufIOGetString
**
*/
PUBLIC
#ifdef __ANSI_C__
char *BufIOGetString(FILE *file)
#else
char *BufIOGetString(file)
FILE *file;
#endif
{
  int c;
  Buffer buffer;
  char *s;

  buffer = BufferNew();
  c = BufIOGetChar(file);
  if (c == EOF) return (NULL);
  while (c != '\n' && c != EOF) {
    BufferAddChar(buffer,c);
    c = BufIOGetChar(file);
  }
  s = BufferToString(buffer);
  BufferDispose(buffer);
  return (s);
}

/*
**
** BufIOInitialize
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufIOInitialize(void)
#else
void BufIOInitialize()
#endif
{
  BufferTree = AVLTreeNew();
}

/*
**
** BufIOUnGetChar
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufIOUnGetChar(int c, FILE *file)
#else
void BufIOUnGetChar(c,file)
int c;
FILE *file;
#endif
{
  Buffer buffer;

  buffer = LookupBuffer(file);
  if (buffer != NULL) BufferAddChar(buffer,c);
  else {
    buffer = BufferNew();
    AVLTreeInsert(BufferTree,FileBufferNew(file,buffer),FileBufferCode,
      CompareOnFile);
    BufferAddChar(buffer,c);
  }
}

/*
**
** BufIOTerminate
**
*/
PUBLIC
#ifdef __ANSI_C__
void BufIOTerminate(void)
#else
void BufIOTerminate()
#endif
{
  AVLTreeDispose(BufferTree,FileBufferDispose);
}

/*
**
** CompareOnFile
**
*/
PRIVATE
#ifdef __ANSI_C__
int CompareOnFile(void *x, void *y)
#else
int CompareOnFile(x,y)
void *x;
void *y;
#endif
{
  FileBuffer fx = x, fy = y;

  return ((fx->file > fy->file) - (fx->file < fy->file));
}

/*
**
** FileBufferDispose
**
*/
PRIVATE
#ifdef __ANSI_C__
void FileBufferDispose(void *fb)
#else
void FileBufferDispose(fb)
void *fb;
#endif
{
  FileBuffer fh = fb;
  if (fh) free(fh);
}

/*
**
** FileBufferNew
**
*/
PRIVATE
#ifdef __ANSI_C__
FileBuffer FileBufferNew(FILE *file, Buffer buffer)
#else
FileBuffer FileBufferNew(file,buffer)
FILE *file;
Buffer buffer;
#endif
{
  FileBuffer fb;

  fb = ((FileBuffer)Allocate(sizeof(_FileBuffer)));
  if (fb) {
    fb->file = file;
    fb->buffer = buffer;
  }
  return (fb);
}

/*
**
** LookupBuffer
**
*/
PRIVATE
#ifdef __ANSI_C__
Buffer LookupBuffer(FILE *file)
#else
Buffer LookupBuffer(file)
FILE *file;
#endif
{
  FileBuffer fb;
  FileBuffer key;

  key = FileBufferNew(file,NULL);
  fb = AVLTreeFind(BufferTree,key,CompareOnFile);
  FileBufferDispose(key);
  return (fb != NULL ? fb->buffer : NULL);
}

