/******************************************************************
**
** NTCGEN.C:
**
**    NT Code Generation
**
** This file is part of Apt Node Tool (NT)
** Copyright (c) 1990 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include <stdio.h>

/* ---------- Headers */

#include "apt.h"
#include "aptlib.h"
#include "astlib.h"
#include "gprintf.h"
#include "ntparse.td"
#include "ntparse.h"
#include "ntparse.pt"
#include "queue.h"
#include "sstring.h"

/* ----------- Defines */

#define NodeCode 103

/* ----------- Imported Globals */

EXTERN char *SFilePrefix;

/* ----------- Private Globals */

PRIVATE FILE *CFile;
PRIVATE int CommaFlag;
PRIVATE Node CurrentNode;
PRIVATE char *CurrentNodeName;
PRIVATE Queue EnumQueue;
PRIVATE FILE *HFile;
PRIVATE Queue IncludeQueue;
PRIVATE Queue NodeQueue;
PRIVATE Queue WorkQueue;
PRIVATE int FoundFlag;
PRIVATE int SpaceFlag;

/* ----------- Private Prototypes */

#ifdef __ANSI_C__
void CG(Queue,Queue,Queue);
static void CGCFile(void);
static void CGCFileArgANSI(Decl);
static void CGCFileArgList(Decl);
static void CGCFileArgNANSI(Decl);
static void CGCFileAssignDeclDuplicate(Decl);
static void CGCFileAssignSlotDuplicate(Decl);
static void CGCFileAssignDeclNew(Decl);
static void CGCFileAssignSlotNew(Decl);
static void CGCFileAssignDeclUpdate(Decl);
static void CGCFileAssignSlotUpdate(Decl);
static void CGCFileFooter(void);
static void CGCFileHeader(void);
static void CGCFileNode(Node);
static void CGCFileNodeFunctDuplicate(Node);
static void CGCFileNodeFunctHeaderDeclDuplicate(void);
static void CGCFileNodeFunctSlotDuplicate(Slot);
static void CGCFileNodeFunctHeaderSlotDuplicate(Slot);
static void CGCFileNodeFunctNew(Node);
static void CGCFileNodeFunctHeaderDeclNew(void);
static void CGCFileNodeFunctSlotNew(Slot);
static void CGCFileNodeFunctHeaderSlotNew(Slot);
static void CGCFileNodeFunctUpdate(Node);
static void CGCFileNodeFunctHeaderDeclUpdate(void);
static void CGCFileNodeFunctSlotUpdate(Slot);
static void CGCFileNodeFunctHeaderSlotUpdate(Slot);
static void CGCFileSpec(Queue);
static void CGCFileToken(Token);
static void CGHFile(void);
static void CGHFileArgType(Decl);
static void CGHFileEnum(Enum);
static void CGHFileEnumNode(Node);
static void CGHFileEnumNodeSlot(Slot);
static void CGHFileEnumTag(Token);
static void CGHFileFooter(void);
static void CGHFileHeader(void);
static void CGHFileInclude(Token);
static void CGHFileNode(Node);
static void CGHFileNodeMacro(Node);
static void CGHFileNodeMacroSlot(Slot);
static void CGHFileNodeProto(Node);
static void CGHFileNodeProtoANSI(Slot);
static void CGHFileNodeProtoNANSI(Slot);
static void CGHFileNodeType(Node);
static void CGHFileSpec(Queue);
static void CGHFileStruct(Slot);
static void CGHFileStructElement(Decl);
static void CGHFileToken(Token);
static void CGHFileUnionElement(Slot);
static void CloseCFile(void);
static void CloseHFile(void);
static void OpenCFile(void);
static void OpenHFile(void);
#else
void CG();
static void CGCFile();
static void CGCFileArgANSI();
static void CGCFileArgList();
static void CGCFileArgNANSI();
static void CGCFileAssignDeclDuplicate();
static void CGCFileAssignSlotDuplicate();
static void CGCFileAssignDeclNew();
static void CGCFileAssignSlotNew();
static void CGCFileAssignDeclUpdate();
static void CGCFileAssignSlotUpdate();
static void CGCFileFooter();
static void CGCFileHeader();
static void CGCFileNode();
static void CGCFileNodeFunctDuplicate();
static void CGCFileNodeFunctHeaderDeclDuplicate();
static void CGCFileNodeFunctSlotDuplicate();
static void CGCFileNodeFunctHeaderSlotDuplicate();
static void CGCFileNodeFunctNew();
static void CGCFileNodeFunctHeaderDeclNew();
static void CGCFileNodeFunctSlotNew();
static void CGCFileNodeFunctHeaderSlotNew();
static void CGCFileNodeFunctUpdate();
static void CGCFileNodeFunctHeaderDeclUpdate();
static void CGCFileNodeFunctSlotUpdate();
static void CGCFileNodeFunctHeaderSlotUpdate();
static void CGCFileSpec();
static void CGCFileToken();
static void CGHFile();
static void CGHFileArgType();
static void CGHFileEnum();
static void CGHFileEnumNode();
static void CGHFileEnumNodeSlot();
static void CGHFileEnumTag();
static void CGHFileFooter();
static void CGHFileHeader();
static void CGHFileInclude();
static void CGHFileNode();
static void CGHFileNodeMacro();
static void CGHFileNodeMacroSlot();
static void CGHFileNodeProto();
static void CGHFileNodeProtoANSI();
static void CGHFileNodeProtoNANSI();
static void CGHFileNodeType();
static void CGHFileSpec();
static void CGHFileStruct();
static void CGHFileStructElement();
static void CGHFileToken();
static void CGHFileTypeSlot();
static void CGHFileUnionElement();
static void CloseCFile();
static void CloseHFile();
static void OpenCFile();
static void OpenHFile();
#endif

