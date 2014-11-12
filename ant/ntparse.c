#ifndef ntparse_c
#define ntparse_c

#include "apt.h"
#include "aptlib.h"
#include "astlib.h"
#include "ntparse.td"
#include "ntparse.h"
#include "ntparse.pt"
#include "apttext.h"

_SymbolTableElement SymbolTable[] = {
  "Goal", NonTerminal,
  "Items", NonTerminal,
  "File", NonTerminal,
  "ItemList", NonTerminal,
  "Item", NonTerminal,
  "Enum", NonTerminal,
  "Include", NonTerminal,
  "Node", NonTerminal,
  "Tags", NonTerminal,
  "SemiOpt", NonTerminal,
  "Elements", NonTerminal,
  "TagList", NonTerminal,
  "Tag", NonTerminal,
  "TagListTail", NonTerminal,
  "ElementList", NonTerminal,
  "Element", NonTerminal,
  "Slot", NonTerminal,
  "Decl", NonTerminal,
  "Decls", NonTerminal,
  "DeclList", NonTerminal,
  "NullOp", NonTerminal,
  "Specs", NonTerminal,
  "Vars", NonTerminal,
  "Semi", NonTerminal,
  "SpecList", NonTerminal,
  "ClassSpec", NonTerminal,
  "Spec", NonTerminal,
  "SpecListTail", NonTerminal,
  "TypeSpec", NonTerminal,
  "StClSpec", NonTerminal,
  "TypeQual", NonTerminal,
  "VarList", NonTerminal,
  "Var", NonTerminal,
  "VarListTail", NonTerminal,
  "Ptrs", NonTerminal,
  "Arrays", NonTerminal,
  "PtrList", NonTerminal,
  "ArrayList", NonTerminal,
  "Array", NonTerminal,
  "ArrayTail", NonTerminal,
  "EoF", Terminal,
  "enum", Terminal,
  "ident", Terminal,
  "{", Terminal,
  "}", Terminal,
  "include", Terminal,
  "fileIdent", Terminal,
  "node", Terminal,
  ",", Terminal,
  "slot", Terminal,
  "null", Terminal,
  "struct", Terminal,
  "union", Terminal,
  "void", Terminal,
  "char", Terminal,
  "int", Terminal,
  "float", Terminal,
  "double", Terminal,
  "short", Terminal,
  "long", Terminal,
  "signed", Terminal,
  "unsigned", Terminal,
  "typedef", Terminal,
  "auto", Terminal,
  "static", Terminal,
  "extern", Terminal,
  "const", Terminal,
  "volatile", Terminal,
  "*", Terminal,
  "[", Terminal,
  "integer", Terminal,
  "]", Terminal,
  ";", Terminal,
  "_Encode", Action,
  "_Q", Action,
  "_NQEnum", Action,
  "_NQInclude", Action,
  "_NQNode", Action,
  "_Enum", Action,
  "_Zap", Action,
  "_Node", Action,
  "_NQToken", Action,
  "_NQSlot", Action,
  "_Slot", Action,
  "_FakeToken", Action,
  "_NQVar", Action,
  NULL
};

