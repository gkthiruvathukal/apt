/******************************************************************
**
** ASTSCAN.C:
**
**    AST Scanner
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- Headers */

#include "apt.h"

#include "astlib.h"
#include "astmain.h"
#include "astscan.h"

/* ----------- Functions */

Token Scan(file)
FILE *file;
{
  int CurrentChar = 0;

  SetScanFile(scanInfo,file);
  SetScanState(scanInfo,S_Start);
  SetScanAttribute(scanInfo,-1);
  SetScanBuffer(scanInfo,BufferNew());
  Ignore(scanInfo);
  for (;;) {
    CurrentChar = GetScanChar(scanInfo);
    switch(GetScanState(scanInfo)) {
    case S_Escape:
      if (CharInString(CurrentChar,"\n")) {
        Match(scanInfo);
        SetScanAttribute(scanInfo,T_QuotedLiteral);
        return MakeToken(scanInfo);
      }
      else if (LAMBDA(CurrentChar)) {
        Advance(scanInfo);
        SetScanState(scanInfo,S_Quote);
      }
      break;
    case S_Quote:
      if (CharInString(CurrentChar,"\"\n")) {
        Match(scanInfo);
        SetScanAttribute(scanInfo,T_QuotedLiteral);
        return MakeToken(scanInfo);
      }
      else if (CharInString(CurrentChar,"\\")) {
        Advance(scanInfo);
        SetScanState(scanInfo,S_Escape);
      }
      else if (LAMBDA(CurrentChar)) {
        Advance(scanInfo);
      }
      break;
    case S_Identifier:
      if (NUMERIC(CurrentChar)) {
        Advance(scanInfo);
      }
      else if (CharInString(CurrentChar,"_")) {
        Advance(scanInfo);
      }
      else if (ALPHA(CurrentChar)) {
        Advance(scanInfo);
      }
      else if (LAMBDA(CurrentChar)) {
        PushBack(scanInfo);
        SetScanAttribute(scanInfo,T_Identifier);
        return MakeToken(scanInfo);
      }
      break;
    case S_ReturnToken:
      break;
    case S_Start:
      if (ENDOFFILE(CurrentChar)) {
        Match(scanInfo);
        SetScanAttribute(scanInfo,T_EndOfFile);
        return MakeToken(scanInfo);
      }
      else if (CharInString(CurrentChar,"\n")) {
        Match(scanInfo);
        SetScanAttribute(scanInfo,T_EndOfLine);
        return MakeToken(scanInfo);
      }
      else if (CharInString(CurrentChar,"\"")) {
        Advance(scanInfo);
        SetScanState(scanInfo,S_Quote);
      }
      else if (CharInString(CurrentChar,"_")) {
        Advance(scanInfo);
        SetScanState(scanInfo,S_Identifier);
      }
      else if (ALPHA(CurrentChar)) {
        Advance(scanInfo);
        SetScanState(scanInfo,S_Identifier);
      }
      else if (LAMBDA(CurrentChar)) {
        Ignore(scanInfo);
      }
      break;
    default:
      return MakeErrorToken(scanInfo,T_Error);
    }
  }
}
