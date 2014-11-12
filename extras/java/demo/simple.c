#include <stdio.h>
#include <stdlib.h>

#include "apt.h"

#include "simple.h"

#include "astlib.h"

#include "buffer.h"
#include "bufio.h"

PUBLIC ScanInfo scanInfo;

Token Scan(file)
FILE *file;
{
	int CurrentChar = 0;

	SetScanFile(scanInfo,file);
	SetScanState(scanInfo,S_Start);
	SetScanAttribute(scanInfo,-1);
	SetScanBuffer(scanInfo,BufferNew());
	Ignore(scanInfo);
	for (;;) {
		CurrentChar = GetScanChar(scanInfo);
		switch(GetScanState(scanInfo)) {
			case S_Float2:
				if (NUMERIC(CurrentChar)) {
					Advance(scanInfo);
				}
				else if (LAMBDA(CurrentChar)) {
					PushBack(scanInfo);
					SetScanAttribute(scanInfo,T_Float);
					return (MakeToken(scanInfo));
				}
				break;
			case S_Float1:
				if (NUMERIC(CurrentChar)) {
					Advance(scanInfo);
					SetScanState(scanInfo,S_Float2);
				}
				else if (LAMBDA(CurrentChar)) {
					PushBack(scanInfo);
					SetScanAttribute(scanInfo,T_Float);
					return (MakeToken(scanInfo));
				}
				break;
			case S_Comment:
				if (CharInString(CurrentChar,"\n")) {
					Ignore(scanInfo);
					SetScanState(scanInfo,S_Start);
				}
				else if (LAMBDA(CurrentChar)) {
					Ignore(scanInfo);
				}
				break;
			case S_Integer:
				if (CharInString(CurrentChar,".")) {
					Advance(scanInfo);
					SetScanState(scanInfo,S_Float1);
				}
				else if (NUMERIC(CurrentChar)) {
					Advance(scanInfo);
				}
				else if (LAMBDA(CurrentChar)) {
					PushBack(scanInfo);
					SetScanAttribute(scanInfo,T_Integer);
					return (MakeToken(scanInfo));
				}
				break;
			case S_Ident:
				if (NUMERIC(CurrentChar)) {
					Advance(scanInfo);
				}
				else if (CharInString(CurrentChar,"_")) {
					Advance(scanInfo);
				}
				else if (ALPHA(CurrentChar)) {
					Advance(scanInfo);
				}
				else if (LAMBDA(CurrentChar)) {
					PushBack(scanInfo);
					SetScanAttribute(scanInfo,T_ident);
					return (MakeToken(scanInfo));
				}
				break;
			case S_Start:
				if (WHITESPACE(CurrentChar)) {
					Ignore(scanInfo);
				}
				else if (CharInString(CurrentChar,"=")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_equals);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,",")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_comma);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"%")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_mod);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"/")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_div);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"*")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_mul);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"-")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_sub);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"+")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_add);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"]")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_rbrack);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"[")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_lbrack);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,";")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_semico);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,")")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_rparen);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"(")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_lparen);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"}")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_rbrace);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"{")) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_lbrace);
					return (MakeToken(scanInfo));
				}
				else if (CharInString(CurrentChar,"#")) {
					Ignore(scanInfo);
					SetScanState(scanInfo,S_Comment);
				}
				else if (NUMERIC(CurrentChar)) {
					InitAdvance(scanInfo);
					SetScanState(scanInfo,S_Integer);
				}
				else if (CharInString(CurrentChar,"_")) {
					InitAdvance(scanInfo);
					SetScanState(scanInfo,S_Ident);
				}
				else if (ALPHA(CurrentChar)) {
					InitAdvance(scanInfo);
					SetScanState(scanInfo,S_Ident);
				}
				else if (ENDOFFILE(CurrentChar)) {
					InitIgnore(scanInfo);
					SetScanAttribute(scanInfo,T_EoF);
					return (MakeToken(scanInfo));
				}
				else if (LAMBDA(CurrentChar)) {
					InitMatch(scanInfo);
					SetScanAttribute(scanInfo,T_error);
					return (MakeToken(scanInfo));
				}
				break;
			default:
				gprintf(stderr,"Illegal State Encountered.\n");
				exit(1);
		}
	}
}
