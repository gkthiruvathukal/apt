#ifndef icgnodes_h
#define icgnodes_h

#include "apt.h"
#include "icnnodes.h"

/* Condition Enumeration */

typedef enum {
  EQ,
  NE,
  CS,
  CC,
  HI,
  LS,
  GT,
  LE,
  FS,
  FC,
  LO,
  HS,
  LT,
  GE,
  UC,
  ConditionCount
} Condition;

/* DataType Enumeration */

typedef enum {
  B,
  W,
  D,
  F,
  L,
  DataTypeCount
} DataType;

/* InsnType Enumeration */

typedef enum {
  I,
  M,
  InsnTypeCount
} InsnType;

/* LocType Enumeration */

typedef enum {
  GLOBAL,
  PARAM,
  LOCAL,
  STATIC,
  CONST,
  LocTypeCount
} LocType;

/* ProcReg Enumeration */

typedef enum {
  FP,
  SB,
  SP,
  ProcRegCount
} ProcReg;

/* Addr Enumeration */

typedef enum {
  AddrAbsoluteTag,
  AddrExternalTag,
  AddrFrameTag,
  AddrFrameRelativeTag,
  AddrImmediateTag,
  AddrProgramTag,
  AddrRegisterTag,
  AddrRegisterRelativeTag,
  AddrStackTag,
  AddrStackRelativeTag,
  AddrStaticTag,
  AddrStaticRelativeTag,
  AddrTopOfStackTag,
  AddrTagCount
} AddrTags;

/* Addr Slots */

struct _AddrAbsolute {
  struct _Disp* disp;
};

struct _AddrExternal {
  struct _Disp* disp1;
  struct _Disp* disp2;
};

struct _AddrFrame {
  struct _Disp* disp;
};

struct _AddrFrameRelative {
  struct _Disp* disp2;
  struct _Disp* disp1;
};

struct _AddrImmediate {
  struct _MValue* value;
};

struct _AddrProgram {
  struct _Disp* disp;
};

struct _AddrRegister {
  DataType dt;
  int number;
};

struct _AddrRegisterRelative {
  DataType dt;
  struct _Disp* disp;
  int number;
};

struct _AddrStack {
  struct _Disp* disp;
};

struct _AddrStackRelative {
  struct _Disp* disp2;
  struct _Disp* disp1;
};

struct _AddrStatic {
  struct _Disp* disp;
};

struct _AddrStaticRelative {
  struct _Disp* disp2;
  struct _Disp* disp1;
};

struct _AddrTopOfStack {
  char AptParsingTools;
};

typedef union {
  struct _AddrAbsolute AbsoluteSlot;
  struct _AddrExternal ExternalSlot;
  struct _AddrFrame FrameSlot;
  struct _AddrFrameRelative FrameRelativeSlot;
  struct _AddrImmediate ImmediateSlot;
  struct _AddrProgram ProgramSlot;
  struct _AddrRegister RegisterSlot;
  struct _AddrRegisterRelative RegisterRelativeSlot;
  struct _AddrStack StackSlot;
  struct _AddrStackRelative StackRelativeSlot;
  struct _AddrStatic StaticSlot;
  struct _AddrStaticRelative StaticRelativeSlot;
  struct _AddrTopOfStack TopOfStackSlot;
} AddrUnion;

/* Addr Structure */

typedef struct _Addr {
  AddrTags tag;
  AddrUnion U;
} _Addr, *Addr;

/* Addr Macros */

#define AddrAbsoluteSlot(n) (n->U.AbsoluteSlot)
#define AddrExternalSlot(n) (n->U.ExternalSlot)
#define AddrFrameSlot(n) (n->U.FrameSlot)
#define AddrFrameRelativeSlot(n) (n->U.FrameRelativeSlot)
#define AddrImmediateSlot(n) (n->U.ImmediateSlot)
#define AddrProgramSlot(n) (n->U.ProgramSlot)
#define AddrRegisterSlot(n) (n->U.RegisterSlot)
#define AddrRegisterRelativeSlot(n) (n->U.RegisterRelativeSlot)
#define AddrStackSlot(n) (n->U.StackSlot)
#define AddrStackRelativeSlot(n) (n->U.StackRelativeSlot)
#define AddrStaticSlot(n) (n->U.StaticSlot)
#define AddrStaticRelativeSlot(n) (n->U.StaticRelativeSlot)
#define AddrTopOfStackSlot(n) (n->U.TopOfStackSlot)

/* Addr Prototypes */

