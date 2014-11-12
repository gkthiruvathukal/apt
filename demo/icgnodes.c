#include "apt.h"
#include "icgnodes.h"
#include "allocate.h"

/*
**
** AddrAbsoluteDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrAbsoluteDuplicate(Addr oldAddr)
#else
Addr AddrAbsoluteDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrAbsolute *slot = &newAddr->U.AbsoluteSlot;
  struct _AddrAbsolute *oldslot = &oldAddr->U.AbsoluteSlot;
  newAddr->tag = AddrAbsoluteTag;
  slot->disp = oldslot->disp;
  return (newAddr);
}

/*
**
** AddrExternalDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrExternalDuplicate(Addr oldAddr)
#else
Addr AddrExternalDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrExternal *slot = &newAddr->U.ExternalSlot;
  struct _AddrExternal *oldslot = &oldAddr->U.ExternalSlot;
  newAddr->tag = AddrExternalTag;
  slot->disp1 = oldslot->disp1;
  slot->disp2 = oldslot->disp2;
  return (newAddr);
}

/*
**
** AddrFrameDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameDuplicate(Addr oldAddr)
#else
Addr AddrFrameDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrFrame *slot = &newAddr->U.FrameSlot;
  struct _AddrFrame *oldslot = &oldAddr->U.FrameSlot;
  newAddr->tag = AddrFrameTag;
  slot->disp = oldslot->disp;
  return (newAddr);
}

/*
**
** AddrFrameRelativeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameRelativeDuplicate(Addr oldAddr)
#else
Addr AddrFrameRelativeDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrFrameRelative *slot = &newAddr->U.FrameRelativeSlot;
  struct _AddrFrameRelative *oldslot = &oldAddr->U.FrameRelativeSlot;
  newAddr->tag = AddrFrameRelativeTag;
  slot->disp2 = oldslot->disp2;
  slot->disp1 = oldslot->disp1;
  return (newAddr);
}

/*
**
** AddrImmediateDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrImmediateDuplicate(Addr oldAddr)
#else
Addr AddrImmediateDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrImmediate *slot = &newAddr->U.ImmediateSlot;
  struct _AddrImmediate *oldslot = &oldAddr->U.ImmediateSlot;
  newAddr->tag = AddrImmediateTag;
  slot->value = oldslot->value;
  return (newAddr);
}

/*
**
** AddrProgramDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrProgramDuplicate(Addr oldAddr)
#else
Addr AddrProgramDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrProgram *slot = &newAddr->U.ProgramSlot;
  struct _AddrProgram *oldslot = &oldAddr->U.ProgramSlot;
  newAddr->tag = AddrProgramTag;
  slot->disp = oldslot->disp;
  return (newAddr);
}

/*
**
** AddrRegisterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterDuplicate(Addr oldAddr)
#else
Addr AddrRegisterDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrRegister *slot = &newAddr->U.RegisterSlot;
  struct _AddrRegister *oldslot = &oldAddr->U.RegisterSlot;
  newAddr->tag = AddrRegisterTag;
  slot->dt = oldslot->dt;
  slot->number = oldslot->number;
  return (newAddr);
}

/*
**
** AddrRegisterRelativeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterRelativeDuplicate(Addr oldAddr)
#else
Addr AddrRegisterRelativeDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrRegisterRelative *slot = &newAddr->U.RegisterRelativeSlot;
  struct _AddrRegisterRelative *oldslot = &oldAddr->U.RegisterRelativeSlot;
  newAddr->tag = AddrRegisterRelativeTag;
  slot->dt = oldslot->dt;
  slot->disp = oldslot->disp;
  slot->number = oldslot->number;
  return (newAddr);
}

/*
**
** AddrStackDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackDuplicate(Addr oldAddr)
#else
Addr AddrStackDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStack *slot = &newAddr->U.StackSlot;
  struct _AddrStack *oldslot = &oldAddr->U.StackSlot;
  newAddr->tag = AddrStackTag;
  slot->disp = oldslot->disp;
  return (newAddr);
}

/*
**
** AddrStackRelativeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackRelativeDuplicate(Addr oldAddr)
#else
Addr AddrStackRelativeDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStackRelative *slot = &newAddr->U.StackRelativeSlot;
  struct _AddrStackRelative *oldslot = &oldAddr->U.StackRelativeSlot;
  newAddr->tag = AddrStackRelativeTag;
  slot->disp2 = oldslot->disp2;
  slot->disp1 = oldslot->disp1;
  return (newAddr);
}

/*
**
** AddrStaticDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticDuplicate(Addr oldAddr)
#else
Addr AddrStaticDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStatic *slot = &newAddr->U.StaticSlot;
  struct _AddrStatic *oldslot = &oldAddr->U.StaticSlot;
  newAddr->tag = AddrStaticTag;
  slot->disp = oldslot->disp;
  return (newAddr);
}

/*
**
** AddrStaticRelativeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticRelativeDuplicate(Addr oldAddr)
#else
Addr AddrStaticRelativeDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStaticRelative *slot = &newAddr->U.StaticRelativeSlot;
  struct _AddrStaticRelative *oldslot = &oldAddr->U.StaticRelativeSlot;
  newAddr->tag = AddrStaticRelativeTag;
  slot->disp2 = oldslot->disp2;
  slot->disp1 = oldslot->disp1;
  return (newAddr);
}

/*
**
** AddrTopOfStackDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrTopOfStackDuplicate(Addr oldAddr)
#else
Addr AddrTopOfStackDuplicate(oldAddr)
Addr oldAddr;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  newAddr->tag = AddrTopOfStackTag;
  return (newAddr);
}

/*
**
** AddrAbsoluteNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrAbsoluteNew(Disp disp)
#else
Addr AddrAbsoluteNew(disp)
Disp disp;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrAbsolute *slot = &newAddr->U.AbsoluteSlot;
  newAddr->tag = AddrAbsoluteTag;
  slot->disp = disp;
  return (newAddr);
}

/*
**
** AddrExternalNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrExternalNew(Disp disp1,Disp disp2)
#else
Addr AddrExternalNew(disp1,disp2)
Disp disp1;
Disp disp2;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrExternal *slot = &newAddr->U.ExternalSlot;
  newAddr->tag = AddrExternalTag;
  slot->disp1 = disp1;
  slot->disp2 = disp2;
  return (newAddr);
}

/*
**
** AddrFrameNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameNew(Disp disp)
#else
Addr AddrFrameNew(disp)
Disp disp;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrFrame *slot = &newAddr->U.FrameSlot;
  newAddr->tag = AddrFrameTag;
  slot->disp = disp;
  return (newAddr);
}

/*
**
** AddrFrameRelativeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameRelativeNew(Disp disp2,Disp disp1)
#else
Addr AddrFrameRelativeNew(disp2,disp1)
Disp disp2;
Disp disp1;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrFrameRelative *slot = &newAddr->U.FrameRelativeSlot;
  newAddr->tag = AddrFrameRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (newAddr);
}

/*
**
** AddrImmediateNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrImmediateNew(MValue value)
#else
Addr AddrImmediateNew(value)
MValue value;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrImmediate *slot = &newAddr->U.ImmediateSlot;
  newAddr->tag = AddrImmediateTag;
  slot->value = value;
  return (newAddr);
}

/*
**
** AddrProgramNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrProgramNew(Disp disp)
#else
Addr AddrProgramNew(disp)
Disp disp;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrProgram *slot = &newAddr->U.ProgramSlot;
  newAddr->tag = AddrProgramTag;
  slot->disp = disp;
  return (newAddr);
}

/*
**
** AddrRegisterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterNew(DataType dt,int number)
#else
Addr AddrRegisterNew(dt,number)
DataType dt;
int number;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrRegister *slot = &newAddr->U.RegisterSlot;
  newAddr->tag = AddrRegisterTag;
  slot->dt = dt;
  slot->number = number;
  return (newAddr);
}

/*
**
** AddrRegisterRelativeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterRelativeNew(DataType dt,Disp disp,int number)
#else
Addr AddrRegisterRelativeNew(dt,disp,number)
DataType dt;
Disp disp;
int number;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrRegisterRelative *slot = &newAddr->U.RegisterRelativeSlot;
  newAddr->tag = AddrRegisterRelativeTag;
  slot->dt = dt;
  slot->disp = disp;
  slot->number = number;
  return (newAddr);
}

/*
**
** AddrStackNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackNew(Disp disp)
#else
Addr AddrStackNew(disp)
Disp disp;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStack *slot = &newAddr->U.StackSlot;
  newAddr->tag = AddrStackTag;
  slot->disp = disp;
  return (newAddr);
}

/*
**
** AddrStackRelativeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackRelativeNew(Disp disp2,Disp disp1)
#else
Addr AddrStackRelativeNew(disp2,disp1)
Disp disp2;
Disp disp1;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStackRelative *slot = &newAddr->U.StackRelativeSlot;
  newAddr->tag = AddrStackRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (newAddr);
}

/*
**
** AddrStaticNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticNew(Disp disp)
#else
Addr AddrStaticNew(disp)
Disp disp;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStatic *slot = &newAddr->U.StaticSlot;
  newAddr->tag = AddrStaticTag;
  slot->disp = disp;
  return (newAddr);
}

/*
**
** AddrStaticRelativeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticRelativeNew(Disp disp2,Disp disp1)
#else
Addr AddrStaticRelativeNew(disp2,disp1)
Disp disp2;
Disp disp1;
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  struct _AddrStaticRelative *slot = &newAddr->U.StaticRelativeSlot;
  newAddr->tag = AddrStaticRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (newAddr);
}

/*
**
** AddrTopOfStackNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrTopOfStackNew(void)
#else
Addr AddrTopOfStackNew()
#endif
{
  Addr newAddr = (Addr)Allocate(sizeof(_Addr));
  newAddr->tag = AddrTopOfStackTag;
  return (newAddr);
}

/*
**
** AddrAbsoluteUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrAbsoluteUpdate(Addr oldAddr,Disp disp)
#else
Addr AddrAbsoluteUpdate(oldAddr,disp)
Addr oldAddr;
Disp disp;
#endif
{
  struct _AddrAbsolute *slot = &oldAddr->U.AbsoluteSlot;
  oldAddr->tag = AddrAbsoluteTag;
  slot->disp = disp;
  return (oldAddr);
}

/*
**
** AddrExternalUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrExternalUpdate(Addr oldAddr,Disp disp1,Disp disp2)
#else
Addr AddrExternalUpdate(oldAddr,disp1,disp2)
Addr oldAddr;
Disp disp1;
Disp disp2;
#endif
{
  struct _AddrExternal *slot = &oldAddr->U.ExternalSlot;
  oldAddr->tag = AddrExternalTag;
  slot->disp1 = disp1;
  slot->disp2 = disp2;
  return (oldAddr);
}

/*
**
** AddrFrameUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameUpdate(Addr oldAddr,Disp disp)
#else
Addr AddrFrameUpdate(oldAddr,disp)
Addr oldAddr;
Disp disp;
#endif
{
  struct _AddrFrame *slot = &oldAddr->U.FrameSlot;
  oldAddr->tag = AddrFrameTag;
  slot->disp = disp;
  return (oldAddr);
}

/*
**
** AddrFrameRelativeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrFrameRelativeUpdate(Addr oldAddr,Disp disp2,Disp disp1)
#else
Addr AddrFrameRelativeUpdate(oldAddr,disp2,disp1)
Addr oldAddr;
Disp disp2;
Disp disp1;
#endif
{
  struct _AddrFrameRelative *slot = &oldAddr->U.FrameRelativeSlot;
  oldAddr->tag = AddrFrameRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (oldAddr);
}

/*
**
** AddrImmediateUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrImmediateUpdate(Addr oldAddr,MValue value)
#else
Addr AddrImmediateUpdate(oldAddr,value)
Addr oldAddr;
MValue value;
#endif
{
  struct _AddrImmediate *slot = &oldAddr->U.ImmediateSlot;
  oldAddr->tag = AddrImmediateTag;
  slot->value = value;
  return (oldAddr);
}

/*
**
** AddrProgramUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrProgramUpdate(Addr oldAddr,Disp disp)
#else
Addr AddrProgramUpdate(oldAddr,disp)
Addr oldAddr;
Disp disp;
#endif
{
  struct _AddrProgram *slot = &oldAddr->U.ProgramSlot;
  oldAddr->tag = AddrProgramTag;
  slot->disp = disp;
  return (oldAddr);
}

/*
**
** AddrRegisterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterUpdate(Addr oldAddr,DataType dt,int number)
#else
Addr AddrRegisterUpdate(oldAddr,dt,number)
Addr oldAddr;
DataType dt;
int number;
#endif
{
  struct _AddrRegister *slot = &oldAddr->U.RegisterSlot;
  oldAddr->tag = AddrRegisterTag;
  slot->dt = dt;
  slot->number = number;
  return (oldAddr);
}

/*
**
** AddrRegisterRelativeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrRegisterRelativeUpdate(Addr oldAddr,DataType dt,Disp disp,int number)
#else
Addr AddrRegisterRelativeUpdate(oldAddr,dt,disp,number)
Addr oldAddr;
DataType dt;
Disp disp;
int number;
#endif
{
  struct _AddrRegisterRelative *slot = &oldAddr->U.RegisterRelativeSlot;
  oldAddr->tag = AddrRegisterRelativeTag;
  slot->dt = dt;
  slot->disp = disp;
  slot->number = number;
  return (oldAddr);
}

/*
**
** AddrStackUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackUpdate(Addr oldAddr,Disp disp)
#else
Addr AddrStackUpdate(oldAddr,disp)
Addr oldAddr;
Disp disp;
#endif
{
  struct _AddrStack *slot = &oldAddr->U.StackSlot;
  oldAddr->tag = AddrStackTag;
  slot->disp = disp;
  return (oldAddr);
}

/*
**
** AddrStackRelativeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStackRelativeUpdate(Addr oldAddr,Disp disp2,Disp disp1)
#else
Addr AddrStackRelativeUpdate(oldAddr,disp2,disp1)
Addr oldAddr;
Disp disp2;
Disp disp1;
#endif
{
  struct _AddrStackRelative *slot = &oldAddr->U.StackRelativeSlot;
  oldAddr->tag = AddrStackRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (oldAddr);
}

/*
**
** AddrStaticUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticUpdate(Addr oldAddr,Disp disp)
#else
Addr AddrStaticUpdate(oldAddr,disp)
Addr oldAddr;
Disp disp;
#endif
{
  struct _AddrStatic *slot = &oldAddr->U.StaticSlot;
  oldAddr->tag = AddrStaticTag;
  slot->disp = disp;
  return (oldAddr);
}

/*
**
** AddrStaticRelativeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrStaticRelativeUpdate(Addr oldAddr,Disp disp2,Disp disp1)
#else
Addr AddrStaticRelativeUpdate(oldAddr,disp2,disp1)
Addr oldAddr;
Disp disp2;
Disp disp1;
#endif
{
  struct _AddrStaticRelative *slot = &oldAddr->U.StaticRelativeSlot;
  oldAddr->tag = AddrStaticRelativeTag;
  slot->disp2 = disp2;
  slot->disp1 = disp1;
  return (oldAddr);
}

/*
**
** AddrTopOfStackUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Addr AddrTopOfStackUpdate(Addr oldAddr)
#else
Addr AddrTopOfStackUpdate(oldAddr)
Addr oldAddr;
#endif
{
  oldAddr->tag = AddrTopOfStackTag;
  return (oldAddr);
}

/*
**
** CGContextLoopDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextLoopDuplicate(CGContext oldCGContext)
#else
CGContext CGContextLoopDuplicate(oldCGContext)
CGContext oldCGContext;
#endif
{
  CGContext newCGContext = (CGContext)Allocate(sizeof(_CGContext));
  struct _CGContextLoop *slot = &newCGContext->U.LoopSlot;
  struct _CGContextLoop *oldslot = &oldCGContext->U.LoopSlot;
  newCGContext->tag = CGContextLoopTag;
  slot->e = oldslot->e;
  slot->saveState1 = oldslot->saveState1;
  slot->saveState2 = oldslot->saveState2;
  slot->endLabel = oldslot->endLabel;
  newCGContext->c = oldCGContext->c;
  return (newCGContext);
}

/*
**
** CGContextProcDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextProcDuplicate(CGContext oldCGContext)
#else
CGContext CGContextProcDuplicate(oldCGContext)
CGContext oldCGContext;
#endif
{
  CGContext newCGContext = (CGContext)Allocate(sizeof(_CGContext));
  struct _CGContextProc *slot = &newCGContext->U.ProcSlot;
  struct _CGContextProc *oldslot = &oldCGContext->U.ProcSlot;
  newCGContext->tag = CGContextProcTag;
  slot->p = oldslot->p;
  slot->saveState1 = oldslot->saveState1;
  slot->saveState2 = oldslot->saveState2;
  slot->endLabel = oldslot->endLabel;
  slot->dataLabel = oldslot->dataLabel;
  newCGContext->c = oldCGContext->c;
  return (newCGContext);
}

/*
**
** CGContextLoopNew
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextLoopNew(Expression e,int saveState1,int saveState2,int endLabel,CGContext c)
#else
CGContext CGContextLoopNew(e,saveState1,saveState2,endLabel,c)
Expression e;
int saveState1;
int saveState2;
int endLabel;
CGContext c;
#endif
{
  CGContext newCGContext = (CGContext)Allocate(sizeof(_CGContext));
  struct _CGContextLoop *slot = &newCGContext->U.LoopSlot;
  newCGContext->tag = CGContextLoopTag;
  slot->e = e;
  slot->saveState1 = saveState1;
  slot->saveState2 = saveState2;
  slot->endLabel = endLabel;
  newCGContext->c = c;
  return (newCGContext);
}

/*
**
** CGContextProcNew
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextProcNew(CGProc p,int saveState1,int saveState2,int endLabel,int dataLabel,CGContext c)
#else
CGContext CGContextProcNew(p,saveState1,saveState2,endLabel,dataLabel,c)
CGProc p;
int saveState1;
int saveState2;
int endLabel;
int dataLabel;
CGContext c;
#endif
{
  CGContext newCGContext = (CGContext)Allocate(sizeof(_CGContext));
  struct _CGContextProc *slot = &newCGContext->U.ProcSlot;
  newCGContext->tag = CGContextProcTag;
  slot->p = p;
  slot->saveState1 = saveState1;
  slot->saveState2 = saveState2;
  slot->endLabel = endLabel;
  slot->dataLabel = dataLabel;
  newCGContext->c = c;
  return (newCGContext);
}

/*
**
** CGContextLoopUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextLoopUpdate(CGContext oldCGContext,Expression e,int saveState1,int saveState2,int endLabel,CGContext c)
#else
CGContext CGContextLoopUpdate(oldCGContext,e,saveState1,saveState2,endLabel,c)
CGContext oldCGContext;
Expression e;
int saveState1;
int saveState2;
int endLabel;
CGContext c;
#endif
{
  struct _CGContextLoop *slot = &oldCGContext->U.LoopSlot;
  oldCGContext->tag = CGContextLoopTag;
  slot->e = e;
  slot->saveState1 = saveState1;
  slot->saveState2 = saveState2;
  slot->endLabel = endLabel;
  oldCGContext->c = c;
  return (oldCGContext);
}

/*
**
** CGContextProcUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGContext CGContextProcUpdate(CGContext oldCGContext,CGProc p,int saveState1,int saveState2,int endLabel,int dataLabel,CGContext c)
#else
CGContext CGContextProcUpdate(oldCGContext,p,saveState1,saveState2,endLabel,dataLabel,c)
CGContext oldCGContext;
CGProc p;
int saveState1;
int saveState2;
int endLabel;
int dataLabel;
CGContext c;
#endif
{
  struct _CGContextProc *slot = &oldCGContext->U.ProcSlot;
  oldCGContext->tag = CGContextProcTag;
  slot->p = p;
  slot->saveState1 = saveState1;
  slot->saveState2 = saveState2;
  slot->endLabel = endLabel;
  slot->dataLabel = dataLabel;
  oldCGContext->c = c;
  return (oldCGContext);
}

/*
**
** CGProcDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGProc CGProcDuplicate(CGProc oldCGProc)
#else
CGProc CGProcDuplicate(oldCGProc)
CGProc oldCGProc;
#endif
{
  CGProc newCGProc = (CGProc)Allocate(sizeof(_CGProc));
  newCGProc->name = oldCGProc->name;
  newCGProc->paramQ = oldCGProc->paramQ;
  newCGProc->localQ = oldCGProc->localQ;
  newCGProc->staticQ = oldCGProc->staticQ;
  newCGProc->init = oldCGProc->init;
  newCGProc->body = oldCGProc->body;
  newCGProc->type = oldCGProc->type;
  newCGProc->code = oldCGProc->code;
  newCGProc->constQ = oldCGProc->constQ;
  newCGProc->localSize = oldCGProc->localSize;
  newCGProc->paramSize = oldCGProc->paramSize;
  newCGProc->tempSize = oldCGProc->tempSize;
  return (newCGProc);
}

/*
**
** CGProcNew
**
*/
PUBLIC
#ifdef __ANSI_C__
CGProc CGProcNew(Token name,Queue paramQ,Queue localQ,Queue staticQ,Expression init,Expression body,Type type)
#else
CGProc CGProcNew(name,paramQ,localQ,staticQ,init,body,type)
Token name;
Queue paramQ;
Queue localQ;
Queue staticQ;
Expression init;
Expression body;
Type type;
#endif
{
  CGProc newCGProc = (CGProc)Allocate(sizeof(_CGProc));
  newCGProc->name = name;
  newCGProc->paramQ = paramQ;
  newCGProc->localQ = localQ;
  newCGProc->staticQ = staticQ;
  newCGProc->init = init;
  newCGProc->body = body;
  newCGProc->type = type;
  newCGProc->code = (Queue)0;
  newCGProc->constQ = (Queue)0;
  newCGProc->localSize = (int)0;
  newCGProc->paramSize = (int)0;
  newCGProc->tempSize = (int)0;
  return (newCGProc);
}

