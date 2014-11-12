#ifndef icnparse_c
#define icnparse_c

#include "apt.h"
#include "aptlib.h"
#include "astlib.h"
#include "icnparse.td"
#include "icnparse.h"
#include "icnparse.pt"
#include "apttext.h"

_SymbolTableElement SymbolTable[] = {
  "Goal", NonTerminal,
  "decl", NonTerminal,
  "progtl", NonTerminal,
  "prog", NonTerminal,
  "sep", NonTerminal,
  "type", NonTerminal,
  "fieldlistopt", NonTerminal,
  "typetail", NonTerminal,
  "paramlist", NonTerminal,
  "globaldec", NonTerminal,
  "procdec", NonTerminal,
  "typedec", NonTerminal,
  "idlistd", NonTerminal,
  "idlistdtl", NonTerminal,
  "idlistptl", NonTerminal,
  "idlistp", NonTerminal,
  "fieldlist", NonTerminal,
  "fieldlisttl", NonTerminal,
  "header", NonTerminal,
  "locopt", NonTerminal,
  "initopt", NonTerminal,
  "seq", NonTerminal,
  "refopt", NonTerminal,
  "parameter", NonTerminal,
  "paramlisttl", NonTerminal,
  "localspec", NonTerminal,
  "localstl", NonTerminal,
  "locals", NonTerminal,
  "e", NonTerminal,
  "eopt", NonTerminal,
  "seqtl", NonTerminal,
  "e1", NonTerminal,
  "e2", NonTerminal,
  "e1tl", NonTerminal,
  "e3", NonTerminal,
  "e2tl", NonTerminal,
  "e4", NonTerminal,
  "e3tl", NonTerminal,
  "asgnop", NonTerminal,
  "e5", NonTerminal,
  "e4tl", NonTerminal,
  "byopt", NonTerminal,
  "e6", NonTerminal,
  "e5tl", NonTerminal,
  "e7", NonTerminal,
  "e6tl", NonTerminal,
  "relop", NonTerminal,
  "e8", NonTerminal,
  "e7tl", NonTerminal,
  "e9", NonTerminal,
  "e8tl", NonTerminal,
  "addop", NonTerminal,
  "e10", NonTerminal,
  "e9tl", NonTerminal,
  "mulop", NonTerminal,
  "e11", NonTerminal,
  "e10tl", NonTerminal,
  "e12", NonTerminal,
  "e11tl", NonTerminal,
  "uop", NonTerminal,
  "e13", NonTerminal,
  "ek", NonTerminal,
  "e14", NonTerminal,
  "e13tl", NonTerminal,
  "elist", NonTerminal,
  "rangetl", NonTerminal,
  "elisttl", NonTerminal,
  "doopt", NonTerminal,
  "elseopt", NonTerminal,
  "caselist", NonTerminal,
  "caseclause", NonTerminal,
  "caselisttl", NonTerminal,
  "kwdtl", NonTerminal,
  "lit", NonTerminal,
  "EoF", Terminal,
  "any", Terminal,
  "int", Terminal,
  "real", Terminal,
  "string", Terminal,
  "cset", Terminal,
  "void", Terminal,
  "id", Terminal,
  "record", Terminal,
  "{", Terminal,
  "}", Terminal,
  "union", Terminal,
  "set", Terminal,
  "of", Terminal,
  "[", Terminal,
  "]", Terminal,
  "(", Terminal,
  ")", Terminal,
  "ref", Terminal,
  "=", Terminal,
  "global", Terminal,
  ":", Terminal,
  "external", Terminal,
  ",", Terminal,
  ";", Terminal,
  "end", Terminal,
  "procedure", Terminal,
  "eol", Terminal,
  "local", Terminal,
  "static", Terminal,
  "dynamic", Terminal,
  "initial", Terminal,
  "&", Terminal,
  "?", Terminal,
  "to", Terminal,
  "by", Terminal,
  "|", Terminal,
  "catop", Terminal,
  "^", Terminal,
  "\\", Terminal,
  "@", Terminal,
  "[:", Terminal,
  ".", Terminal,
  "+:", Terminal,
  "-:", Terminal,
  "repeat", Terminal,
  "while", Terminal,
  "until", Terminal,
  "every", Terminal,
  "if", Terminal,
  "then", Terminal,
  "case", Terminal,
  "next", Terminal,
  "break", Terminal,
  "return", Terminal,
  "suspend", Terminal,
  "fail", Terminal,
  "create", Terminal,
  "do", Terminal,
  "else", Terminal,
  "defaultclause", Terminal,
  "default", Terminal,
  "<", Terminal,
  "<=", Terminal,
  ">", Terminal,
  ">=", Terminal,
  "~=", Terminal,
  "not", Terminal,
  "!", Terminal,
  "*", Terminal,
  "+", Terminal,
  "-", Terminal,
  "/", Terminal,
  "~", Terminal,
  "%", Terminal,
  "**", Terminal,
  "++", Terminal,
  "--", Terminal,
  ":=", Terminal,
  "*:=", Terminal,
  "/:=", Terminal,
  "%:=", Terminal,
  "**:=", Terminal,
  "+:=", Terminal,
  "-:=", Terminal,
  "++:=", Terminal,
  "--:=", Terminal,
  "intcon", Terminal,
  "radintcon", Terminal,
  "realcon", Terminal,
  "csetcon", Terminal,
  "stringcon", Terminal,
  "hexcon", Terminal,
  "octcon", Terminal,
  "_Prologue", Action,
  "_Epilogue", Action,
  "_DeclList", Action,
  "_SimpleType", Action,
  "_UserType", Action,
  "_RecordType", Action,
  "_UnionType", Action,
  "_SetType", Action,
  "_ListType", Action,
  "_TableType", Action,
  "_ProcType", Action,
  "_RefType", Action,
  "_NestedType", Action,
  "_NoDecl", Action,
  "_TypeDef", Action,
  "_GlobDecl", Action,
  "_EnqueueFirstIdDecl", Action,
  "_EnqueueNextIdDecl", Action,
  "_EnqueueFirstIdProc", Action,
  "_EnqueueNextIdProc", Action,
  "_NoFields", Action,
  "_FirstField", Action,
  "_NextField", Action,
  "_EndFields", Action,
  "_ProcDecl", Action,
  "_LocalTable", Action,
  "_ProcHead", Action,
  "_EnqueueFirstParameter", Action,
  "_MakeQueueD", Action,
  "_EnqueueNextParameter", Action,
  "_ScrubParameter", Action,
  "_Ref", Action,
  "_NoRef", Action,
  "_Discard", Action,
  "_LocalDecl", Action,
  "_Initializer", Action,
  "_NoInitializer", Action,
  "_ExpSeqHead", Action,
  "_ExpSeqNext", Action,
  "_NoExp", Action,
  "_BinOp", Action,
  "_TerOp", Action,
  "_RelOp", Action,
  "_UnaryOp", Action,
  "_ProcCall", Action,
  "_Subscript", Action,
  "_Cast", Action,
  "_FieldRef", Action,
  "_Range", Action,
  "_NoRange", Action,
  "_NoExpSeq", Action,
  "_ExpSeqNext2", Action,
  "_Repeat", Action,
  "_While", Action,
  "_Until", Action,
  "_Every", Action,
  "_Case", Action,
  "_Next", Action,
  "_Break", Action,
  "_Return", Action,
  "_Suspend", Action,
  "_Fail", Action,
  "_Create", Action,
  "_Do", Action,
  "_NoDo", Action,
  "_IfThenElse", Action,
  "_IfThen", Action,
  "_CaseListHead", Action,
  "_CaseListNext", Action,
  "_CaseClause", Action,
  "_DefaultClause", Action,
  "_NoCaseClause", Action,
  "_Parens", Action,
  "_ListCons", Action,
  "_Block", Action,
  "_Var", Action,
  "_Keyword", Action,
  "_ConstInt", Action,
  "_ConstRadix", Action,
  "_ConstReal", Action,
  "_ConstCset", Action,
  "_ConstString", Action,
  "_MakeQueue", Action,
  "_MoreLocalDecl", Action,
  "_NoIdList1", Action,
  "_NoIdList2", Action,
  "_NoInitList", Action,
  "_NoParameters", Action,
  NULL
};

short _RHS[] = {
  NT_prog, T_EoF, 
  A__Prologue, NT_decl, NT_progtl, A__Epilogue, 
  NT_sep, NT_decl, A__DeclList, NT_progtl, 
  T_any, A__SimpleType, 
  T_int, A__SimpleType, 
  T_real, A__SimpleType, 
  T_string, A__SimpleType, 
  T_cset, A__SimpleType, 
  T_void, A__SimpleType, 
  T_id, A__UserType, 
  T_record, T_lbrace, NT_fieldlistopt, T_rbrace, A__RecordType, 
  T_union, T_lbrace, NT_fieldlistopt, T_rbrace, A__UnionType, 
  T_set, T_of, NT_type, A__SetType, 
  T_lbrack, NT_typetail, 
  T_rbrack, NT_type, A__ListType, 
  NT_type, T_rbrack, NT_type, A__TableType, 
  T_lparen, NT_paramlist, T_rparen, NT_type, A__ProcType, 
  T_ref, NT_type, A__RefType, 
  T_lbrace, NT_type, T_rbrace, A__NestedType, 
  NT_globaldec, 
  NT_procdec, 
  NT_typedec, 
  A__NoDecl, 
  NT_type, T_id, T_equal, NT_type, A__TypeDef, 
  T_global, NT_idlistd, T_colon, NT_type, A__GlobDecl, 
  T_external, NT_idlistd, T_colon, NT_type, A__GlobDecl, 
  T_id, A__EnqueueFirstIdDecl, NT_idlistdtl, 
  T_comma, T_id, A__EnqueueNextIdDecl, NT_idlistdtl, 
  T_id, A__EnqueueFirstIdProc, NT_idlistptl, 
  T_comma, T_id, A__EnqueueNextIdProc, NT_idlistptl, 
  A__NoFields, 
  NT_fieldlist, 
  NT_idlistd, T_colon, NT_type, A__FirstField, NT_fieldlisttl, 
  T_semico, NT_idlistd, T_colon, NT_type, A__NextField, NT_fieldlisttl, 
  A__EndFields, 
  NT_header, NT_locopt, NT_initopt, NT_seq, T_end, A__ProcDecl, 
  A__LocalTable, T_procedure, T_id, T_lparen, NT_paramlist, T_rparen, NT_refopt, NT_type, NT_sep, A__ProcHead, 
  NT_parameter, A__EnqueueFirstParameter, NT_paramlisttl, 
  A__MakeQueueD, 
  T_semico, NT_parameter, A__EnqueueNextParameter, NT_paramlisttl, 
  NT_refopt, T_id, T_colon, NT_type, A__ScrubParameter, 
  T_ref, A__Ref, 
  A__NoRef, 
  T_semico, A__Discard, 
  T_eol, A__Discard, 
  NT_localspec, NT_idlistp, T_colon, NT_type, NT_sep, A__LocalDecl, NT_localstl, 
  NT_localspec, NT_idlistp, T_colon, NT_type, NT_sep, A__LocalDecl, NT_localstl, 
  NT_locals, 
  T_local, 
  T_static, 
  T_dynamic, 
  T_initial, NT_e, NT_sep, A__Initializer, 
  A__NoInitializer, 
  NT_eopt, A__ExpSeqHead, NT_seqtl, 
  NT_sep, NT_eopt, A__ExpSeqNext, NT_seqtl, 
  A__NoExp, 
  NT_e, 
  NT_e1, 
  NT_e2, NT_e1tl, 
  T_conjop, NT_e2, A__BinOp, NT_e1tl, 
  NT_e3, NT_e2tl, 
  T_scanop, NT_e3, A__BinOp, NT_e2tl, 
  NT_e4, NT_e3tl, 
  NT_asgnop, NT_e3, A__BinOp, 
  NT_e5, NT_e4tl, 
  T_to, NT_e5, NT_byopt, NT_e4tl, 
  T_by, NT_e5, A__TerOp, 
  A__BinOp, 
  NT_e6, NT_e5tl, 
  T_altop, NT_e5, A__BinOp, 
  NT_e7, NT_e6tl, 
  NT_relop, NT_e7, A__RelOp, NT_e6tl, 
  T_equal, NT_e7, A__BinOp, NT_e6tl, 
  NT_e8, NT_e7tl, 
  T_catop, NT_e8, A__BinOp, NT_e7tl, 
  NT_e9, NT_e8tl, 
  NT_addop, NT_e9, A__BinOp, NT_e8tl, 
  NT_e10, NT_e9tl, 
  NT_mulop, NT_e10, A__BinOp, NT_e9tl, 
  NT_e11, NT_e10tl, 
  T_carat, NT_e10, A__BinOp, 
  NT_e12, NT_e11tl, 
  T_bslash, NT_e12, A__BinOp, NT_e11tl, 
  T_coop, NT_e12, A__BinOp, NT_e11tl, 
  NT_uop, NT_e12, A__UnaryOp, 
  NT_e13, 
  NT_ek, 
  NT_e14, NT_e13tl, 
  T_lparen, NT_elist, T_rparen, A__ProcCall, NT_e13tl, 
  T_lbrack, NT_e, NT_rangetl, T_rbrack, A__Subscript, NT_e13tl, 
  T_castop, NT_type, T_rbrack, A__Cast, NT_e13tl, 
  T_dot, T_id, A__FieldRef, NT_e13tl, 
  T_colon, NT_e, A__Range, 
  T_pcolon, NT_e, A__Range, 
  T_mcolon, NT_e, A__Range, 
  A__NoRange, 
  NT_e, A__ExpSeqHead, NT_elisttl, 
  A__NoExpSeq, 
  T_comma, NT_e, A__ExpSeqNext2, NT_elisttl, 
  T_repeat, NT_e, A__Repeat, 
  T_while, NT_e, NT_doopt, A__While, 
  T_until, NT_e, NT_doopt, A__Until, 
  T_every, NT_e, NT_doopt, A__Every, 
  T_if, NT_e, T_then, NT_e, NT_elseopt, 
  T_case, NT_e, T_of, T_lbrace, NT_caselist, T_rbrace, A__Case, 
  T_next, A__Next, 
  T_break, NT_eopt, A__Break, 
  T_return, NT_eopt, A__Return, 
  T_suspend, NT_eopt, A__Suspend, 
  T_fail, A__Fail, 
  T_create, NT_e, A__Create, 
  T_do, NT_e, A__Do, 
  A__NoDo, 
  T_else, NT_e, A__IfThenElse, 
  A__IfThen, 
  NT_caseclause, A__CaseListHead, NT_caselisttl, 
  NT_caseclause, A__CaseListHead, 
  NT_sep, NT_caseclause, A__CaseListNext, NT_caselisttl, 
  NT_sep, T_defaultclause, A__CaseListNext, 
  NT_e, T_colon, NT_e, A__CaseClause, 
  T_default, T_colon, NT_e, A__DefaultClause, 
  A__NoCaseClause, 
  T_lparen, NT_elist, T_rparen, A__Parens, 
  T_lbrack, NT_elist, T_rbrack, A__ListCons, 
  T_lbrace, NT_seq, T_rbrace, A__Block, 
  T_id, A__Var, 
  T_conjop, NT_kwdtl, 
  NT_lit, 
  T_id, A__Keyword, 
  T_fail, A__Keyword, 
  T_lt, 
  T_lteq, 
  T_gt, 
  T_gteq, 
  T_noteq, 
  T_not, 
  T_altop, 
  T_bang, 
  T_star, 
  T_plus, 
  T_minus, 
  T_dot, 
  T_slash, 
  T_equal, 
  T_scanop, 
  T_bslash, 
  T_tilde, 
  T_coop, 
  T_carat, 
  T_star, 
  T_slash, 
  T_pct, 
  T_starstar, 
  T_plus, 
  T_minus, 
  T_plusplus, 
  T_minusminus, 
  T_assign, 
  T_star_assign, 
  T_slash_assign, 
  T_pct_assign, 
  T_starstar_assign, 
  T_plus_assign, 
  T_minus_assign, 
  T_plusplus_assign, 
  T_minusminus_assign, 
  T_intcon, A__ConstInt, 
  T_radintcon, A__ConstRadix, 
  T_realcon, A__ConstReal, 
  T_csetcon, A__ConstCset, 
  T_stringcon, A__ConstString, 
  T_hexcon, A__ConstInt, 
  T_octcon, A__ConstInt, 
  0
};