/* ----------- Functions */

/*
**
** CG
**
*/
PUBLIC
#ifdef __ANSI_C__
void CG(Queue enums, Queue includes, Queue nodes)
#else
void CG(enums, includes, nodes)
Queue enums;
Queue includes;
Queue nodes;
#endif
{
  QueueItem qi;

  EnumQueue = enums;
  IncludeQueue = includes;
  NodeQueue = nodes;
  WorkQueue = QueueNew();
  for (qi = QueueHead(NodeQueue); qi != NULL; qi = QueueNext(qi)) {
    QueuePut(WorkQueue,((Node)QueueItemElement(qi))->name->text,0);
  } 
  CGHFile();
  CGCFile();   
}

/*
**
** CGCFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFile(void)
#else
void CGCFile()
#endif
{
  OpenCFile();
  CGCFileHeader();  
  QueueApply(NodeQueue,(ApplyFunction)CGCFileNode);
  CGCFileFooter();
  CloseCFile();
}

/*
**
** CGCFileArgANSI
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileArgANSI(Decl decl)
#else
void CGCFileArgANSI(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) return;
  FoundFlag = 1;
  if (CommaFlag>0) gprintf(CFile,",");
  else if (CommaFlag == 0) CommaFlag = 1;
  CGCFileSpec(decl->specs);
  gprintf(CFile," ");
  SpaceFlag = -1; QueueApply(decl->ptrs,(ApplyFunction)CGCFileToken);
  gprintf(CFile,"%s",decl->name->text);
  SpaceFlag = -1; QueueApply(decl->arrays,(ApplyFunction)CGCFileToken);
}

/*
**
** CGCFileArgList
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileArgList(Decl decl)
#else
void CGCFileArgList(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) return;
  CGCFileSpec(decl->specs);
  gprintf(CFile," ");
  SpaceFlag = -1; QueueApply(decl->ptrs,(ApplyFunction)CGCFileToken);
  gprintf(CFile,"%s",decl->name->text);
  SpaceFlag = -1; QueueApply(decl->arrays,(ApplyFunction)CGCFileToken);
  gprintf(CFile,";\n");
}

/*
**
** CGCFileArgNANSI
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileArgNANSI(Decl decl)
#else
void CGCFileArgNANSI(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) return;
  if (CommaFlag>0) gprintf(CFile,",");
  else if (CommaFlag == 0) CommaFlag = 1;
  gprintf(CFile,"%s",decl->name->text);
}

/*
**
** CGCFileAssignDeclDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignDeclDuplicate(Decl decl)
#else
void CGCFileAssignDeclDuplicate(decl)
Decl decl;
#endif
{
  gprintf(CFile,"  new%s->%s = old%s->%s;\n",CurrentNodeName,decl->name->text,
  /**/ CurrentNodeName,decl->name->text);
}

/*
/*
**
** CGCFileAssignSlotDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignSlotDuplicate(Decl decl)
#else
void CGCFileAssignSlotDuplicate(decl)
Decl decl;
#endif
{
  gprintf(CFile,"  slot->%s = oldslot->%s;\n",decl->name->text,
  /**/ decl->name->text);
}

