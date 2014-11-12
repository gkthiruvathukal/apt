/******************************************************************
**
** MOLD.C:
**
**    AST List Management
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef MOLD_H
#define MOLD_H

/* ---------- External Function Prototypes */

#ifdef __ANSI_C__
struct state_arc_record *insertSymbol(struct state_arc_record*, char*);
struct transition_record *insertTransition(struct transition_record*, 
                                           struct transition_record*);
struct state_arc_record *newSymbol(char*);
struct transition_record *newTransition(char*, char*, char*, char*, char*);
#else
struct state_arc_record *insertSymbol();
struct transition_record *insertTransition();
struct state_arc_record *newSymbol();
struct transition_record *newTransition();
#endif /* __ANSI_C__ */

#endif /* MOLD_H */
