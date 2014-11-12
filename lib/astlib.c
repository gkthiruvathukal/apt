/******************************************************************
**
** ASTLIB.C:
**
**    AST Runtime System Library
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- Headers */

#include "apt.h"

#include "aptlib.h"
#include "astlib.h"

#include "allocate.h"
#include "bufio.h"
#include "buffer.h"
#include "stack.h"

/* ----------- Private Types */

typedef struct _LineColInfo {
  int line;
  int column;
} _LineColInfo, *LineColInfo;

/* ----------- Private Function Prototypes */

#ifdef __ANSI_C__
void LineColInfoDispose(LineColInfo);
LineColInfo LineColInfoNew(int, int);
#else
void LineColInfoDispose();
LineColInfo LineColInfoNew();
#endif

/* ---------- AST User Functions */

int ALPHA(c)
     int c;
{
  return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '_'));
}

int ALPHANUMERIC(c)
     int c;
{
  return (ALPHA(c) || NUMERIC(c));
}

int DEFAULT(c)
     int c;
{
  return (c || 1);
}

int ENDOFFILE(c)
     int c;
{
  return (c == EOF);
}

int HEXDIGIT(c)
     int c;
{
  return (CharInString(c,"0123456789") || CharInString(c,"ABCDEF")
          || CharInString(c,"abcdef"));
}

int LAMBDA(c)
     int c;
{
  return (c || 1);
}

int NUMERIC(c)
     int c;
{
  return (CharInString(c,"0123456789"));
}

int NZDIGIT(c)
     int c;
{
  return (NUMERIC(c) && !CharInString(c,"0"));
}

int OCTDIGIT(c)
     int c;
{
  return (CharInString(c,"01234567"));
}

int WHITESPACE(c)
     int c;
{
  return (CharInString(c," \t\n"));
}

void Advance(scanInfo)
     ScanInfo scanInfo;
{
  BufferAddChar(scanInfo->buffer,scanInfo->c);
  UpdateLineColumn(scanInfo);
}

void AdvanceDelete(scanInfo)
     ScanInfo scanInfo;
{
  Advance(scanInfo);
  BufferDelChar(scanInfo->buffer);
  BufferDelChar(scanInfo->buffer);
}

int CharInString(c,s)
     int c;
     char *s;
{
  char *p;

  for (p=s; *p;  p++) {
    if (*p == c) return (1);
  }
  return (0);
}

void Flush(scanInfo)
     ScanInfo scanInfo;
{
  UpdateLineColumn(scanInfo);
  if (scanInfo->buffer != NULL) BufferDispose(scanInfo->buffer);
  scanInfo->buffer = BufferNew();
}

void Ignore(scanInfo)
     ScanInfo scanInfo;
{
  UpdateLineColumn(scanInfo);
}

void InitAdvance(scanInfo)
     ScanInfo scanInfo;
{
  UpdateStartInfo(scanInfo);
  Advance(scanInfo);
}

void InitIgnore(scanInfo)
     ScanInfo scanInfo;
{
  UpdateStartInfo(scanInfo);
  UpdateLineColumn(scanInfo);
}

void InitMatch(scanInfo)
     ScanInfo scanInfo;
{
  UpdateStartInfo(scanInfo);
  Match(scanInfo);
}

void Match(scanInfo)
     ScanInfo scanInfo;
{
  BufferAddChar(scanInfo->buffer,scanInfo->c);
}

void PushBack(scanInfo)
     ScanInfo scanInfo;
{
  RevUpdateLineColumn(scanInfo);
}

void PushBackCloseChar(scanInfo)
     ScanInfo scanInfo;
{
  PushBack(scanInfo);
  BufferAddChar(scanInfo->buffer,'\'');
}

void PushBackCloseString(scanInfo)
     ScanInfo scanInfo;
{
  PushBack(scanInfo);
  BufferAddChar(scanInfo->buffer,'"');
}

void PushBackTwo(scanInfo)
     ScanInfo scanInfo;
{
  /* Put current character (Y above) back */
  RevUpdateLineColumn(scanInfo);

  /* Put previous character (xN above) back */
  scanInfo->c = BufferDelChar(scanInfo->buffer);
  if (scanInfo->c != EOF) RevUpdateLineColumn(scanInfo);
}

void PushBack2AndFix(scanInfo)
     ScanInfo scanInfo;
{
  PushBackTwo(scanInfo);
}
 
void PushBackThree(scanInfo)
     ScanInfo scanInfo;
{
  /* Put current character (Y above) back */
  RevUpdateLineColumn(scanInfo);

  /* Fetch previous character (xN above) and put it back */
  scanInfo->c = BufferDelChar(scanInfo->buffer);
  if (scanInfo->c != EOF) RevUpdateLineColumn(scanInfo);

  /* Fetch character which preceded xN and put it back */
  scanInfo->c = BufferDelChar(scanInfo->buffer);
  if (scanInfo->c != EOF) RevUpdateLineColumn(scanInfo);
}

void PushBack3AndFix(scanInfo)
     ScanInfo scanInfo;
{
  PushBackThree(scanInfo);
}