short _RHS[] = {
  NT_File, T_EoF, 
  NT_Items, A__Encode, 
  A__Q, A__Q, A__Q, NT_ItemList, 
  NT_Item, NT_ItemList, 
  NT_Enum, A__NQEnum, 
  NT_Include, A__NQInclude, 
  NT_Node, A__NQNode, 
  T_enum, T_ident, T_lbrace, NT_Tags, T_rbrace, A__Enum, NT_SemiOpt, 
  T_include, A__Zap, T_fileIdent, NT_SemiOpt, 
  T_node, T_ident, T_lbrace, NT_Elements, T_rbrace, A__Node, NT_SemiOpt, 
  A__Q, NT_TagList, 
  NT_Tag, NT_TagListTail, 
  T_comma, A__Zap, NT_Tag, NT_TagListTail, 
  T_ident, A__NQToken, 
  A__Q, A__Q, NT_ElementList, 
  NT_Element, NT_ElementList, 
  NT_Slot, A__NQSlot, 
  NT_Decl, 
  T_slot, T_ident, T_lbrace, NT_Decls, T_rbrace, A__Slot, NT_SemiOpt, 
  A__Q, NT_DeclList, 
  NT_Decl, NT_DeclList, 
  NT_NullOp, NT_Specs, NT_Vars, A__Zap, A__Zap, NT_Semi, 
  T_null, 
  A__FakeToken, 
  A__Q, NT_SpecList, 
  NT_ClassSpec, 
  NT_Spec, NT_SpecListTail, 
  NT_Spec, NT_SpecListTail, 
  T_enum, A__NQToken, T_ident, A__NQToken, 
  T_ident, A__NQToken, 
  T_struct, A__NQToken, T_ident, A__NQToken, 
  T_union, A__NQToken, T_ident, A__NQToken, 
  NT_TypeSpec, A__NQToken, 
  NT_StClSpec, A__NQToken, 
  NT_TypeQual, A__NQToken, 
  T_void, 
  T_char, 
  T_int, 
  T_float, 
  T_double, 
  T_short, 
  T_long, 
  T_signed, 
  T_unsigned, 
  T_typedef, 
  T_auto, 
  T_static, 
  T_extern, 
  T_const, 
  T_volatile, 
  NT_VarList, 
  NT_Var, NT_VarListTail, 
  T_comma, A__Zap, NT_Var, NT_VarListTail, 
  NT_Ptrs, T_ident, NT_Arrays, A__NQVar, 
  A__Q, NT_PtrList, 
  T_deref, A__NQToken, NT_PtrList, 
  A__Q, NT_ArrayList, 
  NT_Array, NT_ArrayList, 
  T_lbrack, A__NQToken, NT_ArrayTail, 
  T_integer, A__NQToken, T_rbrack, A__NQToken, 
  T_rbrack, A__NQToken, 
  T_semico, A__Zap, 
  NT_Semi, 
  0
};

_ProductionTableElement ProductionTable[] = {
  NT_Goal, 2, _RHS + 0,
  NT_File, 2, _RHS + 2,
  NT_Items, 4, _RHS + 4,
  NT_ItemList, 2, _RHS + 8,
  NT_ItemList, 0, _RHS + 10,
  NT_Item, 2, _RHS + 10,
  NT_Item, 2, _RHS + 12,
  NT_Item, 2, _RHS + 14,
  NT_Enum, 7, _RHS + 16,
  NT_Include, 4, _RHS + 23,
  NT_Node, 7, _RHS + 27,
  NT_Tags, 2, _RHS + 34,
  NT_TagList, 2, _RHS + 36,
  NT_TagList, 0, _RHS + 38,
  NT_TagListTail, 4, _RHS + 38,
  NT_TagListTail, 0, _RHS + 42,
  NT_Tag, 2, _RHS + 42,
  NT_Elements, 3, _RHS + 44,
  NT_ElementList, 2, _RHS + 47,
  NT_ElementList, 0, _RHS + 49,
  NT_Element, 2, _RHS + 49,
  NT_Element, 1, _RHS + 51,
  NT_Slot, 7, _RHS + 52,
  NT_Decls, 2, _RHS + 59,
  NT_DeclList, 2, _RHS + 61,
  NT_DeclList, 0, _RHS + 63,
  NT_Decl, 6, _RHS + 63,
  NT_NullOp, 1, _RHS + 69,
  NT_NullOp, 1, _RHS + 70,
  NT_Specs, 2, _RHS + 71,
  NT_SpecList, 1, _RHS + 73,
  NT_SpecList, 2, _RHS + 74,
  NT_SpecListTail, 2, _RHS + 76,
  NT_SpecListTail, 0, _RHS + 78,
  NT_ClassSpec, 4, _RHS + 78,
  NT_ClassSpec, 2, _RHS + 82,
  NT_ClassSpec, 4, _RHS + 84,
  NT_ClassSpec, 4, _RHS + 88,
  NT_Spec, 2, _RHS + 92,
  NT_Spec, 2, _RHS + 94,
  NT_Spec, 2, _RHS + 96,
  NT_TypeSpec, 1, _RHS + 98,
  NT_TypeSpec, 1, _RHS + 99,
  NT_TypeSpec, 1, _RHS + 100,
  NT_TypeSpec, 1, _RHS + 101,
  NT_TypeSpec, 1, _RHS + 102,
  NT_TypeSpec, 1, _RHS + 103,
  NT_TypeSpec, 1, _RHS + 104,
  NT_TypeSpec, 1, _RHS + 105,
  NT_TypeSpec, 1, _RHS + 106,
  NT_StClSpec, 1, _RHS + 107,
  NT_StClSpec, 1, _RHS + 108,
  NT_StClSpec, 1, _RHS + 109,
  NT_StClSpec, 1, _RHS + 110,
  NT_TypeQual, 1, _RHS + 111,
  NT_TypeQual, 1, _RHS + 112,
  NT_Vars, 1, _RHS + 113,
  NT_VarList, 2, _RHS + 114,
  NT_VarListTail, 4, _RHS + 116,
  NT_VarListTail, 0, _RHS + 120,
  NT_Var, 4, _RHS + 120,
  NT_Ptrs, 2, _RHS + 124,
  NT_PtrList, 3, _RHS + 126,
  NT_PtrList, 0, _RHS + 129,
  NT_Arrays, 2, _RHS + 129,
  NT_ArrayList, 2, _RHS + 131,
  NT_ArrayList, 0, _RHS + 133,
  NT_Array, 3, _RHS + 133,
  NT_ArrayTail, 4, _RHS + 136,
  NT_ArrayTail, 2, _RHS + 140,
  NT_Semi, 2, _RHS + 142,
  NT_SemiOpt, 1, _RHS + 144,
  NT_SemiOpt, 0, _RHS + 145,
  0
};

