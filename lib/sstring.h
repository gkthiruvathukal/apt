/******************************************************************
**
** STRING.H:
**
**    ADT String Functions
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef STRING_H
#define STRING_H

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
char *StringCatenate(char*, char*);
int StringCompare(char*, char*);
void StringCopy(char*, char*);
char *StringDuplicate(char*);
char *StringDuplicateFirst(char*, int);
int StringPrintable(char*);
char *StringTokenize(char*, char*);
char *StringToUpper(char*);
int StringLength(char*);
#else
char *StringCatenate();
int StringCompare();
void StringCopy();
char *StringDuplicate();
char *StringDuplicateFirst();
int StringPrintable();
char *StringTokenize();
char *StringToUpper();
int StringLength();
#endif /* __ANSI_C__ */

#endif /* STRING_H */
