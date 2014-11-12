/******************************************************************
**
** ASTTYPE.H:
**
**    AST Runtime System Types
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTTYPE_H
#define ASTTYPE_H

/* ----------- C Headers */

#include "cheaders.h"

/* ----------- Headers */

#include "apt.h"

#include "buffer.h"
#include "stack.h"

/* ----------- Exported Types */
 
typedef struct _ScanInfo {
   FILE *file;
   int c;
   int line, column;
   int lastLine, lastColumn;
   int tokenLine, tokenColumn;
   int state;
   int attribute;
   Buffer buffer;
   Stack stack;
   struct _ScanInfo *previous;
} _ScanInfo, *ScanInfo;

typedef struct _Token {
   char *text;
   int type;
   int line, column;
} _Token, *Token;

#endif /* ASTTYPE_H */