_PredictionTripleElement PredictionTriple[] = {
  /* 0 */ NT_Goal, T_EoF, 0,
  /* 1 */ NT_Goal, T_enum, 0,
  /* 2 */ NT_Goal, T_include, 0,
  /* 3 */ NT_Goal, T_node, 0,
  /* 4 */ NT_Items, T_EoF, 2,
  /* 5 */ NT_Items, T_enum, 2,
  /* 6 */ NT_Items, T_include, 2,
  /* 7 */ NT_Items, T_node, 2,
  /* 8 */ NT_File, T_EoF, 1,
  /* 9 */ NT_File, T_enum, 1,
  /* 10 */ NT_File, T_include, 1,
  /* 11 */ NT_File, T_node, 1,
  /* 12 */ NT_ItemList, T_EoF, 4,
  /* 13 */ NT_ItemList, T_enum, 3,
  /* 14 */ NT_ItemList, T_include, 3,
  /* 15 */ NT_ItemList, T_node, 3,
  /* 16 */ NT_Item, T_enum, 5,
  /* 17 */ NT_Item, T_include, 6,
  /* 18 */ NT_Item, T_node, 7,
  /* 19 */ NT_Enum, T_enum, 8,
  /* 20 */ NT_Include, T_include, 9,
  /* 21 */ NT_Node, T_node, 10,
  /* 22 */ NT_Tags, T_ident, 11,
  /* 23 */ NT_Tags, T_rbrace, 11,
  /* 24 */ NT_SemiOpt, T_EoF, 72,
  /* 25 */ NT_SemiOpt, T_enum, 72,
  /* 26 */ NT_SemiOpt, T_ident, 72,
  /* 27 */ NT_SemiOpt, T_rbrace, 72,
  /* 28 */ NT_SemiOpt, T_include, 72,
  /* 29 */ NT_SemiOpt, T_node, 72,
  /* 30 */ NT_SemiOpt, T_slot, 72,
  /* 31 */ NT_SemiOpt, T_null, 72,
  /* 32 */ NT_SemiOpt, T_struct, 72,
  /* 33 */ NT_SemiOpt, T_union, 72,
  /* 34 */ NT_SemiOpt, T_void, 72,
  /* 35 */ NT_SemiOpt, T_char, 72,
  /* 36 */ NT_SemiOpt, T_int, 72,
  /* 37 */ NT_SemiOpt, T_float, 72,
  /* 38 */ NT_SemiOpt, T_double, 72,
  /* 39 */ NT_SemiOpt, T_short, 72,
  /* 40 */ NT_SemiOpt, T_long, 72,
  /* 41 */ NT_SemiOpt, T_signed, 72,
  /* 42 */ NT_SemiOpt, T_unsigned, 72,
  /* 43 */ NT_SemiOpt, T_typedef, 72,
  /* 44 */ NT_SemiOpt, T_auto, 72,
  /* 45 */ NT_SemiOpt, T_static, 72,
  /* 46 */ NT_SemiOpt, T_extern, 72,
  /* 47 */ NT_SemiOpt, T_const, 72,
  /* 48 */ NT_SemiOpt, T_volatile, 72,
  /* 49 */ NT_SemiOpt, T_semico, 71,
  /* 50 */ NT_Elements, T_enum, 17,
  /* 51 */ NT_Elements, T_ident, 17,
  /* 52 */ NT_Elements, T_rbrace, 17,
  /* 53 */ NT_Elements, T_slot, 17,
  /* 54 */ NT_Elements, T_null, 17,
  /* 55 */ NT_Elements, T_struct, 17,
  /* 56 */ NT_Elements, T_union, 17,
  /* 57 */ NT_Elements, T_void, 17,
  /* 58 */ NT_Elements, T_char, 17,
  /* 59 */ NT_Elements, T_int, 17,
  /* 60 */ NT_Elements, T_float, 17,
  /* 61 */ NT_Elements, T_double, 17,
  /* 62 */ NT_Elements, T_short, 17,
  /* 63 */ NT_Elements, T_long, 17,
  /* 64 */ NT_Elements, T_signed, 17,
  /* 65 */ NT_Elements, T_unsigned, 17,
  /* 66 */ NT_Elements, T_typedef, 17,
  /* 67 */ NT_Elements, T_auto, 17,
  /* 68 */ NT_Elements, T_static, 17,
  /* 69 */ NT_Elements, T_extern, 17,
  /* 70 */ NT_Elements, T_const, 17,
  /* 71 */ NT_Elements, T_volatile, 17,
  /* 72 */ NT_TagList, T_ident, 12,
  /* 73 */ NT_TagList, T_rbrace, 13,
  /* 74 */ NT_Tag, T_ident, 16,
  /* 75 */ NT_TagListTail, T_rbrace, 15,
  /* 76 */ NT_TagListTail, T_comma, 14,
  /* 77 */ NT_ElementList, T_enum, 18,
  /* 78 */ NT_ElementList, T_ident, 18,
  /* 79 */ NT_ElementList, T_rbrace, 19,
  /* 80 */ NT_ElementList, T_slot, 18,
  /* 81 */ NT_ElementList, T_null, 18,
  /* 82 */ NT_ElementList, T_struct, 18,
  /* 83 */ NT_ElementList, T_union, 18,
  /* 84 */ NT_ElementList, T_void, 18,
  /* 85 */ NT_ElementList, T_char, 18,
  /* 86 */ NT_ElementList, T_int, 18,
  /* 87 */ NT_ElementList, T_float, 18,
  /* 88 */ NT_ElementList, T_double, 18,
  /* 89 */ NT_ElementList, T_short, 18,
  /* 90 */ NT_ElementList, T_long, 18,
  /* 91 */ NT_ElementList, T_signed, 18,
  /* 92 */ NT_ElementList, T_unsigned, 18,
  /* 93 */ NT_ElementList, T_typedef, 18,
  /* 94 */ NT_ElementList, T_auto, 18,
  /* 95 */ NT_ElementList, T_static, 18,
  /* 96 */ NT_ElementList, T_extern, 18,
  /* 97 */ NT_ElementList, T_const, 18,
  /* 98 */ NT_ElementList, T_volatile, 18,
  /* 99 */ NT_Element, T_enum, 21,
  /* 100 */ NT_Element, T_ident, 21,
  /* 101 */ NT_Element, T_slot, 20,
  /* 102 */ NT_Element, T_null, 21,
  /* 103 */ NT_Element, T_struct, 21,
  /* 104 */ NT_Element, T_union, 21,
  /* 105 */ NT_Element, T_void, 21,
  /* 106 */ NT_Element, T_char, 21,
  /* 107 */ NT_Element, T_int, 21,
  /* 108 */ NT_Element, T_float, 21,
  /* 109 */ NT_Element, T_double, 21,
  /* 110 */ NT_Element, T_short, 21,
  /* 111 */ NT_Element, T_long, 21,
  /* 112 */ NT_Element, T_signed, 21,
  /* 113 */ NT_Element, T_unsigned, 21,
  /* 114 */ NT_Element, T_typedef, 21,
  /* 115 */ NT_Element, T_auto, 21,
  /* 116 */ NT_Element, T_static, 21,
  /* 117 */ NT_Element, T_extern, 21,
  /* 118 */ NT_Element, T_const, 21,
  /* 119 */ NT_Element, T_volatile, 21,
  /* 120 */ NT_Slot, T_slot, 22,
  /* 121 */ NT_Decl, T_enum, 26,
  /* 122 */ NT_Decl, T_ident, 26,
  /* 123 */ NT_Decl, T_null, 26,
  /* 124 */ NT_Decl, T_struct, 26,
  /* 125 */ NT_Decl, T_union, 26,
  /* 126 */ NT_Decl, T_void, 26,
  /* 127 */ NT_Decl, T_char, 26,
  /* 128 */ NT_Decl, T_int, 26,
  /* 129 */ NT_Decl, T_float, 26,
  /* 130 */ NT_Decl, T_double, 26,
  /* 131 */ NT_Decl, T_short, 26,
  /* 132 */ NT_Decl, T_long, 26,
  /* 133 */ NT_Decl, T_signed, 26,
  /* 134 */ NT_Decl, T_unsigned, 26,
  /* 135 */ NT_Decl, T_typedef, 26,
  /* 136 */ NT_Decl, T_auto, 26,
  /* 137 */ NT_Decl, T_static, 26,
  /* 138 */ NT_Decl, T_extern, 26,
  /* 139 */ NT_Decl, T_const, 26,
  /* 140 */ NT_Decl, T_volatile, 26,
  /* 141 */ NT_Decls, T_enum, 23,
  /* 142 */ NT_Decls, T_ident, 23,
  /* 143 */ NT_Decls, T_rbrace, 23,
  /* 144 */ NT_Decls, T_null, 23,
  /* 145 */ NT_Decls, T_struct, 23,
  /* 146 */ NT_Decls, T_union, 23,
  /* 147 */ NT_Decls, T_void, 23,
  /* 148 */ NT_Decls, T_char, 23,
  /* 149 */ NT_Decls, T_int, 23,
  /* 150 */ NT_Decls, T_float, 23,
  /* 151 */ NT_Decls, T_double, 23,
  /* 152 */ NT_Decls, T_short, 23,
  /* 153 */ NT_Decls, T_long, 23,
  /* 154 */ NT_Decls, T_signed, 23,
  /* 155 */ NT_Decls, T_unsigned, 23,
  /* 156 */ NT_Decls, T_typedef, 23,
  /* 157 */ NT_Decls, T_auto, 23,
  /* 158 */ NT_Decls, T_static, 23,
  /* 159 */ NT_Decls, T_extern, 23,
  /* 160 */ NT_Decls, T_const, 23,
  /* 161 */ NT_Decls, T_volatile, 23,
  /* 162 */ NT_DeclList, T_enum, 24,
  /* 163 */ NT_DeclList, T_ident, 24,
  /* 164 */ NT_DeclList, T_rbrace, 25,
  /* 165 */ NT_DeclList, T_null, 24,
  /* 166 */ NT_DeclList, T_struct, 24,
  /* 167 */ NT_DeclList, T_union, 24,
  /* 168 */ NT_DeclList, T_void, 24,
  /* 169 */ NT_DeclList, T_char, 24,
  /* 170 */ NT_DeclList, T_int, 24,
  /* 171 */ NT_DeclList, T_float, 24,
  /* 172 */ NT_DeclList, T_double, 24,
  /* 173 */ NT_DeclList, T_short, 24,
  /* 174 */ NT_DeclList, T_long, 24,
  /* 175 */ NT_DeclList, T_signed, 24,
  /* 176 */ NT_DeclList, T_unsigned, 24,
  /* 177 */ NT_DeclList, T_typedef, 24,
  /* 178 */ NT_DeclList, T_auto, 24,
  /* 179 */ NT_DeclList, T_static, 24,
  /* 180 */ NT_DeclList, T_extern, 24,
  /* 181 */ NT_DeclList, T_const, 24,
  /* 182 */ NT_DeclList, T_volatile, 24,
  /* 183 */ NT_NullOp, T_enum, 28,
  /* 184 */ NT_NullOp, T_ident, 28,
  /* 185 */ NT_NullOp, T_null, 27,
  /* 186 */ NT_NullOp, T_struct, 28,
  /* 187 */ NT_NullOp, T_union, 28,
  /* 188 */ NT_NullOp, T_void, 28,
  /* 189 */ NT_NullOp, T_char, 28,
  /* 190 */ NT_NullOp, T_int, 28,
  /* 191 */ NT_NullOp, T_float, 28,
  /* 192 */ NT_NullOp, T_double, 28,
  /* 193 */ NT_NullOp, T_short, 28,
  /* 194 */ NT_NullOp, T_long, 28,
  /* 195 */ NT_NullOp, T_signed, 28,
  /* 196 */ NT_NullOp, T_unsigned, 28,
  /* 197 */ NT_NullOp, T_typedef, 28,
  /* 198 */ NT_NullOp, T_auto, 28,
  /* 199 */ NT_NullOp, T_static, 28,
  /* 200 */ NT_NullOp, T_extern, 28,
  /* 201 */ NT_NullOp, T_const, 28,
  /* 202 */ NT_NullOp, T_volatile, 28,
  /* 203 */ NT_Specs, T_enum, 29,
  /* 204 */ NT_Specs, T_ident, 29,
  /* 205 */ NT_Specs, T_struct, 29,
  /* 206 */ NT_Specs, T_union, 29,
  /* 207 */ NT_Specs, T_void, 29,
  /* 208 */ NT_Specs, T_char, 29,
  /* 209 */ NT_Specs, T_int, 29,
  /* 210 */ NT_Specs, T_float, 29,
  /* 211 */ NT_Specs, T_double, 29,
  /* 212 */ NT_Specs, T_short, 29,
  /* 213 */ NT_Specs, T_long, 29,
  /* 214 */ NT_Specs, T_signed, 29,
  /* 215 */ NT_Specs, T_unsigned, 29,
  /* 216 */ NT_Specs, T_typedef, 29,
  /* 217 */ NT_Specs, T_auto, 29,
  /* 218 */ NT_Specs, T_static, 29,
  /* 219 */ NT_Specs, T_extern, 29,
  /* 220 */ NT_Specs, T_const, 29,
  /* 221 */ NT_Specs, T_volatile, 29,
  /* 222 */ NT_Vars, T_ident, 56,
  /* 223 */ NT_Vars, T_deref, 56,
  /* 224 */ NT_Semi, T_semico, 70,
  /* 225 */ NT_SpecList, T_enum, 30,
  /* 226 */ NT_SpecList, T_ident, 30,
  /* 227 */ NT_SpecList, T_struct, 30,
  /* 228 */ NT_SpecList, T_union, 30,
  /* 229 */ NT_SpecList, T_void, 31,
  /* 230 */ NT_SpecList, T_char, 31,
  /* 231 */ NT_SpecList, T_int, 31,
  /* 232 */ NT_SpecList, T_float, 31,
  /* 233 */ NT_SpecList, T_double, 31,
  /* 234 */ NT_SpecList, T_short, 31,
  /* 235 */ NT_SpecList, T_long, 31,
  /* 236 */ NT_SpecList, T_signed, 31,
  /* 237 */ NT_SpecList, T_unsigned, 31,
  /* 238 */ NT_SpecList, T_typedef, 31,
  /* 239 */ NT_SpecList, T_auto, 31,
  /* 240 */ NT_SpecList, T_static, 31,
  /* 241 */ NT_SpecList, T_extern, 31,
  /* 242 */ NT_SpecList, T_const, 31,
  /* 243 */ NT_SpecList, T_volatile, 31,
  /* 244 */ NT_ClassSpec, T_enum, 34,
  /* 245 */ NT_ClassSpec, T_ident, 35,
  /* 246 */ NT_ClassSpec, T_struct, 36,
  /* 247 */ NT_ClassSpec, T_union, 37,
  /* 248 */ NT_Spec, T_void, 38,
  /* 249 */ NT_Spec, T_char, 38,
  /* 250 */ NT_Spec, T_int, 38,
  /* 251 */ NT_Spec, T_float, 38,
  /* 252 */ NT_Spec, T_double, 38,
  /* 253 */ NT_Spec, T_short, 38,
  /* 254 */ NT_Spec, T_long, 38,
  /* 255 */ NT_Spec, T_signed, 38,
  /* 256 */ NT_Spec, T_unsigned, 38,
  /* 257 */ NT_Spec, T_typedef, 39,
  /* 258 */ NT_Spec, T_auto, 39,
  /* 259 */ NT_Spec, T_static, 39,
  /* 260 */ NT_Spec, T_extern, 39,
  /* 261 */ NT_Spec, T_const, 40,
  /* 262 */ NT_Spec, T_volatile, 40,
  /* 263 */ NT_SpecListTail, T_ident, 33,
  /* 264 */ NT_SpecListTail, T_void, 32,
  /* 265 */ NT_SpecListTail, T_char, 32,
  /* 266 */ NT_SpecListTail, T_int, 32,
  /* 267 */ NT_SpecListTail, T_float, 32,
  /* 268 */ NT_SpecListTail, T_double, 32,
  /* 269 */ NT_SpecListTail, T_short, 32,
  /* 270 */ NT_SpecListTail, T_long, 32,
  /* 271 */ NT_SpecListTail, T_signed, 32,
  /* 272 */ NT_SpecListTail, T_unsigned, 32,
  /* 273 */ NT_SpecListTail, T_typedef, 32,
  /* 274 */ NT_SpecListTail, T_auto, 32,
  /* 275 */ NT_SpecListTail, T_static, 32,
  /* 276 */ NT_SpecListTail, T_extern, 32,
  /* 277 */ NT_SpecListTail, T_const, 32,
  /* 278 */ NT_SpecListTail, T_volatile, 32,
  /* 279 */ NT_SpecListTail, T_deref, 33,
  /* 280 */ NT_TypeSpec, T_void, 41,
  /* 281 */ NT_TypeSpec, T_char, 42,
  /* 282 */ NT_TypeSpec, T_int, 43,
  /* 283 */ NT_TypeSpec, T_float, 44,
  /* 284 */ NT_TypeSpec, T_double, 45,
  /* 285 */ NT_TypeSpec, T_short, 46,
  /* 286 */ NT_TypeSpec, T_long, 47,
  /* 287 */ NT_TypeSpec, T_signed, 48,
  /* 288 */ NT_TypeSpec, T_unsigned, 49,
  /* 289 */ NT_StClSpec, T_typedef, 50,
  /* 290 */ NT_StClSpec, T_auto, 51,
  /* 291 */ NT_StClSpec, T_static, 52,
  /* 292 */ NT_StClSpec, T_extern, 53,
  /* 293 */ NT_TypeQual, T_const, 54,
  /* 294 */ NT_TypeQual, T_volatile, 55,
  /* 295 */ NT_VarList, T_ident, 57,
  /* 296 */ NT_VarList, T_deref, 57,
  /* 297 */ NT_Var, T_ident, 60,
  /* 298 */ NT_Var, T_deref, 60,
  /* 299 */ NT_VarListTail, T_comma, 58,
  /* 300 */ NT_VarListTail, T_semico, 59,
  /* 301 */ NT_Ptrs, T_ident, 61,
  /* 302 */ NT_Ptrs, T_deref, 61,
  /* 303 */ NT_Arrays, T_comma, 64,
  /* 304 */ NT_Arrays, T_lbrack, 64,
  /* 305 */ NT_Arrays, T_semico, 64,
  /* 306 */ NT_PtrList, T_ident, 63,
  /* 307 */ NT_PtrList, T_deref, 62,
  /* 308 */ NT_ArrayList, T_comma, 66,
  /* 309 */ NT_ArrayList, T_lbrack, 65,
  /* 310 */ NT_ArrayList, T_semico, 66,
  /* 311 */ NT_Array, T_lbrack, 67,
  /* 312 */ NT_ArrayTail, T_integer, 68,
  /* 313 */ NT_ArrayTail, T_rbrack, 69,
  0
};