/*
**
** CGProcUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGProc CGProcUpdate(CGProc oldCGProc,Token name,Queue paramQ,Queue localQ,Queue staticQ,Expression init,Expression body,Type type)
#else
CGProc CGProcUpdate(oldCGProc,name,paramQ,localQ,staticQ,init,body,type)
CGProc oldCGProc;
Token name;
Queue paramQ;
Queue localQ;
Queue staticQ;
Expression init;
Expression body;
Type type;
#endif
{
  oldCGProc->name = name;
  oldCGProc->paramQ = paramQ;
  oldCGProc->localQ = localQ;
  oldCGProc->staticQ = staticQ;
  oldCGProc->init = init;
  oldCGProc->body = body;
  oldCGProc->type = type;
  return (oldCGProc);
}

/*
**
** CGVarDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGVar CGVarDuplicate(CGVar oldCGVar)
#else
CGVar CGVarDuplicate(oldCGVar)
CGVar oldCGVar;
#endif
{
  CGVar newCGVar = (CGVar)Allocate(sizeof(_CGVar));
  newCGVar->name = oldCGVar->name;
  newCGVar->type = oldCGVar->type;
  newCGVar->align = oldCGVar->align;
  newCGVar->location = oldCGVar->location;
  newCGVar->offset = oldCGVar->offset;
  newCGVar->position = oldCGVar->position;
  newCGVar->size = oldCGVar->size;
  newCGVar->value = oldCGVar->value;
  return (newCGVar);
}

/*
**
** CGVarNew
**
*/
PUBLIC
#ifdef __ANSI_C__
CGVar CGVarNew(Token name,Type type)
#else
CGVar CGVarNew(name,type)
Token name;
Type type;
#endif
{
  CGVar newCGVar = (CGVar)Allocate(sizeof(_CGVar));
  newCGVar->name = name;
  newCGVar->type = type;
  newCGVar->align = (int)0;
  newCGVar->location = (LocType)0;
  newCGVar->offset = (int)0;
  newCGVar->position = (int)0;
  newCGVar->size = (int)0;
  newCGVar->value = (MValue)0;
  return (newCGVar);
}

