/******************************************************************
**
** LISTFILE.H:
**
**    APT Listing Output
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef LISTFILE_H
#define LISTFILE_H

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
void listSet(char *caption, short **set);
void listSets(void);
void listSymbolTable(void);
#else
void listSet();
void listSets();
void listSymbolTable();
#endif

#endif /* LISTFILE_H */
