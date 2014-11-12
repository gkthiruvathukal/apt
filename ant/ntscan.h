#ifndef ntscan_h
#define ntscan_h

#include "apt.h"

#include "ntparse.h"

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

#define StateCount S_Error

#endif /* ntscan_h */