/*
**
** CGCFileAssignDeclNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignDeclNew(Decl decl)
#else
void CGCFileAssignDeclNew(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) {
    gprintf(CFile,"  new%s->%s = (",CurrentNodeName,decl->name->text);
    CGCFileSpec(decl->specs); 
    SpaceFlag = -1;
    QueueApply(decl->ptrs,(ApplyFunction)CGCFileToken);
    gprintf(CFile,")0;\n");
  }
  else {
    gprintf(CFile,"  new%s->%s = %s;\n",CurrentNodeName,decl->name->text,
    /**/ decl->name->text);
  }
}

/*
/*
**
** CGCFileAssignSlotNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignSlotNew(Decl decl)
#else
void CGCFileAssignSlotNew(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) {
    gprintf(CFile,"  slot->%s = (",decl->name->text);
    CGCFileSpec(decl->specs); 
    SpaceFlag = -1;
    QueueApply(decl->ptrs,(ApplyFunction)CGCFileToken);
    gprintf(CFile,")0;\n");
  }
  else {
    gprintf(CFile,"  slot->%s = %s;\n",decl->name->text,decl->name->text);
  }
}

/*
**
** CGCFileAssignDeclUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignDeclUpdate(Decl decl)
#else
void CGCFileAssignDeclUpdate(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) {
  }
  else {
    gprintf(CFile,"  old%s->%s = %s;\n",CurrentNodeName,decl->name->text,
    /**/ decl->name->text);
  }
}

/*
/*
**
** CGCFileAssignSlotUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileAssignSlotUpdate(Decl decl)
#else
void CGCFileAssignSlotUpdate(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) {
  }
  else {
    gprintf(CFile,"  slot->%s = %s;\n",decl->name->text,decl->name->text);
  }
}

/*
**
** CGCFileFooter
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileFooter(void)
#else
void CGCFileFooter()
#endif
{
}

/*
**
** CGCFileNode
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNode(Node node)
#else
void CGCFileNode(node)
Node node;
#endif
{
  CurrentNode = node;
  CurrentNodeName = node->name->text;
  CGCFileNodeFunctDuplicate(node);
  CGCFileNodeFunctNew(node);
  CGCFileNodeFunctUpdate(node);
}

/*
**
** CGCFileNodeFunctDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctDuplicate(Node node)
#else
void CGCFileNodeFunctDuplicate(node)
Node node;
#endif
{
  if (QueueSize(node->slots)>0)
    QueueApply(node->slots,(ApplyFunction)CGCFileNodeFunctSlotDuplicate);
  else {
    CGCFileNodeFunctHeaderDeclDuplicate();
    gprintf(CFile,"{\n");
    gprintf(CFile,"  %s new%s = (%s)Allocate(sizeof(_%s));\n",CurrentNodeName,
      CurrentNodeName,CurrentNodeName,CurrentNodeName);
    QueueApply(node->decls,(ApplyFunction)CGCFileAssignDeclDuplicate);
    gprintf(CFile,"  return (new%s);\n",CurrentNodeName);
    gprintf(CFile,"}\n");
    gprintf(CFile,"\n");
  }
}

/*
**
** CGCFileNodeFunctHeaderDeclDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderDeclDuplicate(void)
#else
void CGCFileNodeFunctHeaderDeclDuplicate()
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %sDuplicate\n",CurrentNodeName);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %sDuplicate(%s old%s)\n",CurrentNodeName,CurrentNodeName,
  /**/ CurrentNodeName,CurrentNodeName);
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %sDuplicate(old%s)\n",CurrentNodeName,CurrentNodeName,
  /**/ CurrentNodeName);
  gprintf(CFile,"%s old%s;\n",CurrentNodeName,CurrentNodeName);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileNodeFunctSlotDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctSlotDuplicate(Slot slot)
#else
void CGCFileNodeFunctSlotDuplicate(slot)
Slot slot;
#endif
{
  CGCFileNodeFunctHeaderSlotDuplicate(slot);
  gprintf(CFile,"{\n");
  gprintf(CFile,"  %s new%s = (%s)Allocate(sizeof(_%s));\n",CurrentNodeName,
    CurrentNodeName,CurrentNodeName,CurrentNodeName);
  if (QueueSize(slot->decls)>0) {
    gprintf(CFile,"  struct _%s%s *slot = &new%s->U.%sSlot;\n",
    /**/ CurrentNodeName,slot->name->text,CurrentNodeName,slot->name->text);
    gprintf(CFile,"  struct _%s%s *oldslot = &old%s->U.%sSlot;\n",
    /**/ CurrentNodeName,slot->name->text,CurrentNodeName,slot->name->text);
  }
  gprintf(CFile,"  new%s->tag = %s%sTag;\n",CurrentNodeName,
  /**/ CurrentNodeName,slot->name->text);
  QueueApply(slot->decls,(ApplyFunction)CGCFileAssignSlotDuplicate);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileAssignDeclDuplicate);
  gprintf(CFile,"  return (new%s);\n",CurrentNodeName);
  gprintf(CFile,"}\n");
  gprintf(CFile,"\n");
}

