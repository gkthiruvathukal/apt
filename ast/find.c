/************************************************************/
/*                                                          */
/* -- Apt Scanning Tool (AST)                               */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- FIND.C - Apt Scanning Tool List Find Module           */
/*             Implementation Module                        */
/*                                                          */
/************************************************************/


#include "astmain.h"
#include "astparse.h"
#include "aptlib.h"
#include "find.h"
#include "sstring.h"

int inList(list,name)
struct state_arc_record *list;
char *name;
{
	struct state_arc_record *p;

	for (p=list; p != NULL; p=p->next)
		if (StringCompare(p->text,name) == 0)
			return 1;
	return 0;
}

int findSymbolinList(list,name)
struct state_arc_record *list;
char *name;
{
	struct state_arc_record *p;
	int i;

	for (i=0, p=list; p != NULL; p=p->next, i++)
		if (StringCompare(p->text,name) == 0)
			return i;
	return -1;
}

/* find */

int isBuiltIn(symbol)
char *symbol;
{
   static char *builtins[] = {
      "Advance",
      "PushBack",
      "Ignore",
      "Match",
      "Flush",
      "InitAdvance",
      "InitMatch",
      "PushBack2AndFix"
   };
   char **ip;

   for (ip=builtins; *ip != NULL; ip++)
      if (StringCompare(*ip,symbol) == 0)
         return 1;
   return 0;
}

int isIntrinsic(symbol)
char *symbol;
{
   static char *intrinsics[] = {
      "DEFAULT",
      "LAMBDA",
      "ALPHA",
      "NUMERIC",
      "ALPHANUMERIC",
      "HEXDIGIT",
      "OCTALDIGIT",
      "WHITESPACE",
      "ENDOFFILE",
      NULL
   };
   char **ip;

   for (ip=intrinsics; *ip != NULL; ip++)
      if (StringCompare(*ip,symbol) == 0)
         return 1;
   return 0;
}

int lenList(list)
struct state_arc_record *list;
{
	int i;
	for (i=0; list != NULL; list=list->next, i++)
		;
	return i;
}

char *stateAt(i)
int i;
{
	struct state_arc_record *p;

	for (p=stateList; i && p != NULL; i--, p=p->next)
		;
	return p->text;
}

char *symbolAt(i)
int i;
{
	struct state_arc_record *p;

	for (p=symbolList; i && p != NULL; i--, p=p->next)
		;
	return p->text;
}

char *actionAt(i)
int i;
{
	struct state_arc_record *p;

	for (p=actionList; i && p != NULL; i--, p=p->next)
		;
	return p->text;
}

char *attributeAt(i)
int i;
{
	struct state_arc_record *p;

	for (p=attributeList; i && p != NULL; i--, p=p->next)
		;
	return p->text;
}