/*
**
** CGVarUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
CGVar CGVarUpdate(CGVar oldCGVar,Token name,Type type)
#else
CGVar CGVarUpdate(oldCGVar,name,type)
CGVar oldCGVar;
Token name;
Type type;
#endif
{
  oldCGVar->name = name;
  oldCGVar->type = type;
  return (oldCGVar);
}

/*
**
** DispDataLabelDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispDataLabelDuplicate(Disp oldDisp)
#else
Disp DispDataLabelDuplicate(oldDisp)
Disp oldDisp;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispDataLabel *slot = &newDisp->U.DataLabelSlot;
  struct _DispDataLabel *oldslot = &oldDisp->U.DataLabelSlot;
  newDisp->tag = DispDataLabelTag;
  slot->number = oldslot->number;
  return (newDisp);
}

/*
**
** DispNamedLabelDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNamedLabelDuplicate(Disp oldDisp)
#else
Disp DispNamedLabelDuplicate(oldDisp)
Disp oldDisp;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispNamedLabel *slot = &newDisp->U.NamedLabelSlot;
  struct _DispNamedLabel *oldslot = &oldDisp->U.NamedLabelSlot;
  newDisp->tag = DispNamedLabelTag;
  slot->name = oldslot->name;
  return (newDisp);
}

/*
**
** DispNumberDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNumberDuplicate(Disp oldDisp)
#else
Disp DispNumberDuplicate(oldDisp)
Disp oldDisp;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispNumber *slot = &newDisp->U.NumberSlot;
  struct _DispNumber *oldslot = &oldDisp->U.NumberSlot;
  newDisp->tag = DispNumberTag;
  slot->number = oldslot->number;
  return (newDisp);
}

/*
**
** DispTempLabelDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispTempLabelDuplicate(Disp oldDisp)
#else
Disp DispTempLabelDuplicate(oldDisp)
Disp oldDisp;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispTempLabel *slot = &newDisp->U.TempLabelSlot;
  struct _DispTempLabel *oldslot = &oldDisp->U.TempLabelSlot;
  newDisp->tag = DispTempLabelTag;
  slot->number = oldslot->number;
  return (newDisp);
}

/*
**
** DispDataLabelNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispDataLabelNew(int number)
#else
Disp DispDataLabelNew(number)
int number;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispDataLabel *slot = &newDisp->U.DataLabelSlot;
  newDisp->tag = DispDataLabelTag;
  slot->number = number;
  return (newDisp);
}

/*
**
** DispNamedLabelNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNamedLabelNew(char *name)
#else
Disp DispNamedLabelNew(name)
char *name;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispNamedLabel *slot = &newDisp->U.NamedLabelSlot;
  newDisp->tag = DispNamedLabelTag;
  slot->name = name;
  return (newDisp);
}

/*
**
** DispNumberNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNumberNew(int number)
#else
Disp DispNumberNew(number)
int number;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispNumber *slot = &newDisp->U.NumberSlot;
  newDisp->tag = DispNumberTag;
  slot->number = number;
  return (newDisp);
}

/*
**
** DispTempLabelNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispTempLabelNew(int number)
#else
Disp DispTempLabelNew(number)
int number;
#endif
{
  Disp newDisp = (Disp)Allocate(sizeof(_Disp));
  struct _DispTempLabel *slot = &newDisp->U.TempLabelSlot;
  newDisp->tag = DispTempLabelTag;
  slot->number = number;
  return (newDisp);
}

/*
**
** DispDataLabelUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispDataLabelUpdate(Disp oldDisp,int number)
#else
Disp DispDataLabelUpdate(oldDisp,number)
Disp oldDisp;
int number;
#endif
{
  struct _DispDataLabel *slot = &oldDisp->U.DataLabelSlot;
  oldDisp->tag = DispDataLabelTag;
  slot->number = number;
  return (oldDisp);
}

/*
**
** DispNamedLabelUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNamedLabelUpdate(Disp oldDisp,char *name)
#else
Disp DispNamedLabelUpdate(oldDisp,name)
Disp oldDisp;
char *name;
#endif
{
  struct _DispNamedLabel *slot = &oldDisp->U.NamedLabelSlot;
  oldDisp->tag = DispNamedLabelTag;
  slot->name = name;
  return (oldDisp);
}

/*
**
** DispNumberUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispNumberUpdate(Disp oldDisp,int number)
#else
Disp DispNumberUpdate(oldDisp,number)
Disp oldDisp;
int number;
#endif
{
  struct _DispNumber *slot = &oldDisp->U.NumberSlot;
  oldDisp->tag = DispNumberTag;
  slot->number = number;
  return (oldDisp);
}

/*
**
** DispTempLabelUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Disp DispTempLabelUpdate(Disp oldDisp,int number)
#else
Disp DispTempLabelUpdate(oldDisp,number)
Disp oldDisp;
int number;
#endif
{
  struct _DispTempLabel *slot = &oldDisp->U.TempLabelSlot;
  oldDisp->tag = DispTempLabelTag;
  slot->number = number;
  return (oldDisp);
}

/*
**
** InsnAlignDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnAlignDuplicate(Insn oldInsn)
#else
Insn InsnAlignDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnAlign *slot = &newInsn->U.AlignSlot;
  struct _InsnAlign *oldslot = &oldInsn->U.AlignSlot;
  newInsn->tag = InsnAlignTag;
  slot->number = oldslot->number;
  return (newInsn);
}

/*
**
** InsnCommentDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnCommentDuplicate(Insn oldInsn)
#else
Insn InsnCommentDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnComment *slot = &newInsn->U.CommentSlot;
  struct _InsnComment *oldslot = &oldInsn->U.CommentSlot;
  newInsn->tag = InsnCommentTag;
  slot->text = oldslot->text;
  return (newInsn);
}

/*
**
** InsnDataModeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDataModeDuplicate(Insn oldInsn)
#else
Insn InsnDataModeDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  newInsn->tag = InsnDataModeTag;
  return (newInsn);
}

/*
**
** InsnDocumentDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDocumentDuplicate(Insn oldInsn)
#else
Insn InsnDocumentDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnDocument *slot = &newInsn->U.DocumentSlot;
  struct _InsnDocument *oldslot = &oldInsn->U.DocumentSlot;
  newInsn->tag = InsnDocumentTag;
  slot->var = oldslot->var;
  return (newInsn);
}

/*
**
** InsnGlobalDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnGlobalDuplicate(Insn oldInsn)
#else
Insn InsnGlobalDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnGlobal *slot = &newInsn->U.GlobalSlot;
  struct _InsnGlobal *oldslot = &oldInsn->U.GlobalSlot;
  newInsn->tag = InsnGlobalTag;
  slot->label = oldslot->label;
  return (newInsn);
}

/*
**
** InsnMInsnDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnMInsnDuplicate(Insn oldInsn)
#else
Insn InsnMInsnDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnMInsn *slot = &newInsn->U.MInsnSlot;
  struct _InsnMInsn *oldslot = &oldInsn->U.MInsnSlot;
  newInsn->tag = InsnMInsnTag;
  slot->mi = oldslot->mi;
  return (newInsn);
}

/*
**
** InsnNamedDataDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedDataDuplicate(Insn oldInsn)
#else
Insn InsnNamedDataDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnNamedData *slot = &newInsn->U.NamedDataSlot;
  struct _InsnNamedData *oldslot = &oldInsn->U.NamedDataSlot;
  newInsn->tag = InsnNamedDataTag;
  slot->name = oldslot->name;
  slot->value = oldslot->value;
  return (newInsn);
}

/*
**
** InsnNamedLabelDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedLabelDuplicate(Insn oldInsn)
#else
Insn InsnNamedLabelDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnNamedLabel *slot = &newInsn->U.NamedLabelSlot;
  struct _InsnNamedLabel *oldslot = &oldInsn->U.NamedLabelSlot;
  newInsn->tag = InsnNamedLabelTag;
  slot->name = oldslot->name;
  return (newInsn);
}

/*
**
** InsnQueueDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnQueueDuplicate(Insn oldInsn)
#else
Insn InsnQueueDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnQueue *slot = &newInsn->U.QueueSlot;
  struct _InsnQueue *oldslot = &oldInsn->U.QueueSlot;
  newInsn->tag = InsnQueueTag;
  slot->queue = oldslot->queue;
  return (newInsn);
}

/*
**
** InsnRSDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnRSDuplicate(Insn oldInsn)
#else
Insn InsnRSDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnRS *slot = &newInsn->U.RSSlot;
  struct _InsnRS *oldslot = &oldInsn->U.RSSlot;
  newInsn->tag = InsnRSTag;
  slot->number1 = oldslot->number1;
  slot->number2 = oldslot->number2;
  return (newInsn);
}

/*
**
** InsnSSDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnSSDuplicate(Insn oldInsn)
#else
Insn InsnSSDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnSS *slot = &newInsn->U.SSSlot;
  struct _InsnSS *oldslot = &oldInsn->U.SSSlot;
  newInsn->tag = InsnSSTag;
  slot->number1 = oldslot->number1;
  slot->number2 = oldslot->number2;
  return (newInsn);
}

/*
**
** InsnTempDataDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempDataDuplicate(Insn oldInsn)
#else
Insn InsnTempDataDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnTempData *slot = &newInsn->U.TempDataSlot;
  struct _InsnTempData *oldslot = &oldInsn->U.TempDataSlot;
  newInsn->tag = InsnTempDataTag;
  slot->number = oldslot->number;
  slot->value = oldslot->value;
  return (newInsn);
}

/*
**
** InsnTempLabelDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempLabelDuplicate(Insn oldInsn)
#else
Insn InsnTempLabelDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnTempLabel *slot = &newInsn->U.TempLabelSlot;
  struct _InsnTempLabel *oldslot = &oldInsn->U.TempLabelSlot;
  newInsn->tag = InsnTempLabelTag;
  slot->number = oldslot->number;
  return (newInsn);
}

/*
**
** InsnTextModeDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTextModeDuplicate(Insn oldInsn)
#else
Insn InsnTextModeDuplicate(oldInsn)
Insn oldInsn;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  newInsn->tag = InsnTextModeTag;
  return (newInsn);
}

/*
**
** InsnAlignNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnAlignNew(int number)
#else
Insn InsnAlignNew(number)
int number;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnAlign *slot = &newInsn->U.AlignSlot;
  newInsn->tag = InsnAlignTag;
  slot->number = number;
  return (newInsn);
}

/*
**
** InsnCommentNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnCommentNew(char *text)
#else
Insn InsnCommentNew(text)
char *text;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnComment *slot = &newInsn->U.CommentSlot;
  newInsn->tag = InsnCommentTag;
  slot->text = text;
  return (newInsn);
}

/*
**
** InsnDataModeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDataModeNew(void)
#else
Insn InsnDataModeNew()
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  newInsn->tag = InsnDataModeTag;
  return (newInsn);
}

/*
**
** InsnDocumentNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDocumentNew(CGVar var)
#else
Insn InsnDocumentNew(var)
CGVar var;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnDocument *slot = &newInsn->U.DocumentSlot;
  newInsn->tag = InsnDocumentTag;
  slot->var = var;
  return (newInsn);
}

/*
**
** InsnGlobalNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnGlobalNew(char *label)
#else
Insn InsnGlobalNew(label)
char *label;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnGlobal *slot = &newInsn->U.GlobalSlot;
  newInsn->tag = InsnGlobalTag;
  slot->label = label;
  return (newInsn);
}

/*
**
** InsnMInsnNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnMInsnNew(MInsn mi)
#else
Insn InsnMInsnNew(mi)
MInsn mi;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnMInsn *slot = &newInsn->U.MInsnSlot;
  newInsn->tag = InsnMInsnTag;
  slot->mi = mi;
  return (newInsn);
}

/*
**
** InsnNamedDataNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedDataNew(char *name,MValue value)
#else
Insn InsnNamedDataNew(name,value)
char *name;
MValue value;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnNamedData *slot = &newInsn->U.NamedDataSlot;
  newInsn->tag = InsnNamedDataTag;
  slot->name = name;
  slot->value = value;
  return (newInsn);
}

/*
**
** InsnNamedLabelNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedLabelNew(char *name)
#else
Insn InsnNamedLabelNew(name)
char *name;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnNamedLabel *slot = &newInsn->U.NamedLabelSlot;
  newInsn->tag = InsnNamedLabelTag;
  slot->name = name;
  return (newInsn);
}

/*
**
** InsnQueueNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnQueueNew(Queue queue)
#else
Insn InsnQueueNew(queue)
Queue queue;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnQueue *slot = &newInsn->U.QueueSlot;
  newInsn->tag = InsnQueueTag;
  slot->queue = queue;
  return (newInsn);
}

/*
**
** InsnRSNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnRSNew(int number1,int number2)
#else
Insn InsnRSNew(number1,number2)
int number1;
int number2;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnRS *slot = &newInsn->U.RSSlot;
  newInsn->tag = InsnRSTag;
  slot->number1 = number1;
  slot->number2 = number2;
  return (newInsn);
}

/*
**
** InsnSSNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnSSNew(int number1,int number2)
#else
Insn InsnSSNew(number1,number2)
int number1;
int number2;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnSS *slot = &newInsn->U.SSSlot;
  newInsn->tag = InsnSSTag;
  slot->number1 = number1;
  slot->number2 = number2;
  return (newInsn);
}

/*
**
** InsnTempDataNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempDataNew(int number,MValue value)
#else
Insn InsnTempDataNew(number,value)
int number;
MValue value;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnTempData *slot = &newInsn->U.TempDataSlot;
  newInsn->tag = InsnTempDataTag;
  slot->number = number;
  slot->value = value;
  return (newInsn);
}

/*
**
** InsnTempLabelNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempLabelNew(int number)
#else
Insn InsnTempLabelNew(number)
int number;
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  struct _InsnTempLabel *slot = &newInsn->U.TempLabelSlot;
  newInsn->tag = InsnTempLabelTag;
  slot->number = number;
  return (newInsn);
}

/*
**
** InsnTextModeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTextModeNew(void)
#else
Insn InsnTextModeNew()
#endif
{
  Insn newInsn = (Insn)Allocate(sizeof(_Insn));
  newInsn->tag = InsnTextModeTag;
  return (newInsn);
}

/*
**
** InsnAlignUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnAlignUpdate(Insn oldInsn,int number)
#else
Insn InsnAlignUpdate(oldInsn,number)
Insn oldInsn;
int number;
#endif
{
  struct _InsnAlign *slot = &oldInsn->U.AlignSlot;
  oldInsn->tag = InsnAlignTag;
  slot->number = number;
  return (oldInsn);
}

/*
**
** InsnCommentUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnCommentUpdate(Insn oldInsn,char *text)
#else
Insn InsnCommentUpdate(oldInsn,text)
Insn oldInsn;
char *text;
#endif
{
  struct _InsnComment *slot = &oldInsn->U.CommentSlot;
  oldInsn->tag = InsnCommentTag;
  slot->text = text;
  return (oldInsn);
}

/*
**
** InsnDataModeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDataModeUpdate(Insn oldInsn)
#else
Insn InsnDataModeUpdate(oldInsn)
Insn oldInsn;
#endif
{
  oldInsn->tag = InsnDataModeTag;
  return (oldInsn);
}

/*
**
** InsnDocumentUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnDocumentUpdate(Insn oldInsn,CGVar var)
#else
Insn InsnDocumentUpdate(oldInsn,var)
Insn oldInsn;
CGVar var;
#endif
{
  struct _InsnDocument *slot = &oldInsn->U.DocumentSlot;
  oldInsn->tag = InsnDocumentTag;
  slot->var = var;
  return (oldInsn);
}

/*
**
** InsnGlobalUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnGlobalUpdate(Insn oldInsn,char *label)
#else
Insn InsnGlobalUpdate(oldInsn,label)
Insn oldInsn;
char *label;
#endif
{
  struct _InsnGlobal *slot = &oldInsn->U.GlobalSlot;
  oldInsn->tag = InsnGlobalTag;
  slot->label = label;
  return (oldInsn);
}

/*
**
** InsnMInsnUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnMInsnUpdate(Insn oldInsn,MInsn mi)
#else
Insn InsnMInsnUpdate(oldInsn,mi)
Insn oldInsn;
MInsn mi;
#endif
{
  struct _InsnMInsn *slot = &oldInsn->U.MInsnSlot;
  oldInsn->tag = InsnMInsnTag;
  slot->mi = mi;
  return (oldInsn);
}

/*
**
** InsnNamedDataUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedDataUpdate(Insn oldInsn,char *name,MValue value)
#else
Insn InsnNamedDataUpdate(oldInsn,name,value)
Insn oldInsn;
char *name;
MValue value;
#endif
{
  struct _InsnNamedData *slot = &oldInsn->U.NamedDataSlot;
  oldInsn->tag = InsnNamedDataTag;
  slot->name = name;
  slot->value = value;
  return (oldInsn);
}

/*
**
** InsnNamedLabelUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnNamedLabelUpdate(Insn oldInsn,char *name)
#else
Insn InsnNamedLabelUpdate(oldInsn,name)
Insn oldInsn;
char *name;
#endif
{
  struct _InsnNamedLabel *slot = &oldInsn->U.NamedLabelSlot;
  oldInsn->tag = InsnNamedLabelTag;
  slot->name = name;
  return (oldInsn);
}

/*
**
** InsnQueueUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnQueueUpdate(Insn oldInsn,Queue queue)
#else
Insn InsnQueueUpdate(oldInsn,queue)
Insn oldInsn;
Queue queue;
#endif
{
  struct _InsnQueue *slot = &oldInsn->U.QueueSlot;
  oldInsn->tag = InsnQueueTag;
  slot->queue = queue;
  return (oldInsn);
}

/*
**
** InsnRSUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnRSUpdate(Insn oldInsn,int number1,int number2)
#else
Insn InsnRSUpdate(oldInsn,number1,number2)
Insn oldInsn;
int number1;
int number2;
#endif
{
  struct _InsnRS *slot = &oldInsn->U.RSSlot;
  oldInsn->tag = InsnRSTag;
  slot->number1 = number1;
  slot->number2 = number2;
  return (oldInsn);
}

/*
**
** InsnSSUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnSSUpdate(Insn oldInsn,int number1,int number2)
#else
Insn InsnSSUpdate(oldInsn,number1,number2)
Insn oldInsn;
int number1;
int number2;
#endif
{
  struct _InsnSS *slot = &oldInsn->U.SSSlot;
  oldInsn->tag = InsnSSTag;
  slot->number1 = number1;
  slot->number2 = number2;
  return (oldInsn);
}

/*
**
** InsnTempDataUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempDataUpdate(Insn oldInsn,int number,MValue value)
#else
Insn InsnTempDataUpdate(oldInsn,number,value)
Insn oldInsn;
int number;
MValue value;
#endif
{
  struct _InsnTempData *slot = &oldInsn->U.TempDataSlot;
  oldInsn->tag = InsnTempDataTag;
  slot->number = number;
  slot->value = value;
  return (oldInsn);
}

/*
**
** InsnTempLabelUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTempLabelUpdate(Insn oldInsn,int number)
#else
Insn InsnTempLabelUpdate(oldInsn,number)
Insn oldInsn;
int number;
#endif
{
  struct _InsnTempLabel *slot = &oldInsn->U.TempLabelSlot;
  oldInsn->tag = InsnTempLabelTag;
  slot->number = number;
  return (oldInsn);
}

/*
**
** InsnTextModeUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
Insn InsnTextModeUpdate(Insn oldInsn)
#else
Insn InsnTextModeUpdate(oldInsn)
Insn oldInsn;
#endif
{
  oldInsn->tag = InsnTextModeTag;
  return (oldInsn);
}

/*
**
** MInsnAbsoluteValueDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAbsoluteValueDuplicate(MInsn oldMInsn)
#else
MInsn MInsnAbsoluteValueDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAbsoluteValue *slot = &newMInsn->U.AbsoluteValueSlot;
  struct _MInsnAbsoluteValue *oldslot = &oldMInsn->U.AbsoluteValueSlot;
  newMInsn->tag = MInsnAbsoluteValueTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnAddDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddDuplicate(MInsn oldMInsn)
#else
MInsn MInsnAddDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAdd *slot = &newMInsn->U.AddSlot;
  struct _MInsnAdd *oldslot = &oldMInsn->U.AddSlot;
  newMInsn->tag = MInsnAddTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnAddQuickDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddQuickDuplicate(MInsn oldMInsn)
#else
MInsn MInsnAddQuickDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAddQuick *slot = &newMInsn->U.AddQuickSlot;
  struct _MInsnAddQuick *oldslot = &oldMInsn->U.AddQuickSlot;
  newMInsn->tag = MInsnAddQuickTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnAdjustStackPointerDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAdjustStackPointerDuplicate(MInsn oldMInsn)
#else
MInsn MInsnAdjustStackPointerDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAdjustStackPointer *slot = &newMInsn->U.AdjustStackPointerSlot;
  struct _MInsnAdjustStackPointer *oldslot = &oldMInsn->U.AdjustStackPointerSlot;
  newMInsn->tag = MInsnAdjustStackPointerTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  return (newMInsn);
}

/*
**
** MInsnAndDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAndDuplicate(MInsn oldMInsn)
#else
MInsn MInsnAndDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAnd *slot = &newMInsn->U.AndSlot;
  struct _MInsnAnd *oldslot = &oldMInsn->U.AndSlot;
  newMInsn->tag = MInsnAndTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnArithmeticComplementDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticComplementDuplicate(MInsn oldMInsn)
#else
MInsn MInsnArithmeticComplementDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnArithmeticComplement *slot = &newMInsn->U.ArithmeticComplementSlot;
  struct _MInsnArithmeticComplement *oldslot = &oldMInsn->U.ArithmeticComplementSlot;
  newMInsn->tag = MInsnArithmeticComplementTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnArithmeticShiftDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticShiftDuplicate(MInsn oldMInsn)
#else
MInsn MInsnArithmeticShiftDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnArithmeticShift *slot = &newMInsn->U.ArithmeticShiftSlot;
  struct _MInsnArithmeticShift *oldslot = &oldMInsn->U.ArithmeticShiftSlot;
  newMInsn->tag = MInsnArithmeticShiftTag;
  slot->dt = oldslot->dt;
  slot->count = oldslot->count;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnBranchDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchDuplicate(MInsn oldMInsn)
#else
MInsn MInsnBranchDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnBranch *slot = &newMInsn->U.BranchSlot;
  struct _MInsnBranch *oldslot = &oldMInsn->U.BranchSlot;
  newMInsn->tag = MInsnBranchTag;
  slot->cond = oldslot->cond;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnBranchToSubroutineDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchToSubroutineDuplicate(MInsn oldMInsn)
#else
MInsn MInsnBranchToSubroutineDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnBranchToSubroutine *slot = &newMInsn->U.BranchToSubroutineSlot;
  struct _MInsnBranchToSubroutine *oldslot = &oldMInsn->U.BranchToSubroutineSlot;
  newMInsn->tag = MInsnBranchToSubroutineTag;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnCompareDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareDuplicate(MInsn oldMInsn)
#else
MInsn MInsnCompareDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompare *slot = &newMInsn->U.CompareSlot;
  struct _MInsnCompare *oldslot = &oldMInsn->U.CompareSlot;
  newMInsn->tag = MInsnCompareTag;
  slot->dt = oldslot->dt;
  slot->src1 = oldslot->src1;
  slot->src2 = oldslot->src2;
  return (newMInsn);
}

/*
**
** MInsnCompareMultipleDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareMultipleDuplicate(MInsn oldMInsn)
#else
MInsn MInsnCompareMultipleDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompareMultiple *slot = &newMInsn->U.CompareMultipleSlot;
  struct _MInsnCompareMultiple *oldslot = &oldMInsn->U.CompareMultipleSlot;
  newMInsn->tag = MInsnCompareMultipleTag;
  slot->dt = oldslot->dt;
  slot->block1 = oldslot->block1;
  slot->block2 = oldslot->block2;
  slot->length = oldslot->length;
  return (newMInsn);
}

/*
**
** MInsnCompareQuickDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareQuickDuplicate(MInsn oldMInsn)
#else
MInsn MInsnCompareQuickDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompareQuick *slot = &newMInsn->U.CompareQuickSlot;
  struct _MInsnCompareQuick *oldslot = &oldMInsn->U.CompareQuickSlot;
  newMInsn->tag = MInsnCompareQuickTag;
  slot->dt = oldslot->dt;
  slot->src1 = oldslot->src1;
  slot->src2 = oldslot->src2;
  return (newMInsn);
}

/*
**
** MInsnConvertDFDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertDFDuplicate(MInsn oldMInsn)
#else
MInsn MInsnConvertDFDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnConvertDF *slot = &newMInsn->U.ConvertDFSlot;
  struct _MInsnConvertDF *oldslot = &oldMInsn->U.ConvertDFSlot;
  newMInsn->tag = MInsnConvertDFTag;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnConvertFDDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertFDDuplicate(MInsn oldMInsn)
#else
MInsn MInsnConvertFDDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnConvertFD *slot = &newMInsn->U.ConvertFDSlot;
  struct _MInsnConvertFD *oldslot = &oldMInsn->U.ConvertFDSlot;
  newMInsn->tag = MInsnConvertFDTag;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnDivideDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnDivideDuplicate(MInsn oldMInsn)
#else
MInsn MInsnDivideDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnDivide *slot = &newMInsn->U.DivideSlot;
  struct _MInsnDivide *oldslot = &oldMInsn->U.DivideSlot;
  newMInsn->tag = MInsnDivideTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnEffectiveAddressDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEffectiveAddressDuplicate(MInsn oldMInsn)
#else
MInsn MInsnEffectiveAddressDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnEffectiveAddress *slot = &newMInsn->U.EffectiveAddressSlot;
  struct _MInsnEffectiveAddress *oldslot = &oldMInsn->U.EffectiveAddressSlot;
  newMInsn->tag = MInsnEffectiveAddressTag;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnEnterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEnterDuplicate(MInsn oldMInsn)
#else
MInsn MInsnEnterDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnEnter *slot = &newMInsn->U.EnterSlot;
  struct _MInsnEnter *oldslot = &oldMInsn->U.EnterSlot;
  newMInsn->tag = MInsnEnterTag;
  slot->regs = oldslot->regs;
  slot->disp = oldslot->disp;
  return (newMInsn);
}

/*
**
** MInsnExitDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnExitDuplicate(MInsn oldMInsn)
#else
MInsn MInsnExitDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnExit *slot = &newMInsn->U.ExitSlot;
  struct _MInsnExit *oldslot = &oldMInsn->U.ExitSlot;
  newMInsn->tag = MInsnExitTag;
  slot->regs = oldslot->regs;
  return (newMInsn);
}

/*
**
** MInsnJumpDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpDuplicate(MInsn oldMInsn)
#else
MInsn MInsnJumpDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnJump *slot = &newMInsn->U.JumpSlot;
  struct _MInsnJump *oldslot = &oldMInsn->U.JumpSlot;
  newMInsn->tag = MInsnJumpTag;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnJumpToSubroutineDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpToSubroutineDuplicate(MInsn oldMInsn)
#else
MInsn MInsnJumpToSubroutineDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnJumpToSubroutine *slot = &newMInsn->U.JumpToSubroutineSlot;
  struct _MInsnJumpToSubroutine *oldslot = &oldMInsn->U.JumpToSubroutineSlot;
  newMInsn->tag = MInsnJumpToSubroutineTag;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnLoadProcessorRegisterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLoadProcessorRegisterDuplicate(MInsn oldMInsn)
#else
MInsn MInsnLoadProcessorRegisterDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLoadProcessorRegister *slot = &newMInsn->U.LoadProcessorRegisterSlot;
  struct _MInsnLoadProcessorRegister *oldslot = &oldMInsn->U.LoadProcessorRegisterSlot;
  newMInsn->tag = MInsnLoadProcessorRegisterTag;
  slot->dt = oldslot->dt;
  slot->procreg = oldslot->procreg;
  slot->src = oldslot->src;
  return (newMInsn);
}

/*
**
** MInsnLogicalComplementDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalComplementDuplicate(MInsn oldMInsn)
#else
MInsn MInsnLogicalComplementDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLogicalComplement *slot = &newMInsn->U.LogicalComplementSlot;
  struct _MInsnLogicalComplement *oldslot = &oldMInsn->U.LogicalComplementSlot;
  newMInsn->tag = MInsnLogicalComplementTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnLogicalShiftDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalShiftDuplicate(MInsn oldMInsn)
#else
MInsn MInsnLogicalShiftDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLogicalShift *slot = &newMInsn->U.LogicalShiftSlot;
  struct _MInsnLogicalShift *oldslot = &oldMInsn->U.LogicalShiftSlot;
  newMInsn->tag = MInsnLogicalShiftTag;
  slot->dt = oldslot->dt;
  slot->count = oldslot->count;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnModulusDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnModulusDuplicate(MInsn oldMInsn)
#else
MInsn MInsnModulusDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnModulus *slot = &newMInsn->U.ModulusSlot;
  struct _MInsnModulus *oldslot = &oldMInsn->U.ModulusSlot;
  newMInsn->tag = MInsnModulusTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnMoveDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveDuplicate(MInsn oldMInsn)
#else
MInsn MInsnMoveDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMove *slot = &newMInsn->U.MoveSlot;
  struct _MInsnMove *oldslot = &oldMInsn->U.MoveSlot;
  newMInsn->tag = MInsnMoveTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnMoveMultipleDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveMultipleDuplicate(MInsn oldMInsn)
#else
MInsn MInsnMoveMultipleDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMoveMultiple *slot = &newMInsn->U.MoveMultipleSlot;
  struct _MInsnMoveMultiple *oldslot = &oldMInsn->U.MoveMultipleSlot;
  newMInsn->tag = MInsnMoveMultipleTag;
  slot->dt = oldslot->dt;
  slot->block1 = oldslot->block1;
  slot->block2 = oldslot->block2;
  slot->length = oldslot->length;
  return (newMInsn);
}

/*
**
** MInsnMoveQuickDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveQuickDuplicate(MInsn oldMInsn)
#else
MInsn MInsnMoveQuickDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMoveQuick *slot = &newMInsn->U.MoveQuickSlot;
  struct _MInsnMoveQuick *oldslot = &oldMInsn->U.MoveQuickSlot;
  newMInsn->tag = MInsnMoveQuickTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnMultiplyDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMultiplyDuplicate(MInsn oldMInsn)
#else
MInsn MInsnMultiplyDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMultiply *slot = &newMInsn->U.MultiplySlot;
  struct _MInsnMultiply *oldslot = &oldMInsn->U.MultiplySlot;
  newMInsn->tag = MInsnMultiplyTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnNegateDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNegateDuplicate(MInsn oldMInsn)
#else
MInsn MInsnNegateDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnNegate *slot = &newMInsn->U.NegateSlot;
  struct _MInsnNegate *oldslot = &oldMInsn->U.NegateSlot;
  newMInsn->tag = MInsnNegateTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnNoOperationDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNoOperationDuplicate(MInsn oldMInsn)
#else
MInsn MInsnNoOperationDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  newMInsn->tag = MInsnNoOperationTag;
  return (newMInsn);
}

/*
**
** MInsnOrDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnOrDuplicate(MInsn oldMInsn)
#else
MInsn MInsnOrDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnOr *slot = &newMInsn->U.OrSlot;
  struct _MInsnOr *oldslot = &oldMInsn->U.OrSlot;
  newMInsn->tag = MInsnOrTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnQueueDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQueueDuplicate(MInsn oldMInsn)
#else
MInsn MInsnQueueDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnQueue *slot = &newMInsn->U.QueueSlot;
  struct _MInsnQueue *oldslot = &oldMInsn->U.QueueSlot;
  newMInsn->tag = MInsnQueueTag;
  slot->queue = oldslot->queue;
  return (newMInsn);
}

/*
**
** MInsnQuotientDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQuotientDuplicate(MInsn oldMInsn)
#else
MInsn MInsnQuotientDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnQuotient *slot = &newMInsn->U.QuotientSlot;
  struct _MInsnQuotient *oldslot = &oldMInsn->U.QuotientSlot;
  newMInsn->tag = MInsnQuotientTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnRemainderDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRemainderDuplicate(MInsn oldMInsn)
#else
MInsn MInsnRemainderDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnRemainder *slot = &newMInsn->U.RemainderSlot;
  struct _MInsnRemainder *oldslot = &oldMInsn->U.RemainderSlot;
  newMInsn->tag = MInsnRemainderTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnReturnDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnReturnDuplicate(MInsn oldMInsn)
#else
MInsn MInsnReturnDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnReturn *slot = &newMInsn->U.ReturnSlot;
  struct _MInsnReturn *oldslot = &oldMInsn->U.ReturnSlot;
  newMInsn->tag = MInsnReturnTag;
  slot->constant = oldslot->constant;
  return (newMInsn);
}

/*
**
** MInsnRotateDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRotateDuplicate(MInsn oldMInsn)
#else
MInsn MInsnRotateDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnRotate *slot = &newMInsn->U.RotateSlot;
  struct _MInsnRotate *oldslot = &oldMInsn->U.RotateSlot;
  newMInsn->tag = MInsnRotateTag;
  slot->dt = oldslot->dt;
  slot->count = oldslot->count;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnStoreProcessorRegisterDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnStoreProcessorRegisterDuplicate(MInsn oldMInsn)
#else
MInsn MInsnStoreProcessorRegisterDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnStoreProcessorRegister *slot = &newMInsn->U.StoreProcessorRegisterSlot;
  struct _MInsnStoreProcessorRegister *oldslot = &oldMInsn->U.StoreProcessorRegisterSlot;
  newMInsn->tag = MInsnStoreProcessorRegisterTag;
  slot->dt = oldslot->dt;
  slot->procreg = oldslot->procreg;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnSubtractDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnSubtractDuplicate(MInsn oldMInsn)
#else
MInsn MInsnSubtractDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnSubtract *slot = &newMInsn->U.SubtractSlot;
  struct _MInsnSubtract *oldslot = &oldMInsn->U.SubtractSlot;
  newMInsn->tag = MInsnSubtractTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnXorDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnXorDuplicate(MInsn oldMInsn)
#else
MInsn MInsnXorDuplicate(oldMInsn)
MInsn oldMInsn;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnXor *slot = &newMInsn->U.XorSlot;
  struct _MInsnXor *oldslot = &oldMInsn->U.XorSlot;
  newMInsn->tag = MInsnXorTag;
  slot->dt = oldslot->dt;
  slot->src = oldslot->src;
  slot->dest = oldslot->dest;
  return (newMInsn);
}

/*
**
** MInsnAbsoluteValueNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAbsoluteValueNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAbsoluteValueNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAbsoluteValue *slot = &newMInsn->U.AbsoluteValueSlot;
  newMInsn->tag = MInsnAbsoluteValueTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnAddNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAddNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAdd *slot = &newMInsn->U.AddSlot;
  newMInsn->tag = MInsnAddTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnAddQuickNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddQuickNew(DataType dt,int src,Addr dest)
#else
MInsn MInsnAddQuickNew(dt,src,dest)
DataType dt;
int src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAddQuick *slot = &newMInsn->U.AddQuickSlot;
  newMInsn->tag = MInsnAddQuickTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnAdjustStackPointerNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAdjustStackPointerNew(DataType dt,Addr src)
#else
MInsn MInsnAdjustStackPointerNew(dt,src)
DataType dt;
Addr src;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAdjustStackPointer *slot = &newMInsn->U.AdjustStackPointerSlot;
  newMInsn->tag = MInsnAdjustStackPointerTag;
  slot->dt = dt;
  slot->src = src;
  return (newMInsn);
}

/*
**
** MInsnAndNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAndNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAndNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnAnd *slot = &newMInsn->U.AndSlot;
  newMInsn->tag = MInsnAndTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnArithmeticComplementNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticComplementNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnArithmeticComplementNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnArithmeticComplement *slot = &newMInsn->U.ArithmeticComplementSlot;
  newMInsn->tag = MInsnArithmeticComplementTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnArithmeticShiftNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticShiftNew(DataType dt,Addr count,Addr dest)
#else
MInsn MInsnArithmeticShiftNew(dt,count,dest)
DataType dt;
Addr count;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnArithmeticShift *slot = &newMInsn->U.ArithmeticShiftSlot;
  newMInsn->tag = MInsnArithmeticShiftTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnBranchNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchNew(Condition cond,Disp dest)
#else
MInsn MInsnBranchNew(cond,dest)
Condition cond;
Disp dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnBranch *slot = &newMInsn->U.BranchSlot;
  newMInsn->tag = MInsnBranchTag;
  slot->cond = cond;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnBranchToSubroutineNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchToSubroutineNew(Disp dest)
#else
MInsn MInsnBranchToSubroutineNew(dest)
Disp dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnBranchToSubroutine *slot = &newMInsn->U.BranchToSubroutineSlot;
  newMInsn->tag = MInsnBranchToSubroutineTag;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnCompareNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareNew(DataType dt,Addr src1,Addr src2)
#else
MInsn MInsnCompareNew(dt,src1,src2)
DataType dt;
Addr src1;
Addr src2;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompare *slot = &newMInsn->U.CompareSlot;
  newMInsn->tag = MInsnCompareTag;
  slot->dt = dt;
  slot->src1 = src1;
  slot->src2 = src2;
  return (newMInsn);
}

/*
**
** MInsnCompareMultipleNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareMultipleNew(DataType dt,Addr block1,Addr block2,int length)
#else
MInsn MInsnCompareMultipleNew(dt,block1,block2,length)
DataType dt;
Addr block1;
Addr block2;
int length;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompareMultiple *slot = &newMInsn->U.CompareMultipleSlot;
  newMInsn->tag = MInsnCompareMultipleTag;
  slot->dt = dt;
  slot->block1 = block1;
  slot->block2 = block2;
  slot->length = length;
  return (newMInsn);
}

/*
**
** MInsnCompareQuickNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareQuickNew(DataType dt,int src1,Addr src2)
#else
MInsn MInsnCompareQuickNew(dt,src1,src2)
DataType dt;
int src1;
Addr src2;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnCompareQuick *slot = &newMInsn->U.CompareQuickSlot;
  newMInsn->tag = MInsnCompareQuickTag;
  slot->dt = dt;
  slot->src1 = src1;
  slot->src2 = src2;
  return (newMInsn);
}

/*
**
** MInsnConvertDFNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertDFNew(Addr src,Addr dest)
#else
MInsn MInsnConvertDFNew(src,dest)
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnConvertDF *slot = &newMInsn->U.ConvertDFSlot;
  newMInsn->tag = MInsnConvertDFTag;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnConvertFDNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertFDNew(Addr src,Addr dest)
#else
MInsn MInsnConvertFDNew(src,dest)
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnConvertFD *slot = &newMInsn->U.ConvertFDSlot;
  newMInsn->tag = MInsnConvertFDTag;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnDivideNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnDivideNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnDivideNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnDivide *slot = &newMInsn->U.DivideSlot;
  newMInsn->tag = MInsnDivideTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnEffectiveAddressNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEffectiveAddressNew(Addr src,Addr dest)
#else
MInsn MInsnEffectiveAddressNew(src,dest)
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnEffectiveAddress *slot = &newMInsn->U.EffectiveAddressSlot;
  newMInsn->tag = MInsnEffectiveAddressTag;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnEnterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEnterNew(Queue regs,int disp)
#else
MInsn MInsnEnterNew(regs,disp)
Queue regs;
int disp;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnEnter *slot = &newMInsn->U.EnterSlot;
  newMInsn->tag = MInsnEnterTag;
  slot->regs = regs;
  slot->disp = disp;
  return (newMInsn);
}

/*
**
** MInsnExitNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnExitNew(Queue regs)
#else
MInsn MInsnExitNew(regs)
Queue regs;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnExit *slot = &newMInsn->U.ExitSlot;
  newMInsn->tag = MInsnExitTag;
  slot->regs = regs;
  return (newMInsn);
}

/*
**
** MInsnJumpNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpNew(Addr dest)
#else
MInsn MInsnJumpNew(dest)
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnJump *slot = &newMInsn->U.JumpSlot;
  newMInsn->tag = MInsnJumpTag;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnJumpToSubroutineNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpToSubroutineNew(Addr dest)
#else
MInsn MInsnJumpToSubroutineNew(dest)
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnJumpToSubroutine *slot = &newMInsn->U.JumpToSubroutineSlot;
  newMInsn->tag = MInsnJumpToSubroutineTag;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnLoadProcessorRegisterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLoadProcessorRegisterNew(DataType dt,ProcReg procreg,Addr src)
#else
MInsn MInsnLoadProcessorRegisterNew(dt,procreg,src)
DataType dt;
ProcReg procreg;
Addr src;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLoadProcessorRegister *slot = &newMInsn->U.LoadProcessorRegisterSlot;
  newMInsn->tag = MInsnLoadProcessorRegisterTag;
  slot->dt = dt;
  slot->procreg = procreg;
  slot->src = src;
  return (newMInsn);
}

/*
**
** MInsnLogicalComplementNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalComplementNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnLogicalComplementNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLogicalComplement *slot = &newMInsn->U.LogicalComplementSlot;
  newMInsn->tag = MInsnLogicalComplementTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnLogicalShiftNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalShiftNew(DataType dt,Addr count,Addr dest)
#else
MInsn MInsnLogicalShiftNew(dt,count,dest)
DataType dt;
Addr count;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnLogicalShift *slot = &newMInsn->U.LogicalShiftSlot;
  newMInsn->tag = MInsnLogicalShiftTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnModulusNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnModulusNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnModulusNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnModulus *slot = &newMInsn->U.ModulusSlot;
  newMInsn->tag = MInsnModulusTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnMoveNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnMoveNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMove *slot = &newMInsn->U.MoveSlot;
  newMInsn->tag = MInsnMoveTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnMoveMultipleNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveMultipleNew(DataType dt,Addr block1,Addr block2,int length)
#else
MInsn MInsnMoveMultipleNew(dt,block1,block2,length)
DataType dt;
Addr block1;
Addr block2;
int length;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMoveMultiple *slot = &newMInsn->U.MoveMultipleSlot;
  newMInsn->tag = MInsnMoveMultipleTag;
  slot->dt = dt;
  slot->block1 = block1;
  slot->block2 = block2;
  slot->length = length;
  return (newMInsn);
}

/*
**
** MInsnMoveQuickNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveQuickNew(DataType dt,int src,Addr dest)
#else
MInsn MInsnMoveQuickNew(dt,src,dest)
DataType dt;
int src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMoveQuick *slot = &newMInsn->U.MoveQuickSlot;
  newMInsn->tag = MInsnMoveQuickTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnMultiplyNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMultiplyNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnMultiplyNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnMultiply *slot = &newMInsn->U.MultiplySlot;
  newMInsn->tag = MInsnMultiplyTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnNegateNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNegateNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnNegateNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnNegate *slot = &newMInsn->U.NegateSlot;
  newMInsn->tag = MInsnNegateTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnNoOperationNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNoOperationNew(void)
#else
MInsn MInsnNoOperationNew()
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  newMInsn->tag = MInsnNoOperationTag;
  return (newMInsn);
}

/*
**
** MInsnOrNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnOrNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnOrNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnOr *slot = &newMInsn->U.OrSlot;
  newMInsn->tag = MInsnOrTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnQueueNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQueueNew(Queue queue)
#else
MInsn MInsnQueueNew(queue)
Queue queue;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnQueue *slot = &newMInsn->U.QueueSlot;
  newMInsn->tag = MInsnQueueTag;
  slot->queue = queue;
  return (newMInsn);
}

/*
**
** MInsnQuotientNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQuotientNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnQuotientNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnQuotient *slot = &newMInsn->U.QuotientSlot;
  newMInsn->tag = MInsnQuotientTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnRemainderNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRemainderNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnRemainderNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnRemainder *slot = &newMInsn->U.RemainderSlot;
  newMInsn->tag = MInsnRemainderTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnReturnNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnReturnNew(int constant)
#else
MInsn MInsnReturnNew(constant)
int constant;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnReturn *slot = &newMInsn->U.ReturnSlot;
  newMInsn->tag = MInsnReturnTag;
  slot->constant = constant;
  return (newMInsn);
}

/*
**
** MInsnRotateNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRotateNew(DataType dt,Addr count,Addr dest)
#else
MInsn MInsnRotateNew(dt,count,dest)
DataType dt;
Addr count;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnRotate *slot = &newMInsn->U.RotateSlot;
  newMInsn->tag = MInsnRotateTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnStoreProcessorRegisterNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnStoreProcessorRegisterNew(DataType dt,ProcReg procreg,Addr dest)
#else
MInsn MInsnStoreProcessorRegisterNew(dt,procreg,dest)
DataType dt;
ProcReg procreg;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnStoreProcessorRegister *slot = &newMInsn->U.StoreProcessorRegisterSlot;
  newMInsn->tag = MInsnStoreProcessorRegisterTag;
  slot->dt = dt;
  slot->procreg = procreg;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnSubtractNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnSubtractNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnSubtractNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnSubtract *slot = &newMInsn->U.SubtractSlot;
  newMInsn->tag = MInsnSubtractTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnXorNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnXorNew(DataType dt,Addr src,Addr dest)
#else
MInsn MInsnXorNew(dt,src,dest)
DataType dt;
Addr src;
Addr dest;
#endif
{
  MInsn newMInsn = (MInsn)Allocate(sizeof(_MInsn));
  struct _MInsnXor *slot = &newMInsn->U.XorSlot;
  newMInsn->tag = MInsnXorTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (newMInsn);
}

/*
**
** MInsnAbsoluteValueUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAbsoluteValueUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAbsoluteValueUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnAbsoluteValue *slot = &oldMInsn->U.AbsoluteValueSlot;
  oldMInsn->tag = MInsnAbsoluteValueTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnAddUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAddUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnAdd *slot = &oldMInsn->U.AddSlot;
  oldMInsn->tag = MInsnAddTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnAddQuickUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAddQuickUpdate(MInsn oldMInsn,DataType dt,int src,Addr dest)
#else
MInsn MInsnAddQuickUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
int src;
Addr dest;
#endif
{
  struct _MInsnAddQuick *slot = &oldMInsn->U.AddQuickSlot;
  oldMInsn->tag = MInsnAddQuickTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnAdjustStackPointerUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAdjustStackPointerUpdate(MInsn oldMInsn,DataType dt,Addr src)
#else
MInsn MInsnAdjustStackPointerUpdate(oldMInsn,dt,src)
MInsn oldMInsn;
DataType dt;
Addr src;
#endif
{
  struct _MInsnAdjustStackPointer *slot = &oldMInsn->U.AdjustStackPointerSlot;
  oldMInsn->tag = MInsnAdjustStackPointerTag;
  slot->dt = dt;
  slot->src = src;
  return (oldMInsn);
}

/*
**
** MInsnAndUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnAndUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnAndUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnAnd *slot = &oldMInsn->U.AndSlot;
  oldMInsn->tag = MInsnAndTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnArithmeticComplementUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticComplementUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnArithmeticComplementUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnArithmeticComplement *slot = &oldMInsn->U.ArithmeticComplementSlot;
  oldMInsn->tag = MInsnArithmeticComplementTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnArithmeticShiftUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnArithmeticShiftUpdate(MInsn oldMInsn,DataType dt,Addr count,Addr dest)
#else
MInsn MInsnArithmeticShiftUpdate(oldMInsn,dt,count,dest)
MInsn oldMInsn;
DataType dt;
Addr count;
Addr dest;
#endif
{
  struct _MInsnArithmeticShift *slot = &oldMInsn->U.ArithmeticShiftSlot;
  oldMInsn->tag = MInsnArithmeticShiftTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnBranchUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchUpdate(MInsn oldMInsn,Condition cond,Disp dest)
#else
MInsn MInsnBranchUpdate(oldMInsn,cond,dest)
MInsn oldMInsn;
Condition cond;
Disp dest;
#endif
{
  struct _MInsnBranch *slot = &oldMInsn->U.BranchSlot;
  oldMInsn->tag = MInsnBranchTag;
  slot->cond = cond;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnBranchToSubroutineUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnBranchToSubroutineUpdate(MInsn oldMInsn,Disp dest)
#else
MInsn MInsnBranchToSubroutineUpdate(oldMInsn,dest)
MInsn oldMInsn;
Disp dest;
#endif
{
  struct _MInsnBranchToSubroutine *slot = &oldMInsn->U.BranchToSubroutineSlot;
  oldMInsn->tag = MInsnBranchToSubroutineTag;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnCompareUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareUpdate(MInsn oldMInsn,DataType dt,Addr src1,Addr src2)
#else
MInsn MInsnCompareUpdate(oldMInsn,dt,src1,src2)
MInsn oldMInsn;
DataType dt;
Addr src1;
Addr src2;
#endif
{
  struct _MInsnCompare *slot = &oldMInsn->U.CompareSlot;
  oldMInsn->tag = MInsnCompareTag;
  slot->dt = dt;
  slot->src1 = src1;
  slot->src2 = src2;
  return (oldMInsn);
}

/*
**
** MInsnCompareMultipleUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareMultipleUpdate(MInsn oldMInsn,DataType dt,Addr block1,Addr block2,int length)
#else
MInsn MInsnCompareMultipleUpdate(oldMInsn,dt,block1,block2,length)
MInsn oldMInsn;
DataType dt;
Addr block1;
Addr block2;
int length;
#endif
{
  struct _MInsnCompareMultiple *slot = &oldMInsn->U.CompareMultipleSlot;
  oldMInsn->tag = MInsnCompareMultipleTag;
  slot->dt = dt;
  slot->block1 = block1;
  slot->block2 = block2;
  slot->length = length;
  return (oldMInsn);
}

/*
**
** MInsnCompareQuickUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnCompareQuickUpdate(MInsn oldMInsn,DataType dt,int src1,Addr src2)
#else
MInsn MInsnCompareQuickUpdate(oldMInsn,dt,src1,src2)
MInsn oldMInsn;
DataType dt;
int src1;
Addr src2;
#endif
{
  struct _MInsnCompareQuick *slot = &oldMInsn->U.CompareQuickSlot;
  oldMInsn->tag = MInsnCompareQuickTag;
  slot->dt = dt;
  slot->src1 = src1;
  slot->src2 = src2;
  return (oldMInsn);
}

/*
**
** MInsnConvertDFUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertDFUpdate(MInsn oldMInsn,Addr src,Addr dest)
#else
MInsn MInsnConvertDFUpdate(oldMInsn,src,dest)
MInsn oldMInsn;
Addr src;
Addr dest;
#endif
{
  struct _MInsnConvertDF *slot = &oldMInsn->U.ConvertDFSlot;
  oldMInsn->tag = MInsnConvertDFTag;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnConvertFDUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnConvertFDUpdate(MInsn oldMInsn,Addr src,Addr dest)
#else
MInsn MInsnConvertFDUpdate(oldMInsn,src,dest)
MInsn oldMInsn;
Addr src;
Addr dest;
#endif
{
  struct _MInsnConvertFD *slot = &oldMInsn->U.ConvertFDSlot;
  oldMInsn->tag = MInsnConvertFDTag;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnDivideUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnDivideUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnDivideUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnDivide *slot = &oldMInsn->U.DivideSlot;
  oldMInsn->tag = MInsnDivideTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnEffectiveAddressUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEffectiveAddressUpdate(MInsn oldMInsn,Addr src,Addr dest)
#else
MInsn MInsnEffectiveAddressUpdate(oldMInsn,src,dest)
MInsn oldMInsn;
Addr src;
Addr dest;
#endif
{
  struct _MInsnEffectiveAddress *slot = &oldMInsn->U.EffectiveAddressSlot;
  oldMInsn->tag = MInsnEffectiveAddressTag;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnEnterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnEnterUpdate(MInsn oldMInsn,Queue regs,int disp)
#else
MInsn MInsnEnterUpdate(oldMInsn,regs,disp)
MInsn oldMInsn;
Queue regs;
int disp;
#endif
{
  struct _MInsnEnter *slot = &oldMInsn->U.EnterSlot;
  oldMInsn->tag = MInsnEnterTag;
  slot->regs = regs;
  slot->disp = disp;
  return (oldMInsn);
}

/*
**
** MInsnExitUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnExitUpdate(MInsn oldMInsn,Queue regs)
#else
MInsn MInsnExitUpdate(oldMInsn,regs)
MInsn oldMInsn;
Queue regs;
#endif
{
  struct _MInsnExit *slot = &oldMInsn->U.ExitSlot;
  oldMInsn->tag = MInsnExitTag;
  slot->regs = regs;
  return (oldMInsn);
}

/*
**
** MInsnJumpUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpUpdate(MInsn oldMInsn,Addr dest)
#else
MInsn MInsnJumpUpdate(oldMInsn,dest)
MInsn oldMInsn;
Addr dest;
#endif
{
  struct _MInsnJump *slot = &oldMInsn->U.JumpSlot;
  oldMInsn->tag = MInsnJumpTag;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnJumpToSubroutineUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnJumpToSubroutineUpdate(MInsn oldMInsn,Addr dest)
#else
MInsn MInsnJumpToSubroutineUpdate(oldMInsn,dest)
MInsn oldMInsn;
Addr dest;
#endif
{
  struct _MInsnJumpToSubroutine *slot = &oldMInsn->U.JumpToSubroutineSlot;
  oldMInsn->tag = MInsnJumpToSubroutineTag;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnLoadProcessorRegisterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLoadProcessorRegisterUpdate(MInsn oldMInsn,DataType dt,ProcReg procreg,Addr src)
#else
MInsn MInsnLoadProcessorRegisterUpdate(oldMInsn,dt,procreg,src)
MInsn oldMInsn;
DataType dt;
ProcReg procreg;
Addr src;
#endif
{
  struct _MInsnLoadProcessorRegister *slot = &oldMInsn->U.LoadProcessorRegisterSlot;
  oldMInsn->tag = MInsnLoadProcessorRegisterTag;
  slot->dt = dt;
  slot->procreg = procreg;
  slot->src = src;
  return (oldMInsn);
}

/*
**
** MInsnLogicalComplementUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalComplementUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnLogicalComplementUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnLogicalComplement *slot = &oldMInsn->U.LogicalComplementSlot;
  oldMInsn->tag = MInsnLogicalComplementTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnLogicalShiftUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnLogicalShiftUpdate(MInsn oldMInsn,DataType dt,Addr count,Addr dest)
#else
MInsn MInsnLogicalShiftUpdate(oldMInsn,dt,count,dest)
MInsn oldMInsn;
DataType dt;
Addr count;
Addr dest;
#endif
{
  struct _MInsnLogicalShift *slot = &oldMInsn->U.LogicalShiftSlot;
  oldMInsn->tag = MInsnLogicalShiftTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnModulusUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnModulusUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnModulusUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnModulus *slot = &oldMInsn->U.ModulusSlot;
  oldMInsn->tag = MInsnModulusTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnMoveUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnMoveUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnMove *slot = &oldMInsn->U.MoveSlot;
  oldMInsn->tag = MInsnMoveTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnMoveMultipleUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveMultipleUpdate(MInsn oldMInsn,DataType dt,Addr block1,Addr block2,int length)
#else
MInsn MInsnMoveMultipleUpdate(oldMInsn,dt,block1,block2,length)
MInsn oldMInsn;
DataType dt;
Addr block1;
Addr block2;
int length;
#endif
{
  struct _MInsnMoveMultiple *slot = &oldMInsn->U.MoveMultipleSlot;
  oldMInsn->tag = MInsnMoveMultipleTag;
  slot->dt = dt;
  slot->block1 = block1;
  slot->block2 = block2;
  slot->length = length;
  return (oldMInsn);
}

/*
**
** MInsnMoveQuickUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMoveQuickUpdate(MInsn oldMInsn,DataType dt,int src,Addr dest)
#else
MInsn MInsnMoveQuickUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
int src;
Addr dest;
#endif
{
  struct _MInsnMoveQuick *slot = &oldMInsn->U.MoveQuickSlot;
  oldMInsn->tag = MInsnMoveQuickTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnMultiplyUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnMultiplyUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnMultiplyUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnMultiply *slot = &oldMInsn->U.MultiplySlot;
  oldMInsn->tag = MInsnMultiplyTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnNegateUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNegateUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnNegateUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnNegate *slot = &oldMInsn->U.NegateSlot;
  oldMInsn->tag = MInsnNegateTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnNoOperationUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnNoOperationUpdate(MInsn oldMInsn)
#else
MInsn MInsnNoOperationUpdate(oldMInsn)
MInsn oldMInsn;
#endif
{
  oldMInsn->tag = MInsnNoOperationTag;
  return (oldMInsn);
}

/*
**
** MInsnOrUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnOrUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnOrUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnOr *slot = &oldMInsn->U.OrSlot;
  oldMInsn->tag = MInsnOrTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnQueueUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQueueUpdate(MInsn oldMInsn,Queue queue)
#else
MInsn MInsnQueueUpdate(oldMInsn,queue)
MInsn oldMInsn;
Queue queue;
#endif
{
  struct _MInsnQueue *slot = &oldMInsn->U.QueueSlot;
  oldMInsn->tag = MInsnQueueTag;
  slot->queue = queue;
  return (oldMInsn);
}

/*
**
** MInsnQuotientUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnQuotientUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnQuotientUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnQuotient *slot = &oldMInsn->U.QuotientSlot;
  oldMInsn->tag = MInsnQuotientTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnRemainderUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRemainderUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnRemainderUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnRemainder *slot = &oldMInsn->U.RemainderSlot;
  oldMInsn->tag = MInsnRemainderTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnReturnUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnReturnUpdate(MInsn oldMInsn,int constant)
#else
MInsn MInsnReturnUpdate(oldMInsn,constant)
MInsn oldMInsn;
int constant;
#endif
{
  struct _MInsnReturn *slot = &oldMInsn->U.ReturnSlot;
  oldMInsn->tag = MInsnReturnTag;
  slot->constant = constant;
  return (oldMInsn);
}

/*
**
** MInsnRotateUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnRotateUpdate(MInsn oldMInsn,DataType dt,Addr count,Addr dest)
#else
MInsn MInsnRotateUpdate(oldMInsn,dt,count,dest)
MInsn oldMInsn;
DataType dt;
Addr count;
Addr dest;
#endif
{
  struct _MInsnRotate *slot = &oldMInsn->U.RotateSlot;
  oldMInsn->tag = MInsnRotateTag;
  slot->dt = dt;
  slot->count = count;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnStoreProcessorRegisterUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnStoreProcessorRegisterUpdate(MInsn oldMInsn,DataType dt,ProcReg procreg,Addr dest)
#else
MInsn MInsnStoreProcessorRegisterUpdate(oldMInsn,dt,procreg,dest)
MInsn oldMInsn;
DataType dt;
ProcReg procreg;
Addr dest;
#endif
{
  struct _MInsnStoreProcessorRegister *slot = &oldMInsn->U.StoreProcessorRegisterSlot;
  oldMInsn->tag = MInsnStoreProcessorRegisterTag;
  slot->dt = dt;
  slot->procreg = procreg;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnSubtractUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnSubtractUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnSubtractUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnSubtract *slot = &oldMInsn->U.SubtractSlot;
  oldMInsn->tag = MInsnSubtractTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MInsnXorUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MInsn MInsnXorUpdate(MInsn oldMInsn,DataType dt,Addr src,Addr dest)
#else
MInsn MInsnXorUpdate(oldMInsn,dt,src,dest)
MInsn oldMInsn;
DataType dt;
Addr src;
Addr dest;
#endif
{
  struct _MInsnXor *slot = &oldMInsn->U.XorSlot;
  oldMInsn->tag = MInsnXorTag;
  slot->dt = dt;
  slot->src = src;
  slot->dest = dest;
  return (oldMInsn);
}

/*
**
** MValueByteDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueByteDuplicate(MValue oldMValue)
#else
MValue MValueByteDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueByte *slot = &newMValue->U.ByteSlot;
  struct _MValueByte *oldslot = &oldMValue->U.ByteSlot;
  newMValue->tag = MValueByteTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueWordDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueWordDuplicate(MValue oldMValue)
#else
MValue MValueWordDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueWord *slot = &newMValue->U.WordSlot;
  struct _MValueWord *oldslot = &oldMValue->U.WordSlot;
  newMValue->tag = MValueWordTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueDoubleWordDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueDoubleWordDuplicate(MValue oldMValue)
#else
MValue MValueDoubleWordDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueDoubleWord *slot = &newMValue->U.DoubleWordSlot;
  struct _MValueDoubleWord *oldslot = &oldMValue->U.DoubleWordSlot;
  newMValue->tag = MValueDoubleWordTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueFloatDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueFloatDuplicate(MValue oldMValue)
#else
MValue MValueFloatDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueFloat *slot = &newMValue->U.FloatSlot;
  struct _MValueFloat *oldslot = &oldMValue->U.FloatSlot;
  newMValue->tag = MValueFloatTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueLongFloatDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueLongFloatDuplicate(MValue oldMValue)
#else
MValue MValueLongFloatDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueLongFloat *slot = &newMValue->U.LongFloatSlot;
  struct _MValueLongFloat *oldslot = &oldMValue->U.LongFloatSlot;
  newMValue->tag = MValueLongFloatTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueCsetDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueCsetDuplicate(MValue oldMValue)
#else
MValue MValueCsetDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueCset *slot = &newMValue->U.CsetSlot;
  struct _MValueCset *oldslot = &oldMValue->U.CsetSlot;
  newMValue->tag = MValueCsetTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueStringDuplicate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueStringDuplicate(MValue oldMValue)
#else
MValue MValueStringDuplicate(oldMValue)
MValue oldMValue;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueString *slot = &newMValue->U.StringSlot;
  struct _MValueString *oldslot = &oldMValue->U.StringSlot;
  newMValue->tag = MValueStringTag;
  slot->value = oldslot->value;
  return (newMValue);
}

/*
**
** MValueByteNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueByteNew(char value)
#else
MValue MValueByteNew(value)
char value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueByte *slot = &newMValue->U.ByteSlot;
  newMValue->tag = MValueByteTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueWordNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueWordNew(short value)
#else
MValue MValueWordNew(value)
short value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueWord *slot = &newMValue->U.WordSlot;
  newMValue->tag = MValueWordTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueDoubleWordNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueDoubleWordNew(long value)
#else
MValue MValueDoubleWordNew(value)
long value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueDoubleWord *slot = &newMValue->U.DoubleWordSlot;
  newMValue->tag = MValueDoubleWordTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueFloatNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueFloatNew(float value)
#else
MValue MValueFloatNew(value)
float value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueFloat *slot = &newMValue->U.FloatSlot;
  newMValue->tag = MValueFloatTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueLongFloatNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueLongFloatNew(double value)
#else
MValue MValueLongFloatNew(value)
double value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueLongFloat *slot = &newMValue->U.LongFloatSlot;
  newMValue->tag = MValueLongFloatTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueCsetNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueCsetNew(char *value)
#else
MValue MValueCsetNew(value)
char *value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueCset *slot = &newMValue->U.CsetSlot;
  newMValue->tag = MValueCsetTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueStringNew
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueStringNew(char *value)
#else
MValue MValueStringNew(value)
char *value;
#endif
{
  MValue newMValue = (MValue)Allocate(sizeof(_MValue));
  struct _MValueString *slot = &newMValue->U.StringSlot;
  newMValue->tag = MValueStringTag;
  slot->value = value;
  return (newMValue);
}

/*
**
** MValueByteUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueByteUpdate(MValue oldMValue,char value)
#else
MValue MValueByteUpdate(oldMValue,value)
MValue oldMValue;
char value;
#endif
{
  struct _MValueByte *slot = &oldMValue->U.ByteSlot;
  oldMValue->tag = MValueByteTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueWordUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueWordUpdate(MValue oldMValue,short value)
#else
MValue MValueWordUpdate(oldMValue,value)
MValue oldMValue;
short value;
#endif
{
  struct _MValueWord *slot = &oldMValue->U.WordSlot;
  oldMValue->tag = MValueWordTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueDoubleWordUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueDoubleWordUpdate(MValue oldMValue,long value)
#else
MValue MValueDoubleWordUpdate(oldMValue,value)
MValue oldMValue;
long value;
#endif
{
  struct _MValueDoubleWord *slot = &oldMValue->U.DoubleWordSlot;
  oldMValue->tag = MValueDoubleWordTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueFloatUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueFloatUpdate(MValue oldMValue,float value)
#else
MValue MValueFloatUpdate(oldMValue,value)
MValue oldMValue;
float value;
#endif
{
  struct _MValueFloat *slot = &oldMValue->U.FloatSlot;
  oldMValue->tag = MValueFloatTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueLongFloatUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueLongFloatUpdate(MValue oldMValue,double value)
#else
MValue MValueLongFloatUpdate(oldMValue,value)
MValue oldMValue;
double value;
#endif
{
  struct _MValueLongFloat *slot = &oldMValue->U.LongFloatSlot;
  oldMValue->tag = MValueLongFloatTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueCsetUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueCsetUpdate(MValue oldMValue,char *value)
#else
MValue MValueCsetUpdate(oldMValue,value)
MValue oldMValue;
char *value;
#endif
{
  struct _MValueCset *slot = &oldMValue->U.CsetSlot;
  oldMValue->tag = MValueCsetTag;
  slot->value = value;
  return (oldMValue);
}

/*
**
** MValueStringUpdate
**
*/
PUBLIC
#ifdef __ANSI_C__
MValue MValueStringUpdate(MValue oldMValue,char *value)
#else
MValue MValueStringUpdate(oldMValue,value)
MValue oldMValue;
char *value;
#endif
{
  struct _MValueString *slot = &oldMValue->U.StringSlot;
  oldMValue->tag = MValueStringTag;
  slot->value = value;
  return (oldMValue);
}

