#ifndef ntscan_h
#define ntscan_h

#include "apt.h"

EXTERN ScanInfo scanInfo;

#ifdef __ANSI_C__
void InitIgnore(ScanInfo);
#else
void InitIgnore();
#endif

enum States {
	S_Integer,
	S_Comment,
	S_FileIdent,
	S_Ident,
	S_Start,
	S_Error
};

enum TerminalDefinitions {
	T_integer,
	T_comma,
	T_deref,
	T_rbrack,
	T_lbrack,
	T_semico,
	T_rbrace,
	T_lbrace,
	T_fileIdent,
	T_ident,
	T_EoF,
	TerminalCount
};

#define StateCount S_Error

#endif /* ntscan_h */
