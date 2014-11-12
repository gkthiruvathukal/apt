/******************************************************************
**
** ANALYSIS.C:
**
**    AST FSM Analysis Module
**
** This file is part of Apt Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ----------- C Headers */

/* ----------- Headers */

#include "apt.h"

#include "astmain.h"
#include "astparse.h"
#include "closure.h"
#include "convert.h"
#include "find.h"

#include "allocate.h"
#include "gprintf.h"
#include "sstring.h"

/* ----------- Functions */

void checkForErrors()
{
  int i, j, errors = 0;
  int startStateIndex;
  int *acceptingState, acceptingStates;
  struct transition_record *p;

  acceptingStates = lenList(stateList);
  acceptingState = (int *)Allocate(acceptingStates * sizeof(int));
  for (p=transitionList; p != NULL; p=p->next)
    if (p->attribute != NULL)
      acceptingState[findSymbolinList(stateList,p->state_i)] = 1;

#if 0
      if (StringCompare(p->state_j,ReturnToken) == 0)
         acceptingState[findSymbolinList(stateList,p->state_i)] = 1;
      if (StringCompare(p->state_j,ReturnErrorToken) == 0)
         acceptingState[findSymbolinList(stateList,p->state_i)] = 1;
#endif

  startStateIndex = findSymbolinList(stateList,stateAt(states-1));

  BuildReachesMatrix();
  Warshall(reaches,states);

  for (i=0; i<states; i++) {
    if (StringCompare(stateAt(i),ReturnToken) == 0) continue;
    if (StringCompare(stateAt(i),ReturnErrorToken) == 0) continue;
    if (!reaches[startStateIndex][i]) {
      gprintf(stderr,"Error: State %s cannot be reached from");
      gprintf(stderr," the starting state.\n",stateAt(i));
      errors = 1;
    }
    for (j=0; j<states; j++) if (reaches[i][j] && acceptingState[j]) break;
    if (j == acceptingStates) {
      gprintf(stderr,"Error: State %s does not reach an");
      gprintf(stderr," accepting state.\n",stateAt(i));
      errors = 1;
    }
  }
  if (errors) {
    gprintf(stderr,"\nErrors detected during processing:");
    gprintf(stderr," Apt Scan Tool aborted.\n");
    exit(1);
  }
}
