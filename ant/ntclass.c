/******************************************************************
**
** NTCLASS.C:
**
**    NT Token Classification
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- Headers */

#include "apt.h"

#include "ntparse.h"
#include "ntscan.h"

#include "astlib.h"

#include "sstring.h"

/* ---------- Private Globals */

PRIVATE struct _KeyWord {
  char *id;
  int attribute;
} KeyWord[] = {
  "include", T_include,
  "node", T_node,
  "slot", T_slot,
  "enum", T_enum,
  "struct", T_struct,
  "union", T_union,
  "void", T_void,
  "char", T_char,
  "int", T_int,
  "float", T_float,
  "double", T_double,
  "short", T_short,
  "long", T_long,
  "signed", T_signed,
  "unsigned", T_unsigned,
  "typedef", T_typedef,
  "auto", T_auto,
  "static", T_static,
  "null", T_null,
  "extern", T_extern,
  "const", T_const,
  "volatile", T_volatile,
  NULL, -1
};

/* ---------- Functions */

/*
**
** Classify
**
*/
PUBLIC
#ifdef __ANSI_C__
int Classify(Token id, int attr)
#else
int Classify(id,attr)
Token id;
int attr;
#endif
{
  struct _KeyWord *keyWord;

  if (attr == T_ident) {
    for (keyWord = KeyWord; keyWord->id != NULL; keyWord++)
      if (StringCompare(keyWord->id,id->text) == 0) return (keyWord->attribute);
        return (T_ident);
  } else return (attr);
}