short PredictIndexTable[] = {
  0,
  4,
  8,
  12,
  16,
  19,
  20,
  21,
  22,
  24,
  50,
  72,
  74,
  75,
  77,
  99,
  120,
  121,
  141,
  162,
  183,
  203,
  222,
  224,
  225,
  244,
  248,
  263,
  280,
  289,
  293,
  295,
  297,
  299,
  301,
  303,
  306,
  308,
  311,
  312,
  314
};

char *SemanticStackTypeTable[] = {
  "Queue",
  "Enum",
  "Node",
  "Slot",
  "Token",
  "Void"
};

void _Encode_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_Encode_XL",SemanticStack,3,SST_Queue);
  CheckStackAt("_Encode_XL",SemanticStack,2,SST_Queue);
  CheckStackAt("_Encode_XL",SemanticStack,1,SST_Queue);
#endif

  doEncode(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,2)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
}

void _Q_XL()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Queue;
  AttIn->u.U_Queue = doQ();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NQEnum_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQEnum_XL",SemanticStack,4,SST_Queue);
  CheckStackAt("_NQEnum_XL",SemanticStack,1,SST_Enum);
#endif

  doNQEnum(SSEGet(SemanticStack,4)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Enum);
  AStackSpill(SemanticStack,1,NULL);
}