_ProductionTableElement ProductionTable[] = {
  NT_Goal, 2, _RHS + 0,
  NT_prog, 4, _RHS + 2,
  NT_progtl, 4, _RHS + 6,
  NT_progtl, 0, _RHS + 10,
  NT_type, 2, _RHS + 10,
  NT_type, 2, _RHS + 12,
  NT_type, 2, _RHS + 14,
  NT_type, 2, _RHS + 16,
  NT_type, 2, _RHS + 18,
  NT_type, 2, _RHS + 20,
  NT_type, 2, _RHS + 22,
  NT_type, 5, _RHS + 24,
  NT_type, 5, _RHS + 29,
  NT_type, 4, _RHS + 34,
  NT_type, 2, _RHS + 38,
  NT_typetail, 3, _RHS + 40,
  NT_typetail, 4, _RHS + 43,
  NT_type, 5, _RHS + 47,
  NT_type, 3, _RHS + 52,
  NT_type, 4, _RHS + 55,
  NT_decl, 1, _RHS + 59,
  NT_decl, 1, _RHS + 60,
  NT_decl, 1, _RHS + 61,
  NT_decl, 1, _RHS + 62,
  NT_typedec, 5, _RHS + 63,
  NT_globaldec, 5, _RHS + 68,
  NT_globaldec, 5, _RHS + 73,
  NT_idlistd, 3, _RHS + 78,
  NT_idlistdtl, 4, _RHS + 81,
  NT_idlistdtl, 0, _RHS + 85,
  NT_idlistp, 3, _RHS + 85,
  NT_idlistptl, 4, _RHS + 88,
  NT_idlistptl, 0, _RHS + 92,
  NT_fieldlistopt, 1, _RHS + 92,
  NT_fieldlistopt, 1, _RHS + 93,
  NT_fieldlist, 5, _RHS + 94,
  NT_fieldlisttl, 6, _RHS + 99,
  NT_fieldlisttl, 1, _RHS + 105,
  NT_procdec, 6, _RHS + 106,
  NT_header, 10, _RHS + 112,
  NT_paramlist, 3, _RHS + 122,
  NT_paramlist, 1, _RHS + 125,
  NT_paramlisttl, 4, _RHS + 126,
  NT_paramlisttl, 0, _RHS + 130,
  NT_parameter, 5, _RHS + 130,
  NT_refopt, 2, _RHS + 135,
  NT_refopt, 1, _RHS + 137,
  NT_sep, 2, _RHS + 138,
  NT_sep, 2, _RHS + 140,
  NT_locals, 7, _RHS + 142,
  NT_localstl, 7, _RHS + 149,
  NT_localstl, 0, _RHS + 156,
  NT_locopt, 1, _RHS + 156,
  NT_locopt, 0, _RHS + 157,
  NT_localspec, 1, _RHS + 157,
  NT_localspec, 1, _RHS + 158,
  NT_localspec, 1, _RHS + 159,
  NT_initopt, 4, _RHS + 160,
  NT_initopt, 1, _RHS + 164,
  NT_seq, 3, _RHS + 165,
  NT_seqtl, 4, _RHS + 168,
  NT_seqtl, 0, _RHS + 172,
  NT_eopt, 1, _RHS + 172,
  NT_eopt, 1, _RHS + 173,
  NT_e, 1, _RHS + 174,
  NT_e1, 2, _RHS + 175,
  NT_e1tl, 4, _RHS + 177,
  NT_e1tl, 0, _RHS + 181,
  NT_e2, 2, _RHS + 181,
  NT_e2tl, 4, _RHS + 183,
  NT_e2tl, 0, _RHS + 187,
  NT_e3, 2, _RHS + 187,
  NT_e3tl, 3, _RHS + 189,
  NT_e3tl, 0, _RHS + 192,
  NT_e4, 2, _RHS + 192,
  NT_e4tl, 4, _RHS + 194,
  NT_e4tl, 0, _RHS + 198,
  NT_byopt, 3, _RHS + 198,
  NT_byopt, 1, _RHS + 201,
  NT_e5, 2, _RHS + 202,
  NT_e5tl, 3, _RHS + 204,
  NT_e5tl, 0, _RHS + 207,
  NT_e6, 2, _RHS + 207,
  NT_e6tl, 4, _RHS + 209,
  NT_e6tl, 4, _RHS + 213,
  NT_e6tl, 0, _RHS + 217,
  NT_e7, 2, _RHS + 217,
  NT_e7tl, 4, _RHS + 219,
  NT_e7tl, 0, _RHS + 223,
  NT_e8, 2, _RHS + 223,
  NT_e8tl, 4, _RHS + 225,
  NT_e8tl, 0, _RHS + 229,
  NT_e9, 2, _RHS + 229,
  NT_e9tl, 4, _RHS + 231,
  NT_e9tl, 0, _RHS + 235,
  NT_e10, 2, _RHS + 235,
  NT_e10tl, 3, _RHS + 237,
  NT_e10tl, 0, _RHS + 240,
  NT_e11, 2, _RHS + 240,
  NT_e11tl, 4, _RHS + 242,
  NT_e11tl, 4, _RHS + 246,
  NT_e11tl, 0, _RHS + 250,
  NT_e12, 3, _RHS + 250,
  NT_e12, 1, _RHS + 253,
  NT_e13, 1, _RHS + 254,
  NT_e13, 2, _RHS + 255,
  NT_e13tl, 5, _RHS + 257,
  NT_e13tl, 6, _RHS + 262,
  NT_e13tl, 5, _RHS + 268,
  NT_e13tl, 4, _RHS + 273,
  NT_e13tl, 0, _RHS + 277,
  NT_rangetl, 3, _RHS + 277,
  NT_rangetl, 3, _RHS + 280,
  NT_rangetl, 3, _RHS + 283,
  NT_rangetl, 1, _RHS + 286,
  NT_elist, 3, _RHS + 287,
  NT_elist, 1, _RHS + 290,
  NT_elisttl, 4, _RHS + 291,
  NT_elisttl, 0, _RHS + 295,
  NT_ek, 3, _RHS + 295,
  NT_ek, 4, _RHS + 298,
  NT_ek, 4, _RHS + 302,
  NT_ek, 4, _RHS + 306,
  NT_ek, 5, _RHS + 310,
  NT_ek, 7, _RHS + 315,
  NT_ek, 2, _RHS + 322,
  NT_ek, 3, _RHS + 324,
  NT_ek, 3, _RHS + 327,
  NT_ek, 3, _RHS + 330,
  NT_ek, 2, _RHS + 333,
  NT_ek, 3, _RHS + 335,
  NT_doopt, 3, _RHS + 338,
  NT_doopt, 1, _RHS + 341,
  NT_elseopt, 3, _RHS + 342,
  NT_elseopt, 1, _RHS + 345,
  NT_caselist, 3, _RHS + 346,
  NT_caselist, 2, _RHS + 349,
  NT_caselisttl, 0, _RHS + 351,
  NT_caselisttl, 4, _RHS + 351,
  NT_caselisttl, 3, _RHS + 355,
  NT_caseclause, 4, _RHS + 358,
  NT_caseclause, 4, _RHS + 362,
  NT_caseclause, 1, _RHS + 366,
  NT_e14, 4, _RHS + 367,
  NT_e14, 4, _RHS + 371,
  NT_e14, 4, _RHS + 375,
  NT_e14, 2, _RHS + 379,
  NT_e14, 2, _RHS + 381,
  NT_e14, 1, _RHS + 383,
  NT_kwdtl, 2, _RHS + 384,
  NT_kwdtl, 2, _RHS + 386,
  NT_relop, 1, _RHS + 388,
  NT_relop, 1, _RHS + 389,
  NT_relop, 1, _RHS + 390,
  NT_relop, 1, _RHS + 391,
  NT_relop, 1, _RHS + 392,
  NT_uop, 1, _RHS + 393,
  NT_uop, 1, _RHS + 394,
  NT_uop, 1, _RHS + 395,
  NT_uop, 1, _RHS + 396,
  NT_uop, 1, _RHS + 397,
  NT_uop, 1, _RHS + 398,
  NT_uop, 1, _RHS + 399,
  NT_uop, 1, _RHS + 400,
  NT_uop, 1, _RHS + 401,
  NT_uop, 1, _RHS + 402,
  NT_uop, 1, _RHS + 403,
  NT_uop, 1, _RHS + 404,
  NT_uop, 1, _RHS + 405,
  NT_uop, 1, _RHS + 406,
  NT_mulop, 1, _RHS + 407,
  NT_mulop, 1, _RHS + 408,
  NT_mulop, 1, _RHS + 409,
  NT_mulop, 1, _RHS + 410,
  NT_addop, 1, _RHS + 411,
  NT_addop, 1, _RHS + 412,
  NT_addop, 1, _RHS + 413,
  NT_addop, 1, _RHS + 414,
  NT_asgnop, 1, _RHS + 415,
  NT_asgnop, 1, _RHS + 416,
  NT_asgnop, 1, _RHS + 417,
  NT_asgnop, 1, _RHS + 418,
  NT_asgnop, 1, _RHS + 419,
  NT_asgnop, 1, _RHS + 420,
  NT_asgnop, 1, _RHS + 421,
  NT_asgnop, 1, _RHS + 422,
  NT_asgnop, 1, _RHS + 423,
  NT_lit, 2, _RHS + 424,
  NT_lit, 2, _RHS + 426,
  NT_lit, 2, _RHS + 428,
  NT_lit, 2, _RHS + 430,
  NT_lit, 2, _RHS + 432,
  NT_lit, 2, _RHS + 434,
  NT_lit, 2, _RHS + 436,
  NULL
};