#ifdef __ANSI_C__
Addr AddrAbsoluteDuplicate(Addr);
Addr AddrAbsoluteNew(struct _Disp*);
Addr AddrAbsoluteUpdate(Addr,struct _Disp*);
Addr AddrExternalDuplicate(Addr);
Addr AddrExternalNew(struct _Disp*,struct _Disp*);
Addr AddrExternalUpdate(Addr,struct _Disp*,struct _Disp*);
Addr AddrFrameDuplicate(Addr);
Addr AddrFrameNew(struct _Disp*);
Addr AddrFrameUpdate(Addr,struct _Disp*);
Addr AddrFrameRelativeDuplicate(Addr);
Addr AddrFrameRelativeNew(struct _Disp*,struct _Disp*);
Addr AddrFrameRelativeUpdate(Addr,struct _Disp*,struct _Disp*);
Addr AddrImmediateDuplicate(Addr);
Addr AddrImmediateNew(struct _MValue*);
Addr AddrImmediateUpdate(Addr,struct _MValue*);
Addr AddrProgramDuplicate(Addr);
Addr AddrProgramNew(struct _Disp*);
Addr AddrProgramUpdate(Addr,struct _Disp*);
Addr AddrRegisterDuplicate(Addr);
Addr AddrRegisterNew(DataType,int);
Addr AddrRegisterUpdate(Addr,DataType,int);
Addr AddrRegisterRelativeDuplicate(Addr);
Addr AddrRegisterRelativeNew(DataType,struct _Disp*,int);
Addr AddrRegisterRelativeUpdate(Addr,DataType,struct _Disp*,int);
Addr AddrStackDuplicate(Addr);
Addr AddrStackNew(struct _Disp*);
Addr AddrStackUpdate(Addr,struct _Disp*);
Addr AddrStackRelativeDuplicate(Addr);
Addr AddrStackRelativeNew(struct _Disp*,struct _Disp*);
Addr AddrStackRelativeUpdate(Addr,struct _Disp*,struct _Disp*);
Addr AddrStaticDuplicate(Addr);
Addr AddrStaticNew(struct _Disp*);
Addr AddrStaticUpdate(Addr,struct _Disp*);
Addr AddrStaticRelativeDuplicate(Addr);
Addr AddrStaticRelativeNew(struct _Disp*,struct _Disp*);
Addr AddrStaticRelativeUpdate(Addr,struct _Disp*,struct _Disp*);
Addr AddrTopOfStackDuplicate(Addr);
Addr AddrTopOfStackNew(void);
Addr AddrTopOfStackUpdate(Addr);
#else
Addr AddrAbsoluteDuplicate();
Addr AddrAbsoluteNew();
Addr AddrAbsoluteUpdate();
Addr AddrExternalDuplicate();
Addr AddrExternalNew();
Addr AddrExternalUpdate();
Addr AddrFrameDuplicate();
Addr AddrFrameNew();
Addr AddrFrameUpdate();
Addr AddrFrameRelativeDuplicate();
Addr AddrFrameRelativeNew();
Addr AddrFrameRelativeUpdate();
Addr AddrImmediateDuplicate();
Addr AddrImmediateNew();
Addr AddrImmediateUpdate();
Addr AddrProgramDuplicate();
Addr AddrProgramNew();
Addr AddrProgramUpdate();
Addr AddrRegisterDuplicate();
Addr AddrRegisterNew();
Addr AddrRegisterUpdate();
Addr AddrRegisterRelativeDuplicate();
Addr AddrRegisterRelativeNew();
Addr AddrRegisterRelativeUpdate();
Addr AddrStackDuplicate();
Addr AddrStackNew();
Addr AddrStackUpdate();
Addr AddrStackRelativeDuplicate();
Addr AddrStackRelativeNew();
Addr AddrStackRelativeUpdate();
Addr AddrStaticDuplicate();
Addr AddrStaticNew();
Addr AddrStaticUpdate();
Addr AddrStaticRelativeDuplicate();
Addr AddrStaticRelativeNew();
Addr AddrStaticRelativeUpdate();
Addr AddrTopOfStackDuplicate();
Addr AddrTopOfStackNew();
Addr AddrTopOfStackUpdate();
#endif

/* CGContext Enumeration */

typedef enum {
  CGContextLoopTag,
  CGContextProcTag,
  CGContextTagCount
} CGContextTags;

/* CGContext Slots */

struct _CGContextLoop {
  Expression e;
  int saveState1;
  int saveState2;
  int endLabel;
};

struct _CGContextProc {
  struct _CGProc* p;
  int saveState1;
  int saveState2;
  int endLabel;
  int dataLabel;
};

typedef union {
  struct _CGContextLoop LoopSlot;
  struct _CGContextProc ProcSlot;
} CGContextUnion;

/* CGContext Structure */

typedef struct _CGContext {
  CGContextTags tag;
  CGContextUnion U;
  struct _CGContext* c;
} _CGContext, *CGContext;

/* CGContext Macros */

#define CGContextLoopSlot(n) (n->U.LoopSlot)
#define CGContextProcSlot(n) (n->U.ProcSlot)

/* CGContext Prototypes */

#ifdef __ANSI_C__
CGContext CGContextLoopDuplicate(CGContext);
CGContext CGContextLoopNew(Expression,int,int,int,struct _CGContext*);
CGContext CGContextLoopUpdate(CGContext,Expression,int,int,int,struct _CGContext*);
CGContext CGContextProcDuplicate(CGContext);
CGContext CGContextProcNew(struct _CGProc*,int,int,int,int,struct _CGContext*);
CGContext CGContextProcUpdate(CGContext,struct _CGProc*,int,int,int,int,struct _CGContext*);
#else
CGContext CGContextLoopDuplicate();
CGContext CGContextLoopNew();
CGContext CGContextLoopUpdate();
CGContext CGContextProcDuplicate();
CGContext CGContextProcNew();
CGContext CGContextProcUpdate();
#endif

/* CGProc Structure */

typedef struct _CGProc {
  Token name;
  Queue paramQ;
  Queue localQ;
  Queue staticQ;
  Expression init;
  Expression body;
  Type type;
  Queue code;
  Queue constQ;
  int localSize;
  int paramSize;
  int tempSize;
} _CGProc, *CGProc;

/* CGProc Prototypes */

#ifdef __ANSI_C__
CGProc CGProcDuplicate(CGProc);
CGProc CGProcNew(Token,Queue,Queue,Queue,Expression,Expression,Type);
CGProc CGProcUpdate(CGProc,Token,Queue,Queue,Queue,Expression,Expression,Type);
#else
CGProc CGProcDuplicate();
CGProc CGProcNew();
CGProc CGProcUpdate();
#endif

/* CGVar Structure */

typedef struct _CGVar {
  Token name;
  Type type;
  int align;
  LocType location;
  int offset;
  int position;
  int size;
  struct _MValue* value;
} _CGVar, *CGVar;

/* CGVar Prototypes */

#ifdef __ANSI_C__
CGVar CGVarDuplicate(CGVar);
CGVar CGVarNew(Token,Type);
CGVar CGVarUpdate(CGVar,Token,Type);
#else
CGVar CGVarDuplicate();
CGVar CGVarNew();
CGVar CGVarUpdate();
#endif

/* Disp Enumeration */

