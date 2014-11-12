/******************************************************************
**
** DEBUG.H:
**
**    APT Debugging Routines
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef DEBUG_H
#define DEBUG_H

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void DisplayMessage(int tab, char *s);
void DumpProduction(int id);
void ReportMinLenTermString(void);
void ReportUnreachableSymbols(void);
#else
void DisplayMessage();
void DumpProduction();
void ReportMinLenTermString();
void ReportUnreachableSymbols();
#endif /* __ANSI_C__ */

#endif /* DEBUG_H */
