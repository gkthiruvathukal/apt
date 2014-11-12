/******************************************************************
**
** ASTSCAN.C:
**
**    AST Scanner Module
**
** This file is part of Ast Scanning Tool (AST)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef ASTSCAN_H
#define ASTSCAN_H

/* ----------- Headers */

#include "apt.h"

/* ----------- Defines */

#define StateCount S_Error

/* ----------- Types */

enum States {
	S_Escape,
	S_ReturnToken,
	S_Quote,
	S_Identifier,
	S_Start,
	S_Error
};

enum TerminalDefinitions {
	T_QuotedLiteral,
	T_Identifier,
	T_EndOfFile,
	T_EndOfLine,
	T_Error,
	TerminalCount
};

#endif /* ASTSCAN_H */