typedef enum {
  DispDataLabelTag,
  DispNamedLabelTag,
  DispNumberTag,
  DispTempLabelTag,
  DispTagCount
} DispTags;

/* Disp Slots */

struct _DispDataLabel {
  int number;
};

struct _DispNamedLabel {
  char *name;
};

struct _DispNumber {
  int number;
};

struct _DispTempLabel {
  int number;
};

typedef union {
  struct _DispDataLabel DataLabelSlot;
  struct _DispNamedLabel NamedLabelSlot;
  struct _DispNumber NumberSlot;
  struct _DispTempLabel TempLabelSlot;
} DispUnion;

/* Disp Structure */

typedef struct _Disp {
  DispTags tag;
  DispUnion U;
} _Disp, *Disp;

/* Disp Macros */

#define DispDataLabelSlot(n) (n->U.DataLabelSlot)
#define DispNamedLabelSlot(n) (n->U.NamedLabelSlot)
#define DispNumberSlot(n) (n->U.NumberSlot)
#define DispTempLabelSlot(n) (n->U.TempLabelSlot)

/* Disp Prototypes */

#ifdef __ANSI_C__
Disp DispDataLabelDuplicate(Disp);
Disp DispDataLabelNew(int);
Disp DispDataLabelUpdate(Disp,int);
Disp DispNamedLabelDuplicate(Disp);
Disp DispNamedLabelNew(char*);
Disp DispNamedLabelUpdate(Disp,char*);
Disp DispNumberDuplicate(Disp);
Disp DispNumberNew(int);
Disp DispNumberUpdate(Disp,int);
Disp DispTempLabelDuplicate(Disp);
Disp DispTempLabelNew(int);
Disp DispTempLabelUpdate(Disp,int);
#else
Disp DispDataLabelDuplicate();
Disp DispDataLabelNew();
Disp DispDataLabelUpdate();
Disp DispNamedLabelDuplicate();
Disp DispNamedLabelNew();
Disp DispNamedLabelUpdate();
Disp DispNumberDuplicate();
Disp DispNumberNew();
Disp DispNumberUpdate();
Disp DispTempLabelDuplicate();
Disp DispTempLabelNew();
Disp DispTempLabelUpdate();
#endif

/* Insn Enumeration */

typedef enum {
  InsnAlignTag,
  InsnCommentTag,
  InsnDataModeTag,
  InsnDocumentTag,
  InsnGlobalTag,
  InsnMInsnTag,
  InsnNamedDataTag,
  InsnNamedLabelTag,
  InsnQueueTag,
  InsnRSTag,
  InsnSSTag,
  InsnTempDataTag,
  InsnTempLabelTag,
  InsnTextModeTag,
  InsnTagCount
} InsnTags;

/* Insn Slots */

struct _InsnAlign {
  int number;
};

struct _InsnComment {
  char *text;
};

struct _InsnDataMode {
  char AptParsingTools;
};

struct _InsnDocument {
  CGVar var;
};

struct _InsnGlobal {
  char *label;
};

struct _InsnMInsn {
  struct _MInsn* mi;
};

struct _InsnNamedData {
  char *name;
  struct _MValue* value;
};

struct _InsnNamedLabel {
  char *name;
};

struct _InsnQueue {
  Queue queue;
};

struct _InsnRS {
  int number1;
  int number2;
};

struct _InsnSS {
  int number1;
  int number2;
};

struct _InsnTempData {
  int number;
  struct _MValue* value;
};

struct _InsnTempLabel {
  int number;
};

struct _InsnTextMode {
  char AptParsingTools;
};

typedef union {
  struct _InsnAlign AlignSlot;
  struct _InsnComment CommentSlot;
  struct _InsnDataMode DataModeSlot;
  struct _InsnDocument DocumentSlot;
  struct _InsnGlobal GlobalSlot;
  struct _InsnMInsn MInsnSlot;
  struct _InsnNamedData NamedDataSlot;
  struct _InsnNamedLabel NamedLabelSlot;
  struct _InsnQueue QueueSlot;
  struct _InsnRS RSSlot;
  struct _InsnSS SSSlot;
  struct _InsnTempData TempDataSlot;
  struct _InsnTempLabel TempLabelSlot;
  struct _InsnTextMode TextModeSlot;
} InsnUnion;

/* Insn Structure */

typedef struct _Insn {
  InsnTags tag;
  InsnUnion U;
} _Insn, *Insn;

/* Insn Macros */

#define InsnAlignSlot(n) (n->U.AlignSlot)
#define InsnCommentSlot(n) (n->U.CommentSlot)
#define InsnDataModeSlot(n) (n->U.DataModeSlot)
#define InsnDocumentSlot(n) (n->U.DocumentSlot)
#define InsnGlobalSlot(n) (n->U.GlobalSlot)
#define InsnMInsnSlot(n) (n->U.MInsnSlot)
#define InsnNamedDataSlot(n) (n->U.NamedDataSlot)
#define InsnNamedLabelSlot(n) (n->U.NamedLabelSlot)
#define InsnQueueSlot(n) (n->U.QueueSlot)
#define InsnRSSlot(n) (n->U.RSSlot)
#define InsnSSSlot(n) (n->U.SSSlot)
#define InsnTempDataSlot(n) (n->U.TempDataSlot)
#define InsnTempLabelSlot(n) (n->U.TempLabelSlot)
#define InsnTextModeSlot(n) (n->U.TextModeSlot)

/* Insn Prototypes */