_PredictionTripleElement PredictionTriple[] = {
  /* 0 */ NT_Goal, T_EoF, 0,
  /* 1 */ NT_Goal, T_any, 0,
  /* 2 */ NT_Goal, T_int, 0,
  /* 3 */ NT_Goal, T_real, 0,
  /* 4 */ NT_Goal, T_string, 0,
  /* 5 */ NT_Goal, T_cset, 0,
  /* 6 */ NT_Goal, T_void, 0,
  /* 7 */ NT_Goal, T_id, 0,
  /* 8 */ NT_Goal, T_record, 0,
  /* 9 */ NT_Goal, T_lbrace, 0,
  /* 10 */ NT_Goal, T_union, 0,
  /* 11 */ NT_Goal, T_set, 0,
  /* 12 */ NT_Goal, T_lbrack, 0,
  /* 13 */ NT_Goal, T_lparen, 0,
  /* 14 */ NT_Goal, T_ref, 0,
  /* 15 */ NT_Goal, T_global, 0,
  /* 16 */ NT_Goal, T_external, 0,
  /* 17 */ NT_Goal, T_semico, 0,
  /* 18 */ NT_Goal, T_procedure, 0,
  /* 19 */ NT_Goal, T_eol, 0,
  /* 20 */ NT_decl, T_EoF, 23,
  /* 21 */ NT_decl, T_any, 22,
  /* 22 */ NT_decl, T_int, 22,
  /* 23 */ NT_decl, T_real, 22,
  /* 24 */ NT_decl, T_string, 22,
  /* 25 */ NT_decl, T_cset, 22,
  /* 26 */ NT_decl, T_void, 22,
  /* 27 */ NT_decl, T_id, 22,
  /* 28 */ NT_decl, T_record, 22,
  /* 29 */ NT_decl, T_lbrace, 22,
  /* 30 */ NT_decl, T_union, 22,
  /* 31 */ NT_decl, T_set, 22,
  /* 32 */ NT_decl, T_lbrack, 22,
  /* 33 */ NT_decl, T_lparen, 22,
  /* 34 */ NT_decl, T_ref, 22,
  /* 35 */ NT_decl, T_global, 20,
  /* 36 */ NT_decl, T_external, 20,
  /* 37 */ NT_decl, T_semico, 23,
  /* 38 */ NT_decl, T_procedure, 21,
  /* 39 */ NT_decl, T_eol, 23,
  /* 40 */ NT_progtl, T_EoF, 3,
  /* 41 */ NT_progtl, T_semico, 2,
  /* 42 */ NT_progtl, T_eol, 2,
  /* 43 */ NT_prog, T_EoF, 1,
  /* 44 */ NT_prog, T_any, 1,
  /* 45 */ NT_prog, T_int, 1,
  /* 46 */ NT_prog, T_real, 1,
  /* 47 */ NT_prog, T_string, 1,
  /* 48 */ NT_prog, T_cset, 1,
  /* 49 */ NT_prog, T_void, 1,
  /* 50 */ NT_prog, T_id, 1,
  /* 51 */ NT_prog, T_record, 1,
  /* 52 */ NT_prog, T_lbrace, 1,
  /* 53 */ NT_prog, T_union, 1,
  /* 54 */ NT_prog, T_set, 1,
  /* 55 */ NT_prog, T_lbrack, 1,
  /* 56 */ NT_prog, T_lparen, 1,
  /* 57 */ NT_prog, T_ref, 1,
  /* 58 */ NT_prog, T_global, 1,
  /* 59 */ NT_prog, T_external, 1,
  /* 60 */ NT_prog, T_semico, 1,
  /* 61 */ NT_prog, T_procedure, 1,
  /* 62 */ NT_prog, T_eol, 1,
  /* 63 */ NT_sep, T_semico, 47,
  /* 64 */ NT_sep, T_eol, 48,
  /* 65 */ NT_type, T_any, 4,
  /* 66 */ NT_type, T_int, 5,
  /* 67 */ NT_type, T_real, 6,
  /* 68 */ NT_type, T_string, 7,
  /* 69 */ NT_type, T_cset, 8,
  /* 70 */ NT_type, T_void, 9,
  /* 71 */ NT_type, T_id, 10,
  /* 72 */ NT_type, T_record, 11,
  /* 73 */ NT_type, T_lbrace, 19,
  /* 74 */ NT_type, T_union, 12,
  /* 75 */ NT_type, T_set, 13,
  /* 76 */ NT_type, T_lbrack, 14,
  /* 77 */ NT_type, T_lparen, 17,
  /* 78 */ NT_type, T_ref, 18,
  /* 79 */ NT_fieldlistopt, T_id, 34,
  /* 80 */ NT_fieldlistopt, T_rbrace, 33,
  /* 81 */ NT_typetail, T_any, 16,
  /* 82 */ NT_typetail, T_int, 16,
  /* 83 */ NT_typetail, T_real, 16,
  /* 84 */ NT_typetail, T_string, 16,
  /* 85 */ NT_typetail, T_cset, 16,
  /* 86 */ NT_typetail, T_void, 16,
  /* 87 */ NT_typetail, T_id, 16,
  /* 88 */ NT_typetail, T_record, 16,
  /* 89 */ NT_typetail, T_lbrace, 16,
  /* 90 */ NT_typetail, T_union, 16,
  /* 91 */ NT_typetail, T_set, 16,
  /* 92 */ NT_typetail, T_lbrack, 16,
  /* 93 */ NT_typetail, T_rbrack, 15,
  /* 94 */ NT_typetail, T_lparen, 16,
  /* 95 */ NT_typetail, T_ref, 16,
  /* 96 */ NT_paramlist, T_id, 40,
  /* 97 */ NT_paramlist, T_rparen, 41,
  /* 98 */ NT_paramlist, T_ref, 40,
  /* 99 */ NT_globaldec, T_global, 25,
  /* 100 */ NT_globaldec, T_external, 26,
  /* 101 */ NT_procdec, T_procedure, 38,
  /* 102 */ NT_typedec, T_any, 24,
  /* 103 */ NT_typedec, T_int, 24,
  /* 104 */ NT_typedec, T_real, 24,
  /* 105 */ NT_typedec, T_string, 24,
  /* 106 */ NT_typedec, T_cset, 24,
  /* 107 */ NT_typedec, T_void, 24,
  /* 108 */ NT_typedec, T_id, 24,
  /* 109 */ NT_typedec, T_record, 24,
  /* 110 */ NT_typedec, T_lbrace, 24,
  /* 111 */ NT_typedec, T_union, 24,
  /* 112 */ NT_typedec, T_set, 24,
  /* 113 */ NT_typedec, T_lbrack, 24,
  /* 114 */ NT_typedec, T_lparen, 24,
  /* 115 */ NT_typedec, T_ref, 24,
  /* 116 */ NT_idlistd, T_id, 27,
  /* 117 */ NT_idlistdtl, T_colon, 29,
  /* 118 */ NT_idlistdtl, T_comma, 28,
  /* 119 */ NT_idlistptl, T_colon, 32,
  /* 120 */ NT_idlistptl, T_comma, 31,
  /* 121 */ NT_idlistp, T_id, 30,
  /* 122 */ NT_fieldlist, T_id, 35,
  /* 123 */ NT_fieldlisttl, T_rbrace, 37,
  /* 124 */ NT_fieldlisttl, T_semico, 36,
  /* 125 */ NT_header, T_procedure, 39,
  /* 126 */ NT_locopt, T_id, 53,
  /* 127 */ NT_locopt, T_lbrace, 53,
  /* 128 */ NT_locopt, T_lbrack, 53,
  /* 129 */ NT_locopt, T_lparen, 53,
  /* 130 */ NT_locopt, T_equal, 53,
  /* 131 */ NT_locopt, T_semico, 53,
  /* 132 */ NT_locopt, T_end, 53,
  /* 133 */ NT_locopt, T_eol, 53,
  /* 134 */ NT_locopt, T_local, 52,
  /* 135 */ NT_locopt, T_static, 52,
  /* 136 */ NT_locopt, T_dynamic, 52,
  /* 137 */ NT_locopt, T_initial, 53,
  /* 138 */ NT_locopt, T_conjop, 53,
  /* 139 */ NT_locopt, T_scanop, 53,
  /* 140 */ NT_locopt, T_altop, 53,
  /* 141 */ NT_locopt, T_carat, 53,
  /* 142 */ NT_locopt, T_bslash, 53,
  /* 143 */ NT_locopt, T_coop, 53,
  /* 144 */ NT_locopt, T_dot, 53,
  /* 145 */ NT_locopt, T_repeat, 53,
  /* 146 */ NT_locopt, T_while, 53,
  /* 147 */ NT_locopt, T_until, 53,
  /* 148 */ NT_locopt, T_every, 53,
  /* 149 */ NT_locopt, T_if, 53,
  /* 150 */ NT_locopt, T_case, 53,
  /* 151 */ NT_locopt, T_next, 53,
  /* 152 */ NT_locopt, T_break, 53,
  /* 153 */ NT_locopt, T_return, 53,
  /* 154 */ NT_locopt, T_suspend, 53,
  /* 155 */ NT_locopt, T_fail, 53,
  /* 156 */ NT_locopt, T_create, 53,
  /* 157 */ NT_locopt, T_not, 53,
  /* 158 */ NT_locopt, T_bang, 53,
  /* 159 */ NT_locopt, T_star, 53,
  /* 160 */ NT_locopt, T_plus, 53,
  /* 161 */ NT_locopt, T_minus, 53,
  /* 162 */ NT_locopt, T_slash, 53,
  /* 163 */ NT_locopt, T_tilde, 53,
  /* 164 */ NT_locopt, T_intcon, 53,
  /* 165 */ NT_locopt, T_radintcon, 53,
  /* 166 */ NT_locopt, T_realcon, 53,
  /* 167 */ NT_locopt, T_csetcon, 53,
  /* 168 */ NT_locopt, T_stringcon, 53,
  /* 169 */ NT_locopt, T_hexcon, 53,
  /* 170 */ NT_locopt, T_octcon, 53,
  /* 171 */ NT_initopt, T_id, 58,
  /* 172 */ NT_initopt, T_lbrace, 58,
  /* 173 */ NT_initopt, T_lbrack, 58,
  /* 174 */ NT_initopt, T_lparen, 58,
  /* 175 */ NT_initopt, T_equal, 58,
  /* 176 */ NT_initopt, T_semico, 58,
  /* 177 */ NT_initopt, T_end, 58,
  /* 178 */ NT_initopt, T_eol, 58,
  /* 179 */ NT_initopt, T_initial, 57,
  /* 180 */ NT_initopt, T_conjop, 58,
  /* 181 */ NT_initopt, T_scanop, 58,
  /* 182 */ NT_initopt, T_altop, 58,
  /* 183 */ NT_initopt, T_carat, 58,
  /* 184 */ NT_initopt, T_bslash, 58,
  /* 185 */ NT_initopt, T_coop, 58,
  /* 186 */ NT_initopt, T_dot, 58,
  /* 187 */ NT_initopt, T_repeat, 58,
  /* 188 */ NT_initopt, T_while, 58,
  /* 189 */ NT_initopt, T_until, 58,
  /* 190 */ NT_initopt, T_every, 58,
  /* 191 */ NT_initopt, T_if, 58,
  /* 192 */ NT_initopt, T_case, 58,
  /* 193 */ NT_initopt, T_next, 58,
  /* 194 */ NT_initopt, T_break, 58,
  /* 195 */ NT_initopt, T_return, 58,
  /* 196 */ NT_initopt, T_suspend, 58,
  /* 197 */ NT_initopt, T_fail, 58,
  /* 198 */ NT_initopt, T_create, 58,
  /* 199 */ NT_initopt, T_not, 58,
  /* 200 */ NT_initopt, T_bang, 58,
  /* 201 */ NT_initopt, T_star, 58,
  /* 202 */ NT_initopt, T_plus, 58,
  /* 203 */ NT_initopt, T_minus, 58,
  /* 204 */ NT_initopt, T_slash, 58,
  /* 205 */ NT_initopt, T_tilde, 58,
  /* 206 */ NT_initopt, T_intcon, 58,
  /* 207 */ NT_initopt, T_radintcon, 58,
  /* 208 */ NT_initopt, T_realcon, 58,
  /* 209 */ NT_initopt, T_csetcon, 58,
  /* 210 */ NT_initopt, T_stringcon, 58,
  /* 211 */ NT_initopt, T_hexcon, 58,
  /* 212 */ NT_initopt, T_octcon, 58,
  /* 213 */ NT_seq, T_id, 59,
  /* 214 */ NT_seq, T_lbrace, 59,
  /* 215 */ NT_seq, T_rbrace, 59,
  /* 216 */ NT_seq, T_lbrack, 59,
  /* 217 */ NT_seq, T_lparen, 59,
  /* 218 */ NT_seq, T_equal, 59,
  /* 219 */ NT_seq, T_semico, 59,
  /* 220 */ NT_seq, T_end, 59,
  /* 221 */ NT_seq, T_eol, 59,
  /* 222 */ NT_seq, T_conjop, 59,
  /* 223 */ NT_seq, T_scanop, 59,
  /* 224 */ NT_seq, T_altop, 59,
  /* 225 */ NT_seq, T_carat, 59,
  /* 226 */ NT_seq, T_bslash, 59,
  /* 227 */ NT_seq, T_coop, 59,
  /* 228 */ NT_seq, T_dot, 59,
  /* 229 */ NT_seq, T_repeat, 59,
  /* 230 */ NT_seq, T_while, 59,
  /* 231 */ NT_seq, T_until, 59,
  /* 232 */ NT_seq, T_every, 59,
  /* 233 */ NT_seq, T_if, 59,
  /* 234 */ NT_seq, T_case, 59,
  /* 235 */ NT_seq, T_next, 59,
  /* 236 */ NT_seq, T_break, 59,
  /* 237 */ NT_seq, T_return, 59,
  /* 238 */ NT_seq, T_suspend, 59,
  /* 239 */ NT_seq, T_fail, 59,
  /* 240 */ NT_seq, T_create, 59,
  /* 241 */ NT_seq, T_not, 59,
  /* 242 */ NT_seq, T_bang, 59,
  /* 243 */ NT_seq, T_star, 59,
  /* 244 */ NT_seq, T_plus, 59,
  /* 245 */ NT_seq, T_minus, 59,
  /* 246 */ NT_seq, T_slash, 59,
  /* 247 */ NT_seq, T_tilde, 59,
  /* 248 */ NT_seq, T_intcon, 59,
  /* 249 */ NT_seq, T_radintcon, 59,
  /* 250 */ NT_seq, T_realcon, 59,
  /* 251 */ NT_seq, T_csetcon, 59,
  /* 252 */ NT_seq, T_stringcon, 59,
  /* 253 */ NT_seq, T_hexcon, 59,
  /* 254 */ NT_seq, T_octcon, 59,
  /* 255 */ NT_refopt, T_any, 46,
  /* 256 */ NT_refopt, T_int, 46,
  /* 257 */ NT_refopt, T_real, 46,
  /* 258 */ NT_refopt, T_string, 46,
  /* 259 */ NT_refopt, T_cset, 46,
  /* 260 */ NT_refopt, T_void, 46,
  /* 261 */ NT_refopt, T_id, 46,
  /* 262 */ NT_refopt, T_record, 46,
  /* 263 */ NT_refopt, T_lbrace, 46,
  /* 264 */ NT_refopt, T_union, 46,
  /* 265 */ NT_refopt, T_set, 46,
  /* 266 */ NT_refopt, T_lbrack, 46,
  /* 267 */ NT_refopt, T_lparen, 46,
  /* 268 */ NT_refopt, T_ref, 45,
  /* 269 */ NT_parameter, T_id, 44,
  /* 270 */ NT_parameter, T_ref, 44,
  /* 271 */ NT_paramlisttl, T_rparen, 43,
  /* 272 */ NT_paramlisttl, T_semico, 42,
  /* 273 */ NT_localspec, T_local, 54,
  /* 274 */ NT_localspec, T_static, 55,
  /* 275 */ NT_localspec, T_dynamic, 56,
  /* 276 */ NT_localstl, T_id, 51,
  /* 277 */ NT_localstl, T_lbrace, 51,
  /* 278 */ NT_localstl, T_lbrack, 51,
  /* 279 */ NT_localstl, T_lparen, 51,
  /* 280 */ NT_localstl, T_equal, 51,
  /* 281 */ NT_localstl, T_semico, 51,
  /* 282 */ NT_localstl, T_end, 51,
  /* 283 */ NT_localstl, T_eol, 51,
  /* 284 */ NT_localstl, T_local, 50,
  /* 285 */ NT_localstl, T_static, 50,
  /* 286 */ NT_localstl, T_dynamic, 50,
  /* 287 */ NT_localstl, T_initial, 51,
  /* 288 */ NT_localstl, T_conjop, 51,
  /* 289 */ NT_localstl, T_scanop, 51,
  /* 290 */ NT_localstl, T_altop, 51,
  /* 291 */ NT_localstl, T_carat, 51,
  /* 292 */ NT_localstl, T_bslash, 51,
  /* 293 */ NT_localstl, T_coop, 51,
  /* 294 */ NT_localstl, T_dot, 51,
  /* 295 */ NT_localstl, T_repeat, 51,
  /* 296 */ NT_localstl, T_while, 51,
  /* 297 */ NT_localstl, T_until, 51,
  /* 298 */ NT_localstl, T_every, 51,
  /* 299 */ NT_localstl, T_if, 51,
  /* 300 */ NT_localstl, T_case, 51,
  /* 301 */ NT_localstl, T_next, 51,
  /* 302 */ NT_localstl, T_break, 51,
  /* 303 */ NT_localstl, T_return, 51,
  /* 304 */ NT_localstl, T_suspend, 51,
  /* 305 */ NT_localstl, T_fail, 51,
  /* 306 */ NT_localstl, T_create, 51,
  /* 307 */ NT_localstl, T_not, 51,
  /* 308 */ NT_localstl, T_bang, 51,
  /* 309 */ NT_localstl, T_star, 51,
  /* 310 */ NT_localstl, T_plus, 51,
  /* 311 */ NT_localstl, T_minus, 51,
  /* 312 */ NT_localstl, T_slash, 51,
  /* 313 */ NT_localstl, T_tilde, 51,
  /* 314 */ NT_localstl, T_intcon, 51,
  /* 315 */ NT_localstl, T_radintcon, 51,
  /* 316 */ NT_localstl, T_realcon, 51,
  /* 317 */ NT_localstl, T_csetcon, 51,
  /* 318 */ NT_localstl, T_stringcon, 51,
  /* 319 */ NT_localstl, T_hexcon, 51,
  /* 320 */ NT_localstl, T_octcon, 51,
  /* 321 */ NT_locals, T_local, 49,
  /* 322 */ NT_locals, T_static, 49,
  /* 323 */ NT_locals, T_dynamic, 49,
  /* 324 */ NT_e, T_id, 64,
  /* 325 */ NT_e, T_lbrace, 64,
  /* 326 */ NT_e, T_lbrack, 64,
  /* 327 */ NT_e, T_lparen, 64,
  /* 328 */ NT_e, T_equal, 64,
  /* 329 */ NT_e, T_conjop, 64,
  /* 330 */ NT_e, T_scanop, 64,
  /* 331 */ NT_e, T_altop, 64,
  /* 332 */ NT_e, T_carat, 64,
  /* 333 */ NT_e, T_bslash, 64,
  /* 334 */ NT_e, T_coop, 64,
  /* 335 */ NT_e, T_dot, 64,
  /* 336 */ NT_e, T_repeat, 64,
  /* 337 */ NT_e, T_while, 64,
  /* 338 */ NT_e, T_until, 64,
  /* 339 */ NT_e, T_every, 64,
  /* 340 */ NT_e, T_if, 64,
  /* 341 */ NT_e, T_case, 64,
  /* 342 */ NT_e, T_next, 64,
  /* 343 */ NT_e, T_break, 64,
  /* 344 */ NT_e, T_return, 64,
  /* 345 */ NT_e, T_suspend, 64,
  /* 346 */ NT_e, T_fail, 64,
  /* 347 */ NT_e, T_create, 64,
  /* 348 */ NT_e, T_not, 64,
  /* 349 */ NT_e, T_bang, 64,
  /* 350 */ NT_e, T_star, 64,
  /* 351 */ NT_e, T_plus, 64,
  /* 352 */ NT_e, T_minus, 64,
  /* 353 */ NT_e, T_slash, 64,
  /* 354 */ NT_e, T_tilde, 64,
  /* 355 */ NT_e, T_intcon, 64,
  /* 356 */ NT_e, T_radintcon, 64,
  /* 357 */ NT_e, T_realcon, 64,
  /* 358 */ NT_e, T_csetcon, 64,
  /* 359 */ NT_e, T_stringcon, 64,
  /* 360 */ NT_e, T_hexcon, 64,
  /* 361 */ NT_e, T_octcon, 64,
  /* 362 */ NT_eopt, T_id, 63,
  /* 363 */ NT_eopt, T_lbrace, 63,
  /* 364 */ NT_eopt, T_rbrace, 62,
  /* 365 */ NT_eopt, T_of, 62,
  /* 366 */ NT_eopt, T_lbrack, 63,
  /* 367 */ NT_eopt, T_rbrack, 62,
  /* 368 */ NT_eopt, T_lparen, 63,
  /* 369 */ NT_eopt, T_rparen, 62,
  /* 370 */ NT_eopt, T_equal, 62,
  /* 371 */ NT_eopt, T_colon, 62,
  /* 372 */ NT_eopt, T_comma, 62,
  /* 373 */ NT_eopt, T_semico, 62,
  /* 374 */ NT_eopt, T_end, 62,
  /* 375 */ NT_eopt, T_eol, 62,
  /* 376 */ NT_eopt, T_conjop, 62,
  /* 377 */ NT_eopt, T_scanop, 62,
  /* 378 */ NT_eopt, T_to, 62,
  /* 379 */ NT_eopt, T_by, 62,
  /* 380 */ NT_eopt, T_altop, 62,
  /* 381 */ NT_eopt, T_catop, 62,
  /* 382 */ NT_eopt, T_carat, 62,
  /* 383 */ NT_eopt, T_bslash, 62,
  /* 384 */ NT_eopt, T_coop, 62,
  /* 385 */ NT_eopt, T_dot, 63,
  /* 386 */ NT_eopt, T_pcolon, 62,
  /* 387 */ NT_eopt, T_mcolon, 62,
  /* 388 */ NT_eopt, T_repeat, 63,
  /* 389 */ NT_eopt, T_while, 63,
  /* 390 */ NT_eopt, T_until, 63,
  /* 391 */ NT_eopt, T_every, 63,
  /* 392 */ NT_eopt, T_if, 63,
  /* 393 */ NT_eopt, T_then, 62,
  /* 394 */ NT_eopt, T_case, 63,
  /* 395 */ NT_eopt, T_next, 63,
  /* 396 */ NT_eopt, T_break, 63,
  /* 397 */ NT_eopt, T_return, 63,
  /* 398 */ NT_eopt, T_suspend, 63,
  /* 399 */ NT_eopt, T_fail, 63,
  /* 400 */ NT_eopt, T_create, 63,
  /* 401 */ NT_eopt, T_do, 62,
  /* 402 */ NT_eopt, T_else, 62,
  /* 403 */ NT_eopt, T_lt, 62,
  /* 404 */ NT_eopt, T_lteq, 62,
  /* 405 */ NT_eopt, T_gt, 62,
  /* 406 */ NT_eopt, T_gteq, 62,
  /* 407 */ NT_eopt, T_noteq, 62,
  /* 408 */ NT_eopt, T_not, 63,
  /* 409 */ NT_eopt, T_bang, 63,
  /* 410 */ NT_eopt, T_star, 62,
  /* 411 */ NT_eopt, T_plus, 62,
  /* 412 */ NT_eopt, T_minus, 62,
  /* 413 */ NT_eopt, T_slash, 62,
  /* 414 */ NT_eopt, T_tilde, 63,
  /* 415 */ NT_eopt, T_pct, 62,
  /* 416 */ NT_eopt, T_starstar, 62,
  /* 417 */ NT_eopt, T_plusplus, 62,
  /* 418 */ NT_eopt, T_minusminus, 62,
  /* 419 */ NT_eopt, T_assign, 62,
  /* 420 */ NT_eopt, T_star_assign, 62,
  /* 421 */ NT_eopt, T_slash_assign, 62,
  /* 422 */ NT_eopt, T_pct_assign, 62,
  /* 423 */ NT_eopt, T_starstar_assign, 62,
  /* 424 */ NT_eopt, T_plus_assign, 62,
  /* 425 */ NT_eopt, T_minus_assign, 62,
  /* 426 */ NT_eopt, T_plusplus_assign, 62,
  /* 427 */ NT_eopt, T_minusminus_assign, 62,
  /* 428 */ NT_eopt, T_intcon, 63,
  /* 429 */ NT_eopt, T_radintcon, 63,
  /* 430 */ NT_eopt, T_realcon, 63,
  /* 431 */ NT_eopt, T_csetcon, 63,
  /* 432 */ NT_eopt, T_stringcon, 63,
  /* 433 */ NT_eopt, T_hexcon, 63,
  /* 434 */ NT_eopt, T_octcon, 63,
  /* 435 */ NT_seqtl, T_rbrace, 61,
  /* 436 */ NT_seqtl, T_semico, 60,
  /* 437 */ NT_seqtl, T_end, 61,
  /* 438 */ NT_seqtl, T_eol, 60,
  /* 439 */ NT_e1, T_id, 65,
  /* 440 */ NT_e1, T_lbrace, 65,
  /* 441 */ NT_e1, T_lbrack, 65,
  /* 442 */ NT_e1, T_lparen, 65,
  /* 443 */ NT_e1, T_equal, 65,
  /* 444 */ NT_e1, T_conjop, 65,
  /* 445 */ NT_e1, T_scanop, 65,
  /* 446 */ NT_e1, T_altop, 65,
  /* 447 */ NT_e1, T_carat, 65,
  /* 448 */ NT_e1, T_bslash, 65,
  /* 449 */ NT_e1, T_coop, 65,
  /* 450 */ NT_e1, T_dot, 65,
  /* 451 */ NT_e1, T_repeat, 65,
  /* 452 */ NT_e1, T_while, 65,
  /* 453 */ NT_e1, T_until, 65,
  /* 454 */ NT_e1, T_every, 65,
  /* 455 */ NT_e1, T_if, 65,
  /* 456 */ NT_e1, T_case, 65,
  /* 457 */ NT_e1, T_next, 65,
  /* 458 */ NT_e1, T_break, 65,
  /* 459 */ NT_e1, T_return, 65,
  /* 460 */ NT_e1, T_suspend, 65,
  /* 461 */ NT_e1, T_fail, 65,
  /* 462 */ NT_e1, T_create, 65,
  /* 463 */ NT_e1, T_not, 65,
  /* 464 */ NT_e1, T_bang, 65,
  /* 465 */ NT_e1, T_star, 65,
  /* 466 */ NT_e1, T_plus, 65,
  /* 467 */ NT_e1, T_minus, 65,
  /* 468 */ NT_e1, T_slash, 65,
  /* 469 */ NT_e1, T_tilde, 65,
  /* 470 */ NT_e1, T_intcon, 65,
  /* 471 */ NT_e1, T_radintcon, 65,
  /* 472 */ NT_e1, T_realcon, 65,
  /* 473 */ NT_e1, T_csetcon, 65,
  /* 474 */ NT_e1, T_stringcon, 65,
  /* 475 */ NT_e1, T_hexcon, 65,
  /* 476 */ NT_e1, T_octcon, 65,
  /* 477 */ NT_e2, T_id, 68,
  /* 478 */ NT_e2, T_lbrace, 68,
  /* 479 */ NT_e2, T_lbrack, 68,
  /* 480 */ NT_e2, T_lparen, 68,
  /* 481 */ NT_e2, T_equal, 68,
  /* 482 */ NT_e2, T_conjop, 68,
  /* 483 */ NT_e2, T_scanop, 68,
  /* 484 */ NT_e2, T_altop, 68,
  /* 485 */ NT_e2, T_carat, 68,
  /* 486 */ NT_e2, T_bslash, 68,
  /* 487 */ NT_e2, T_coop, 68,
  /* 488 */ NT_e2, T_dot, 68,
  /* 489 */ NT_e2, T_repeat, 68,
  /* 490 */ NT_e2, T_while, 68,
  /* 491 */ NT_e2, T_until, 68,
  /* 492 */ NT_e2, T_every, 68,
  /* 493 */ NT_e2, T_if, 68,
  /* 494 */ NT_e2, T_case, 68,
  /* 495 */ NT_e2, T_next, 68,
  /* 496 */ NT_e2, T_break, 68,
  /* 497 */ NT_e2, T_return, 68,
  /* 498 */ NT_e2, T_suspend, 68,
  /* 499 */ NT_e2, T_fail, 68,
  /* 500 */ NT_e2, T_create, 68,
  /* 501 */ NT_e2, T_not, 68,
  /* 502 */ NT_e2, T_bang, 68,
  /* 503 */ NT_e2, T_star, 68,
  /* 504 */ NT_e2, T_plus, 68,
  /* 505 */ NT_e2, T_minus, 68,
  /* 506 */ NT_e2, T_slash, 68,
  /* 507 */ NT_e2, T_tilde, 68,
  /* 508 */ NT_e2, T_intcon, 68,
  /* 509 */ NT_e2, T_radintcon, 68,
  /* 510 */ NT_e2, T_realcon, 68,
  /* 511 */ NT_e2, T_csetcon, 68,
  /* 512 */ NT_e2, T_stringcon, 68,
  /* 513 */ NT_e2, T_hexcon, 68,
  /* 514 */ NT_e2, T_octcon, 68,
  /* 515 */ NT_e1tl, T_rbrace, 67,
  /* 516 */ NT_e1tl, T_of, 67,
  /* 517 */ NT_e1tl, T_rbrack, 67,
  /* 518 */ NT_e1tl, T_rparen, 67,
  /* 519 */ NT_e1tl, T_equal, 67,
  /* 520 */ NT_e1tl, T_colon, 67,
  /* 521 */ NT_e1tl, T_comma, 67,
  /* 522 */ NT_e1tl, T_semico, 67,
  /* 523 */ NT_e1tl, T_end, 67,
  /* 524 */ NT_e1tl, T_eol, 67,
  /* 525 */ NT_e1tl, T_conjop, 66,
  /* 526 */ NT_e1tl, T_scanop, 67,
  /* 527 */ NT_e1tl, T_to, 67,
  /* 528 */ NT_e1tl, T_by, 67,
  /* 529 */ NT_e1tl, T_altop, 67,
  /* 530 */ NT_e1tl, T_catop, 67,
  /* 531 */ NT_e1tl, T_carat, 67,
  /* 532 */ NT_e1tl, T_bslash, 67,
  /* 533 */ NT_e1tl, T_coop, 67,
  /* 534 */ NT_e1tl, T_pcolon, 67,
  /* 535 */ NT_e1tl, T_mcolon, 67,
  /* 536 */ NT_e1tl, T_then, 67,
  /* 537 */ NT_e1tl, T_do, 67,
  /* 538 */ NT_e1tl, T_else, 67,
  /* 539 */ NT_e1tl, T_lt, 67,
  /* 540 */ NT_e1tl, T_lteq, 67,
  /* 541 */ NT_e1tl, T_gt, 67,
  /* 542 */ NT_e1tl, T_gteq, 67,
  /* 543 */ NT_e1tl, T_noteq, 67,
  /* 544 */ NT_e1tl, T_star, 67,
  /* 545 */ NT_e1tl, T_plus, 67,
  /* 546 */ NT_e1tl, T_minus, 67,
  /* 547 */ NT_e1tl, T_slash, 67,
  /* 548 */ NT_e1tl, T_pct, 67,
  /* 549 */ NT_e1tl, T_starstar, 67,
  /* 550 */ NT_e1tl, T_plusplus, 67,
  /* 551 */ NT_e1tl, T_minusminus, 67,
  /* 552 */ NT_e1tl, T_assign, 67,
  /* 553 */ NT_e1tl, T_star_assign, 67,
  /* 554 */ NT_e1tl, T_slash_assign, 67,
  /* 555 */ NT_e1tl, T_pct_assign, 67,
  /* 556 */ NT_e1tl, T_starstar_assign, 67,
  /* 557 */ NT_e1tl, T_plus_assign, 67,
  /* 558 */ NT_e1tl, T_minus_assign, 67,
  /* 559 */ NT_e1tl, T_plusplus_assign, 67,
  /* 560 */ NT_e1tl, T_minusminus_assign, 67,
  /* 561 */ NT_e3, T_id, 71,
  /* 562 */ NT_e3, T_lbrace, 71,
  /* 563 */ NT_e3, T_lbrack, 71,
  /* 564 */ NT_e3, T_lparen, 71,
  /* 565 */ NT_e3, T_equal, 71,
  /* 566 */ NT_e3, T_conjop, 71,
  /* 567 */ NT_e3, T_scanop, 71,
  /* 568 */ NT_e3, T_altop, 71,
  /* 569 */ NT_e3, T_carat, 71,
  /* 570 */ NT_e3, T_bslash, 71,
  /* 571 */ NT_e3, T_coop, 71,
  /* 572 */ NT_e3, T_dot, 71,
  /* 573 */ NT_e3, T_repeat, 71,
  /* 574 */ NT_e3, T_while, 71,
  /* 575 */ NT_e3, T_until, 71,
  /* 576 */ NT_e3, T_every, 71,
  /* 577 */ NT_e3, T_if, 71,
  /* 578 */ NT_e3, T_case, 71,
  /* 579 */ NT_e3, T_next, 71,
  /* 580 */ NT_e3, T_break, 71,
  /* 581 */ NT_e3, T_return, 71,
  /* 582 */ NT_e3, T_suspend, 71,
  /* 583 */ NT_e3, T_fail, 71,
  /* 584 */ NT_e3, T_create, 71,
  /* 585 */ NT_e3, T_not, 71,
  /* 586 */ NT_e3, T_bang, 71,
  /* 587 */ NT_e3, T_star, 71,
  /* 588 */ NT_e3, T_plus, 71,
  /* 589 */ NT_e3, T_minus, 71,
  /* 590 */ NT_e3, T_slash, 71,
  /* 591 */ NT_e3, T_tilde, 71,
  /* 592 */ NT_e3, T_intcon, 71,
  /* 593 */ NT_e3, T_radintcon, 71,
  /* 594 */ NT_e3, T_realcon, 71,
  /* 595 */ NT_e3, T_csetcon, 71,
  /* 596 */ NT_e3, T_stringcon, 71,
  /* 597 */ NT_e3, T_hexcon, 71,
  /* 598 */ NT_e3, T_octcon, 71,
  /* 599 */ NT_e2tl, T_rbrace, 70,
  /* 600 */ NT_e2tl, T_of, 70,
  /* 601 */ NT_e2tl, T_rbrack, 70,
  /* 602 */ NT_e2tl, T_rparen, 70,
  /* 603 */ NT_e2tl, T_equal, 70,
  /* 604 */ NT_e2tl, T_colon, 70,
  /* 605 */ NT_e2tl, T_comma, 70,
  /* 606 */ NT_e2tl, T_semico, 70,
  /* 607 */ NT_e2tl, T_end, 70,
  /* 608 */ NT_e2tl, T_eol, 70,
  /* 609 */ NT_e2tl, T_conjop, 70,
  /* 610 */ NT_e2tl, T_scanop, 69,
  /* 611 */ NT_e2tl, T_to, 70,
  /* 612 */ NT_e2tl, T_by, 70,
  /* 613 */ NT_e2tl, T_altop, 70,
  /* 614 */ NT_e2tl, T_catop, 70,
  /* 615 */ NT_e2tl, T_carat, 70,
  /* 616 */ NT_e2tl, T_bslash, 70,
  /* 617 */ NT_e2tl, T_coop, 70,
  /* 618 */ NT_e2tl, T_pcolon, 70,
  /* 619 */ NT_e2tl, T_mcolon, 70,
  /* 620 */ NT_e2tl, T_then, 70,
  /* 621 */ NT_e2tl, T_do, 70,
  /* 622 */ NT_e2tl, T_else, 70,
  /* 623 */ NT_e2tl, T_lt, 70,
  /* 624 */ NT_e2tl, T_lteq, 70,
  /* 625 */ NT_e2tl, T_gt, 70,
  /* 626 */ NT_e2tl, T_gteq, 70,
  /* 627 */ NT_e2tl, T_noteq, 70,
  /* 628 */ NT_e2tl, T_star, 70,
  /* 629 */ NT_e2tl, T_plus, 70,
  /* 630 */ NT_e2tl, T_minus, 70,
  /* 631 */ NT_e2tl, T_slash, 70,
  /* 632 */ NT_e2tl, T_pct, 70,
  /* 633 */ NT_e2tl, T_starstar, 70,
  /* 634 */ NT_e2tl, T_plusplus, 70,
  /* 635 */ NT_e2tl, T_minusminus, 70,
  /* 636 */ NT_e2tl, T_assign, 70,
  /* 637 */ NT_e2tl, T_star_assign, 70,
  /* 638 */ NT_e2tl, T_slash_assign, 70,
  /* 639 */ NT_e2tl, T_pct_assign, 70,
  /* 640 */ NT_e2tl, T_starstar_assign, 70,
  /* 641 */ NT_e2tl, T_plus_assign, 70,
  /* 642 */ NT_e2tl, T_minus_assign, 70,
  /* 643 */ NT_e2tl, T_plusplus_assign, 70,
  /* 644 */ NT_e2tl, T_minusminus_assign, 70,
  /* 645 */ NT_e4, T_id, 74,
  /* 646 */ NT_e4, T_lbrace, 74,
  /* 647 */ NT_e4, T_lbrack, 74,
  /* 648 */ NT_e4, T_lparen, 74,
  /* 649 */ NT_e4, T_equal, 74,
  /* 650 */ NT_e4, T_conjop, 74,
  /* 651 */ NT_e4, T_scanop, 74,
  /* 652 */ NT_e4, T_altop, 74,
  /* 653 */ NT_e4, T_carat, 74,
  /* 654 */ NT_e4, T_bslash, 74,
  /* 655 */ NT_e4, T_coop, 74,
  /* 656 */ NT_e4, T_dot, 74,
  /* 657 */ NT_e4, T_repeat, 74,
  /* 658 */ NT_e4, T_while, 74,
  /* 659 */ NT_e4, T_until, 74,
  /* 660 */ NT_e4, T_every, 74,
  /* 661 */ NT_e4, T_if, 74,
  /* 662 */ NT_e4, T_case, 74,
  /* 663 */ NT_e4, T_next, 74,
  /* 664 */ NT_e4, T_break, 74,
  /* 665 */ NT_e4, T_return, 74,
  /* 666 */ NT_e4, T_suspend, 74,
  /* 667 */ NT_e4, T_fail, 74,
  /* 668 */ NT_e4, T_create, 74,
  /* 669 */ NT_e4, T_not, 74,
  /* 670 */ NT_e4, T_bang, 74,
  /* 671 */ NT_e4, T_star, 74,
  /* 672 */ NT_e4, T_plus, 74,
  /* 673 */ NT_e4, T_minus, 74,
  /* 674 */ NT_e4, T_slash, 74,
  /* 675 */ NT_e4, T_tilde, 74,
  /* 676 */ NT_e4, T_intcon, 74,
  /* 677 */ NT_e4, T_radintcon, 74,
  /* 678 */ NT_e4, T_realcon, 74,
  /* 679 */ NT_e4, T_csetcon, 74,
  /* 680 */ NT_e4, T_stringcon, 74,
  /* 681 */ NT_e4, T_hexcon, 74,
  /* 682 */ NT_e4, T_octcon, 74,
  /* 683 */ NT_e3tl, T_rbrace, 73,
  /* 684 */ NT_e3tl, T_of, 73,
  /* 685 */ NT_e3tl, T_rbrack, 73,
  /* 686 */ NT_e3tl, T_rparen, 73,
  /* 687 */ NT_e3tl, T_equal, 73,
  /* 688 */ NT_e3tl, T_colon, 73,
  /* 689 */ NT_e3tl, T_comma, 73,
  /* 690 */ NT_e3tl, T_semico, 73,
  /* 691 */ NT_e3tl, T_end, 73,
  /* 692 */ NT_e3tl, T_eol, 73,
  /* 693 */ NT_e3tl, T_conjop, 73,
  /* 694 */ NT_e3tl, T_scanop, 73,
  /* 695 */ NT_e3tl, T_to, 73,
  /* 696 */ NT_e3tl, T_by, 73,
  /* 697 */ NT_e3tl, T_altop, 73,
  /* 698 */ NT_e3tl, T_catop, 73,
  /* 699 */ NT_e3tl, T_carat, 73,
  /* 700 */ NT_e3tl, T_bslash, 73,
  /* 701 */ NT_e3tl, T_coop, 73,
  /* 702 */ NT_e3tl, T_pcolon, 73,
  /* 703 */ NT_e3tl, T_mcolon, 73,
  /* 704 */ NT_e3tl, T_then, 73,
  /* 705 */ NT_e3tl, T_do, 73,
  /* 706 */ NT_e3tl, T_else, 73,
  /* 707 */ NT_e3tl, T_lt, 73,
  /* 708 */ NT_e3tl, T_lteq, 73,
  /* 709 */ NT_e3tl, T_gt, 73,
  /* 710 */ NT_e3tl, T_gteq, 73,
  /* 711 */ NT_e3tl, T_noteq, 73,
  /* 712 */ NT_e3tl, T_star, 73,
  /* 713 */ NT_e3tl, T_plus, 73,
  /* 714 */ NT_e3tl, T_minus, 73,
  /* 715 */ NT_e3tl, T_slash, 73,
  /* 716 */ NT_e3tl, T_pct, 73,
  /* 717 */ NT_e3tl, T_starstar, 73,
  /* 718 */ NT_e3tl, T_plusplus, 73,
  /* 719 */ NT_e3tl, T_minusminus, 73,
  /* 720 */ NT_e3tl, T_assign, 72,
  /* 721 */ NT_e3tl, T_star_assign, 72,
  /* 722 */ NT_e3tl, T_slash_assign, 72,
  /* 723 */ NT_e3tl, T_pct_assign, 72,
  /* 724 */ NT_e3tl, T_starstar_assign, 72,
  /* 725 */ NT_e3tl, T_plus_assign, 72,
  /* 726 */ NT_e3tl, T_minus_assign, 72,
  /* 727 */ NT_e3tl, T_plusplus_assign, 72,
  /* 728 */ NT_e3tl, T_minusminus_assign, 72,
  /* 729 */ NT_asgnop, T_assign, 178,
  /* 730 */ NT_asgnop, T_star_assign, 179,
  /* 731 */ NT_asgnop, T_slash_assign, 180,
  /* 732 */ NT_asgnop, T_pct_assign, 181,
  /* 733 */ NT_asgnop, T_starstar_assign, 182,
  /* 734 */ NT_asgnop, T_plus_assign, 183,
  /* 735 */ NT_asgnop, T_minus_assign, 184,
  /* 736 */ NT_asgnop, T_plusplus_assign, 185,
  /* 737 */ NT_asgnop, T_minusminus_assign, 186,
  /* 738 */ NT_e5, T_id, 79,
  /* 739 */ NT_e5, T_lbrace, 79,
  /* 740 */ NT_e5, T_lbrack, 79,
  /* 741 */ NT_e5, T_lparen, 79,
  /* 742 */ NT_e5, T_equal, 79,
  /* 743 */ NT_e5, T_conjop, 79,
  /* 744 */ NT_e5, T_scanop, 79,
  /* 745 */ NT_e5, T_altop, 79,
  /* 746 */ NT_e5, T_carat, 79,
  /* 747 */ NT_e5, T_bslash, 79,
  /* 748 */ NT_e5, T_coop, 79,
  /* 749 */ NT_e5, T_dot, 79,
  /* 750 */ NT_e5, T_repeat, 79,
  /* 751 */ NT_e5, T_while, 79,
  /* 752 */ NT_e5, T_until, 79,
  /* 753 */ NT_e5, T_every, 79,
  /* 754 */ NT_e5, T_if, 79,
  /* 755 */ NT_e5, T_case, 79,
  /* 756 */ NT_e5, T_next, 79,
  /* 757 */ NT_e5, T_break, 79,
  /* 758 */ NT_e5, T_return, 79,
  /* 759 */ NT_e5, T_suspend, 79,
  /* 760 */ NT_e5, T_fail, 79,
  /* 761 */ NT_e5, T_create, 79,
  /* 762 */ NT_e5, T_not, 79,
  /* 763 */ NT_e5, T_bang, 79,
  /* 764 */ NT_e5, T_star, 79,
  /* 765 */ NT_e5, T_plus, 79,
  /* 766 */ NT_e5, T_minus, 79,
  /* 767 */ NT_e5, T_slash, 79,
  /* 768 */ NT_e5, T_tilde, 79,
  /* 769 */ NT_e5, T_intcon, 79,
  /* 770 */ NT_e5, T_radintcon, 79,
  /* 771 */ NT_e5, T_realcon, 79,
  /* 772 */ NT_e5, T_csetcon, 79,
  /* 773 */ NT_e5, T_stringcon, 79,
  /* 774 */ NT_e5, T_hexcon, 79,
  /* 775 */ NT_e5, T_octcon, 79,
  /* 776 */ NT_e4tl, T_rbrace, 76,
  /* 777 */ NT_e4tl, T_of, 76,
  /* 778 */ NT_e4tl, T_rbrack, 76,
  /* 779 */ NT_e4tl, T_rparen, 76,
  /* 780 */ NT_e4tl, T_equal, 76,
  /* 781 */ NT_e4tl, T_colon, 76,
  /* 782 */ NT_e4tl, T_comma, 76,
  /* 783 */ NT_e4tl, T_semico, 76,
  /* 784 */ NT_e4tl, T_end, 76,
  /* 785 */ NT_e4tl, T_eol, 76,
  /* 786 */ NT_e4tl, T_conjop, 76,
  /* 787 */ NT_e4tl, T_scanop, 76,
  /* 788 */ NT_e4tl, T_to, 75,
  /* 789 */ NT_e4tl, T_by, 76,
  /* 790 */ NT_e4tl, T_altop, 76,
  /* 791 */ NT_e4tl, T_catop, 76,
  /* 792 */ NT_e4tl, T_carat, 76,
  /* 793 */ NT_e4tl, T_bslash, 76,
  /* 794 */ NT_e4tl, T_coop, 76,
  /* 795 */ NT_e4tl, T_pcolon, 76,
  /* 796 */ NT_e4tl, T_mcolon, 76,
  /* 797 */ NT_e4tl, T_then, 76,
  /* 798 */ NT_e4tl, T_do, 76,
  /* 799 */ NT_e4tl, T_else, 76,
  /* 800 */ NT_e4tl, T_lt, 76,
  /* 801 */ NT_e4tl, T_lteq, 76,
  /* 802 */ NT_e4tl, T_gt, 76,
  /* 803 */ NT_e4tl, T_gteq, 76,
  /* 804 */ NT_e4tl, T_noteq, 76,
  /* 805 */ NT_e4tl, T_star, 76,
  /* 806 */ NT_e4tl, T_plus, 76,
  /* 807 */ NT_e4tl, T_minus, 76,
  /* 808 */ NT_e4tl, T_slash, 76,
  /* 809 */ NT_e4tl, T_pct, 76,
  /* 810 */ NT_e4tl, T_starstar, 76,
  /* 811 */ NT_e4tl, T_plusplus, 76,
  /* 812 */ NT_e4tl, T_minusminus, 76,
  /* 813 */ NT_e4tl, T_assign, 76,
  /* 814 */ NT_e4tl, T_star_assign, 76,
  /* 815 */ NT_e4tl, T_slash_assign, 76,
  /* 816 */ NT_e4tl, T_pct_assign, 76,
  /* 817 */ NT_e4tl, T_starstar_assign, 76,
  /* 818 */ NT_e4tl, T_plus_assign, 76,
  /* 819 */ NT_e4tl, T_minus_assign, 76,
  /* 820 */ NT_e4tl, T_plusplus_assign, 76,
  /* 821 */ NT_e4tl, T_minusminus_assign, 76,
  /* 822 */ NT_byopt, T_rbrace, 78,
  /* 823 */ NT_byopt, T_of, 78,
  /* 824 */ NT_byopt, T_rbrack, 78,
  /* 825 */ NT_byopt, T_rparen, 78,
  /* 826 */ NT_byopt, T_equal, 78,
  /* 827 */ NT_byopt, T_colon, 78,
  /* 828 */ NT_byopt, T_comma, 78,
  /* 829 */ NT_byopt, T_semico, 78,
  /* 830 */ NT_byopt, T_end, 78,
  /* 831 */ NT_byopt, T_eol, 78,
  /* 832 */ NT_byopt, T_conjop, 78,
  /* 833 */ NT_byopt, T_scanop, 78,
  /* 834 */ NT_byopt, T_to, 78,
  /* 835 */ NT_byopt, T_by, 77,
  /* 836 */ NT_byopt, T_altop, 78,
  /* 837 */ NT_byopt, T_catop, 78,
  /* 838 */ NT_byopt, T_carat, 78,
  /* 839 */ NT_byopt, T_bslash, 78,
  /* 840 */ NT_byopt, T_coop, 78,
  /* 841 */ NT_byopt, T_pcolon, 78,
  /* 842 */ NT_byopt, T_mcolon, 78,
  /* 843 */ NT_byopt, T_then, 78,
  /* 844 */ NT_byopt, T_do, 78,
  /* 845 */ NT_byopt, T_else, 78,
  /* 846 */ NT_byopt, T_lt, 78,
  /* 847 */ NT_byopt, T_lteq, 78,
  /* 848 */ NT_byopt, T_gt, 78,
  /* 849 */ NT_byopt, T_gteq, 78,
  /* 850 */ NT_byopt, T_noteq, 78,
  /* 851 */ NT_byopt, T_star, 78,
  /* 852 */ NT_byopt, T_plus, 78,
  /* 853 */ NT_byopt, T_minus, 78,
  /* 854 */ NT_byopt, T_slash, 78,
  /* 855 */ NT_byopt, T_pct, 78,
  /* 856 */ NT_byopt, T_starstar, 78,
  /* 857 */ NT_byopt, T_plusplus, 78,
  /* 858 */ NT_byopt, T_minusminus, 78,
  /* 859 */ NT_byopt, T_assign, 78,
  /* 860 */ NT_byopt, T_star_assign, 78,
  /* 861 */ NT_byopt, T_slash_assign, 78,
  /* 862 */ NT_byopt, T_pct_assign, 78,
  /* 863 */ NT_byopt, T_starstar_assign, 78,
  /* 864 */ NT_byopt, T_plus_assign, 78,
  /* 865 */ NT_byopt, T_minus_assign, 78,
  /* 866 */ NT_byopt, T_plusplus_assign, 78,
  /* 867 */ NT_byopt, T_minusminus_assign, 78,
  /* 868 */ NT_e6, T_id, 82,
  /* 869 */ NT_e6, T_lbrace, 82,
  /* 870 */ NT_e6, T_lbrack, 82,
  /* 871 */ NT_e6, T_lparen, 82,
  /* 872 */ NT_e6, T_equal, 82,
  /* 873 */ NT_e6, T_conjop, 82,
  /* 874 */ NT_e6, T_scanop, 82,
  /* 875 */ NT_e6, T_altop, 82,
  /* 876 */ NT_e6, T_carat, 82,
  /* 877 */ NT_e6, T_bslash, 82,
  /* 878 */ NT_e6, T_coop, 82,
  /* 879 */ NT_e6, T_dot, 82,
  /* 880 */ NT_e6, T_repeat, 82,
  /* 881 */ NT_e6, T_while, 82,
  /* 882 */ NT_e6, T_until, 82,
  /* 883 */ NT_e6, T_every, 82,
  /* 884 */ NT_e6, T_if, 82,
  /* 885 */ NT_e6, T_case, 82,
  /* 886 */ NT_e6, T_next, 82,
  /* 887 */ NT_e6, T_break, 82,
  /* 888 */ NT_e6, T_return, 82,
  /* 889 */ NT_e6, T_suspend, 82,
  /* 890 */ NT_e6, T_fail, 82,
  /* 891 */ NT_e6, T_create, 82,
  /* 892 */ NT_e6, T_not, 82,
  /* 893 */ NT_e6, T_bang, 82,
  /* 894 */ NT_e6, T_star, 82,
  /* 895 */ NT_e6, T_plus, 82,
  /* 896 */ NT_e6, T_minus, 82,
  /* 897 */ NT_e6, T_slash, 82,
  /* 898 */ NT_e6, T_tilde, 82,
  /* 899 */ NT_e6, T_intcon, 82,
  /* 900 */ NT_e6, T_radintcon, 82,
  /* 901 */ NT_e6, T_realcon, 82,
  /* 902 */ NT_e6, T_csetcon, 82,
  /* 903 */ NT_e6, T_stringcon, 82,
  /* 904 */ NT_e6, T_hexcon, 82,
  /* 905 */ NT_e6, T_octcon, 82,
  /* 906 */ NT_e5tl, T_rbrace, 81,
  /* 907 */ NT_e5tl, T_of, 81,
  /* 908 */ NT_e5tl, T_rbrack, 81,
  /* 909 */ NT_e5tl, T_rparen, 81,
  /* 910 */ NT_e5tl, T_equal, 81,
  /* 911 */ NT_e5tl, T_colon, 81,
  /* 912 */ NT_e5tl, T_comma, 81,
  /* 913 */ NT_e5tl, T_semico, 81,
  /* 914 */ NT_e5tl, T_end, 81,
  /* 915 */ NT_e5tl, T_eol, 81,
  /* 916 */ NT_e5tl, T_conjop, 81,
  /* 917 */ NT_e5tl, T_scanop, 81,
  /* 918 */ NT_e5tl, T_to, 81,
  /* 919 */ NT_e5tl, T_by, 81,
  /* 920 */ NT_e5tl, T_altop, 80,
  /* 921 */ NT_e5tl, T_catop, 81,
  /* 922 */ NT_e5tl, T_carat, 81,
  /* 923 */ NT_e5tl, T_bslash, 81,
  /* 924 */ NT_e5tl, T_coop, 81,
  /* 925 */ NT_e5tl, T_pcolon, 81,
  /* 926 */ NT_e5tl, T_mcolon, 81,
  /* 927 */ NT_e5tl, T_then, 81,
  /* 928 */ NT_e5tl, T_do, 81,
  /* 929 */ NT_e5tl, T_else, 81,
  /* 930 */ NT_e5tl, T_lt, 81,
  /* 931 */ NT_e5tl, T_lteq, 81,
  /* 932 */ NT_e5tl, T_gt, 81,
  /* 933 */ NT_e5tl, T_gteq, 81,
  /* 934 */ NT_e5tl, T_noteq, 81,
  /* 935 */ NT_e5tl, T_star, 81,
  /* 936 */ NT_e5tl, T_plus, 81,
  /* 937 */ NT_e5tl, T_minus, 81,
  /* 938 */ NT_e5tl, T_slash, 81,
  /* 939 */ NT_e5tl, T_pct, 81,
  /* 940 */ NT_e5tl, T_starstar, 81,
  /* 941 */ NT_e5tl, T_plusplus, 81,
  /* 942 */ NT_e5tl, T_minusminus, 81,
  /* 943 */ NT_e5tl, T_assign, 81,
  /* 944 */ NT_e5tl, T_star_assign, 81,
  /* 945 */ NT_e5tl, T_slash_assign, 81,
  /* 946 */ NT_e5tl, T_pct_assign, 81,
  /* 947 */ NT_e5tl, T_starstar_assign, 81,
  /* 948 */ NT_e5tl, T_plus_assign, 81,
  /* 949 */ NT_e5tl, T_minus_assign, 81,
  /* 950 */ NT_e5tl, T_plusplus_assign, 81,
  /* 951 */ NT_e5tl, T_minusminus_assign, 81,
  /* 952 */ NT_e7, T_id, 86,
  /* 953 */ NT_e7, T_lbrace, 86,
  /* 954 */ NT_e7, T_lbrack, 86,
  /* 955 */ NT_e7, T_lparen, 86,
  /* 956 */ NT_e7, T_equal, 86,
  /* 957 */ NT_e7, T_conjop, 86,
  /* 958 */ NT_e7, T_scanop, 86,
  /* 959 */ NT_e7, T_altop, 86,
  /* 960 */ NT_e7, T_carat, 86,
  /* 961 */ NT_e7, T_bslash, 86,
  /* 962 */ NT_e7, T_coop, 86,
  /* 963 */ NT_e7, T_dot, 86,
  /* 964 */ NT_e7, T_repeat, 86,
  /* 965 */ NT_e7, T_while, 86,
  /* 966 */ NT_e7, T_until, 86,
  /* 967 */ NT_e7, T_every, 86,
  /* 968 */ NT_e7, T_if, 86,
  /* 969 */ NT_e7, T_case, 86,
  /* 970 */ NT_e7, T_next, 86,
  /* 971 */ NT_e7, T_break, 86,
  /* 972 */ NT_e7, T_return, 86,
  /* 973 */ NT_e7, T_suspend, 86,
  /* 974 */ NT_e7, T_fail, 86,
  /* 975 */ NT_e7, T_create, 86,
  /* 976 */ NT_e7, T_not, 86,
  /* 977 */ NT_e7, T_bang, 86,
  /* 978 */ NT_e7, T_star, 86,
  /* 979 */ NT_e7, T_plus, 86,
  /* 980 */ NT_e7, T_minus, 86,
  /* 981 */ NT_e7, T_slash, 86,
  /* 982 */ NT_e7, T_tilde, 86,
  /* 983 */ NT_e7, T_intcon, 86,
  /* 984 */ NT_e7, T_radintcon, 86,
  /* 985 */ NT_e7, T_realcon, 86,
  /* 986 */ NT_e7, T_csetcon, 86,
  /* 987 */ NT_e7, T_stringcon, 86,
  /* 988 */ NT_e7, T_hexcon, 86,
  /* 989 */ NT_e7, T_octcon, 86,
  /* 990 */ NT_e6tl, T_rbrace, 85,
  /* 991 */ NT_e6tl, T_of, 85,
  /* 992 */ NT_e6tl, T_rbrack, 85,
  /* 993 */ NT_e6tl, T_rparen, 85,
  /* 994 */ NT_e6tl, T_equal, 84,
  /* 995 */ NT_e6tl, T_colon, 85,
  /* 996 */ NT_e6tl, T_comma, 85,
  /* 997 */ NT_e6tl, T_semico, 85,
  /* 998 */ NT_e6tl, T_end, 85,
  /* 999 */ NT_e6tl, T_eol, 85,
  /* 1000 */ NT_e6tl, T_conjop, 85,
  /* 1001 */ NT_e6tl, T_scanop, 85,
  /* 1002 */ NT_e6tl, T_to, 85,
  /* 1003 */ NT_e6tl, T_by, 85,
  /* 1004 */ NT_e6tl, T_altop, 85,
  /* 1005 */ NT_e6tl, T_catop, 85,
  /* 1006 */ NT_e6tl, T_carat, 85,
  /* 1007 */ NT_e6tl, T_bslash, 85,
  /* 1008 */ NT_e6tl, T_coop, 85,
  /* 1009 */ NT_e6tl, T_pcolon, 85,
  /* 1010 */ NT_e6tl, T_mcolon, 85,
  /* 1011 */ NT_e6tl, T_then, 85,
  /* 1012 */ NT_e6tl, T_do, 85,
  /* 1013 */ NT_e6tl, T_else, 85,
  /* 1014 */ NT_e6tl, T_lt, 83,
  /* 1015 */ NT_e6tl, T_lteq, 83,
  /* 1016 */ NT_e6tl, T_gt, 83,
  /* 1017 */ NT_e6tl, T_gteq, 83,
  /* 1018 */ NT_e6tl, T_noteq, 83,
  /* 1019 */ NT_e6tl, T_star, 85,
  /* 1020 */ NT_e6tl, T_plus, 85,
  /* 1021 */ NT_e6tl, T_minus, 85,
  /* 1022 */ NT_e6tl, T_slash, 85,
  /* 1023 */ NT_e6tl, T_pct, 85,
  /* 1024 */ NT_e6tl, T_starstar, 85,
  /* 1025 */ NT_e6tl, T_plusplus, 85,
  /* 1026 */ NT_e6tl, T_minusminus, 85,
  /* 1027 */ NT_e6tl, T_assign, 85,
  /* 1028 */ NT_e6tl, T_star_assign, 85,
  /* 1029 */ NT_e6tl, T_slash_assign, 85,
  /* 1030 */ NT_e6tl, T_pct_assign, 85,
  /* 1031 */ NT_e6tl, T_starstar_assign, 85,
  /* 1032 */ NT_e6tl, T_plus_assign, 85,
  /* 1033 */ NT_e6tl, T_minus_assign, 85,
  /* 1034 */ NT_e6tl, T_plusplus_assign, 85,
  /* 1035 */ NT_e6tl, T_minusminus_assign, 85,
  /* 1036 */ NT_relop, T_lt, 151,
  /* 1037 */ NT_relop, T_lteq, 152,
  /* 1038 */ NT_relop, T_gt, 153,
  /* 1039 */ NT_relop, T_gteq, 154,
  /* 1040 */ NT_relop, T_noteq, 155,
  /* 1041 */ NT_e8, T_id, 89,
  /* 1042 */ NT_e8, T_lbrace, 89,
  /* 1043 */ NT_e8, T_lbrack, 89,
  /* 1044 */ NT_e8, T_lparen, 89,
  /* 1045 */ NT_e8, T_equal, 89,
  /* 1046 */ NT_e8, T_conjop, 89,
  /* 1047 */ NT_e8, T_scanop, 89,
  /* 1048 */ NT_e8, T_altop, 89,
  /* 1049 */ NT_e8, T_carat, 89,
  /* 1050 */ NT_e8, T_bslash, 89,
  /* 1051 */ NT_e8, T_coop, 89,
  /* 1052 */ NT_e8, T_dot, 89,
  /* 1053 */ NT_e8, T_repeat, 89,
  /* 1054 */ NT_e8, T_while, 89,
  /* 1055 */ NT_e8, T_until, 89,
  /* 1056 */ NT_e8, T_every, 89,
  /* 1057 */ NT_e8, T_if, 89,
  /* 1058 */ NT_e8, T_case, 89,
  /* 1059 */ NT_e8, T_next, 89,
  /* 1060 */ NT_e8, T_break, 89,
  /* 1061 */ NT_e8, T_return, 89,
  /* 1062 */ NT_e8, T_suspend, 89,
  /* 1063 */ NT_e8, T_fail, 89,
  /* 1064 */ NT_e8, T_create, 89,
  /* 1065 */ NT_e8, T_not, 89,
  /* 1066 */ NT_e8, T_bang, 89,
  /* 1067 */ NT_e8, T_star, 89,
  /* 1068 */ NT_e8, T_plus, 89,
  /* 1069 */ NT_e8, T_minus, 89,
  /* 1070 */ NT_e8, T_slash, 89,
  /* 1071 */ NT_e8, T_tilde, 89,
  /* 1072 */ NT_e8, T_intcon, 89,
  /* 1073 */ NT_e8, T_radintcon, 89,
  /* 1074 */ NT_e8, T_realcon, 89,
  /* 1075 */ NT_e8, T_csetcon, 89,
  /* 1076 */ NT_e8, T_stringcon, 89,
  /* 1077 */ NT_e8, T_hexcon, 89,
  /* 1078 */ NT_e8, T_octcon, 89,
  /* 1079 */ NT_e7tl, T_rbrace, 88,
  /* 1080 */ NT_e7tl, T_of, 88,
  /* 1081 */ NT_e7tl, T_rbrack, 88,
  /* 1082 */ NT_e7tl, T_rparen, 88,
  /* 1083 */ NT_e7tl, T_equal, 88,
  /* 1084 */ NT_e7tl, T_colon, 88,
  /* 1085 */ NT_e7tl, T_comma, 88,
  /* 1086 */ NT_e7tl, T_semico, 88,
  /* 1087 */ NT_e7tl, T_end, 88,
  /* 1088 */ NT_e7tl, T_eol, 88,
  /* 1089 */ NT_e7tl, T_conjop, 88,
  /* 1090 */ NT_e7tl, T_scanop, 88,
  /* 1091 */ NT_e7tl, T_to, 88,
  /* 1092 */ NT_e7tl, T_by, 88,
  /* 1093 */ NT_e7tl, T_altop, 88,
  /* 1094 */ NT_e7tl, T_catop, 87,
  /* 1095 */ NT_e7tl, T_carat, 88,
  /* 1096 */ NT_e7tl, T_bslash, 88,
  /* 1097 */ NT_e7tl, T_coop, 88,
  /* 1098 */ NT_e7tl, T_pcolon, 88,
  /* 1099 */ NT_e7tl, T_mcolon, 88,
  /* 1100 */ NT_e7tl, T_then, 88,
  /* 1101 */ NT_e7tl, T_do, 88,
  /* 1102 */ NT_e7tl, T_else, 88,
  /* 1103 */ NT_e7tl, T_lt, 88,
  /* 1104 */ NT_e7tl, T_lteq, 88,
  /* 1105 */ NT_e7tl, T_gt, 88,
  /* 1106 */ NT_e7tl, T_gteq, 88,
  /* 1107 */ NT_e7tl, T_noteq, 88,
  /* 1108 */ NT_e7tl, T_star, 88,
  /* 1109 */ NT_e7tl, T_plus, 88,
  /* 1110 */ NT_e7tl, T_minus, 88,
  /* 1111 */ NT_e7tl, T_slash, 88,
  /* 1112 */ NT_e7tl, T_pct, 88,
  /* 1113 */ NT_e7tl, T_starstar, 88,
  /* 1114 */ NT_e7tl, T_plusplus, 88,
  /* 1115 */ NT_e7tl, T_minusminus, 88,
  /* 1116 */ NT_e7tl, T_assign, 88,
  /* 1117 */ NT_e7tl, T_star_assign, 88,
  /* 1118 */ NT_e7tl, T_slash_assign, 88,
  /* 1119 */ NT_e7tl, T_pct_assign, 88,
  /* 1120 */ NT_e7tl, T_starstar_assign, 88,
  /* 1121 */ NT_e7tl, T_plus_assign, 88,
  /* 1122 */ NT_e7tl, T_minus_assign, 88,
  /* 1123 */ NT_e7tl, T_plusplus_assign, 88,
  /* 1124 */ NT_e7tl, T_minusminus_assign, 88,
  /* 1125 */ NT_e9, T_id, 92,
  /* 1126 */ NT_e9, T_lbrace, 92,
  /* 1127 */ NT_e9, T_lbrack, 92,
  /* 1128 */ NT_e9, T_lparen, 92,
  /* 1129 */ NT_e9, T_equal, 92,
  /* 1130 */ NT_e9, T_conjop, 92,
  /* 1131 */ NT_e9, T_scanop, 92,
  /* 1132 */ NT_e9, T_altop, 92,
  /* 1133 */ NT_e9, T_carat, 92,
  /* 1134 */ NT_e9, T_bslash, 92,
  /* 1135 */ NT_e9, T_coop, 92,
  /* 1136 */ NT_e9, T_dot, 92,
  /* 1137 */ NT_e9, T_repeat, 92,
  /* 1138 */ NT_e9, T_while, 92,
  /* 1139 */ NT_e9, T_until, 92,
  /* 1140 */ NT_e9, T_every, 92,
  /* 1141 */ NT_e9, T_if, 92,
  /* 1142 */ NT_e9, T_case, 92,
  /* 1143 */ NT_e9, T_next, 92,
  /* 1144 */ NT_e9, T_break, 92,
  /* 1145 */ NT_e9, T_return, 92,
  /* 1146 */ NT_e9, T_suspend, 92,
  /* 1147 */ NT_e9, T_fail, 92,
  /* 1148 */ NT_e9, T_create, 92,
  /* 1149 */ NT_e9, T_not, 92,
  /* 1150 */ NT_e9, T_bang, 92,
  /* 1151 */ NT_e9, T_star, 92,
  /* 1152 */ NT_e9, T_plus, 92,
  /* 1153 */ NT_e9, T_minus, 92,
  /* 1154 */ NT_e9, T_slash, 92,
  /* 1155 */ NT_e9, T_tilde, 92,
  /* 1156 */ NT_e9, T_intcon, 92,
  /* 1157 */ NT_e9, T_radintcon, 92,
  /* 1158 */ NT_e9, T_realcon, 92,
  /* 1159 */ NT_e9, T_csetcon, 92,
  /* 1160 */ NT_e9, T_stringcon, 92,
  /* 1161 */ NT_e9, T_hexcon, 92,
  /* 1162 */ NT_e9, T_octcon, 92,
  /* 1163 */ NT_e8tl, T_rbrace, 91,
  /* 1164 */ NT_e8tl, T_of, 91,
  /* 1165 */ NT_e8tl, T_rbrack, 91,
  /* 1166 */ NT_e8tl, T_rparen, 91,
  /* 1167 */ NT_e8tl, T_equal, 91,
  /* 1168 */ NT_e8tl, T_colon, 91,
  /* 1169 */ NT_e8tl, T_comma, 91,
  /* 1170 */ NT_e8tl, T_semico, 91,
  /* 1171 */ NT_e8tl, T_end, 91,
  /* 1172 */ NT_e8tl, T_eol, 91,
  /* 1173 */ NT_e8tl, T_conjop, 91,
  /* 1174 */ NT_e8tl, T_scanop, 91,
  /* 1175 */ NT_e8tl, T_to, 91,
  /* 1176 */ NT_e8tl, T_by, 91,
  /* 1177 */ NT_e8tl, T_altop, 91,
  /* 1178 */ NT_e8tl, T_catop, 91,
  /* 1179 */ NT_e8tl, T_carat, 91,
  /* 1180 */ NT_e8tl, T_bslash, 91,
  /* 1181 */ NT_e8tl, T_coop, 91,
  /* 1182 */ NT_e8tl, T_pcolon, 91,
  /* 1183 */ NT_e8tl, T_mcolon, 91,
  /* 1184 */ NT_e8tl, T_then, 91,
  /* 1185 */ NT_e8tl, T_do, 91,
  /* 1186 */ NT_e8tl, T_else, 91,
  /* 1187 */ NT_e8tl, T_lt, 91,
  /* 1188 */ NT_e8tl, T_lteq, 91,
  /* 1189 */ NT_e8tl, T_gt, 91,
  /* 1190 */ NT_e8tl, T_gteq, 91,
  /* 1191 */ NT_e8tl, T_noteq, 91,
  /* 1192 */ NT_e8tl, T_star, 91,
  /* 1193 */ NT_e8tl, T_plus, 90,
  /* 1194 */ NT_e8tl, T_minus, 90,
  /* 1195 */ NT_e8tl, T_slash, 91,
  /* 1196 */ NT_e8tl, T_pct, 91,
  /* 1197 */ NT_e8tl, T_starstar, 91,
  /* 1198 */ NT_e8tl, T_plusplus, 90,
  /* 1199 */ NT_e8tl, T_minusminus, 90,
  /* 1200 */ NT_e8tl, T_assign, 91,
  /* 1201 */ NT_e8tl, T_star_assign, 91,
  /* 1202 */ NT_e8tl, T_slash_assign, 91,
  /* 1203 */ NT_e8tl, T_pct_assign, 91,
  /* 1204 */ NT_e8tl, T_starstar_assign, 91,
  /* 1205 */ NT_e8tl, T_plus_assign, 91,
  /* 1206 */ NT_e8tl, T_minus_assign, 91,
  /* 1207 */ NT_e8tl, T_plusplus_assign, 91,
  /* 1208 */ NT_e8tl, T_minusminus_assign, 91,
  /* 1209 */ NT_addop, T_plus, 174,
  /* 1210 */ NT_addop, T_minus, 175,
  /* 1211 */ NT_addop, T_plusplus, 176,
  /* 1212 */ NT_addop, T_minusminus, 177,
  /* 1213 */ NT_e10, T_id, 95,
  /* 1214 */ NT_e10, T_lbrace, 95,
  /* 1215 */ NT_e10, T_lbrack, 95,
  /* 1216 */ NT_e10, T_lparen, 95,
  /* 1217 */ NT_e10, T_equal, 95,
  /* 1218 */ NT_e10, T_conjop, 95,
  /* 1219 */ NT_e10, T_scanop, 95,
  /* 1220 */ NT_e10, T_altop, 95,
  /* 1221 */ NT_e10, T_carat, 95,
  /* 1222 */ NT_e10, T_bslash, 95,
  /* 1223 */ NT_e10, T_coop, 95,
  /* 1224 */ NT_e10, T_dot, 95,
  /* 1225 */ NT_e10, T_repeat, 95,
  /* 1226 */ NT_e10, T_while, 95,
  /* 1227 */ NT_e10, T_until, 95,
  /* 1228 */ NT_e10, T_every, 95,
  /* 1229 */ NT_e10, T_if, 95,
  /* 1230 */ NT_e10, T_case, 95,
  /* 1231 */ NT_e10, T_next, 95,
  /* 1232 */ NT_e10, T_break, 95,
  /* 1233 */ NT_e10, T_return, 95,
  /* 1234 */ NT_e10, T_suspend, 95,
  /* 1235 */ NT_e10, T_fail, 95,
  /* 1236 */ NT_e10, T_create, 95,
  /* 1237 */ NT_e10, T_not, 95,
  /* 1238 */ NT_e10, T_bang, 95,
  /* 1239 */ NT_e10, T_star, 95,
  /* 1240 */ NT_e10, T_plus, 95,
  /* 1241 */ NT_e10, T_minus, 95,
  /* 1242 */ NT_e10, T_slash, 95,
  /* 1243 */ NT_e10, T_tilde, 95,
  /* 1244 */ NT_e10, T_intcon, 95,
  /* 1245 */ NT_e10, T_radintcon, 95,
  /* 1246 */ NT_e10, T_realcon, 95,
  /* 1247 */ NT_e10, T_csetcon, 95,
  /* 1248 */ NT_e10, T_stringcon, 95,
  /* 1249 */ NT_e10, T_hexcon, 95,
  /* 1250 */ NT_e10, T_octcon, 95,
  /* 1251 */ NT_e9tl, T_rbrace, 94,
  /* 1252 */ NT_e9tl, T_of, 94,
  /* 1253 */ NT_e9tl, T_rbrack, 94,
  /* 1254 */ NT_e9tl, T_rparen, 94,
  /* 1255 */ NT_e9tl, T_equal, 94,
  /* 1256 */ NT_e9tl, T_colon, 94,
  /* 1257 */ NT_e9tl, T_comma, 94,
  /* 1258 */ NT_e9tl, T_semico, 94,
  /* 1259 */ NT_e9tl, T_end, 94,
  /* 1260 */ NT_e9tl, T_eol, 94,
  /* 1261 */ NT_e9tl, T_conjop, 94,
  /* 1262 */ NT_e9tl, T_scanop, 94,
  /* 1263 */ NT_e9tl, T_to, 94,
  /* 1264 */ NT_e9tl, T_by, 94,
  /* 1265 */ NT_e9tl, T_altop, 94,
  /* 1266 */ NT_e9tl, T_catop, 94,
  /* 1267 */ NT_e9tl, T_carat, 94,
  /* 1268 */ NT_e9tl, T_bslash, 94,
  /* 1269 */ NT_e9tl, T_coop, 94,
  /* 1270 */ NT_e9tl, T_pcolon, 94,
  /* 1271 */ NT_e9tl, T_mcolon, 94,
  /* 1272 */ NT_e9tl, T_then, 94,
  /* 1273 */ NT_e9tl, T_do, 94,
  /* 1274 */ NT_e9tl, T_else, 94,
  /* 1275 */ NT_e9tl, T_lt, 94,
  /* 1276 */ NT_e9tl, T_lteq, 94,
  /* 1277 */ NT_e9tl, T_gt, 94,
  /* 1278 */ NT_e9tl, T_gteq, 94,
  /* 1279 */ NT_e9tl, T_noteq, 94,
  /* 1280 */ NT_e9tl, T_star, 93,
  /* 1281 */ NT_e9tl, T_plus, 94,
  /* 1282 */ NT_e9tl, T_minus, 94,
  /* 1283 */ NT_e9tl, T_slash, 93,
  /* 1284 */ NT_e9tl, T_pct, 93,
  /* 1285 */ NT_e9tl, T_starstar, 93,
  /* 1286 */ NT_e9tl, T_plusplus, 94,
  /* 1287 */ NT_e9tl, T_minusminus, 94,
  /* 1288 */ NT_e9tl, T_assign, 94,
  /* 1289 */ NT_e9tl, T_star_assign, 94,
  /* 1290 */ NT_e9tl, T_slash_assign, 94,
  /* 1291 */ NT_e9tl, T_pct_assign, 94,
  /* 1292 */ NT_e9tl, T_starstar_assign, 94,
  /* 1293 */ NT_e9tl, T_plus_assign, 94,
  /* 1294 */ NT_e9tl, T_minus_assign, 94,
  /* 1295 */ NT_e9tl, T_plusplus_assign, 94,
  /* 1296 */ NT_e9tl, T_minusminus_assign, 94,
  /* 1297 */ NT_mulop, T_star, 170,
  /* 1298 */ NT_mulop, T_slash, 171,
  /* 1299 */ NT_mulop, T_pct, 172,
  /* 1300 */ NT_mulop, T_starstar, 173,
  /* 1301 */ NT_e11, T_id, 98,
  /* 1302 */ NT_e11, T_lbrace, 98,
  /* 1303 */ NT_e11, T_lbrack, 98,
  /* 1304 */ NT_e11, T_lparen, 98,
  /* 1305 */ NT_e11, T_equal, 98,
  /* 1306 */ NT_e11, T_conjop, 98,
  /* 1307 */ NT_e11, T_scanop, 98,
  /* 1308 */ NT_e11, T_altop, 98,
  /* 1309 */ NT_e11, T_carat, 98,
  /* 1310 */ NT_e11, T_bslash, 98,
  /* 1311 */ NT_e11, T_coop, 98,
  /* 1312 */ NT_e11, T_dot, 98,
  /* 1313 */ NT_e11, T_repeat, 98,
  /* 1314 */ NT_e11, T_while, 98,
  /* 1315 */ NT_e11, T_until, 98,
  /* 1316 */ NT_e11, T_every, 98,
  /* 1317 */ NT_e11, T_if, 98,
  /* 1318 */ NT_e11, T_case, 98,
  /* 1319 */ NT_e11, T_next, 98,
  /* 1320 */ NT_e11, T_break, 98,
  /* 1321 */ NT_e11, T_return, 98,
  /* 1322 */ NT_e11, T_suspend, 98,
  /* 1323 */ NT_e11, T_fail, 98,
  /* 1324 */ NT_e11, T_create, 98,
  /* 1325 */ NT_e11, T_not, 98,
  /* 1326 */ NT_e11, T_bang, 98,
  /* 1327 */ NT_e11, T_star, 98,
  /* 1328 */ NT_e11, T_plus, 98,
  /* 1329 */ NT_e11, T_minus, 98,
  /* 1330 */ NT_e11, T_slash, 98,
  /* 1331 */ NT_e11, T_tilde, 98,
  /* 1332 */ NT_e11, T_intcon, 98,
  /* 1333 */ NT_e11, T_radintcon, 98,
  /* 1334 */ NT_e11, T_realcon, 98,
  /* 1335 */ NT_e11, T_csetcon, 98,
  /* 1336 */ NT_e11, T_stringcon, 98,
  /* 1337 */ NT_e11, T_hexcon, 98,
  /* 1338 */ NT_e11, T_octcon, 98,
  /* 1339 */ NT_e10tl, T_rbrace, 97,
  /* 1340 */ NT_e10tl, T_of, 97,
  /* 1341 */ NT_e10tl, T_rbrack, 97,
  /* 1342 */ NT_e10tl, T_rparen, 97,
  /* 1343 */ NT_e10tl, T_equal, 97,
  /* 1344 */ NT_e10tl, T_colon, 97,
  /* 1345 */ NT_e10tl, T_comma, 97,
  /* 1346 */ NT_e10tl, T_semico, 97,
  /* 1347 */ NT_e10tl, T_end, 97,
  /* 1348 */ NT_e10tl, T_eol, 97,
  /* 1349 */ NT_e10tl, T_conjop, 97,
  /* 1350 */ NT_e10tl, T_scanop, 97,
  /* 1351 */ NT_e10tl, T_to, 97,
  /* 1352 */ NT_e10tl, T_by, 97,
  /* 1353 */ NT_e10tl, T_altop, 97,
  /* 1354 */ NT_e10tl, T_catop, 97,
  /* 1355 */ NT_e10tl, T_carat, 96,
  /* 1356 */ NT_e10tl, T_bslash, 97,
  /* 1357 */ NT_e10tl, T_coop, 97,
  /* 1358 */ NT_e10tl, T_pcolon, 97,
  /* 1359 */ NT_e10tl, T_mcolon, 97,
  /* 1360 */ NT_e10tl, T_then, 97,
  /* 1361 */ NT_e10tl, T_do, 97,
  /* 1362 */ NT_e10tl, T_else, 97,
  /* 1363 */ NT_e10tl, T_lt, 97,
  /* 1364 */ NT_e10tl, T_lteq, 97,
  /* 1365 */ NT_e10tl, T_gt, 97,
  /* 1366 */ NT_e10tl, T_gteq, 97,
  /* 1367 */ NT_e10tl, T_noteq, 97,
  /* 1368 */ NT_e10tl, T_star, 97,
  /* 1369 */ NT_e10tl, T_plus, 97,
  /* 1370 */ NT_e10tl, T_minus, 97,
  /* 1371 */ NT_e10tl, T_slash, 97,
  /* 1372 */ NT_e10tl, T_pct, 97,
  /* 1373 */ NT_e10tl, T_starstar, 97,
  /* 1374 */ NT_e10tl, T_plusplus, 97,
  /* 1375 */ NT_e10tl, T_minusminus, 97,
  /* 1376 */ NT_e10tl, T_assign, 97,
  /* 1377 */ NT_e10tl, T_star_assign, 97,
  /* 1378 */ NT_e10tl, T_slash_assign, 97,
  /* 1379 */ NT_e10tl, T_pct_assign, 97,
  /* 1380 */ NT_e10tl, T_starstar_assign, 97,
  /* 1381 */ NT_e10tl, T_plus_assign, 97,
  /* 1382 */ NT_e10tl, T_minus_assign, 97,
  /* 1383 */ NT_e10tl, T_plusplus_assign, 97,
  /* 1384 */ NT_e10tl, T_minusminus_assign, 97,
  /* 1385 */ NT_e12, T_id, 103,
  /* 1386 */ NT_e12, T_lbrace, 103,
  /* 1387 */ NT_e12, T_lbrack, 103,
  /* 1388 */ NT_e12, T_lparen, 103,
  /* 1389 */ NT_e12, T_equal, 102,
  /* 1390 */ NT_e12, T_conjop, 103,
  /* 1391 */ NT_e12, T_scanop, 102,
  /* 1392 */ NT_e12, T_altop, 102,
  /* 1393 */ NT_e12, T_carat, 102,
  /* 1394 */ NT_e12, T_bslash, 102,
  /* 1395 */ NT_e12, T_coop, 102,
  /* 1396 */ NT_e12, T_dot, 102,
  /* 1397 */ NT_e12, T_repeat, 103,
  /* 1398 */ NT_e12, T_while, 103,
  /* 1399 */ NT_e12, T_until, 103,
  /* 1400 */ NT_e12, T_every, 103,
  /* 1401 */ NT_e12, T_if, 103,
  /* 1402 */ NT_e12, T_case, 103,
  /* 1403 */ NT_e12, T_next, 103,
  /* 1404 */ NT_e12, T_break, 103,
  /* 1405 */ NT_e12, T_return, 103,
  /* 1406 */ NT_e12, T_suspend, 103,
  /* 1407 */ NT_e12, T_fail, 103,
  /* 1408 */ NT_e12, T_create, 103,
  /* 1409 */ NT_e12, T_not, 102,
  /* 1410 */ NT_e12, T_bang, 102,
  /* 1411 */ NT_e12, T_star, 102,
  /* 1412 */ NT_e12, T_plus, 102,
  /* 1413 */ NT_e12, T_minus, 102,
  /* 1414 */ NT_e12, T_slash, 102,
  /* 1415 */ NT_e12, T_tilde, 102,
  /* 1416 */ NT_e12, T_intcon, 103,
  /* 1417 */ NT_e12, T_radintcon, 103,
  /* 1418 */ NT_e12, T_realcon, 103,
  /* 1419 */ NT_e12, T_csetcon, 103,
  /* 1420 */ NT_e12, T_stringcon, 103,
  /* 1421 */ NT_e12, T_hexcon, 103,
  /* 1422 */ NT_e12, T_octcon, 103,
  /* 1423 */ NT_e11tl, T_rbrace, 101,
  /* 1424 */ NT_e11tl, T_of, 101,
  /* 1425 */ NT_e11tl, T_rbrack, 101,
  /* 1426 */ NT_e11tl, T_rparen, 101,
  /* 1427 */ NT_e11tl, T_equal, 101,
  /* 1428 */ NT_e11tl, T_colon, 101,
  /* 1429 */ NT_e11tl, T_comma, 101,
  /* 1430 */ NT_e11tl, T_semico, 101,
  /* 1431 */ NT_e11tl, T_end, 101,
  /* 1432 */ NT_e11tl, T_eol, 101,
  /* 1433 */ NT_e11tl, T_conjop, 101,
  /* 1434 */ NT_e11tl, T_scanop, 101,
  /* 1435 */ NT_e11tl, T_to, 101,
  /* 1436 */ NT_e11tl, T_by, 101,
  /* 1437 */ NT_e11tl, T_altop, 101,
  /* 1438 */ NT_e11tl, T_catop, 101,
  /* 1439 */ NT_e11tl, T_carat, 101,
  /* 1440 */ NT_e11tl, T_bslash, 99,
  /* 1441 */ NT_e11tl, T_coop, 100,
  /* 1442 */ NT_e11tl, T_pcolon, 101,
  /* 1443 */ NT_e11tl, T_mcolon, 101,
  /* 1444 */ NT_e11tl, T_then, 101,
  /* 1445 */ NT_e11tl, T_do, 101,
  /* 1446 */ NT_e11tl, T_else, 101,
  /* 1447 */ NT_e11tl, T_lt, 101,
  /* 1448 */ NT_e11tl, T_lteq, 101,
  /* 1449 */ NT_e11tl, T_gt, 101,
  /* 1450 */ NT_e11tl, T_gteq, 101,
  /* 1451 */ NT_e11tl, T_noteq, 101,
  /* 1452 */ NT_e11tl, T_star, 101,
  /* 1453 */ NT_e11tl, T_plus, 101,
  /* 1454 */ NT_e11tl, T_minus, 101,
  /* 1455 */ NT_e11tl, T_slash, 101,
  /* 1456 */ NT_e11tl, T_pct, 101,
  /* 1457 */ NT_e11tl, T_starstar, 101,
  /* 1458 */ NT_e11tl, T_plusplus, 101,
  /* 1459 */ NT_e11tl, T_minusminus, 101,
  /* 1460 */ NT_e11tl, T_assign, 101,
  /* 1461 */ NT_e11tl, T_star_assign, 101,
  /* 1462 */ NT_e11tl, T_slash_assign, 101,
  /* 1463 */ NT_e11tl, T_pct_assign, 101,
  /* 1464 */ NT_e11tl, T_starstar_assign, 101,
  /* 1465 */ NT_e11tl, T_plus_assign, 101,
  /* 1466 */ NT_e11tl, T_minus_assign, 101,
  /* 1467 */ NT_e11tl, T_plusplus_assign, 101,
  /* 1468 */ NT_e11tl, T_minusminus_assign, 101,
  /* 1469 */ NT_uop, T_equal, 164,
  /* 1470 */ NT_uop, T_scanop, 165,
  /* 1471 */ NT_uop, T_altop, 157,
  /* 1472 */ NT_uop, T_carat, 169,
  /* 1473 */ NT_uop, T_bslash, 166,
  /* 1474 */ NT_uop, T_coop, 168,
  /* 1475 */ NT_uop, T_dot, 162,
  /* 1476 */ NT_uop, T_not, 156,
  /* 1477 */ NT_uop, T_bang, 158,
  /* 1478 */ NT_uop, T_star, 159,
  /* 1479 */ NT_uop, T_plus, 160,
  /* 1480 */ NT_uop, T_minus, 161,
  /* 1481 */ NT_uop, T_slash, 163,
  /* 1482 */ NT_uop, T_tilde, 167,
  /* 1483 */ NT_e13, T_id, 105,
  /* 1484 */ NT_e13, T_lbrace, 105,
  /* 1485 */ NT_e13, T_lbrack, 105,
  /* 1486 */ NT_e13, T_lparen, 105,
  /* 1487 */ NT_e13, T_conjop, 105,
  /* 1488 */ NT_e13, T_repeat, 104,
  /* 1489 */ NT_e13, T_while, 104,
  /* 1490 */ NT_e13, T_until, 104,
  /* 1491 */ NT_e13, T_every, 104,
  /* 1492 */ NT_e13, T_if, 104,
  /* 1493 */ NT_e13, T_case, 104,
  /* 1494 */ NT_e13, T_next, 104,
  /* 1495 */ NT_e13, T_break, 104,
  /* 1496 */ NT_e13, T_return, 104,
  /* 1497 */ NT_e13, T_suspend, 104,
  /* 1498 */ NT_e13, T_fail, 104,
  /* 1499 */ NT_e13, T_create, 104,
  /* 1500 */ NT_e13, T_intcon, 105,
  /* 1501 */ NT_e13, T_radintcon, 105,
  /* 1502 */ NT_e13, T_realcon, 105,
  /* 1503 */ NT_e13, T_csetcon, 105,
  /* 1504 */ NT_e13, T_stringcon, 105,
  /* 1505 */ NT_e13, T_hexcon, 105,
  /* 1506 */ NT_e13, T_octcon, 105,
  /* 1507 */ NT_ek, T_repeat, 119,
  /* 1508 */ NT_ek, T_while, 120,
  /* 1509 */ NT_ek, T_until, 121,
  /* 1510 */ NT_ek, T_every, 122,
  /* 1511 */ NT_ek, T_if, 123,
  /* 1512 */ NT_ek, T_case, 124,
  /* 1513 */ NT_ek, T_next, 125,
  /* 1514 */ NT_ek, T_break, 126,
  /* 1515 */ NT_ek, T_return, 127,
  /* 1516 */ NT_ek, T_suspend, 128,
  /* 1517 */ NT_ek, T_fail, 129,
  /* 1518 */ NT_ek, T_create, 130,
  /* 1519 */ NT_e14, T_id, 146,
  /* 1520 */ NT_e14, T_lbrace, 145,
  /* 1521 */ NT_e14, T_lbrack, 144,
  /* 1522 */ NT_e14, T_lparen, 143,
  /* 1523 */ NT_e14, T_conjop, 147,
  /* 1524 */ NT_e14, T_intcon, 148,
  /* 1525 */ NT_e14, T_radintcon, 148,
  /* 1526 */ NT_e14, T_realcon, 148,
  /* 1527 */ NT_e14, T_csetcon, 148,
  /* 1528 */ NT_e14, T_stringcon, 148,
  /* 1529 */ NT_e14, T_hexcon, 148,
  /* 1530 */ NT_e14, T_octcon, 148,
  /* 1531 */ NT_e13tl, T_rbrace, 110,
  /* 1532 */ NT_e13tl, T_of, 110,
  /* 1533 */ NT_e13tl, T_lbrack, 107,
  /* 1534 */ NT_e13tl, T_rbrack, 110,
  /* 1535 */ NT_e13tl, T_lparen, 106,
  /* 1536 */ NT_e13tl, T_rparen, 110,
  /* 1537 */ NT_e13tl, T_equal, 110,
  /* 1538 */ NT_e13tl, T_colon, 110,
  /* 1539 */ NT_e13tl, T_comma, 110,
  /* 1540 */ NT_e13tl, T_semico, 110,
  /* 1541 */ NT_e13tl, T_end, 110,
  /* 1542 */ NT_e13tl, T_eol, 110,
  /* 1543 */ NT_e13tl, T_conjop, 110,
  /* 1544 */ NT_e13tl, T_scanop, 110,
  /* 1545 */ NT_e13tl, T_to, 110,
  /* 1546 */ NT_e13tl, T_by, 110,
  /* 1547 */ NT_e13tl, T_altop, 110,
  /* 1548 */ NT_e13tl, T_catop, 110,
  /* 1549 */ NT_e13tl, T_carat, 110,
  /* 1550 */ NT_e13tl, T_bslash, 110,
  /* 1551 */ NT_e13tl, T_coop, 110,
  /* 1552 */ NT_e13tl, T_castop, 108,
  /* 1553 */ NT_e13tl, T_dot, 109,
  /* 1554 */ NT_e13tl, T_pcolon, 110,
  /* 1555 */ NT_e13tl, T_mcolon, 110,
  /* 1556 */ NT_e13tl, T_then, 110,
  /* 1557 */ NT_e13tl, T_do, 110,
  /* 1558 */ NT_e13tl, T_else, 110,
  /* 1559 */ NT_e13tl, T_lt, 110,
  /* 1560 */ NT_e13tl, T_lteq, 110,
  /* 1561 */ NT_e13tl, T_gt, 110,
  /* 1562 */ NT_e13tl, T_gteq, 110,
  /* 1563 */ NT_e13tl, T_noteq, 110,
  /* 1564 */ NT_e13tl, T_star, 110,
  /* 1565 */ NT_e13tl, T_plus, 110,
  /* 1566 */ NT_e13tl, T_minus, 110,
  /* 1567 */ NT_e13tl, T_slash, 110,
  /* 1568 */ NT_e13tl, T_pct, 110,
  /* 1569 */ NT_e13tl, T_starstar, 110,
  /* 1570 */ NT_e13tl, T_plusplus, 110,
  /* 1571 */ NT_e13tl, T_minusminus, 110,
  /* 1572 */ NT_e13tl, T_assign, 110,
  /* 1573 */ NT_e13tl, T_star_assign, 110,
  /* 1574 */ NT_e13tl, T_slash_assign, 110,
  /* 1575 */ NT_e13tl, T_pct_assign, 110,
  /* 1576 */ NT_e13tl, T_starstar_assign, 110,
  /* 1577 */ NT_e13tl, T_plus_assign, 110,
  /* 1578 */ NT_e13tl, T_minus_assign, 110,
  /* 1579 */ NT_e13tl, T_plusplus_assign, 110,
  /* 1580 */ NT_e13tl, T_minusminus_assign, 110,
  /* 1581 */ NT_elist, T_id, 115,
  /* 1582 */ NT_elist, T_lbrace, 115,
  /* 1583 */ NT_elist, T_lbrack, 115,
  /* 1584 */ NT_elist, T_rbrack, 116,
  /* 1585 */ NT_elist, T_lparen, 115,
  /* 1586 */ NT_elist, T_rparen, 116,
  /* 1587 */ NT_elist, T_equal, 115,
  /* 1588 */ NT_elist, T_conjop, 115,
  /* 1589 */ NT_elist, T_scanop, 115,
  /* 1590 */ NT_elist, T_altop, 115,
  /* 1591 */ NT_elist, T_carat, 115,
  /* 1592 */ NT_elist, T_bslash, 115,
  /* 1593 */ NT_elist, T_coop, 115,
  /* 1594 */ NT_elist, T_dot, 115,
  /* 1595 */ NT_elist, T_repeat, 115,
  /* 1596 */ NT_elist, T_while, 115,
  /* 1597 */ NT_elist, T_until, 115,
  /* 1598 */ NT_elist, T_every, 115,
  /* 1599 */ NT_elist, T_if, 115,
  /* 1600 */ NT_elist, T_case, 115,
  /* 1601 */ NT_elist, T_next, 115,
  /* 1602 */ NT_elist, T_break, 115,
  /* 1603 */ NT_elist, T_return, 115,
  /* 1604 */ NT_elist, T_suspend, 115,
  /* 1605 */ NT_elist, T_fail, 115,
  /* 1606 */ NT_elist, T_create, 115,
  /* 1607 */ NT_elist, T_not, 115,
  /* 1608 */ NT_elist, T_bang, 115,
  /* 1609 */ NT_elist, T_star, 115,
  /* 1610 */ NT_elist, T_plus, 115,
  /* 1611 */ NT_elist, T_minus, 115,
  /* 1612 */ NT_elist, T_slash, 115,
  /* 1613 */ NT_elist, T_tilde, 115,
  /* 1614 */ NT_elist, T_intcon, 115,
  /* 1615 */ NT_elist, T_radintcon, 115,
  /* 1616 */ NT_elist, T_realcon, 115,
  /* 1617 */ NT_elist, T_csetcon, 115,
  /* 1618 */ NT_elist, T_stringcon, 115,
  /* 1619 */ NT_elist, T_hexcon, 115,
  /* 1620 */ NT_elist, T_octcon, 115,
  /* 1621 */ NT_rangetl, T_rbrack, 114,
  /* 1622 */ NT_rangetl, T_colon, 111,
  /* 1623 */ NT_rangetl, T_pcolon, 112,
  /* 1624 */ NT_rangetl, T_mcolon, 113,
  /* 1625 */ NT_elisttl, T_rbrack, 118,
  /* 1626 */ NT_elisttl, T_rparen, 118,
  /* 1627 */ NT_elisttl, T_comma, 117,
  /* 1628 */ NT_doopt, T_rbrace, 132,
  /* 1629 */ NT_doopt, T_of, 132,
  /* 1630 */ NT_doopt, T_rbrack, 132,
  /* 1631 */ NT_doopt, T_rparen, 132,
  /* 1632 */ NT_doopt, T_equal, 132,
  /* 1633 */ NT_doopt, T_colon, 132,
  /* 1634 */ NT_doopt, T_comma, 132,
  /* 1635 */ NT_doopt, T_semico, 132,
  /* 1636 */ NT_doopt, T_end, 132,
  /* 1637 */ NT_doopt, T_eol, 132,
  /* 1638 */ NT_doopt, T_conjop, 132,
  /* 1639 */ NT_doopt, T_scanop, 132,
  /* 1640 */ NT_doopt, T_to, 132,
  /* 1641 */ NT_doopt, T_by, 132,
  /* 1642 */ NT_doopt, T_altop, 132,
  /* 1643 */ NT_doopt, T_catop, 132,
  /* 1644 */ NT_doopt, T_carat, 132,
  /* 1645 */ NT_doopt, T_bslash, 132,
  /* 1646 */ NT_doopt, T_coop, 132,
  /* 1647 */ NT_doopt, T_pcolon, 132,
  /* 1648 */ NT_doopt, T_mcolon, 132,
  /* 1649 */ NT_doopt, T_then, 132,
  /* 1650 */ NT_doopt, T_do, 131,
  /* 1651 */ NT_doopt, T_else, 132,
  /* 1652 */ NT_doopt, T_lt, 132,
  /* 1653 */ NT_doopt, T_lteq, 132,
  /* 1654 */ NT_doopt, T_gt, 132,
  /* 1655 */ NT_doopt, T_gteq, 132,
  /* 1656 */ NT_doopt, T_noteq, 132,
  /* 1657 */ NT_doopt, T_star, 132,
  /* 1658 */ NT_doopt, T_plus, 132,
  /* 1659 */ NT_doopt, T_minus, 132,
  /* 1660 */ NT_doopt, T_slash, 132,
  /* 1661 */ NT_doopt, T_pct, 132,
  /* 1662 */ NT_doopt, T_starstar, 132,
  /* 1663 */ NT_doopt, T_plusplus, 132,
  /* 1664 */ NT_doopt, T_minusminus, 132,
  /* 1665 */ NT_doopt, T_assign, 132,
  /* 1666 */ NT_doopt, T_star_assign, 132,
  /* 1667 */ NT_doopt, T_slash_assign, 132,
  /* 1668 */ NT_doopt, T_pct_assign, 132,
  /* 1669 */ NT_doopt, T_starstar_assign, 132,
  /* 1670 */ NT_doopt, T_plus_assign, 132,
  /* 1671 */ NT_doopt, T_minus_assign, 132,
  /* 1672 */ NT_doopt, T_plusplus_assign, 132,
  /* 1673 */ NT_doopt, T_minusminus_assign, 132,
  /* 1674 */ NT_elseopt, T_rbrace, 134,
  /* 1675 */ NT_elseopt, T_of, 134,
  /* 1676 */ NT_elseopt, T_rbrack, 134,
  /* 1677 */ NT_elseopt, T_rparen, 134,
  /* 1678 */ NT_elseopt, T_equal, 134,
  /* 1679 */ NT_elseopt, T_colon, 134,
  /* 1680 */ NT_elseopt, T_comma, 134,
  /* 1681 */ NT_elseopt, T_semico, 134,
  /* 1682 */ NT_elseopt, T_end, 134,
  /* 1683 */ NT_elseopt, T_eol, 134,
  /* 1684 */ NT_elseopt, T_conjop, 134,
  /* 1685 */ NT_elseopt, T_scanop, 134,
  /* 1686 */ NT_elseopt, T_to, 134,
  /* 1687 */ NT_elseopt, T_by, 134,
  /* 1688 */ NT_elseopt, T_altop, 134,
  /* 1689 */ NT_elseopt, T_catop, 134,
  /* 1690 */ NT_elseopt, T_carat, 134,
  /* 1691 */ NT_elseopt, T_bslash, 134,
  /* 1692 */ NT_elseopt, T_coop, 134,
  /* 1693 */ NT_elseopt, T_pcolon, 134,
  /* 1694 */ NT_elseopt, T_mcolon, 134,
  /* 1695 */ NT_elseopt, T_then, 134,
  /* 1696 */ NT_elseopt, T_do, 134,
  /* 1697 */ NT_elseopt, T_else, 133,
  /* 1698 */ NT_elseopt, T_lt, 134,
  /* 1699 */ NT_elseopt, T_lteq, 134,
  /* 1700 */ NT_elseopt, T_gt, 134,
  /* 1701 */ NT_elseopt, T_gteq, 134,
  /* 1702 */ NT_elseopt, T_noteq, 134,
  /* 1703 */ NT_elseopt, T_star, 134,
  /* 1704 */ NT_elseopt, T_plus, 134,
  /* 1705 */ NT_elseopt, T_minus, 134,
  /* 1706 */ NT_elseopt, T_slash, 134,
  /* 1707 */ NT_elseopt, T_pct, 134,
  /* 1708 */ NT_elseopt, T_starstar, 134,
  /* 1709 */ NT_elseopt, T_plusplus, 134,
  /* 1710 */ NT_elseopt, T_minusminus, 134,
  /* 1711 */ NT_elseopt, T_assign, 134,
  /* 1712 */ NT_elseopt, T_star_assign, 134,
  /* 1713 */ NT_elseopt, T_slash_assign, 134,
  /* 1714 */ NT_elseopt, T_pct_assign, 134,
  /* 1715 */ NT_elseopt, T_starstar_assign, 134,
  /* 1716 */ NT_elseopt, T_plus_assign, 134,
  /* 1717 */ NT_elseopt, T_minus_assign, 134,
  /* 1718 */ NT_elseopt, T_plusplus_assign, 134,
  /* 1719 */ NT_elseopt, T_minusminus_assign, 134,
  /* 1720 */ NT_caselist, T_id, 135,
  /* 1721 */ NT_caselist, T_lbrace, 135,
  /* 1722 */ NT_caselist, T_rbrace, 135,
  /* 1723 */ NT_caselist, T_lbrack, 135,
  /* 1724 */ NT_caselist, T_lparen, 135,
  /* 1725 */ NT_caselist, T_equal, 135,
  /* 1726 */ NT_caselist, T_semico, 135,
  /* 1727 */ NT_caselist, T_eol, 135,
  /* 1728 */ NT_caselist, T_conjop, 135,
  /* 1729 */ NT_caselist, T_scanop, 135,
  /* 1730 */ NT_caselist, T_altop, 135,
  /* 1731 */ NT_caselist, T_carat, 135,
  /* 1732 */ NT_caselist, T_bslash, 135,
  /* 1733 */ NT_caselist, T_coop, 135,
  /* 1734 */ NT_caselist, T_dot, 135,
  /* 1735 */ NT_caselist, T_repeat, 135,
  /* 1736 */ NT_caselist, T_while, 135,
  /* 1737 */ NT_caselist, T_until, 135,
  /* 1738 */ NT_caselist, T_every, 135,
  /* 1739 */ NT_caselist, T_if, 135,
  /* 1740 */ NT_caselist, T_case, 135,
  /* 1741 */ NT_caselist, T_next, 135,
  /* 1742 */ NT_caselist, T_break, 135,
  /* 1743 */ NT_caselist, T_return, 135,
  /* 1744 */ NT_caselist, T_suspend, 135,
  /* 1745 */ NT_caselist, T_fail, 135,
  /* 1746 */ NT_caselist, T_create, 135,
  /* 1747 */ NT_caselist, T_default, 135,
  /* 1748 */ NT_caselist, T_not, 135,
  /* 1749 */ NT_caselist, T_bang, 135,
  /* 1750 */ NT_caselist, T_star, 135,
  /* 1751 */ NT_caselist, T_plus, 135,
  /* 1752 */ NT_caselist, T_minus, 135,
  /* 1753 */ NT_caselist, T_slash, 135,
  /* 1754 */ NT_caselist, T_tilde, 135,
  /* 1755 */ NT_caselist, T_intcon, 135,
  /* 1756 */ NT_caselist, T_radintcon, 135,
  /* 1757 */ NT_caselist, T_realcon, 135,
  /* 1758 */ NT_caselist, T_csetcon, 135,
  /* 1759 */ NT_caselist, T_stringcon, 135,
  /* 1760 */ NT_caselist, T_hexcon, 135,
  /* 1761 */ NT_caselist, T_octcon, 135,
  /* 1762 */ NT_caseclause, T_id, 140,
  /* 1763 */ NT_caseclause, T_lbrace, 140,
  /* 1764 */ NT_caseclause, T_rbrace, 142,
  /* 1765 */ NT_caseclause, T_lbrack, 140,
  /* 1766 */ NT_caseclause, T_lparen, 140,
  /* 1767 */ NT_caseclause, T_equal, 140,
  /* 1768 */ NT_caseclause, T_semico, 142,
  /* 1769 */ NT_caseclause, T_eol, 142,
  /* 1770 */ NT_caseclause, T_conjop, 140,
  /* 1771 */ NT_caseclause, T_scanop, 140,
  /* 1772 */ NT_caseclause, T_altop, 140,
  /* 1773 */ NT_caseclause, T_carat, 140,
  /* 1774 */ NT_caseclause, T_bslash, 140,
  /* 1775 */ NT_caseclause, T_coop, 140,
  /* 1776 */ NT_caseclause, T_dot, 140,
  /* 1777 */ NT_caseclause, T_repeat, 140,
  /* 1778 */ NT_caseclause, T_while, 140,
  /* 1779 */ NT_caseclause, T_until, 140,
  /* 1780 */ NT_caseclause, T_every, 140,
  /* 1781 */ NT_caseclause, T_if, 140,
  /* 1782 */ NT_caseclause, T_case, 140,
  /* 1783 */ NT_caseclause, T_next, 140,
  /* 1784 */ NT_caseclause, T_break, 140,
  /* 1785 */ NT_caseclause, T_return, 140,
  /* 1786 */ NT_caseclause, T_suspend, 140,
  /* 1787 */ NT_caseclause, T_fail, 140,
  /* 1788 */ NT_caseclause, T_create, 140,
  /* 1789 */ NT_caseclause, T_default, 141,
  /* 1790 */ NT_caseclause, T_not, 140,
  /* 1791 */ NT_caseclause, T_bang, 140,
  /* 1792 */ NT_caseclause, T_star, 140,
  /* 1793 */ NT_caseclause, T_plus, 140,
  /* 1794 */ NT_caseclause, T_minus, 140,
  /* 1795 */ NT_caseclause, T_slash, 140,
  /* 1796 */ NT_caseclause, T_tilde, 140,
  /* 1797 */ NT_caseclause, T_intcon, 140,
  /* 1798 */ NT_caseclause, T_radintcon, 140,
  /* 1799 */ NT_caseclause, T_realcon, 140,
  /* 1800 */ NT_caseclause, T_csetcon, 140,
  /* 1801 */ NT_caseclause, T_stringcon, 140,
  /* 1802 */ NT_caseclause, T_hexcon, 140,
  /* 1803 */ NT_caseclause, T_octcon, 140,
  /* 1804 */ NT_caselisttl, T_rbrace, 137,
  /* 1805 */ NT_caselisttl, T_semico, 138,
  /* 1806 */ NT_caselisttl, T_eol, 138,
  /* 1807 */ NT_kwdtl, T_id, 149,
  /* 1808 */ NT_kwdtl, T_fail, 150,
  /* 1809 */ NT_lit, T_intcon, 187,
  /* 1810 */ NT_lit, T_radintcon, 188,
  /* 1811 */ NT_lit, T_realcon, 189,
  /* 1812 */ NT_lit, T_csetcon, 190,
  /* 1813 */ NT_lit, T_stringcon, 191,
  /* 1814 */ NT_lit, T_hexcon, 192,
  /* 1815 */ NT_lit, T_octcon, 193,
  0
};

