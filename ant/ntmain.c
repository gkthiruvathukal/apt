/******************************************************************
**
** NTMAIN.C:
**
**    NT Main Module 
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ---------- Headers */

#include "apt.h"

#include "ntparse.h"
#include "ntscan.h"

#include "aptlib.h"
#include "astlib.h"

#include "buffer.h"
#include "bufio.h"
#include "gprintf.h"

/* ---------- Exported Globals */

PUBLIC char *SFilePrefix;

/* ---------- Private Globals */

PRIVATE char *FooterMemo[] = {
  "ANT Terminated Normally",
  NULL
};

PRIVATE char *HeaderMemo[] = {
  "Apt Node Tool 1.2",
  "Copyright (c) 1991 -- Apt Technologies",
  NULL
};

PRIVATE int LastLinePrinted = 0;

PRIVATE char *UsageMemo[] = {
  "ANT accepts a node description file and translates it into a header",
  "file and a code file.  The header file contains enumeration types,",
  "structure types, and union types, while the code file contains",
  "routines to allocate the different structures.",
  "",
  "To put the ANT to work, supply files of the form *.nt at the",
  "command line prompt:",
  "",
  "% nt file1.nt file2.nt ... filen.nt",
  NULL
};

/* ---------- Private Prototypes */

#ifdef __ANSI_C__
int main(int, char**);
static int DigitsIn(int);
static void EraseSpaces(FILE*, int, int);
static int LogBase10(int);
static void PrintFooter(void);
static void PrintHeader(void);
static void PrintLine(Token);
static void PrintMemo(char**);
static void PrintPhaseName(char*);
static void PrintUsageInfo(void);
static void ProcessSFile(char*);
#else
int main();
static int DigitsIn();
static void EraseSpaces();
static int LogBase10();
static void PrintFooter();
static void PrintHeader();
static void PrintLine();
static void PrintMemo();
static void PrintPhaseName();
static void PrintUsageInfo();
static void ProcessSFile();
#endif

/* ----------- Functions */

/*
**
** main
**
*/
#ifdef __ANSI_C__
int main(int argc, char **argv)
#else
int main(argc,argv)
int argc;
char *argv[];
#endif
{
  int i;

  PrintHeader();
  if (argc < 2) PrintUsageInfo();
  BufIOInitialize();
  ParseInitialize();
  for (i=1; i<argc; i++) ProcessSFile(argv[i]);
  PrintFooter();
  exit(0);
}

/*
**
** DigitsIn
**
*/
PRIVATE
#ifdef __ANSI_C__
int DigitsIn(int n)
#else
int DigitsIn(n)
int n;
#endif
{
  return (LogBase10(n) + 1);
}

/*
**
** EraseSpaces
**
*/
PRIVATE
#ifdef __ANSI_C__
void EraseSpaces(FILE *file, int n, int obliterate)
#else
void EraseSpaces(file,n,obliterate)
FILE *file;
int n;
int obliterate;
#endif
{
  int i;

  for (i=0; i<n; i++) {
    putc('\b',file);
    if (obliterate) {
      putc(' ',file);
      putc('\b',file);
    }
  }
}

/*
**
** LogBase10
**
*/
PRIVATE
#ifdef __ANSI_C__
int LogBase10(int n)
#else
int LogBase10(n)
int n;
#endif
{
  int log = 0;

  if (n<=0) return (0);
  for (;n>0;n/=10) log++;
  return (log-1);
}

/*
**
** PrintFooter
**
*/
PRIVATE
#ifdef __ANSI_C__
void PrintFooter(void)
#else
void PrintFooter()
#endif
{
  PrintMemo(FooterMemo);
}

/*
**
** PrintHeader
**
*/
PRIVATE
#ifdef __ANSI_C__
void PrintHeader(void)
#else
void PrintHeader()
#endif
{
  PrintMemo(HeaderMemo);
}

/*
**
** PrintLine
**
*/ 
PRIVATE
#ifdef __ANSI_C__
void PrintLine(Token token)
#else
void PrintLine(token)
Token token;
#endif
{
#if 1
  if (LastLinePrinted > 0) EraseSpaces(stdout,DigitsIn(LastLinePrinted),0);
  gprintf(stdout,"%d",token->line);
  LastLinePrinted = token->line;
#else
  gprintf(stdout,"%s\n",token->text);
#endif
}

/*
**
** PrintMemo
**
*/
PRIVATE
#ifdef __ANSI_C__
void PrintMemo(char **memo)
#else
void PrintMemo(memo)
char **memo;
#endif
{
  char **memoline;

  for (memoline=memo; *memoline != NULL; memoline++)
    gprintf(stdout,"%s\n",*memoline);
  gprintf(stdout,"\n");
}

/*
**
** PrintPhaseName
**
*/
PRIVATE
#ifdef __ANSI_C__
void PrintPhaseName(char *phase)
#else
void PrintPhaseName(phase)
char *phase;
#endif
{
  gprintf(stdout,"Semantic Phase: %s\n",phase);
}

/*
**
** PrintUsageInfo
**
*/
PRIVATE
#ifdef __ANSI_C__
void PrintUsageInfo(void)
#else
void PrintUsageInfo()
#endif
{
  PrintMemo(UsageMemo);
  exit(1);
}

/*
**
** ProcessSFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void ProcessSFile(char *fpName)
#else
void ProcessSFile(fpName)
char *fpName;
#endif
{
  Buffer buffer;
  FILE *ep;
  char *epName;
  FILE *fp;
  char *p;

  buffer = BufferNew();
  for (p=fpName; *p; p++) {
    if (*p == '.') break;
    BufferAddChar(buffer,*p);
  }
  SFilePrefix = BufferToString(buffer);
  BufferAddString(buffer,".eopm");
  epName = BufferToString(buffer);
  BufferDispose(buffer);

  /* Write the EOPM File */
  fp = fopen(fpName,"r");
  if (fp == NULL) goto clean_exit;
  ep = fopen(epName,"w");
  if (ep == NULL) goto clean_exit;
  ScanStateSwitch(&scanInfo,fp);
  gprintf(stdout,"Parse Source File: %s => ",fpName);
  LastLinePrinted = 0;
  SetDebugOption(DebugToken);
  ParseEOPMOut(fp,ep,PrintLine,NULL);
  ResetDebugOption(DebugToken);
  gprintf(stdout," Lines OK\n");
  ScanStateRevert(&scanInfo);
  fclose(ep);
  fclose(fp);

  /* Read the EOPM File */
  ep = fopen(epName,"r");
  if (ep == NULL) goto clean_exit;
  gprintf(stdout,"Parse EOPM File: %s\n",epName);
  LastLinePrinted = 0;
  SetDebugOption(DebugToken);
  ParseEOPMIn(ep,PrintLine,PrintPhaseName);
  ResetDebugOption(DebugToken);
  fclose(ep);
  unlink(epName);

clean_exit:

  free(epName);
  gprintf(stdout,"\n");
}
