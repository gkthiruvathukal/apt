/******************************************************************
**
** SETS.H:
**
**    APT Set (F/L/NT/FL) Construction
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef SETS_H
#define SETS_H

/* ----------- Exported Globals */

EXTERN short **first;
EXTERN short **follow;
EXTERN short **last;
EXTERN short **nextto;

/* ----------- Exported Function Prototypes */

#ifdef __ANSI_C__
void ConstructFirstLastSets(void);
void ConstructFollowSet(void);
void ConstructNextToSet(void);
#else
void ConstructFirstLastSets();
void ConstructFollowSet();
void ConstructNextToSet();
#endif /* __ANSI_C__ */

#endif /* SETS_H */