/*
**
** CGCFileNodeFunctHeaderSlotDuplicate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderSlotDuplicate(Slot slot)
#else
void CGCFileNodeFunctHeaderSlotDuplicate(slot)
Slot slot;
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %s%sDuplicate\n",CurrentNodeName,slot->name->text);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %s%sDuplicate(%s old%s)\n",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text,CurrentNodeName,CurrentNodeName);
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %s%sDuplicate(old%s)\n",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text,CurrentNodeName);
  gprintf(CFile,"%s old%s;\n",CurrentNodeName,CurrentNodeName);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileNodeFunctNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctNew(Node node)
#else
void CGCFileNodeFunctNew(node)
Node node;
#endif
{
  if (QueueSize(node->slots)>0)
    QueueApply(node->slots,(ApplyFunction)CGCFileNodeFunctSlotNew);
  else {
    CGCFileNodeFunctHeaderDeclNew();
    gprintf(CFile,"{\n");
    gprintf(CFile,"  %s new%s = (%s)Allocate(sizeof(_%s));\n",CurrentNodeName,
      CurrentNodeName,CurrentNodeName,CurrentNodeName);
    QueueApply(node->decls,(ApplyFunction)CGCFileAssignDeclNew);
    gprintf(CFile,"  return (new%s);\n",CurrentNodeName);
    gprintf(CFile,"}\n");
    gprintf(CFile,"\n");
  }
}

/*
**
** CGCFileNodeFunctHeaderDeclNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderDeclNew(void)
#else
void CGCFileNodeFunctHeaderDeclNew()
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %sNew\n",CurrentNodeName);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %sNew(",CurrentNodeName,CurrentNodeName);
  CommaFlag = 0; FoundFlag = 0;
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgANSI);
  if (FoundFlag == 0) gprintf(CFile,"void");
  gprintf(CFile,")\n");
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %sNew(",CurrentNodeName,CurrentNodeName);
  CommaFlag = 0;
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgNANSI);
  gprintf(CFile,")\n");
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgList);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileNodeFunctSlotNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctSlotNew(Slot slot)
#else
void CGCFileNodeFunctSlotNew(slot)
Slot slot;
#endif
{
  CGCFileNodeFunctHeaderSlotNew(slot);
  gprintf(CFile,"{\n");
  gprintf(CFile,"  %s new%s = (%s)Allocate(sizeof(_%s));\n",CurrentNodeName,
    CurrentNodeName,CurrentNodeName,CurrentNodeName);
  if (QueueSize(slot->decls)>0)
    gprintf(CFile,"  struct _%s%s *slot = &new%s->U.%sSlot;\n",
      CurrentNodeName,slot->name->text,CurrentNodeName,slot->name->text);
  gprintf(CFile,"  new%s->tag = %s%sTag;\n",CurrentNodeName,
    CurrentNodeName,slot->name->text);
  QueueApply(slot->decls,(ApplyFunction)CGCFileAssignSlotNew);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileAssignDeclNew);
  gprintf(CFile,"  return (new%s);\n",CurrentNodeName);
  gprintf(CFile,"}\n");
  gprintf(CFile,"\n");
}

/*
**
** CGCFileNodeFunctHeaderSlotNew
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderSlotNew(Slot slot)
#else
void CGCFileNodeFunctHeaderSlotNew(slot)
Slot slot;
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %s%sNew\n",CurrentNodeName,slot->name->text);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %s%sNew(",CurrentNodeName,CurrentNodeName,slot->name->text);
  CommaFlag = 0; FoundFlag = 0;
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgANSI);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgANSI);
  if (FoundFlag == 0) gprintf(CFile,"void");
  gprintf(CFile,")\n");
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %s%sNew(",CurrentNodeName,CurrentNodeName,slot->name->text);
  CommaFlag = 0;
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgNANSI);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgNANSI);
  gprintf(CFile,")\n");
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgList);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgList);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileNodeFunctUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctUpdate(Node node)
#else
void CGCFileNodeFunctUpdate(node)
Node node;
#endif
{
  if (QueueSize(node->slots)>0)
    QueueApply(node->slots,(ApplyFunction)CGCFileNodeFunctSlotUpdate);
  else {
    CGCFileNodeFunctHeaderDeclUpdate();
    gprintf(CFile,"{\n");
    QueueApply(node->decls,(ApplyFunction)CGCFileAssignDeclUpdate);
    gprintf(CFile,"  return (old%s);\n",CurrentNodeName);
    gprintf(CFile,"}\n");
    gprintf(CFile,"\n");
  }
}

/*
**
** CGCFileNodeFunctHeaderDeclUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderDeclUpdate(void)
#else
void CGCFileNodeFunctHeaderDeclUpdate()
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %sUpdate\n",CurrentNodeName);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %sUpdate(%s old%s",CurrentNodeName,CurrentNodeName,
  /**/ CurrentNodeName, CurrentNodeName);
  CommaFlag = 1;
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgANSI);
  gprintf(CFile,")\n");
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %sUpdate(old%s",CurrentNodeName,CurrentNodeName,
  /**/ CurrentNodeName);
  CommaFlag = 1;
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgNANSI);
  gprintf(CFile,")\n");
  gprintf(CFile,"%s old%s;\n",CurrentNodeName,CurrentNodeName);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgList);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileNodeFunctSlotUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctSlotUpdate(Slot slot)