short PredictIndexTable[] = {
  0,
  20,
  40,
  43,
  63,
  65,
  79,
  81,
  96,
  99,
  101,
  102,
  116,
  117,
  119,
  121,
  122,
  123,
  125,
  126,
  171,
  213,
  255,
  269,
  271,
  273,
  276,
  321,
  324,
  362,
  435,
  439,
  477,
  515,
  561,
  599,
  645,
  683,
  729,
  738,
  776,
  822,
  868,
  906,
  952,
  990,
  1036,
  1041,
  1079,
  1125,
  1163,
  1209,
  1213,
  1251,
  1297,
  1301,
  1339,
  1385,
  1423,
  1469,
  1483,
  1507,
  1519,
  1531,
  1581,
  1621,
  1625,
  1628,
  1674,
  1720,
  1762,
  1804,
  1807,
  1809,
  1816
};

char *SemanticStackTypeTable[] = {
  "Queue",
  "Type",
  "Misc",
  "Expression",
  "CaseClause",
  "Token",
  "Void"
};

void _Prologue_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doDeclPrologue();
  AStackSpill(SemanticStack,0,NULL);
}

void _Epilogue_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doDeclEpilogue();
  AStackSpill(SemanticStack,0,NULL);
}

void _DeclList_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _SimpleType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_SimpleType_Declaration",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = doSimpleType(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _UserType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_UserType_Declaration",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeIdNew(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _RecordType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RecordType_Declaration",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeRecordNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _UnionType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_UnionType_Declaration",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeUnionNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _SetType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_SetType_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeSetNew(SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ListType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ListType_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeListNew(SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _TableType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_TableType_Declaration",SemanticStack,3,SST_Type);
  CheckStackAt("_TableType_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeTableNew(SSEGet(SemanticStack,3)->u.U_Type,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ProcType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcType_Declaration",SemanticStack,3,SST_Queue);
  CheckStackAt("_ProcType_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeProcedureNew(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _RefType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RefType_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeRefNew(SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NestedType_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_NestedType_Declaration",SemanticStack,2,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = doNestedType(SSEGet(SemanticStack,2)->u.U_Type);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _TypeDef_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_TypeDef_Declaration",SemanticStack,3,SST_Token);
  CheckStackAt("_TypeDef_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = doTypeDef(SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _GlobDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_GlobDecl_Declaration",SemanticStack,4,SST_Token);
  CheckStackAt("_GlobDecl_Declaration",SemanticStack,3,SST_Queue);
  CheckStackAt("_GlobDecl_Declaration",SemanticStack,1,SST_Type);
#endif

  doGlobDecl(SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
}

void _EnqueueFirstIdDecl_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueFirstIdDecl_Declaration",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doEnqueueFirstId(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EnqueueNextIdDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueNextIdDecl_Declaration",SemanticStack,3,SST_Queue);
  CheckStackAt("_EnqueueNextIdDecl_Declaration",SemanticStack,1,SST_Token);
#endif

  doEnqueueNextId(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,2,NULL);
}

void _EnqueueFirstIdProc_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _EnqueueNextIdProc_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _NoFields_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _FirstField_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_FirstField_Declaration",SemanticStack,3,SST_Queue);
  CheckStackAt("_FirstField_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doFirstField(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NextField_Declaration()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NextField_Declaration",SemanticStack,5,SST_Queue);
  CheckStackAt("_NextField_Declaration",SemanticStack,3,SST_Queue);
  CheckStackAt("_NextField_Declaration",SemanticStack,1,SST_Type);
#endif

  doNextField(SSEGet(SemanticStack,5)->u.U_Queue,
      SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
}

void _EndFields_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ProcDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcDecl_Declaration",SemanticStack,2,SST_Misc);
#endif

  PutProcedureDecl(SSEGet(SemanticStack,2)->u.U_Misc);
  AStackSpill(SemanticStack,2,NULL);
}

void _LocalTable_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ProcHead_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcHead_Declaration",SemanticStack,6,SST_Token);
  CheckStackAt("_ProcHead_Declaration",SemanticStack,4,SST_Queue);
  CheckStackAt("_ProcHead_Declaration",SemanticStack,2,SST_Token);
  CheckStackAt("_ProcHead_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Misc;
  AttIn->u.U_Misc = doProcHead(SSEGet(SemanticStack,6)->u.U_Token,
      SSEGet(SemanticStack,4)->u.U_Queue,
      SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,7,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EnqueueFirstParameter_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueFirstParameter_Declaration",SemanticStack,4,SST_Token);
  CheckStackAt("_EnqueueFirstParameter_Declaration",SemanticStack,3,SST_Token);
  CheckStackAt("_EnqueueFirstParameter_Declaration",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doEnqueueFirstParam(SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _MakeQueueD_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EnqueueNextParameter_Declaration()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueNextParameter_Declaration",SemanticStack,6,SST_Queue);
  CheckStackAt("_EnqueueNextParameter_Declaration",SemanticStack,4,SST_Token);
  CheckStackAt("_EnqueueNextParameter_Declaration",SemanticStack,3,SST_Token);
  CheckStackAt("_EnqueueNextParameter_Declaration",SemanticStack,1,SST_Type);
#endif

  doEnqueueNextParam(SSEGet(SemanticStack,6)->u.U_Queue,
      SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,5,NULL);
}

void _ScrubParameter_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _Ref_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoRef_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = doPushNullToken();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Discard_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _LocalDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,3,NULL);
}

void _Initializer_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _NoInitializer_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ExpSeqHead_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ExpSeqNext_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoExp_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _BinOp_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _TerOp_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _RelOp_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _UnaryOp_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _ProcCall_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _Subscript_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _Cast_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _FieldRef_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Range_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _NoRange_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoExpSeq_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ExpSeqNext2_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Repeat_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _While_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Until_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Every_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Case_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,4,NULL);
}

