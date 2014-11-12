/************************************************************/
/*                                                          */
/* -- Apt Scanning Tool (AST)                               */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- CONVERT.C - Apt Scanning Tool List Conversion         */
/*                Implementation Module                     */
/*                                                          */
/************************************************************/

#include "apt.h"

#include "astmain.h"
#include "astparse.h"
#include "convert.h"
#include "find.h"
#include "matrix.h"

short **Shift, **ActionM, **Attribute, **reaches;

void BuildReachesMatrix()
{
   struct transition_record *p;
   int i;

   reaches = imatrix(0,states,0,states);
   for (p=transitionList; p != NULL; p=p->next)
      reaches[findSymbolinList(stateList,p->state_i)]
             [findSymbolinList(stateList,p->state_j)] = 1;
   for (i=0; i < states; i++) reaches[i][i] = 1;
}

void BuildTransitionMatrix()
{
	struct transition_record *p;
	int state_i, state_j, symbol, action, attribute;
	int i, j;

	Shift = imatrix(0,states,0,symbols);
	ActionM = imatrix(0,states,0,symbols);
  Attribute = imatrix(0,states,0,symbols);
	for (i=0; i < states; i++)
		for (j=0; j < symbols; j++)
			ActionM[i][j] = Shift[i][j] = -1;

	for (p=transitionList; p != NULL; p=p->next) {
		state_i = findSymbolinList(stateList,p->state_i);
		state_j = findSymbolinList(stateList,p->state_j);
		symbol = findSymbolinList(symbolList,p->symbol);
		action = findSymbolinList(actionList,p->action);
      attribute = findSymbolinList(attributeList,p->attribute);
		Shift[state_i][symbol] = state_j;
		ActionM[state_i][symbol] = action;
      Attribute[state_i][symbol] = attribute;
	}
}