#else
void CGCFileNodeFunctSlotUpdate(slot)
Slot slot;
#endif
{
  CGCFileNodeFunctHeaderSlotUpdate(slot);
  gprintf(CFile,"{\n");
  if (QueueSize(slot->decls)>0)
    gprintf(CFile,"  struct _%s%s *slot = &old%s->U.%sSlot;\n",
      CurrentNodeName,slot->name->text,CurrentNodeName,slot->name->text);
  gprintf(CFile,"  old%s->tag = %s%sTag;\n",CurrentNodeName,
    CurrentNodeName,slot->name->text);
  QueueApply(slot->decls,(ApplyFunction)CGCFileAssignSlotUpdate);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileAssignDeclUpdate);
  gprintf(CFile,"  return (old%s);\n",CurrentNodeName);
  gprintf(CFile,"}\n");
  gprintf(CFile,"\n");
}

/*
**
** CGCFileNodeFunctHeaderSlotUpdate
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileNodeFunctHeaderSlotUpdate(Slot slot)
#else
void CGCFileNodeFunctHeaderSlotUpdate(slot)
Slot slot;
#endif
{
  gprintf(CFile,"/*\n");
  gprintf(CFile,"**\n");
  gprintf(CFile,"** %s%sUpdate\n",CurrentNodeName,slot->name->text);
  gprintf(CFile,"**\n");
  gprintf(CFile,"*/\n");
  gprintf(CFile,"PUBLIC\n");
  gprintf(CFile,"#ifdef __ANSI_C__\n");
  gprintf(CFile,"%s %s%sUpdate(%s old%s",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text,CurrentNodeName,CurrentNodeName);
  CommaFlag = 1;
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgANSI);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgANSI);
  gprintf(CFile,")\n");
  gprintf(CFile,"#else\n");
  gprintf(CFile,"%s %s%sUpdate(old%s",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text,CurrentNodeName);
  CommaFlag = 1;
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgNANSI);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgNANSI);
  gprintf(CFile,")\n");
  gprintf(CFile,"%s old%s;\n",CurrentNodeName,CurrentNodeName);
  QueueApply(slot->decls,(ApplyFunction)CGCFileArgList);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGCFileArgList);
  gprintf(CFile,"#endif\n");
}