/* ----------- Functions */

int GetScanAttribute(si)
     ScanInfo si;
{
  return (si->attribute);
}

Buffer GetScanBuffer(si)
     ScanInfo si;
{
  return (si->buffer);
}

int GetScanChar(si)
     ScanInfo si;
{
  return (si->c);
}

int GetScanColumn(si)
     ScanInfo si;
{
  return (si->tokenColumn);
}

int GetScanLine(si)
     ScanInfo si;
{
  return (si->tokenLine);
}

int GetScanState(si)
     ScanInfo si;
{
  return (si->state);
}

void LineColInfoDispose(info)
     LineColInfo info;
{
  if (info) free(info);
}

LineColInfo LineColInfoNew(line,column)
     int line;
     int column;
{
  LineColInfo lci;

  lci = ((LineColInfo)Allocate(sizeof(_LineColInfo)));
  if (lci) {
    lci->line = line;
    lci->column = column;
  }
  return (lci);
}

Token MakeErrorToken(scanInfo,errorAttr)
     ScanInfo scanInfo;
     int errorAttr;
{
  scanInfo->attribute = errorAttr;
  return (MakeToken(scanInfo));
}

Token MakeToken(scanInfo)
     ScanInfo scanInfo;
{
  Token token;

  token = ((Token)Allocate(sizeof(_Token)));
  if (token) {
    token->text = BufferToString(scanInfo->buffer);
    token->line = scanInfo->tokenLine;
    token->column = scanInfo->tokenColumn;
    token->type = Classify(token,scanInfo->attribute);
  }
  return (token);
}

void RevUpdateLineColumn(scanInfo)
     ScanInfo scanInfo;
{
  if (scanInfo->c != '\n') scanInfo->column--;
  BufIOUnGetChar(scanInfo->c,scanInfo->file);
}

ScanInfo ScanInfoNew(file,previous)
     FILE *file;
     ScanInfo previous;
{
  ScanInfo si;
  
  si = ((ScanInfo)Allocate(sizeof(_ScanInfo)));
  if (si) {
    si->file = file;
    si->c = 0;
    si->line = 1;
    si->column = 0;
    si->lastLine = si->lastColumn = 0;
    si->tokenLine = si->tokenColumn = 0;
    si->state = 0;
    si->attribute = 0;
    si->buffer = NULL;
    si->stack = StackNew();
    si->previous = previous;
  }
  return (si);
}

void ScanStateInit(scanInfoAdr,file)
     ScanInfo *scanInfoAdr;
     FILE *file;
{
  ScanStateSwitch(scanInfoAdr,file);
}

void ScanStateRevert(scanInfoAdr)
     ScanInfo *scanInfoAdr;
{
  ScanInfo old;

  if (*scanInfoAdr == NULL) return;
  old = (*scanInfoAdr)->previous;
  free(*scanInfoAdr);
  *scanInfoAdr = old;
}

void ScanStateSwitch(scanInfoAdr,file)
     ScanInfo *scanInfoAdr;
     FILE *file;
{
  ScanInfo si;

  si = ScanInfoNew(file,*scanInfoAdr);
  *scanInfoAdr = si;
}

void SetScanAttribute(si,attribute)
     ScanInfo si;
     int attribute;
{
  si->attribute = attribute;
}

void SetScanBuffer(si,buffer)
     ScanInfo si;
     Buffer buffer;
{
  si->buffer = buffer;
}

void SetScanColumn(si,column)
     ScanInfo si;
     int column;
{
  si->column = column;
}

void SetScanFile(si,file)
     ScanInfo si;
     FILE *file;
{
  si->file = file;
}

void SetScanLine(si,line)
     ScanInfo si;
     int line;
{
  si->line = line;
}

void SetScanState(si,state)
     ScanInfo si;
     int state;
{
  si->state = state;
}

Token TokenNew(text,type,line,column)
     char *text;
     int type;
     int line;
     int column;
{
  Token token;

  token = ((Token)Allocate(sizeof(_Token)));
  if (token) {
    token->text = text;
    token->type = type;
    token->line = line;
    token->column = column;
  }
  return (token);
}

void UpdateLineColumn(scanInfo)
     ScanInfo scanInfo;
{
  int fresh_char;
  LineColInfo lc;

  if (scanInfo->c == '\n') {
    scanInfo->line++;
    scanInfo->column = 1;
  } else scanInfo->column++;

  fresh_char = !BufIOBufferSize(scanInfo->file);
  scanInfo->c = BufIOGetChar(scanInfo->file);
  if (scanInfo->c == '\n') {
    if (fresh_char) {
      lc = LineColInfoNew(scanInfo->line,scanInfo->column);
      StackPush(scanInfo->stack,lc,0);
    } else {
      lc = (LineColInfo)StackPop(scanInfo->stack);
      if (lc != NULL) {
        scanInfo->line = lc->line;
        scanInfo->column = lc->column;
      }
    }
  }
}

void UpdateStartInfo(scanInfo)
     ScanInfo scanInfo;
{
  scanInfo->tokenLine = scanInfo->line;
  scanInfo->tokenColumn = scanInfo->column;
}
