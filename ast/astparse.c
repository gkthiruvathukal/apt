/******************************************************************
**
** ASTPARSE.C:
**
**    AST Parser Module
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#include "apt.h"
#include "aptlib.h"
#include "astlib.h"
#include "astmain.h"
#include "astparse.h"
#include "astscan.h"
#include "find.h"
#include "mold.h"
#include "sstring.h"


PUBLIC struct state_arc_record *actionList;
PUBLIC int actions;
PUBLIC struct state_arc_record *attributeList;
PUBLIC int attributes;
PUBLIC int defaultPos;
PUBLIC int lambdaPos;
PUBLIC struct state_arc_record *stateList;
PUBLIC int states;
PUBLIC struct state_arc_record *symbolList;
PUBLIC int symbols;
PUBLIC struct transition_record *transitionList;

/*
 * Parse takes lines of the following form and builds appropriate
 * list structures from them:
 * 
 * state-i quoted-literal state-j named-action
 * state-i identifier state-j named-action
 *
 * quoted-literal is a C style quoted literal which contains characters
 * which can appear on the arc joining state-i and state-j.
 *
 * identifier is the name of a function which returns true iff the character
 * in the input is of that class.
 * 
 * named action is an identifier; however, there are identifiers reserved
 * for traditional scanner operations.  In particular, the functions Advance,
 * PushBack, Ignore, and Accept, are reserved.  These functions are the ones
 * recommended for all scanners; others are supported (and code will be
 * generated) but not encouraged. 
 *
 */
void toNextLine()
{
  Token token;

  do {
    token = Scan(file);
  } while (token->type != T_EndOfFile && token->type != T_EndOfLine);
}

void AstParse()
{
  char *state_i, *state_j, *symbol, *action, *attribute;
  Token token;

  symbolList = insertSymbol(symbolList,"DEFAULT");
  symbolList = insertSymbol(symbolList,"LAMBDA");

  /* Brute force parse of input */

  for (;;) {

    token = Scan(file);

    /* search for identifier */

    if (token->type == T_EndOfFile) break;
    if (token->type == T_Identifier)
      state_i = token->text;
    else {
      toNextLine();
      continue;
    }

    /* search for identifier or quoted literal */

    token = Scan(file);
    if (token->type == T_Identifier || token->type == T_QuotedLiteral)
      symbol = token->text;
    else {
      toNextLine();
      continue;
    }

    /* search for identifier */

    token = Scan(file);
    if (token->type == T_Identifier)
      state_j = token->text;
    else {
      toNextLine();
      continue;
    }

    /* search for identifier */

    token = Scan(file);
    if (token->type == T_Identifier)
      action = token->text;
    else {
      toNextLine();
      continue;
    }

    /* search for identifier or end of line */

    token = Scan(file);
    if (token->type == T_Identifier) {
      attribute = token->text;
      toNextLine();
    } else if (token->type == T_EndOfLine)
      attribute = NULL;
    else {
      toNextLine();
      continue;
    }
    if (symbol[0] != '\"')
      symbolList = insertSymbol(symbolList,StringToUpper(symbol));
    else symbolList = insertSymbol(symbolList,symbol);
    stateList = insertSymbol(stateList,state_i);
    stateList = insertSymbol(stateList,state_j);
    actionList = insertSymbol(actionList,action);
    if (NameOfStartState == NULL) NameOfStartState = state_i;
    if (attribute != NULL)
      attributeList = insertSymbol(attributeList,attribute);
    transitionList = insertTransition(transitionList,
      newTransition(state_i,state_j,symbol,action,attribute));
  }
  symbols = lenList(symbolList);
  actions = lenList(actionList);
  states = lenList(stateList);
  attributes = lenList(attributeList);
  lambdaPos = findSymbolinList(symbolList,Lambda);
  defaultPos = findSymbolinList(symbolList,Default);
}
