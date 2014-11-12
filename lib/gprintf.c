/******************************************************************
**
** GPRINTF.C:
**
**    APT Printf() functions
**
** This file is part of Apt Computing Tools (ACT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"
#include "gprintf.h"

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE void emitHexString(FILE*, char*);
PRIVATE void emitInt(FILE*, int);
PRIVATE void emitInt2(FILE*, int);
PRIVATE void emitString(FILE*, char*);
PRIVATE char hexChar(unsigned int);
#else
PRIVATE void emitHexString();
PRIVATE void emitInt();
PRIVATE void emitInt2();
PRIVATE void emitString();
PRIVATE char hexChar();
#endif /* __ANSI_C__ */

/* ---------- Functions */

/*
**
** emitHexString
**
*/
PRIVATE
#ifdef __ANSI_C__
void emitHexString(FILE *file, char *sval)
#else
void emitHexString(file,sval)
FILE *file;
char *sval;
#endif
{
  unsigned int nibble;
 
  for (; *sval; sval++) {
    nibble = (*sval >> 4) & 0xf;
    gprintf(file,"%c",hexChar(nibble));
    nibble = *sval & 0xf;
    gprintf(file,"%c",hexChar(nibble));
  }
}

/*
**
** emitInt
**
*/
PRIVATE
#ifdef __ANSI_C__
void emitInt(FILE *file, int ival)
#else
void emitInt(file,ival)
FILE *file;
int ival;
#endif
{
  if (ival == 0) putc('0',file);
  else if (ival < 0) {
    gprintf(file,"-");
    emitInt2(file,-ival);
  } else emitInt2(file,ival);
}

/*
**
** emitInt2
**
*/
PRIVATE
#ifdef __ANSI_C__
void emitInt2(FILE *file, int ival)
#else
void emitInt2(file,ival)
FILE *file;
int ival;
#endif
{
  if (ival > 0) {
    emitInt2(file,ival/10);
    putc('0' + ival % 10,file);
  }
}

/*
**
** emitString
**
*/
PRIVATE
#ifdef __ANSI_C__
void emitString(FILE *file, char *sval)
#else
void emitString(file,sval)
FILE *file;
char *sval;
#endif
{
  char *p;

  if (sval == NULL) return;
  for (p=sval; *p; p++) putc(*p,file);
}

/*
**
** gprintf:
**
**   Code Generation emitter Function
**
**   Format Control Codes:
**     %%   emit a '%'
**     %d   emit an integer
**     %s   emit a string
**     %H   emit a hexidecimal coded string (non-printable)
**     %J   emit a quoted string literal
**
*/
PUBLIC
#ifdef __ANSI_C__
void gprintf(FILE *file, char *format, ...)
#else
void gprintf(va_alist)
va_dcl
#endif
{
#ifdef __ANSI_C__
  va_list ap;
#else
  va_list ap;
  FILE *file;
  char *format;
#endif
  char *c;
  char cval;
  int ival;
  char *sval;

#ifdef __ANSI_C__
  va_start(ap,format);
#else
  va_start(ap);
  file = va_arg(ap, FILE *);
  format = va_arg(ap, char *);
#endif

  for (c=format; *c; c++) {
    if (*c == '%') {
      c++;
      switch(*c) {
      case '%':
        putc(*c,file);
        break;
      case 'c':
        cval = va_arg(ap,int);
        putc(cval,file);
        break;
      case 'd':
        ival = va_arg(ap,int);
        emitInt(file,ival);
        break;
      case 's':
        sval = va_arg(ap,char*);
        emitString(file,sval);
        break;
      case 'H':
        sval = va_arg(ap,char*);
        emitHexString(file,sval);
        break;
      case 'J':
        sval = va_arg(ap,char*);
        putc('\"',file);
        emitString(file,sval);
        putc('\"',file);
        break;
      }
    } else if (*c == '\\') {
      c++;
      switch(*c) {
      case 'n':
        putc('\n',file);
        break;
      case 't':
        putc('\t',file);
        break;
      case 'b':
        putc('\b',file);
        break;
      case 'r':
        putc('\r',file);
        break;
      case '\\':
        putc('\\',file);
        break;
      default:
        putc(*c,file);
        break;
      }
    } else putc(*c,file);
  }
  va_end(ap);
}

/*
**
** hexChar
**
*/
PRIVATE
#ifdef __ANSI_C__
char hexChar(unsigned int c)
#else
char hexChar(c)
unsigned int c;
#endif
{
  if (c >= 0 && c <= 9) return (c + '0');
  if (c >= 10 && c <= 15) return (c + 'A' - 10);
  return ('\0');
}