#ifdef __ANSI_C__
Insn InsnAlignDuplicate(Insn);
Insn InsnAlignNew(int);
Insn InsnAlignUpdate(Insn,int);
Insn InsnCommentDuplicate(Insn);
Insn InsnCommentNew(char*);
Insn InsnCommentUpdate(Insn,char*);
Insn InsnDataModeDuplicate(Insn);
Insn InsnDataModeNew(void);
Insn InsnDataModeUpdate(Insn);
Insn InsnDocumentDuplicate(Insn);
Insn InsnDocumentNew(CGVar);
Insn InsnDocumentUpdate(Insn,CGVar);
Insn InsnGlobalDuplicate(Insn);
Insn InsnGlobalNew(char*);
Insn InsnGlobalUpdate(Insn,char*);
Insn InsnMInsnDuplicate(Insn);
Insn InsnMInsnNew(struct _MInsn*);
Insn InsnMInsnUpdate(Insn,struct _MInsn*);
Insn InsnNamedDataDuplicate(Insn);
Insn InsnNamedDataNew(char*,struct _MValue*);
Insn InsnNamedDataUpdate(Insn,char*,struct _MValue*);
Insn InsnNamedLabelDuplicate(Insn);
Insn InsnNamedLabelNew(char*);
Insn InsnNamedLabelUpdate(Insn,char*);
Insn InsnQueueDuplicate(Insn);
Insn InsnQueueNew(Queue);
Insn InsnQueueUpdate(Insn,Queue);
Insn InsnRSDuplicate(Insn);
Insn InsnRSNew(int,int);
Insn InsnRSUpdate(Insn,int,int);
Insn InsnSSDuplicate(Insn);
Insn InsnSSNew(int,int);
Insn InsnSSUpdate(Insn,int,int);
Insn InsnTempDataDuplicate(Insn);
Insn InsnTempDataNew(int,struct _MValue*);
Insn InsnTempDataUpdate(Insn,int,struct _MValue*);
Insn InsnTempLabelDuplicate(Insn);
Insn InsnTempLabelNew(int);
Insn InsnTempLabelUpdate(Insn,int);
Insn InsnTextModeDuplicate(Insn);
Insn InsnTextModeNew(void);
Insn InsnTextModeUpdate(Insn);
#else
Insn InsnAlignDuplicate();
Insn InsnAlignNew();
Insn InsnAlignUpdate();
Insn InsnCommentDuplicate();
Insn InsnCommentNew();
Insn InsnCommentUpdate();
Insn InsnDataModeDuplicate();
Insn InsnDataModeNew();
Insn InsnDataModeUpdate();
Insn InsnDocumentDuplicate();
Insn InsnDocumentNew();
Insn InsnDocumentUpdate();
Insn InsnGlobalDuplicate();
Insn InsnGlobalNew();
Insn InsnGlobalUpdate();
Insn InsnMInsnDuplicate();
Insn InsnMInsnNew();
Insn InsnMInsnUpdate();
Insn InsnNamedDataDuplicate();
Insn InsnNamedDataNew();
Insn InsnNamedDataUpdate();
Insn InsnNamedLabelDuplicate();
Insn InsnNamedLabelNew();
Insn InsnNamedLabelUpdate();
Insn InsnQueueDuplicate();
Insn InsnQueueNew();
Insn InsnQueueUpdate();
Insn InsnRSDuplicate();
Insn InsnRSNew();
Insn InsnRSUpdate();
Insn InsnSSDuplicate();
Insn InsnSSNew();
Insn InsnSSUpdate();
Insn InsnTempDataDuplicate();
Insn InsnTempDataNew();
Insn InsnTempDataUpdate();
Insn InsnTempLabelDuplicate();
Insn InsnTempLabelNew();
Insn InsnTempLabelUpdate();
Insn InsnTextModeDuplicate();
Insn InsnTextModeNew();
Insn InsnTextModeUpdate();
#endif

/* MInsn Enumeration */

typedef enum {
  MInsnAbsoluteValueTag,
  MInsnAddTag,
  MInsnAddQuickTag,
  MInsnAdjustStackPointerTag,
  MInsnAndTag,
  MInsnArithmeticComplementTag,
  MInsnArithmeticShiftTag,
  MInsnBranchTag,
  MInsnBranchToSubroutineTag,
  MInsnCompareTag,
  MInsnCompareMultipleTag,
  MInsnCompareQuickTag,
  MInsnConvertDFTag,
  MInsnConvertFDTag,
  MInsnDivideTag,
  MInsnEffectiveAddressTag,
  MInsnEnterTag,
  MInsnExitTag,
  MInsnJumpTag,
  MInsnJumpToSubroutineTag,
  MInsnLoadProcessorRegisterTag,
  MInsnLogicalComplementTag,
  MInsnLogicalShiftTag,
  MInsnModulusTag,
  MInsnMoveTag,
  MInsnMoveMultipleTag,
  MInsnMoveQuickTag,
  MInsnMultiplyTag,
  MInsnNegateTag,
  MInsnNoOperationTag,
  MInsnOrTag,
  MInsnQueueTag,
  MInsnQuotientTag,
  MInsnRemainderTag,
  MInsnReturnTag,
  MInsnRotateTag,
  MInsnStoreProcessorRegisterTag,
  MInsnSubtractTag,
  MInsnXorTag,
  MInsnTagCount
} MInsnTags;

/* MInsn Slots */

