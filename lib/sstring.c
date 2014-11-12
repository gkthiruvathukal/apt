/******************************************************************
**
** STRING.C:
**
**    ADT String Functions
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
#include "sstring.h"

/* ---------- Functions */

#ifdef __ANSI_C__
void StringCopy(char *s, char *t)
#else
void StringCopy(s,t)
char *s, *t;
#endif
{
  for ( ; *t; s++, t++) *s = *t;
}


#ifdef __ANSI_C__
char *StringCatenate(char *s, char *t)
#else
char *StringCatenate(s,t)
char *s, *t;
#endif
{
  char *p;

  for (p=s; *p; p++) ;
  StringCopy(p,t);
  return (s);
}

#ifdef __ANSI_C__
int StringCompare(char *s, char *t)
#else
int StringCompare(s,t)
char *s, *t;
#endif
{
  if (s == NULL) s = "";
  if (t == NULL) t = "";

  for ( ; *s && *t && *s == *t; s++, t++) ;
  return (*s - *t);
}

#ifdef __ANSI_C__
char *StringDuplicate(char *s)
#else
char *StringDuplicate(s)
char *s;
#endif
{
  char *c;

  c = ((char*)Allocate(StringLength(s)+1));
  StringCopy(c,s);
  return (c);
}

#ifdef __ANSI_C__
char *StringDuplicateFirst(char *s, int n)
#else
char *StringDuplicateFirst(s,n)
char *s;
int n;
#endif
{
  char *c;
  int i;

  c = (char *)Allocate(n + 1);
  for (i=0; s[i] && i<n; i++) c[i] = s[i];
  c[n] = 0;
  return (c);
}

#ifdef __ANSI_C__
int StringLength(char *s)
#else
int StringLength(s)
char *s;
#endif
{
  int i;

  if (s == NULL) return (0);
  for (i=0; *s; i++, s++) ;
  return (i);
}

/*
**
** StringPrintable
**
*/
PUBLIC
#ifdef __ANSI_C__
int StringPrintable(char *s)
#else
int StringPrintable(s)
char *s;
#endif
{
  for (; *s; s++) if (!isprint(*s)) return (0);
  return (1);
}

#ifdef __ANSI_C__
char *StringTokenize(char *string1, char *string2)
#else
char *StringTokenize(string1,string2)
char *string1, *string2;
#endif
{
  static char *last = NULL;
  char *p, *q;
  char *token = NULL;
  char *tstring = string1;

  if (tstring == NULL) tstring = last;
  if (tstring == NULL) return (tstring);

  /* -- strip leading occurrences of delimeters in string2 */

  for (p=tstring; *p; p++) {
    for (q=string2; *q; q++) {
      if (*p == *q) *p = 0;
    }
    if (*p != 0) break;
  }

  /* -- gather characters until another occurrence of a delimeter */

  for (token=p; *p; p++)
    for (q=string2; *q; q++)
      if (*p == *q) {
        *p = 0;
        last = ++p;
        return (token);
      }
  last = p;
  return (p != token ? token : NULL);
}

#ifdef __ANSI_C__
char *StringToUpper(char *s)
#else
char *StringToUpper(s)
char *s;
#endif
{
  char *p;

  for (p=s; *p; p++) if (islower(*p)) *p = toupper(*p);
  return (s);
}