/*
**
** CGCFileHeader
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileHeader(void)
#else
void CGCFileHeader()
#endif
{
  gprintf(CFile,"#include \"apt.h\"\n");
  gprintf(CFile,"#include \"%s.h\"\n",SFilePrefix);
  gprintf(CFile,"#include \"allocate.h\"\n");
  gprintf(CFile,"\n");
}

/*
**
** CGCFileSpec
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileSpec(Queue specs)
#else
void CGCFileSpec(specs)
Queue specs;
#endif
{
  if (QueueSize(specs)>1) {
    SpaceFlag = 0; QueueApply(specs,(ApplyFunction)CGCFileToken);
  } else {
    Token t = QueueLook(specs);
    if (t->type == T_ident) {
      gprintf(CFile,"%s",t->text);
    } else gprintf(CFile,"%s",t->text);
  }
}

/*
**
** CGCFileToken
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGCFileToken(Token token)
#else
void CGCFileToken(token)
Token token;
#endif
{
  if (SpaceFlag>0) gprintf(CFile," ");
  else if (SpaceFlag == 0) SpaceFlag = 1;
  gprintf(CFile,"%s",token->text);
}

/*
**
** CGHFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFile(void)
#else
void CGHFile()
#endif
{
  OpenHFile();
  CGHFileHeader();  
  QueueApply(IncludeQueue,(ApplyFunction)CGHFileInclude);
  gprintf(HFile,"\n");
  QueueApply(EnumQueue,(ApplyFunction)CGHFileEnum);
  QueueApply(NodeQueue,(ApplyFunction)CGHFileNode);
  CGHFileFooter();
  CloseHFile();
}

/*
**
** CGHFileArgType
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileArgType(Decl decl)
#else
void CGHFileArgType(decl)
Decl decl;
#endif
{
  if (decl->nullFlg) return;
  FoundFlag = 1;
  if (CommaFlag>0) gprintf(HFile,",");
  else if (CommaFlag == 0) CommaFlag = 1;
  CGHFileSpec(decl->specs);
  SpaceFlag = -1; QueueApply(decl->ptrs,(ApplyFunction)CGHFileToken);
  SpaceFlag = -1; QueueApply(decl->arrays,(ApplyFunction)CGHFileToken);
}

/*
**
** CGHFileEnum
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileEnum(Enum en)
#else
void CGHFileEnum(en)
Enum en;
#endif
{
  gprintf(HFile,"/* %s Enumeration */\n\n",en->name->text);

  gprintf(HFile,"typedef enum {\n");
  QueueApply(en->tags,(ApplyFunction)CGHFileEnumTag);
  gprintf(HFile,"  %sCount\n",en->name->text);
  gprintf(HFile,"} %s;\n",en->name->text);

  gprintf(HFile,"\n");
}

/*
**
** CGHFileEnumNode
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileEnumNode(Node node)
#else
void CGHFileEnumNode(node)
Node node;
#endif
{
  gprintf(HFile,"/* %s Enumeration */\n\n",CurrentNodeName);

  gprintf(HFile,"typedef enum {\n");
  QueueApply(node->slots,(ApplyFunction)CGHFileEnumNodeSlot);
  gprintf(HFile,"  %sTagCount\n",CurrentNodeName);
  gprintf(HFile,"} %sTags;\n",CurrentNodeName);

  gprintf(HFile,"\n");
}

/*
**
** CGHFileEnumNodeSlot
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileEnumNodeSlot(Slot slot)
#else
void CGHFileEnumNodeSlot(slot)
Slot slot;
#endif
{
  gprintf(HFile,"  %s%sTag,\n",CurrentNodeName,slot->name->text);
}

/*
**
** CGHFileEnumTag
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileEnumTag(Token tag)
#else
void CGHFileEnumTag(tag)
Token tag;
#endif
{
  gprintf(HFile,"  %s,\n",tag->text);
}

/*
**
** CGHFileFooter
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileFooter(void)
#else
void CGHFileFooter()
#endif
{
  gprintf(HFile,"#endif /* %s_h */\n",SFilePrefix);
}

/*
**
** CGHFileHeader
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileHeader(void)
#else
void CGHFileHeader()
#endif
{
  gprintf(HFile,"#ifndef %s_h\n",SFilePrefix);
  gprintf(HFile,"#define %s_h\n",SFilePrefix);
  gprintf(HFile,"\n");
  gprintf(HFile,"#include \"apt.h\"\n");
}

/*
**
** CGHFileInclude
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileInclude(Token include)
#else
void CGHFileInclude(include)
Token include;
#endif
{
  gprintf(HFile,"#include %J\n",include->text);
}

/*
**
** CGHFileNode
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNode(Node node)
#else
void CGHFileNode(node)
Node node;
#endif
{
  CurrentNode = node;
  CurrentNodeName = node->name->text;
  if (QueueSize(node->slots)>0) CGHFileEnumNode(node);
  CGHFileNodeType(node);
  if (QueueSize(node->slots)>0) CGHFileNodeMacro(node);
  CGHFileNodeProto(node);
  QueueGet(WorkQueue);
}

/*
**
** CGHFileNodeMacros
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeMacro(Node node)
#else
void CGHFileNodeMacro(node)
Node node;
#endif
{
  gprintf(HFile,"/* %s Macros */\n\n",CurrentNodeName);
  QueueApply(node->slots,(ApplyFunction)CGHFileNodeMacroSlot);
  gprintf(HFile,"\n");
}