struct _MInsnAbsoluteValue {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnAdd {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnAddQuick {
  DataType dt;
  int src;
  Addr dest;
};

struct _MInsnAdjustStackPointer {
  DataType dt;
  Addr src;
};

struct _MInsnAnd {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnArithmeticComplement {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnArithmeticShift {
  DataType dt;
  Addr count;
  Addr dest;
};

struct _MInsnBranch {
  Condition cond;
  Disp dest;
};

struct _MInsnBranchToSubroutine {
  Disp dest;
};

struct _MInsnCompare {
  DataType dt;
  Addr src1;
  Addr src2;
};

struct _MInsnCompareMultiple {
  DataType dt;
  Addr block1;
  Addr block2;
  int length;
};

struct _MInsnCompareQuick {
  DataType dt;
  int src1;
  Addr src2;
};

struct _MInsnConvertDF {
  Addr src;
  Addr dest;
};

struct _MInsnConvertFD {
  Addr src;
  Addr dest;
};

struct _MInsnDivide {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnEffectiveAddress {
  Addr src;
  Addr dest;
};

struct _MInsnEnter {
  Queue regs;
  int disp;
};

struct _MInsnExit {
  Queue regs;
};

struct _MInsnJump {
  Addr dest;
};

struct _MInsnJumpToSubroutine {
  Addr dest;
};

struct _MInsnLoadProcessorRegister {
  DataType dt;
  ProcReg procreg;
  Addr src;
};

struct _MInsnLogicalComplement {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnLogicalShift {
  DataType dt;
  Addr count;
  Addr dest;
};

struct _MInsnModulus {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnMove {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnMoveMultiple {
  DataType dt;
  Addr block1;
  Addr block2;
  int length;
};

struct _MInsnMoveQuick {
  DataType dt;
  int src;
  Addr dest;
};

struct _MInsnMultiply {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnNegate {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnNoOperation {
  char AptParsingTools;
};

struct _MInsnOr {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnQueue {
  Queue queue;
};

struct _MInsnQuotient {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnRemainder {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnReturn {
  int constant;
};

struct _MInsnRotate {
  DataType dt;
  Addr count;
  Addr dest;
};

struct _MInsnStoreProcessorRegister {
  DataType dt;
  ProcReg procreg;
  Addr dest;
};

struct _MInsnSubtract {
  DataType dt;
  Addr src;
  Addr dest;
};

struct _MInsnXor {
  DataType dt;
  Addr src;
  Addr dest;
};

typedef union {
  struct _MInsnAbsoluteValue AbsoluteValueSlot;
  struct _MInsnAdd AddSlot;
  struct _MInsnAddQuick AddQuickSlot;
  struct _MInsnAdjustStackPointer AdjustStackPointerSlot;
  struct _MInsnAnd AndSlot;
  struct _MInsnArithmeticComplement ArithmeticComplementSlot;
  struct _MInsnArithmeticShift ArithmeticShiftSlot;
  struct _MInsnBranch BranchSlot;
  struct _MInsnBranchToSubroutine BranchToSubroutineSlot;
  struct _MInsnCompare CompareSlot;
  struct _MInsnCompareMultiple CompareMultipleSlot;
  struct _MInsnCompareQuick CompareQuickSlot;
  struct _MInsnConvertDF ConvertDFSlot;
  struct _MInsnConvertFD ConvertFDSlot;
  struct _MInsnDivide DivideSlot;
  struct _MInsnEffectiveAddress EffectiveAddressSlot;
  struct _MInsnEnter EnterSlot;
  struct _MInsnExit ExitSlot;
  struct _MInsnJump JumpSlot;
  struct _MInsnJumpToSubroutine JumpToSubroutineSlot;
  struct _MInsnLoadProcessorRegister LoadProcessorRegisterSlot;
  struct _MInsnLogicalComplement LogicalComplementSlot;
  struct _MInsnLogicalShift LogicalShiftSlot;
  struct _MInsnModulus ModulusSlot;
  struct _MInsnMove MoveSlot;
  struct _MInsnMoveMultiple MoveMultipleSlot;
  struct _MInsnMoveQuick MoveQuickSlot;
  struct _MInsnMultiply MultiplySlot;
  struct _MInsnNegate NegateSlot;
  struct _MInsnNoOperation NoOperationSlot;
  struct _MInsnOr OrSlot;
  struct _MInsnQueue QueueSlot;
  struct _MInsnQuotient QuotientSlot;
  struct _MInsnRemainder RemainderSlot;
  struct _MInsnReturn ReturnSlot;
  struct _MInsnRotate RotateSlot;
  struct _MInsnStoreProcessorRegister StoreProcessorRegisterSlot;
  struct _MInsnSubtract SubtractSlot;
  struct _MInsnXor XorSlot;
} MInsnUnion;

/* MInsn Structure */

typedef struct _MInsn {
  MInsnTags tag;
  MInsnUnion U;
} _MInsn, *MInsn;

/* MInsn Macros */

#define MInsnAbsoluteValueSlot(n) (n->U.AbsoluteValueSlot)
#define MInsnAddSlot(n) (n->U.AddSlot)
#define MInsnAddQuickSlot(n) (n->U.AddQuickSlot)
#define MInsnAdjustStackPointerSlot(n) (n->U.AdjustStackPointerSlot)
#define MInsnAndSlot(n) (n->U.AndSlot)
#define MInsnArithmeticComplementSlot(n) (n->U.ArithmeticComplementSlot)
#define MInsnArithmeticShiftSlot(n) (n->U.ArithmeticShiftSlot)
#define MInsnBranchSlot(n) (n->U.BranchSlot)
#define MInsnBranchToSubroutineSlot(n) (n->U.BranchToSubroutineSlot)
#define MInsnCompareSlot(n) (n->U.CompareSlot)
#define MInsnCompareMultipleSlot(n) (n->U.CompareMultipleSlot)
#define MInsnCompareQuickSlot(n) (n->U.CompareQuickSlot)
#define MInsnConvertDFSlot(n) (n->U.ConvertDFSlot)
#define MInsnConvertFDSlot(n) (n->U.ConvertFDSlot)
#define MInsnDivideSlot(n) (n->U.DivideSlot)
#define MInsnEffectiveAddressSlot(n) (n->U.EffectiveAddressSlot)
#define MInsnEnterSlot(n) (n->U.EnterSlot)
#define MInsnExitSlot(n) (n->U.ExitSlot)
#define MInsnJumpSlot(n) (n->U.JumpSlot)
#define MInsnJumpToSubroutineSlot(n) (n->U.JumpToSubroutineSlot)
#define MInsnLoadProcessorRegisterSlot(n) (n->U.LoadProcessorRegisterSlot)
#define MInsnLogicalComplementSlot(n) (n->U.LogicalComplementSlot)
#define MInsnLogicalShiftSlot(n) (n->U.LogicalShiftSlot)
#define MInsnModulusSlot(n) (n->U.ModulusSlot)
#define MInsnMoveSlot(n) (n->U.MoveSlot)
#define MInsnMoveMultipleSlot(n) (n->U.MoveMultipleSlot)
#define MInsnMoveQuickSlot(n) (n->U.MoveQuickSlot)
#define MInsnMultiplySlot(n) (n->U.MultiplySlot)
#define MInsnNegateSlot(n) (n->U.NegateSlot)
#define MInsnNoOperationSlot(n) (n->U.NoOperationSlot)
#define MInsnOrSlot(n) (n->U.OrSlot)
#define MInsnQueueSlot(n) (n->U.QueueSlot)
#define MInsnQuotientSlot(n) (n->U.QuotientSlot)
#define MInsnRemainderSlot(n) (n->U.RemainderSlot)
#define MInsnReturnSlot(n) (n->U.ReturnSlot)
#define MInsnRotateSlot(n) (n->U.RotateSlot)
#define MInsnStoreProcessorRegisterSlot(n) (n->U.StoreProcessorRegisterSlot)
#define MInsnSubtractSlot(n) (n->U.SubtractSlot)
#define MInsnXorSlot(n) (n->U.XorSlot)

/* MInsn Prototypes */

#ifdef __ANSI_C__
MInsn MInsnAbsoluteValueDuplicate(MInsn);
MInsn MInsnAbsoluteValueNew(DataType,Addr,Addr);
MInsn MInsnAbsoluteValueUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnAddDuplicate(MInsn);
MInsn MInsnAddNew(DataType,Addr,Addr);
MInsn MInsnAddUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnAddQuickDuplicate(MInsn);
MInsn MInsnAddQuickNew(DataType,int,Addr);
MInsn MInsnAddQuickUpdate(MInsn,DataType,int,Addr);
MInsn MInsnAdjustStackPointerDuplicate(MInsn);
MInsn MInsnAdjustStackPointerNew(DataType,Addr);
MInsn MInsnAdjustStackPointerUpdate(MInsn,DataType,Addr);
MInsn MInsnAndDuplicate(MInsn);
MInsn MInsnAndNew(DataType,Addr,Addr);
MInsn MInsnAndUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnArithmeticComplementDuplicate(MInsn);
MInsn MInsnArithmeticComplementNew(DataType,Addr,Addr);
MInsn MInsnArithmeticComplementUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnArithmeticShiftDuplicate(MInsn);
MInsn MInsnArithmeticShiftNew(DataType,Addr,Addr);
MInsn MInsnArithmeticShiftUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnBranchDuplicate(MInsn);
MInsn MInsnBranchNew(Condition,Disp);
MInsn MInsnBranchUpdate(MInsn,Condition,Disp);
MInsn MInsnBranchToSubroutineDuplicate(MInsn);
MInsn MInsnBranchToSubroutineNew(Disp);
MInsn MInsnBranchToSubroutineUpdate(MInsn,Disp);
MInsn MInsnCompareDuplicate(MInsn);
MInsn MInsnCompareNew(DataType,Addr,Addr);
MInsn MInsnCompareUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnCompareMultipleDuplicate(MInsn);
MInsn MInsnCompareMultipleNew(DataType,Addr,Addr,int);
MInsn MInsnCompareMultipleUpdate(MInsn,DataType,Addr,Addr,int);
MInsn MInsnCompareQuickDuplicate(MInsn);
MInsn MInsnCompareQuickNew(DataType,int,Addr);
MInsn MInsnCompareQuickUpdate(MInsn,DataType,int,Addr);
MInsn MInsnConvertDFDuplicate(MInsn);
MInsn MInsnConvertDFNew(Addr,Addr);
MInsn MInsnConvertDFUpdate(MInsn,Addr,Addr);
MInsn MInsnConvertFDDuplicate(MInsn);
MInsn MInsnConvertFDNew(Addr,Addr);
MInsn MInsnConvertFDUpdate(MInsn,Addr,Addr);
MInsn MInsnDivideDuplicate(MInsn);
MInsn MInsnDivideNew(DataType,Addr,Addr);
MInsn MInsnDivideUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnEffectiveAddressDuplicate(MInsn);
MInsn MInsnEffectiveAddressNew(Addr,Addr);
MInsn MInsnEffectiveAddressUpdate(MInsn,Addr,Addr);
MInsn MInsnEnterDuplicate(MInsn);
MInsn MInsnEnterNew(Queue,int);
MInsn MInsnEnterUpdate(MInsn,Queue,int);
MInsn MInsnExitDuplicate(MInsn);
MInsn MInsnExitNew(Queue);
MInsn MInsnExitUpdate(MInsn,Queue);
MInsn MInsnJumpDuplicate(MInsn);
MInsn MInsnJumpNew(Addr);
MInsn MInsnJumpUpdate(MInsn,Addr);
MInsn MInsnJumpToSubroutineDuplicate(MInsn);
MInsn MInsnJumpToSubroutineNew(Addr);
MInsn MInsnJumpToSubroutineUpdate(MInsn,Addr);
MInsn MInsnLoadProcessorRegisterDuplicate(MInsn);
MInsn MInsnLoadProcessorRegisterNew(DataType,ProcReg,Addr);
MInsn MInsnLoadProcessorRegisterUpdate(MInsn,DataType,ProcReg,Addr);
MInsn MInsnLogicalComplementDuplicate(MInsn);
MInsn MInsnLogicalComplementNew(DataType,Addr,Addr);
MInsn MInsnLogicalComplementUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnLogicalShiftDuplicate(MInsn);
MInsn MInsnLogicalShiftNew(DataType,Addr,Addr);
MInsn MInsnLogicalShiftUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnModulusDuplicate(MInsn);
MInsn MInsnModulusNew(DataType,Addr,Addr);
MInsn MInsnModulusUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnMoveDuplicate(MInsn);
MInsn MInsnMoveNew(DataType,Addr,Addr);
MInsn MInsnMoveUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnMoveMultipleDuplicate(MInsn);
MInsn MInsnMoveMultipleNew(DataType,Addr,Addr,int);
MInsn MInsnMoveMultipleUpdate(MInsn,DataType,Addr,Addr,int);
MInsn MInsnMoveQuickDuplicate(MInsn);
MInsn MInsnMoveQuickNew(DataType,int,Addr);
MInsn MInsnMoveQuickUpdate(MInsn,DataType,int,Addr);
MInsn MInsnMultiplyDuplicate(MInsn);
MInsn MInsnMultiplyNew(DataType,Addr,Addr);
MInsn MInsnMultiplyUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnNegateDuplicate(MInsn);
MInsn MInsnNegateNew(DataType,Addr,Addr);
MInsn MInsnNegateUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnNoOperationDuplicate(MInsn);
MInsn MInsnNoOperationNew(void);
MInsn MInsnNoOperationUpdate(MInsn);
MInsn MInsnOrDuplicate(MInsn);
MInsn MInsnOrNew(DataType,Addr,Addr);
MInsn MInsnOrUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnQueueDuplicate(MInsn);
MInsn MInsnQueueNew(Queue);
MInsn MInsnQueueUpdate(MInsn,Queue);
MInsn MInsnQuotientDuplicate(MInsn);
MInsn MInsnQuotientNew(DataType,Addr,Addr);
MInsn MInsnQuotientUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnRemainderDuplicate(MInsn);
MInsn MInsnRemainderNew(DataType,Addr,Addr);
MInsn MInsnRemainderUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnReturnDuplicate(MInsn);
MInsn MInsnReturnNew(int);
MInsn MInsnReturnUpdate(MInsn,int);
MInsn MInsnRotateDuplicate(MInsn);
MInsn MInsnRotateNew(DataType,Addr,Addr);
MInsn MInsnRotateUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnStoreProcessorRegisterDuplicate(MInsn);
MInsn MInsnStoreProcessorRegisterNew(DataType,ProcReg,Addr);
MInsn MInsnStoreProcessorRegisterUpdate(MInsn,DataType,ProcReg,Addr);
MInsn MInsnSubtractDuplicate(MInsn);
MInsn MInsnSubtractNew(DataType,Addr,Addr);
MInsn MInsnSubtractUpdate(MInsn,DataType,Addr,Addr);
MInsn MInsnXorDuplicate(MInsn);
MInsn MInsnXorNew(DataType,Addr,Addr);
MInsn MInsnXorUpdate(MInsn,DataType,Addr,Addr);
#else
MInsn MInsnAbsoluteValueDuplicate();
MInsn MInsnAbsoluteValueNew();
MInsn MInsnAbsoluteValueUpdate();
MInsn MInsnAddDuplicate();
MInsn MInsnAddNew();
MInsn MInsnAddUpdate();
MInsn MInsnAddQuickDuplicate();
MInsn MInsnAddQuickNew();
MInsn MInsnAddQuickUpdate();
MInsn MInsnAdjustStackPointerDuplicate();
MInsn MInsnAdjustStackPointerNew();
MInsn MInsnAdjustStackPointerUpdate();
MInsn MInsnAndDuplicate();
MInsn MInsnAndNew();
MInsn MInsnAndUpdate();
MInsn MInsnArithmeticComplementDuplicate();
MInsn MInsnArithmeticComplementNew();
MInsn MInsnArithmeticComplementUpdate();
MInsn MInsnArithmeticShiftDuplicate();
MInsn MInsnArithmeticShiftNew();
MInsn MInsnArithmeticShiftUpdate();
MInsn MInsnBranchDuplicate();
MInsn MInsnBranchNew();
MInsn MInsnBranchUpdate();
MInsn MInsnBranchToSubroutineDuplicate();
MInsn MInsnBranchToSubroutineNew();
MInsn MInsnBranchToSubroutineUpdate();
MInsn MInsnCompareDuplicate();
MInsn MInsnCompareNew();
MInsn MInsnCompareUpdate();
MInsn MInsnCompareMultipleDuplicate();
MInsn MInsnCompareMultipleNew();
MInsn MInsnCompareMultipleUpdate();
MInsn MInsnCompareQuickDuplicate();
MInsn MInsnCompareQuickNew();
MInsn MInsnCompareQuickUpdate();
MInsn MInsnConvertDFDuplicate();
MInsn MInsnConvertDFNew();
MInsn MInsnConvertDFUpdate();
MInsn MInsnConvertFDDuplicate();
MInsn MInsnConvertFDNew();
MInsn MInsnConvertFDUpdate();
MInsn MInsnDivideDuplicate();
MInsn MInsnDivideNew();
MInsn MInsnDivideUpdate();
MInsn MInsnEffectiveAddressDuplicate();
MInsn MInsnEffectiveAddressNew();
MInsn MInsnEffectiveAddressUpdate();
MInsn MInsnEnterDuplicate();
MInsn MInsnEnterNew();
MInsn MInsnEnterUpdate();
MInsn MInsnExitDuplicate();
MInsn MInsnExitNew();
MInsn MInsnExitUpdate();
MInsn MInsnJumpDuplicate();
MInsn MInsnJumpNew();
MInsn MInsnJumpUpdate();
MInsn MInsnJumpToSubroutineDuplicate();
MInsn MInsnJumpToSubroutineNew();
MInsn MInsnJumpToSubroutineUpdate();
MInsn MInsnLoadProcessorRegisterDuplicate();
MInsn MInsnLoadProcessorRegisterNew();
MInsn MInsnLoadProcessorRegisterUpdate();
MInsn MInsnLogicalComplementDuplicate();
MInsn MInsnLogicalComplementNew();
MInsn MInsnLogicalComplementUpdate();
MInsn MInsnLogicalShiftDuplicate();
MInsn MInsnLogicalShiftNew();
MInsn MInsnLogicalShiftUpdate();
MInsn MInsnModulusDuplicate();
MInsn MInsnModulusNew();
MInsn MInsnModulusUpdate();
MInsn MInsnMoveDuplicate();
MInsn MInsnMoveNew();
MInsn MInsnMoveUpdate();
MInsn MInsnMoveMultipleDuplicate();
MInsn MInsnMoveMultipleNew();
MInsn MInsnMoveMultipleUpdate();
MInsn MInsnMoveQuickDuplicate();
MInsn MInsnMoveQuickNew();
MInsn MInsnMoveQuickUpdate();
MInsn MInsnMultiplyDuplicate();
MInsn MInsnMultiplyNew();
MInsn MInsnMultiplyUpdate();
MInsn MInsnNegateDuplicate();
MInsn MInsnNegateNew();
MInsn MInsnNegateUpdate();
MInsn MInsnNoOperationDuplicate();
MInsn MInsnNoOperationNew();
MInsn MInsnNoOperationUpdate();
MInsn MInsnOrDuplicate();
MInsn MInsnOrNew();
MInsn MInsnOrUpdate();
MInsn MInsnQueueDuplicate();
MInsn MInsnQueueNew();
MInsn MInsnQueueUpdate();
MInsn MInsnQuotientDuplicate();
MInsn MInsnQuotientNew();
MInsn MInsnQuotientUpdate();
MInsn MInsnRemainderDuplicate();
MInsn MInsnRemainderNew();
MInsn MInsnRemainderUpdate();
MInsn MInsnReturnDuplicate();
MInsn MInsnReturnNew();
MInsn MInsnReturnUpdate();
MInsn MInsnRotateDuplicate();
MInsn MInsnRotateNew();
MInsn MInsnRotateUpdate();
MInsn MInsnStoreProcessorRegisterDuplicate();
MInsn MInsnStoreProcessorRegisterNew();
MInsn MInsnStoreProcessorRegisterUpdate();
MInsn MInsnSubtractDuplicate();
MInsn MInsnSubtractNew();
MInsn MInsnSubtractUpdate();
MInsn MInsnXorDuplicate();
MInsn MInsnXorNew();
MInsn MInsnXorUpdate();
#endif

/* MValue Enumeration */

typedef enum {
  MValueByteTag,
  MValueWordTag,
  MValueDoubleWordTag,
  MValueFloatTag,
  MValueLongFloatTag,
  MValueCsetTag,
  MValueStringTag,
  MValueTagCount
} MValueTags;

/* MValue Slots */

struct _MValueByte {
  char value;
};

struct _MValueWord {
  short value;
};

struct _MValueDoubleWord {
  long value;
};

struct _MValueFloat {
  float value;
};

struct _MValueLongFloat {
  double value;
};

struct _MValueCset {
  char *value;
};

struct _MValueString {
  char *value;
};

typedef union {
  struct _MValueByte ByteSlot;
  struct _MValueWord WordSlot;
  struct _MValueDoubleWord DoubleWordSlot;
  struct _MValueFloat FloatSlot;
  struct _MValueLongFloat LongFloatSlot;
  struct _MValueCset CsetSlot;
  struct _MValueString StringSlot;
} MValueUnion;

/* MValue Structure */

typedef struct _MValue {
  MValueTags tag;
  MValueUnion U;
} _MValue, *MValue;

/* MValue Macros */

#define MValueByteSlot(n) (n->U.ByteSlot)
#define MValueWordSlot(n) (n->U.WordSlot)
#define MValueDoubleWordSlot(n) (n->U.DoubleWordSlot)
#define MValueFloatSlot(n) (n->U.FloatSlot)
#define MValueLongFloatSlot(n) (n->U.LongFloatSlot)
#define MValueCsetSlot(n) (n->U.CsetSlot)
#define MValueStringSlot(n) (n->U.StringSlot)

/* MValue Prototypes */

#ifdef __ANSI_C__
MValue MValueByteDuplicate(MValue);
MValue MValueByteNew(char);
MValue MValueByteUpdate(MValue,char);
MValue MValueWordDuplicate(MValue);
MValue MValueWordNew(short);
MValue MValueWordUpdate(MValue,short);
MValue MValueDoubleWordDuplicate(MValue);
MValue MValueDoubleWordNew(long);
MValue MValueDoubleWordUpdate(MValue,long);
MValue MValueFloatDuplicate(MValue);
MValue MValueFloatNew(float);
MValue MValueFloatUpdate(MValue,float);
MValue MValueLongFloatDuplicate(MValue);
MValue MValueLongFloatNew(double);
MValue MValueLongFloatUpdate(MValue,double);
MValue MValueCsetDuplicate(MValue);
MValue MValueCsetNew(char*);
MValue MValueCsetUpdate(MValue,char*);
MValue MValueStringDuplicate(MValue);
MValue MValueStringNew(char*);
MValue MValueStringUpdate(MValue,char*);
#else
MValue MValueByteDuplicate();
MValue MValueByteNew();
MValue MValueByteUpdate();
MValue MValueWordDuplicate();
MValue MValueWordNew();
MValue MValueWordUpdate();
MValue MValueDoubleWordDuplicate();
MValue MValueDoubleWordNew();
MValue MValueDoubleWordUpdate();
MValue MValueFloatDuplicate();
MValue MValueFloatNew();
MValue MValueFloatUpdate();
MValue MValueLongFloatDuplicate();
MValue MValueLongFloatNew();
MValue MValueLongFloatUpdate();
MValue MValueCsetDuplicate();
MValue MValueCsetNew();
MValue MValueCsetUpdate();
MValue MValueStringDuplicate();
MValue MValueStringNew();
MValue MValueStringUpdate();
#endif

#endif /* icgnodes_h */