void _Next_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _Break_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Return_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Suspend_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Fail_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Create_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Do_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _NoDo_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _IfThenElse_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,3,NULL);
}

void _IfThen_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _CaseListHead_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _CaseListNext_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _CaseClause_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _DefaultClause_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _NoCaseClause_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _Parens_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _ListCons_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _Block_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _Var_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Keyword_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _ConstInt_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _ConstRadix_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _ConstReal_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _ConstCset_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _ConstString_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _MakeQueue_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _MoreLocalDecl_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _NoIdList1_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoIdList2_Declaration()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoInitList_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoParameters_Declaration()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

_ActionTableType Declaration_ActionTable = {
  _Prologue_Declaration,
  _Epilogue_Declaration,
  _DeclList_Declaration,
  _SimpleType_Declaration,
  _UserType_Declaration,
  _RecordType_Declaration,
  _UnionType_Declaration,
  _SetType_Declaration,
  _ListType_Declaration,
  _TableType_Declaration,
  _ProcType_Declaration,
  _RefType_Declaration,
  _NestedType_Declaration,
  _NoDecl_Declaration,
  _TypeDef_Declaration,
  _GlobDecl_Declaration,
  _EnqueueFirstIdDecl_Declaration,
  _EnqueueNextIdDecl_Declaration,
  _EnqueueFirstIdProc_Declaration,
  _EnqueueNextIdProc_Declaration,
  _NoFields_Declaration,
  _FirstField_Declaration,
  _NextField_Declaration,
  _EndFields_Declaration,
  _ProcDecl_Declaration,
  _LocalTable_Declaration,
  _ProcHead_Declaration,
  _EnqueueFirstParameter_Declaration,
  _MakeQueueD_Declaration,
  _EnqueueNextParameter_Declaration,
  _ScrubParameter_Declaration,
  _Ref_Declaration,
  _NoRef_Declaration,
  _Discard_Declaration,
  _LocalDecl_Declaration,
  _Initializer_Declaration,
  _NoInitializer_Declaration,
  _ExpSeqHead_Declaration,
  _ExpSeqNext_Declaration,
  _NoExp_Declaration,
  _BinOp_Declaration,
  _TerOp_Declaration,
  _RelOp_Declaration,
  _UnaryOp_Declaration,
  _ProcCall_Declaration,
  _Subscript_Declaration,
  _Cast_Declaration,
  _FieldRef_Declaration,
  _Range_Declaration,
  _NoRange_Declaration,
  _NoExpSeq_Declaration,
  _ExpSeqNext2_Declaration,
  _Repeat_Declaration,
  _While_Declaration,
  _Until_Declaration,
  _Every_Declaration,
  _Case_Declaration,
  _Next_Declaration,
  _Break_Declaration,
  _Return_Declaration,
  _Suspend_Declaration,
  _Fail_Declaration,
  _Create_Declaration,
  _Do_Declaration,
  _NoDo_Declaration,
  _IfThenElse_Declaration,
  _IfThen_Declaration,
  _CaseListHead_Declaration,
  _CaseListNext_Declaration,
  _CaseClause_Declaration,
  _DefaultClause_Declaration,
  _NoCaseClause_Declaration,
  _Parens_Declaration,
  _ListCons_Declaration,
  _Block_Declaration,
  _Var_Declaration,
  _Keyword_Declaration,
  _ConstInt_Declaration,
  _ConstRadix_Declaration,
  _ConstReal_Declaration,
  _ConstCset_Declaration,
  _ConstString_Declaration,
  _MakeQueue_Declaration,
  _MoreLocalDecl_Declaration,
  _NoIdList1_Declaration,
  _NoIdList2_Declaration,
  _NoInitList_Declaration,
  _NoParameters_Declaration,
  NULL
};

