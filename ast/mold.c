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

/* ----------- C Headers */

/* ----------- Headers */

#include "apt.h"

#include "allocate.h"
#include "astmain.h"
#include "find.h"
#include "mold.h"
#include "sstring.h"

/* ----------- Functions */

struct state_arc_record *newSymbol(name)
char *name;
{
	struct state_arc_record *new;
	new = (struct state_arc_record *)Allocate(sizeof(struct state_arc_record));
	new->text = name;
	new->count = 1;
	new->next = NULL;
	return new;
}

struct transition_record *newTransition(state_i,state_j,symbol,action,attribute)
char *state_i, *state_j, *symbol, *action, *attribute;
{
	struct transition_record *new;

	new = (struct transition_record *)Allocate(sizeof(struct transition_record));
	new->state_i = state_i;
	new->state_j = state_j;
	new->symbol = symbol;
	new->action = action;
   new->attribute = attribute;
   new->next = NULL;
	return new;
}

struct state_arc_record *insertSymbol(list,name)
struct state_arc_record *list;
char *name;
{
	if (inList(list,name)) {
		struct state_arc_record *p;
		for (p=list; p != NULL; p=p->next)
			if (StringCompare(p->text,name) == 0)
				p->count++;
		return list;
	} else {
		struct state_arc_record *new;
		new = newSymbol(name);
		new->next = list;
		return new;
	}
}

struct transition_record *insertTransition(list,new)
struct transition_record *list, *new;
{
   if (list == NULL) {
      list = new;
   } else {
      struct transition_record *p, *lastp;

      for (lastp=NULL, p=list; p != NULL; p=p->next)
         lastp = p;
      lastp->next = new;
   }
   return list;
}
