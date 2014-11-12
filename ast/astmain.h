/******************************************************************
**
** ASTMAIN.H:
**
**    AST Main Module
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTMAIN_H
#define ASTMAIN_H

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"
#include "astlib.h"

/* ---------- Defines */

#define Default "default"
#define Lambda "lambda"
#define ReturnErrorToken "ReturnErrorToken"
#define ReturnToken "ReturnToken"

/* ---------- Types */

enum AstOptionList {
  AstOptInclude,
  AstOptAnalyze,
  AstOptTerminals
};

struct state_arc_record {
	char *text;
	int count;
	struct state_arc_record *next;
};

struct transition_record {
	char *state_i, *state_j, *symbol, *action, *attribute;
	struct transition_record *next;
};

/* ---------- Exported Globals */

EXTERN FILE *file;
EXTERN char *NameOfStartState;
EXTERN char *scanFileName;
EXTERN char *scanFilePrefix;
EXTERN char *codeFileName;
EXTERN char *headFileName;
EXTERN char **symbolFileNames;
EXTERN int symbolFileCount;
EXTERN int AstFlags[];
EXTERN ScanInfo scanInfo;

#endif /* ASTMAIN_H */
