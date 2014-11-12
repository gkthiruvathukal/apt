/************************************************************/
/*                                                          */
/* -- Apt Parsing Tool (APT) for LL(1) Parsing              */
/* -- Copyright (c) 1990 by Apt Technologies                */
/* -- Version 2                                             */
/*                                                          */
/* -- Encode.h - Generate code for parse tables for the     */
/*               appropriate language                       */
/*                                                          */
/************************************************************/

#ifndef ASTCGEN_H
#define ASTCGEN_H

#ifdef __ANSI_C__
void codegen(void);
void genHeader(void);
void genCode(void);
#else
void codegen();
void genHeader();
void genCode();
#endif
#endif