_ActionTablePtrType ActionTable = Declaration_ActionTable;

void _Prologue_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doProcPrologue();
  AStackSpill(SemanticStack,0,NULL);
}

void _Epilogue_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doProcEpilogue();
  AStackSpill(SemanticStack,0,NULL);
}

void _DeclList_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _SimpleType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_SimpleType_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = doSimpleType(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _UserType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_UserType_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeIdNew(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _RecordType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RecordType_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeRecordNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _UnionType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_UnionType_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeUnionNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _SetType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_SetType_Translation",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeSetNew(SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ListType_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _TableType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_TableType_Translation",SemanticStack,3,SST_Type);
  CheckStackAt("_TableType_Translation",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeTableNew(SSEGet(SemanticStack,3)->u.U_Type,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ProcType_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _RefType_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RefType_Translation",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = TypeRefNew(SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NestedType_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _NoDecl_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _TypeDef_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_TypeDef_Translation",SemanticStack,3,SST_Token);
  CheckStackAt("_TypeDef_Translation",SemanticStack,1,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Type;
  AttIn->u.U_Type = doTypeDef(SSEGet(SemanticStack,3)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _GlobDecl_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _EnqueueFirstIdDecl_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _EnqueueNextIdDecl_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _EnqueueFirstIdProc_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueFirstIdProc_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doEnqueueFirstId(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _EnqueueNextIdProc_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_EnqueueNextIdProc_Translation",SemanticStack,3,SST_Queue);
  CheckStackAt("_EnqueueNextIdProc_Translation",SemanticStack,1,SST_Token);
#endif

  doEnqueueNextId(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,2,NULL);
}

void _NoFields_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _FirstField_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _NextField_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,2,NULL);
}

void _EndFields_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ProcDecl_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcDecl_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_ProcDecl_Translation",SemanticStack,2,SST_Queue);
#endif

  doProcDeclP(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
}

void _LocalTable_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doLocalTable();
  AStackSpill(SemanticStack,0,NULL);
}

void _ProcHead_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcHead_Translation",SemanticStack,5,SST_Token);
#endif

  doProcHead2(SSEGet(SemanticStack,5)->u.U_Token);
  AStackSpill(SemanticStack,6,NULL);
}

