/******************************************************************
**
** ASTLIB.H:
**
**    AST Runtime System Library
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTLIB_H
#define ASTLIB_H

/* ----------- C Headers */

#include "cheaders.h"

/* ----------- Headers */

#include "apt.h"

#include "astimp.h"
#include "asttype.h"

#include "buffer.h"

/* ----------- Exported Function Prototypes for AST Actions */

#ifdef __ANSI_C__
int ALPHA(int);
int ALPHANUMERIC(int);
int DEFAULT(int);
int ENDOFFILE(int);
int HEXDIGIT(int);
int LAMBDA(int);
int NUMERIC(int);
int NZDIGIT(int);
int OCTDIGIT(int);
int WHITESPACE(int);
void Advance(ScanInfo);
int CharInString(int, char*);
void Flush(ScanInfo);
void Ignore(ScanInfo);
void InitAdvance(ScanInfo);
void InitIgnore(ScanInfo);
void InitMatch(ScanInfo);
void Match(ScanInfo);
void PushBack(ScanInfo);
void PushBackCloseChar(ScanInfo);
void PushBackCloseString(ScanInfo);
void PushBackTwo(ScanInfo);
void PushBack2AndFix(ScanInfo);
void PushBackThree(ScanInfo);
void PushBack3AndFix(ScanInfo);
#else
int ALPHA();
int ALPHANUMERIC();
int DEFAULT();
int ENDOFFILE();
int HEXDIGIT();
int LAMBDA();
int NUMERIC();
int NZDIGIT();
int OCTDIGIT();
int WHITESPACE();
void Advance();
int CharInString();
void Flush();
void Ignore();
void InitAdvance();
void InitMatch();
void InitIgnore();
void Match();
void PushBack();
void PushBackCloseChar();
void PushBackCloseString();
void PushBackTwo();
void PushBack2AndFix();
void PushBackThree();
void PushBack3AndFix();
#endif /* __ANSI_C__ */

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
int GetScanAttribute(ScanInfo);
Buffer GetScanBuffer(ScanInfo);
int GetScanChar(ScanInfo);
int GetScanColumn(ScanInfo);
int GetScanLine(ScanInfo);
int GetScanState(ScanInfo);
Token MakeErrorToken(ScanInfo, int);
Token MakeToken(ScanInfo);
void RevUpdateLineColumn(ScanInfo);
ScanInfo ScanInfoNew(FILE *, ScanInfo);
void ScanStateInit(ScanInfo*, FILE*);
void ScanStateRevert(ScanInfo*);
void ScanStateSwitch(ScanInfo*, FILE*);
void SetScanAttribute(ScanInfo, int);
void SetScanBuffer(ScanInfo, Buffer);
void SetScanColumn(ScanInfo, int);
void SetScanFile(ScanInfo, FILE *);
void SetScanLine(ScanInfo, int);
void SetScanState(ScanInfo, int);
Token TokenNew(char*, int, int, int);
void UpdateLineColumn(ScanInfo);
void UpdateStartInfo(ScanInfo);
#else
int GetScanAttribute();
Buffer GetScanBuffer();
int GetScanChar();
int GetScanColumn();
int GetScanLine();
int GetScanState();
Token MakeErrorToken();
Token MakeToken();
void RevUpdateLineColumn();
ScanInfo ScanInfoNew();
void ScanStateInit();
void ScanStateRevert();
void ScanStateSwitch();
void SetScanAttribute();
void SetScanBuffer();
void SetScanColumn();
void SetScanFile();
void SetScanLine();
void SetScanState();
Token TokenNew();
void UpdateLineColumn();
void UpdateStartInfo();
#endif /* __ANSI_C__ */

#endif /* ASTLIB_H */
