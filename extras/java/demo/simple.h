#ifndef simple_h
#define simple_h

#include "apt.h"

EXTERN ScanInfo scanInfo;

#ifdef __ANSI_C__
void InitIgnore(ScanInfo);
#else
void InitIgnore();
#endif

enum States {
	S_Float2,
	S_Float1,
	S_Comment,
	S_Integer,
	S_Ident,
	S_Start,
	S_Error
};

enum TerminalDefinitions {
	T_error,
	T_equals,
	T_comma,
	T_mod,
	T_div,
	T_mul,
	T_sub,
	T_add,
	T_rbrack,
	T_lbrack,
	T_semico,
	T_rparen,
	T_lparen,
	T_rbrace,
	T_lbrace,
	T_ident,
	T_Float,
	T_Integer,
	T_EoF,
	TerminalCount
};

#define StateCount S_Error

#endif /* simple_h */