void _NQInclude_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQInclude_XL",SemanticStack,3,SST_Queue);
  CheckStackAt("_NQInclude_XL",SemanticStack,1,SST_Token);
#endif

  doNQInclude(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
}

void _NQNode_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQNode_XL",SemanticStack,2,SST_Queue);
  CheckStackAt("_NQNode_XL",SemanticStack,1,SST_Node);
#endif

  doNQNode(SSEGet(SemanticStack,2)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Node);
  AStackSpill(SemanticStack,1,NULL);
}

void _Enum_XL()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Enum_XL",SemanticStack,4,SST_Token);
  CheckStackAt("_Enum_XL",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Enum;
  AttIn->u.U_Enum = doEnum(SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,5,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _Zap_XL()
{
#ifdef SemanticErrorCheckOn
#endif

  doNothing();
  AStackSpill(SemanticStack,1,NULL);
}

void _Node_XL()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Node_XL",SemanticStack,5,SST_Token);
  CheckStackAt("_Node_XL",SemanticStack,3,SST_Queue);
  CheckStackAt("_Node_XL",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Node;
  AttIn->u.U_Node = doNode(SSEGet(SemanticStack,5)->u.U_Token,
      SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,6,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NQToken_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQToken_XL",SemanticStack,2,SST_Queue);
  CheckStackAt("_NQToken_XL",SemanticStack,1,SST_Token);
#endif

  doNQToken(SSEGet(SemanticStack,2)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Token);
  AStackSpill(SemanticStack,1,NULL);
}

void _NQSlot_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQSlot_XL",SemanticStack,3,SST_Queue);
  CheckStackAt("_NQSlot_XL",SemanticStack,1,SST_Slot);
#endif

  doNQSlot(SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,1)->u.U_Slot);
  AStackSpill(SemanticStack,1,NULL);
}

void _Slot_XL()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
  CheckStackAt("_Slot_XL",SemanticStack,4,SST_Token);
  CheckStackAt("_Slot_XL",SemanticStack,2,SST_Queue);
#endif

  AttIn = SSENew();
  AttIn->type = SST_Slot;
  AttIn->u.U_Slot = doSlot(SSEGet(SemanticStack,4)->u.U_Token,
      SSEGet(SemanticStack,2)->u.U_Queue);
  AStackSpill(SemanticStack,5,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _FakeToken_XL()
{
  SemanticStackElement AttIn;

#ifdef SemanticErrorCheckOn
#endif

  AttIn = SSENew();
  AttIn->type = SST_Token;
  AttIn->u.U_Token = doFakeToken();
  AStackSpill(SemanticStack,0,NULL);
  AStackPushPointer(SemanticStack,AttIn);
}

void _NQVar_XL()
{
#ifdef SemanticErrorCheckOn
  CheckStackAt("_NQVar_XL",SemanticStack,6,SST_Queue);
  CheckStackAt("_NQVar_XL",SemanticStack,5,SST_Token);
  CheckStackAt("_NQVar_XL",SemanticStack,4,SST_Queue);
  CheckStackAt("_NQVar_XL",SemanticStack,3,SST_Queue);
  CheckStackAt("_NQVar_XL",SemanticStack,2,SST_Token);
  CheckStackAt("_NQVar_XL",SemanticStack,1,SST_Queue);
#endif

  doNQVar(SSEGet(SemanticStack,6)->u.U_Queue,
      SSEGet(SemanticStack,5)->u.U_Token,
      SSEGet(SemanticStack,4)->u.U_Queue,
      SSEGet(SemanticStack,3)->u.U_Queue,
      SSEGet(SemanticStack,2)->u.U_Token,
      SSEGet(SemanticStack,1)->u.U_Queue);
  AStackSpill(SemanticStack,3,NULL);
}

_ActionTableType XL_ActionTable = {
  _Encode_XL,
  _Q_XL,
  _NQEnum_XL,
  _NQInclude_XL,
  _NQNode_XL,
  _Enum_XL,
  _Zap_XL,
  _Node_XL,
  _NQToken_XL,
  _NQSlot_XL,
  _Slot_XL,
  _FakeToken_XL,
  _NQVar_XL,
  NULL
};

_ActionTablePtrType ActionTable = XL_ActionTable;

_PhaseTableType PhaseTable = {
  XL_ActionTable,
  NULL
};

char *PhaseName[] = {
  "XL",
  NULL
};

#endif /* ntparse_c */