/*
**
** CGHFileNodeMacroSlot
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeMacroSlot(Slot slot)
#else
void CGHFileNodeMacroSlot(slot)
Slot slot;
#endif
{
  gprintf(HFile,"#define %s%sSlot(n) (n->U.%sSlot)\n",
  /**/ CurrentNodeName,slot->name->text,slot->name->text);
}

/*
**
** CGHFileNodeProto
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeProto(Node node)
#else
void CGHFileNodeProto(node)
Node node;
#endif
{
  gprintf(HFile,"/* %s Prototypes */\n\n",CurrentNodeName);

  if (QueueSize(node->slots)>0) {
    gprintf(HFile,"#ifdef __ANSI_C__\n");
    QueueApply(node->slots,(ApplyFunction)CGHFileNodeProtoANSI);
    gprintf(HFile,"#else\n");
    QueueApply(node->slots,(ApplyFunction)CGHFileNodeProtoNANSI);
    gprintf(HFile,"#endif\n");
  } else {
    gprintf(HFile,"#ifdef __ANSI_C__\n");
    gprintf(HFile,"%s %sDuplicate(%s);\n",CurrentNodeName,
    /**/ CurrentNodeName,CurrentNodeName);
    gprintf(HFile,"%s %sNew(",CurrentNodeName,CurrentNodeName);
    CommaFlag = 0; FoundFlag = 0;
    QueueApply(node->decls,(ApplyFunction)CGHFileArgType);
    if (FoundFlag == 0) gprintf(HFile,"void");
    gprintf(HFile,");\n");
    gprintf(HFile,"%s %sUpdate(%s",CurrentNodeName,CurrentNodeName,
    /**/ CurrentNodeName);
    CommaFlag = 1;
    QueueApply(node->decls,(ApplyFunction)CGHFileArgType);
    gprintf(HFile,");\n");
    gprintf(HFile,"#else\n");
    gprintf(HFile,"%s %sDuplicate();\n",CurrentNodeName,CurrentNodeName);
    gprintf(HFile,"%s %sNew();\n",CurrentNodeName,CurrentNodeName);
    gprintf(HFile,"%s %sUpdate();\n",CurrentNodeName,CurrentNodeName);
    gprintf(HFile,"#endif\n");
  }
  
  gprintf(HFile,"\n");
}

/*
**
** CGHFileNodeProtoANSI
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeProtoANSI(Slot slot)
#else
void CGHFileNodeProtoANSI(slot)
Slot slot;
#endif
{
  gprintf(HFile,"%s %s%sDuplicate(%s);\n",CurrentNodeName,
  /**/ CurrentNodeName,slot->name->text,CurrentNodeName);
  gprintf(HFile,"%s %s%sNew(",CurrentNodeName,CurrentNodeName,slot->name->text);
  CommaFlag = 0; FoundFlag = 0;
  QueueApply(slot->decls,(ApplyFunction)CGHFileArgType);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGHFileArgType);
  if (FoundFlag == 0) gprintf(HFile,"void");
  gprintf(HFile,");\n");
  gprintf(HFile,"%s %s%sUpdate(%s",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text,CurrentNodeName);
  CommaFlag = 1;
  QueueApply(slot->decls,(ApplyFunction)CGHFileArgType);
  QueueApply(CurrentNode->decls,(ApplyFunction)CGHFileArgType);
  gprintf(HFile,");\n");
}

/*
**
** CGHFileNodeProtoNANSI
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeProtoNANSI(Slot slot)
#else
void CGHFileNodeProtoNANSI(slot)
Slot slot;
#endif
{
  gprintf(HFile,"%s %s%sDuplicate();\n",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text);
  gprintf(HFile,"%s %s%sNew();\n",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text);
  gprintf(HFile,"%s %s%sUpdate();\n",CurrentNodeName,CurrentNodeName,
  /**/ slot->name->text);
}