void _EnqueueFirstParameter_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _MakeQueueD_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _EnqueueNextParameter_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _ScrubParameter_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,3,NULL);
}

void _Ref_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoRef_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = doPushNullToken();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Discard_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _LocalDecl_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_LocalDecl_Translation",SemanticStack,4,SST_Token);
  CheckStackAt("_LocalDecl_Translation",SemanticStack,3,SST_Queue);
  CheckStackAt("_LocalDecl_Translation",SemanticStack,1,SST_Type);
#endif

  doLocalDecl(SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
}

void _Initializer_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Initializer_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doInitializer(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoInitializer_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doPushNullExpression();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ExpSeqHead_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ExpSeqHead_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doExpSeqHead(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ExpSeqNext_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_ExpSeqNext_Translation",SemanticStack,2,SST_Queue);
  CheckStackAt("_ExpSeqNext_Translation",SemanticStack,1,SST_Expression);
#endif

  doExpSeqNext(SSEGet(SemanticStack,2)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,1,NULL);
}

void _NoExp_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doPushNullExpression();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _BinOp_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_BinOp_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_BinOp_Translation",SemanticStack,2,SST_Token);
  CheckStackAt("_BinOp_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doBinOp(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _TerOp_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_TerOp_Translation",SemanticStack,5,SST_Expression);
  CheckStackAt("_TerOp_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_TerOp_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doTerOp(SSEGet(SemanticStack,5)->u.U_Expression,
      SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,5,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _RelOp_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_RelOp_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_RelOp_Translation",SemanticStack,2,SST_Token);
  CheckStackAt("_RelOp_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doRelOp(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _UnaryOp_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_UnaryOp_Translation",SemanticStack,2,SST_Token);
  CheckStackAt("_UnaryOp_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doUnaryOp(SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ProcCall_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ProcCall_Translation",SemanticStack,4,SST_Expression);
  CheckStackAt("_ProcCall_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionProcCallNew(SSEGet(SemanticStack,4)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Subscript_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Subscript_Translation",SemanticStack,4,SST_Expression);
  CheckStackAt("_Subscript_Translation",SemanticStack,2,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionSubscriptNew(SSEGet(SemanticStack,4)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Expression);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Cast_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Cast_Translation",SemanticStack,4,SST_Expression);
  CheckStackAt("_Cast_Translation",SemanticStack,2,SST_Type);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionCastNew(SSEGet(SemanticStack,4)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Type);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _FieldRef_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_FieldRef_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_FieldRef_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionFieldRefNew(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Range_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Range_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_Range_Translation",SemanticStack,2,SST_Token);
  CheckStackAt("_Range_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doRange(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoRange_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoExpSeq_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ExpSeqNext2_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_ExpSeqNext2_Translation",SemanticStack,3,SST_Queue);
  CheckStackAt("_ExpSeqNext2_Translation",SemanticStack,1,SST_Expression);
#endif

  doExpSeqNext(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
}

void _Repeat_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Repeat_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionRepeatNew(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _While_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_While_Translation",SemanticStack,2,SST_Expression);
  CheckStackAt("_While_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionWhileNew(SSEGet(SemanticStack,2)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Until_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Until_Translation",SemanticStack,2,SST_Expression);
  CheckStackAt("_Until_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionUntilNew(SSEGet(SemanticStack,2)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Every_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Every_Translation",SemanticStack,2,SST_Expression);
  CheckStackAt("_Every_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionEveryNew(SSEGet(SemanticStack,2)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Case_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Case_Translation",SemanticStack,5,SST_Expression);
  CheckStackAt("_Case_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionCaseNew(SSEGet(SemanticStack,5)->u.U_Expression,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,6,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Next_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionNextNew();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Break_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Break_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionBreakNew(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Return_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Return_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionReturnNew(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Suspend_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Suspend_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionSuspendNew(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Fail_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionFailNew();
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Create_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Create_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionCreateNew(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Do_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Do_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doDo(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoDo_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doPushNullExpression();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _IfThenElse_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_IfThenElse_Translation",SemanticStack,5,SST_Expression);
  CheckStackAt("_IfThenElse_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_IfThenElse_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionIfNew(SSEGet(SemanticStack,5)->u.U_Expression,
      SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,6,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _IfThen_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_IfThen_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_IfThen_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doIfThen(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,4,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _CaseListHead_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_CaseListHead_Translation",SemanticStack,1,SST_CaseClause);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doCaseListHead(SSEGet(SemanticStack,1)->u.U_CaseClause);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _CaseListNext_Translation()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_CaseListNext_Translation",SemanticStack,2,SST_Queue);
  CheckStackAt("_CaseListNext_Translation",SemanticStack,1,SST_CaseClause);
#endif

  doCaseListNext(SSEGet(SemanticStack,2)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_CaseClause);
  AStackSpill(SemanticStack,1,NULL);
}

void _CaseClause_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_CaseClause_Translation",SemanticStack,3,SST_Expression);
  CheckStackAt("_CaseClause_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_CaseClause;
  AttIn->u.U_CaseClause = CaseClauseNew(SSEGet(SemanticStack,3)->u.U_Expression,
      SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _DefaultClause_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_DefaultClause_Translation",SemanticStack,1,SST_Expression);
#endif

  AttIn = SSENew();
  AttIn->type = SST_CaseClause;
  AttIn->u.U_CaseClause = doDefaultClause(SSEGet(SemanticStack,1)->u.U_Expression);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoCaseClause_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_CaseClause;
  AttIn->u.U_CaseClause = doPushNullCaseClause();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Parens_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Parens_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doParens(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ListCons_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ListCons_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionListConsNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Block_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Block_Translation",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = ExpressionSequenceNew(SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Var_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Var_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doVar(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Keyword_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Keyword_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doKeyword(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,2,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ConstInt_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ConstInt_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doConstInt(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ConstRadix_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ConstRadix_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doConstRadix(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ConstReal_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ConstReal_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doConstReal(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ConstCset_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ConstCset_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doConstCset(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _ConstString_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_ConstString_Translation",SemanticStack,1,SST_Token);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Expression;
  AttIn->u.U_Expression = doConstString(SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _MakeQueue_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _MoreLocalDecl_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoIdList1_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoIdList2_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

void _NoInitList_Translation()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = QueueNew();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NoParameters_Translation()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,0,NULL);
}

_ActionTableType Translation_ActionTable = {
  _Prologue_Translation,
  _Epilogue_Translation,
  _DeclList_Translation,
  _SimpleType_Translation,
  _UserType_Translation,
  _RecordType_Translation,
  _UnionType_Translation,
  _SetType_Translation,
  _ListType_Translation,
  _TableType_Translation,
  _ProcType_Translation,
  _RefType_Translation,
  _NestedType_Translation,
  _NoDecl_Translation,
  _TypeDef_Translation,
  _GlobDecl_Translation,
  _EnqueueFirstIdDecl_Translation,
  _EnqueueNextIdDecl_Translation,
  _EnqueueFirstIdProc_Translation,
  _EnqueueNextIdProc_Translation,
  _NoFields_Translation,
  _FirstField_Translation,
  _NextField_Translation,
  _EndFields_Translation,
  _ProcDecl_Translation,
  _LocalTable_Translation,
  _ProcHead_Translation,
  _EnqueueFirstParameter_Translation,
  _MakeQueueD_Translation,
  _EnqueueNextParameter_Translation,
  _ScrubParameter_Translation,
  _Ref_Translation,
  _NoRef_Translation,
  _Discard_Translation,
  _LocalDecl_Translation,
  _Initializer_Translation,
  _NoInitializer_Translation,
  _ExpSeqHead_Translation,
  _ExpSeqNext_Translation,
  _NoExp_Translation,
  _BinOp_Translation,
  _TerOp_Translation,
  _RelOp_Translation,
  _UnaryOp_Translation,
  _ProcCall_Translation,
  _Subscript_Translation,
  _Cast_Translation,
  _FieldRef_Translation,
  _Range_Translation,
  _NoRange_Translation,
  _NoExpSeq_Translation,
  _ExpSeqNext2_Translation,
  _Repeat_Translation,
  _While_Translation,
  _Until_Translation,
  _Every_Translation,
  _Case_Translation,
  _Next_Translation,
  _Break_Translation,
  _Return_Translation,
  _Suspend_Translation,
  _Fail_Translation,
  _Create_Translation,
  _Do_Translation,
  _NoDo_Translation,
  _IfThenElse_Translation,
  _IfThen_Translation,
  _CaseListHead_Translation,
  _CaseListNext_Translation,
  _CaseClause_Translation,
  _DefaultClause_Translation,
  _NoCaseClause_Translation,
  _Parens_Translation,
  _ListCons_Translation,
  _Block_Translation,
  _Var_Translation,
  _Keyword_Translation,
  _ConstInt_Translation,
  _ConstRadix_Translation,
  _ConstReal_Translation,
  _ConstCset_Translation,
  _ConstString_Translation,
  _MakeQueue_Translation,
  _MoreLocalDecl_Translation,
  _NoIdList1_Translation,
  _NoIdList2_Translation,
  _NoInitList_Translation,
  _NoParameters_Translation,
  NULL
};

_PhaseTableType PhaseTable = {
  Declaration_ActionTable,
  Translation_ActionTable,
  NULL
};

char *PhaseName[] = {
  "Declaration",
  "Translation",
  NULL
};

#endif /* icnparse_c */