/*
**
** CGHFileNodeType
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileNodeType(Node node)
#else
void CGHFileNodeType(node)
Node node;
#endif
{
  if (QueueSize(node->slots)>0) {
    gprintf(HFile,"/* %s Slots */\n\n",CurrentNodeName);

    QueueApply(node->slots,(ApplyFunction)CGHFileStruct);

    gprintf(HFile,"typedef union {\n");
    QueueApply(node->slots,(ApplyFunction)CGHFileUnionElement);
    gprintf(HFile,"} %sUnion;\n",CurrentNodeName);

    gprintf(HFile,"\n");
  }

  gprintf(HFile,"/* %s Structure */\n\n",CurrentNodeName);

  gprintf(HFile,"typedef struct _%s {\n",CurrentNodeName);

  if (QueueSize(node->slots)>0) {
    gprintf(HFile,"  %sTags tag;\n",CurrentNodeName);
    gprintf(HFile,"  %sUnion U;\n",CurrentNodeName);
  }

  QueueApply(node->decls,(ApplyFunction)CGHFileStructElement);

  gprintf(HFile,"} _%s, *%s;\n",CurrentNodeName,CurrentNodeName);

  gprintf(HFile,"\n");
}

/*
**
** CGHFileSpec
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileSpec(Queue specs)
#else
void CGHFileSpec(specs)
Queue specs;
#endif
{
  if (QueueSize(specs)>1) {
    SpaceFlag = 0; QueueApply(specs,(ApplyFunction)CGHFileToken);
  } else {
    Token t = QueueLook(specs);
    if (t->type == T_ident) {
      if (QueueFind(WorkQueue,t->text,(ComparisonFunction)StringCompare))
        gprintf(HFile,"struct _%s*",t->text);
      else gprintf(HFile,"%s",t->text);
    } else gprintf(HFile,"%s",t->text);
  }
}

/*
**
** CGHFileStruct
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileStruct(Slot slot)
#else
void CGHFileStruct(slot)
Slot slot;
#endif
{
  gprintf(HFile,"struct _%s%s {\n",CurrentNodeName,slot->name->text);
  if (QueueSize(slot->decls)<1) gprintf(HFile,"  char AptParsingTools;\n");
  else QueueApply(slot->decls,(ApplyFunction)CGHFileStructElement);
  gprintf(HFile,"};\n\n");
}

/*
**
** CGHFileStructElement
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileStructElement(Decl decl)
#else
void CGHFileStructElement(decl)
Decl decl;
#endif
{
  gprintf(HFile,"  ");
  CGHFileSpec(decl->specs); 
  gprintf(HFile," ");
  SpaceFlag = -1; QueueApply(decl->ptrs,(ApplyFunction)CGHFileToken);
  gprintf(HFile,"%s",decl->name->text);
  SpaceFlag = -1; QueueApply(decl->arrays,(ApplyFunction)CGHFileToken);
  gprintf(HFile,";\n");
}

/*
**
** CGHFileToken
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileToken(Token token)
#else
void CGHFileToken(token)
Token token;
#endif
{
  if (SpaceFlag>0) gprintf(HFile," ");
  else if (SpaceFlag == 0) SpaceFlag = 1;
  gprintf(HFile,"%s",token->text);
}

/*
**
** CGHFileUnionElement
**
*/
PRIVATE
#ifdef __ANSI_C__
void CGHFileUnionElement(Slot slot)
#else
void CGHFileUnionElement(slot)
Slot slot;
#endif
{
  gprintf(HFile,"  struct _%s%s %sSlot;\n",CurrentNodeName,
    slot->name->text,slot->name->text);
}

/*
**
** CloseCFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void CloseCFile(void)
#else
void CloseCFile()
#endif
{
  fclose(CFile);
}

/*
**
** CloseHFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void CloseHFile(void)
#else
void CloseHFile()
#endif
{
  fclose(HFile);
}

/*
**
** OpenCFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void OpenCFile(void)
#else
void OpenCFile()
#endif
{
  Buffer buffer;
  char *CFileName;

  buffer = BufferNew();
  BufferAddString(buffer,SFilePrefix);
  BufferAddString(buffer,".c");
  CFileName = BufferToString(buffer);
  BufferDispose(buffer);

  CFile = fopen(CFileName,"w");
  if (CFile == NULL) CFile = stdout;
  free(CFileName);
}

/*
**
** OpenHFile
**
*/
PRIVATE
#ifdef __ANSI_C__
void OpenHFile(void)
#else
void OpenHFile()
#endif
{
  Buffer buffer;
  char *HFileName;

  buffer = BufferNew();
  BufferAddString(buffer,SFilePrefix);
  BufferAddString(buffer,".h");
  HFileName = BufferToString(buffer);
  BufferDispose(buffer);

  HFile = fopen(HFileName,"w");
  if (HFile == NULL) HFile = stdout;
  free(HFileName);
}
