/******************************************************************
**
** APTLIB.C:
**
**    APT RTS Library
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"
/* ---------- Headers */

#include "apt.h"

#include "aptlib.h"
#include "astlib.h"

#include "astack.h"
#include "buffer.h"
#include "bufio.h"
#include "gprintf.h"
#include "sstring.h"

/* ---------- Defines */

#ifndef APT_NCHARS
#define APT_NCHARS "\n"
#endif

#ifndef APT_WCHARS
#define APT_WCHARS " \t\n"
#endif

#define AllocationError    200
#define CannotOpenFileIn   201
#define CannotOpenFileOut  202
#define EOPMError          203
#define MatchError         204
#define PredictionError    205

/* ---------- Private Types */

typedef enum _EOPMCode {
  EOPM_Token = 1,
  EOPM_TokenImage,
  EOPM_Action
} EOPMCode;

/* ----------- Exported Globals */

PUBLIC AStack PredictionStack = NULL;
PUBLIC AStack SemanticStack = NULL;

/* ---------- Private Globals */

PRIVATE int ParseDebugOption[NumberOfParseDebugOptions] = { 0 };

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE void EmitEOPM(FILE*, int);
PRIVATE void EmitToken(FILE*, Token);
PRIVATE void ParseError(int, int, ...);
PRIVATE int PredictionAt(int, int);
PRIVATE ProductionTableElement ProductionAt(int);
PRIVATE SymbolType SymbolTypeAt(int);
#else
PRIVATE void EmitEOPM();
PRIVATE void EmitToken();
PRIVATE void ParseError();
PRIVATE int PredictionAt();
PRIVATE ProductionTableElement ProductionAt();
PRIVATE SymbolType SymbolTypeAt();
#endif /* __ANSI_C__ */

/* ---------- Functions */

/*
**
** EmitEOPM
**
*/
PRIVATE
#ifdef __ANSI_C__
void EmitEOPM(FILE *file, int action)
#else
void EmitEOPM(file,action)
FILE *file;
int action;
#endif
{
  gprintf(file,"%d ",EOPM_Action);
  gprintf(file,"%d\n",action);
}

/*
**
** EmitToken:
**
**   Emit a token to the EOPM File in the following fields:
**
**     record type  : TP (token printable) or TU (token binary)
**     token        : token value (integer)
**     token line   : line in source file where token occurs (integer)
**     token column : column in source file where token occurs (integer)
**     text length  : matched text length (integer)
**     text         : matched text (char *)
**
*/
PRIVATE
#ifdef __ANSI_C__
void EmitToken(FILE *file, Token token)
#else
void EmitToken(file,token)
FILE *file;
Token token;
#endif
{
  int printable;

  printable = StringPrintable(token->text);
  if (printable) gprintf(file,"%d ",EOPM_Token);
  else gprintf(file,"%d ",EOPM_TokenImage);
  gprintf(file,"%d ",token->type);
  gprintf(file,"%d ",token->line);
  gprintf(file,"%d ",token->column);
  gprintf(file,"%d ",StringLength(token->text));
  if (printable) gprintf(file,"%s\n",token->text);
  else gprintf(file,"%H\n",token->text);
}

/*
**
** Parse
**
*/
PUBLIC
#ifdef __ANSI_C__
void Parse(FILE *sourceFile, VOID_FN_TOKEN TokenPrinter)
#else
void Parse(sourceFile,TokenPrinter)
FILE *sourceFile;
VOID_FN_TOKEN TokenPrinter;
#endif
{
  int cnt;
  int prediction;
  ProductionTableElement production;
  Token token;
  short topOfStack;

  if (PredictionStack == NULL) return;
  if (SemanticStack == NULL) return;

  AStackPushWord(PredictionStack,(short)GoalSymbolValue);

  token = Scan(sourceFile);
  if (TokenPrinter && ParseDebugOption[DebugToken])
    (*TokenPrinter)(token);

  while (AStackNotEmpty(PredictionStack)) {

    if (ParseDebugOption[DebugPredictionStack])
      DumpPredictionStack(PredictionStack);
    if (ParseDebugOption[DebugSemanticStack])
      DumpSemanticStack(SemanticStack);

    topOfStack = AStackLookWord(PredictionStack);

    switch (SymbolTypeAt(topOfStack)) {

    case Action:
      AStackPopWord(PredictionStack);
      if (ParseDebugOption[DebugSemanticAction])
        gprintf(stdout,"Action: %s\n",SymbolTable[topOfStack].text);
      ActionAt(topOfStack)();
      break;

    case NonTerminal:
      prediction = PredictionAt(topOfStack,token->type);
      if (prediction >= 0) {
        AStackPopWord(PredictionStack);
        production = ProductionAt(prediction);
        for (cnt=production->lenRHS; cnt>0; cnt--)
          AStackPushWord(PredictionStack,production->RHS[cnt-1]);
      }
      else {
        ParseError(PredictionError,2,SymbolTable[topOfStack].text,token);
      }
      break;

    case Terminal:
      if (topOfStack == token->type) {
        AStackPopWord(PredictionStack);
        AStackPushPointer(SemanticStack,SSTENew(token));
        token = Scan(sourceFile);
        if (TokenPrinter && ParseDebugOption[DebugToken])
          (*TokenPrinter)(token);
      }
      else {
        ParseError(MatchError,2,SymbolTable[topOfStack].text,token);
      }
      break;
    }
  }
}

/*
**
** BuildTokenQueue
**
*/

#ifdef __ANSI_C__
Queue BuildTokenQueue(FILE *file, int EoF)
#else
Queue BuildTokenQueue(file,EoF)
FILE *file;
int EoF;
#endif
{
  Token t;
  Queue q;

  q = QueueNew();
  for(;;) {
    t = Scan(file);
    if (t == NULL)
      return q;
    QueuePut(q, t, 0);
    if (t->type == EoF)
      return q;
  } 
}

/*
**
** ParseEOPMIn
**
** Activities:
**   1. "Intermediate" file input
**   2. Semantic analysis
**
** Parameters:
**   eopmFile     : the file handle corresponding to the EOPM file
**   TokenPrinter : user-supplied entry point to function which prints a
**                  token
**
*/
PUBLIC
#ifdef __ANSI_C__
void ParseEOPMIn(FILE *eopmFile, VOID_FN_TOKEN TokenPrinter,
                 VOID_FN_CHAR PhasePrinter)
#else
void ParseEOPMIn(eopmFile,TokenPrinter,PhasePrinter)
FILE *eopmFile;
VOID_FN_TOKEN TokenPrinter;
VOID_FN_CHAR PhasePrinter;
#endif
{
  int action;
  char *buffer;
  char *chunk;
  EOPMCode code;
  int column;
  int error;
  int line;
  int phase;
  char *text;
  Token token;
  int type;

  if (PhaseTable == NULL) return;
  if (SemanticStack == NULL) return;

  for (phase=0; PhaseTable[phase] != NULL; phase++) {

    ActionTable = PhaseTable[phase];
    if (PhasePrinter) (*PhasePrinter)(PhaseName[phase]);

    rewind(eopmFile);
    buffer = BufIOGetString(eopmFile);

    while (buffer != NULL) {

      if (ParseDebugOption[DebugSemanticStack])
        DumpSemanticStack(SemanticStack);

      error = 1;

      if ((chunk = StringTokenize(buffer,APT_WCHARS)) == NULL) break;
      code = (EOPMCode)atoi(chunk);

      switch (code) {

      case EOPM_Token:
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        type = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        line = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        column = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        text = StringTokenize(NULL,APT_NCHARS);
        if (text == NULL) text = "";
        token = TokenNew(text,type,line,column);
        if (TokenPrinter && ParseDebugOption[DebugToken])
          (*TokenPrinter)(token);
        AStackPushPointer(SemanticStack,SSTENew(token));
        error = 0;
        break;

      case EOPM_TokenImage:
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        type = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        line = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        column = atoi(chunk);
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        text = StringTokenize(NULL,APT_NCHARS);
        if (text == NULL) text = "";
        token = TokenNew(text,type,line,column);
        if (TokenPrinter && ParseDebugOption[DebugToken])
          (*TokenPrinter)(token);
        AStackPushPointer(SemanticStack,SSTENew(token));
        error = 0;
        break;

      case EOPM_Action:
        if ((chunk = StringTokenize(NULL,APT_WCHARS)) == NULL) break;
        action = atoi(chunk);
        if (ParseDebugOption[DebugSemanticAction])
          gprintf(stdout,"Action: %s\n",SymbolTable[action].text);
        ActionAt(action)();
        error = 0;
        break;
      }

      if (error) {
        ParseError(EOPMError,1,chunk);
      }

      buffer = BufIOGetString(eopmFile);
    }
  }
}

/*
**
** ParseEOPMOut
** 
** Activities performed:
**   1. syntactic analysis
**   2. insertion of phrase markers in between terminal/action symbols
**   3. generation of "intermediate" file
**
** Parameters:
**   sourceFile   : file handle corresponding to the file being parsed
**   eopmFile     : file handle corresponding to the EOPM file (for output)
**   TokenPrinter : user-supplied entry point to a function which prints a
**                  token
**
*/
PUBLIC
#ifdef __ANSI_C__
void ParseEOPMOut(FILE *sourceFile,FILE *eopmFile, VOID_FN_TOKEN TokenPrinter,
                  INT_FN_TOKEN_ST CanSynchOnToken)
#else
void ParseEOPMOut(sourceFile,eopmFile,TokenPrinter,CanSynchOnToken)
FILE *sourceFile;
FILE *eopmFile;
VOID_FN_TOKEN TokenPrinter;
INT_FN_TOKEN_ST CanSynchOnToken;
#endif
{
  int cnt;
  int prediction;
  ProductionTableElement production;
  Token token;
  short topOfStack;

  if (PredictionStack == NULL) return;
  if (SemanticStack == NULL) return;

  AStackPushWord(PredictionStack,(short)GoalSymbolValue);

  token = Scan(sourceFile);
  if (TokenPrinter && ParseDebugOption[DebugToken])
    (*TokenPrinter)(token);

  while (AStackNotEmpty(PredictionStack)) {

    if (ParseDebugOption[DebugPredictionStack])
      DumpPredictionStack(PredictionStack);

    topOfStack = AStackLookWord(PredictionStack);

    switch (SymbolTypeAt(topOfStack)) {

    case Action:
      AStackPopWord(PredictionStack);
      EmitEOPM(eopmFile,topOfStack);
      break;

    case NonTerminal:
      prediction = PredictionAt(topOfStack,token->type);
      if (prediction >= 0) {
        AStackPopWord(PredictionStack);
        production = ProductionAt(prediction);
        for (cnt=production->lenRHS; cnt>0; cnt--)
          AStackPushWord(PredictionStack,production->RHS[cnt-1]);
      }
      else {
        if (CanSynchOnToken != NULL)
          if ((*CanSynchOnToken)(token, SymbolTypeAt(topOfStack)))
            token = Scan(sourceFile);
          else
            ParseError(PredictionError,2,SymbolTable[topOfStack].text,token);
        else
          ParseError(PredictionError,2,SymbolTable[topOfStack].text,token);
      }
      break;

    case Terminal:
      if (topOfStack == token->type) {
        AStackPopWord(PredictionStack);
        EmitToken(eopmFile,token);
        token = Scan(sourceFile);
        if (TokenPrinter && ParseDebugOption[DebugToken])
          (*TokenPrinter)(token);
      }
      else {
        if (CanSynchOnToken != NULL)
          if ((*CanSynchOnToken)(token, SymbolTypeAt(topOfStack)))
            token = Scan(sourceFile);
          else
            ParseError(MatchError,2,SymbolTable[topOfStack].text,token);
        else
          ParseError(MatchError,2,SymbolTable[topOfStack].text,token);
      }
      break;
    }
  }
}

/*
**
** ParseEOPMOutQ (a form of ParseEOPMOut which works with a Queue)
**
*/

PUBLIC
#ifdef __ANSI_C__
void ParseEOPMOutQ(Queue tokens, FILE *eopmFile, VOID_FN_TOKEN TokenPrinter,
                  INT_FN_TOKEN_ST CanSynchOnToken)
#else
void ParseEOPMOutQ(tokens, eopmFile,TokenPrinter,CanSynchOnToken)
Queue tokens;
FILE *eopmFile;
VOID_FN_TOKEN TokenPrinter;
INT_FN_TOKEN_ST CanSynchOnToken;
#endif
{
  int cnt;
  int prediction;
  ProductionTableElement production;
  Token token;
  short topOfStack;

  if (PredictionStack == NULL) return;
  if (SemanticStack == NULL) return;

  AStackPushWord(PredictionStack,(short)GoalSymbolValue);

  token = QueueGet(tokens);
  if (TokenPrinter && ParseDebugOption[DebugToken])
    (*TokenPrinter)(token);

  while (AStackNotEmpty(PredictionStack)) {

    if (ParseDebugOption[DebugPredictionStack])
      DumpPredictionStack(PredictionStack);

    topOfStack = AStackLookWord(PredictionStack);

    switch (SymbolTypeAt(topOfStack)) {

    case Action:
      AStackPopWord(PredictionStack);
      EmitEOPM(eopmFile,topOfStack);
      break;

    case NonTerminal:
      prediction = PredictionAt(topOfStack,token->type);
      if (prediction >= 0) {
        AStackPopWord(PredictionStack);
        production = ProductionAt(prediction);
        for (cnt=production->lenRHS; cnt>0; cnt--)
          AStackPushWord(PredictionStack,production->RHS[cnt-1]);
      }
      else {
        if (CanSynchOnToken != NULL)
          if ((*CanSynchOnToken)(token, SymbolTypeAt(topOfStack)))
            token = QueueGet(tokens);
          else
            ParseError(PredictionError,2,SymbolTable[topOfStack].text,token);
        else
          ParseError(PredictionError,2,SymbolTable[topOfStack].text,token);
      }
      break;

    case Terminal:
      if (topOfStack == token->type) {
        AStackPopWord(PredictionStack);
        EmitToken(eopmFile,token);
        token = QueueGet(tokens);
        if (TokenPrinter && ParseDebugOption[DebugToken])
          (*TokenPrinter)(token);
      }
      else {
        if (CanSynchOnToken != NULL)
          if ((*CanSynchOnToken)(token, SymbolTypeAt(topOfStack)))
            token = QueueGet(tokens);
          else
            ParseError(MatchError,2,SymbolTable[topOfStack].text,token);
        else
          ParseError(MatchError,2,SymbolTable[topOfStack].text,token);
      }
      break;
    }
  }
}
/*
**
** ParseError
**
*/
PRIVATE
#ifdef __ANSI_C__
void ParseError(int code, int num_arg, ...)
#else
void ParseError(va_alist)
va_dcl
#endif
{
#ifdef __ANSI_C__
  va_list ap;
#else
  va_list ap;
  int code;
  int num_arg;
#endif

#ifdef __ANSI_C__
  va_start(ap,num_arg);
#else
  va_start(ap);
  code = va_arg(ap, int);
  num_arg = va_arg(ap, int);
#endif

  switch (code) {
  case AllocationError:
    {
      int ref;
      ref = va_arg(ap,int);
      gprintf(stdout,"Error: Allocation failure; Check reference %d\n",ref);
    }
    break;


  case CannotOpenFileIn:
    {
      char *filename;
      filename = va_arg(ap,char*);
      gprintf(stdout,"Error: Cannot open '%s' for input\n",filename);
    }
    break;

  case CannotOpenFileOut:
    {
      char *filename;
      filename = va_arg(ap,char*);
      gprintf(stdout,"Error: Cannot open '%s' for output\n",filename);
    }
    break;

  case EOPMError:
    {
      char *text;

      text = va_arg(ap,char*);
      gprintf(stdout,"EOPM file produced unrecongnizable '%s'\n",text);
    }
    break;

  case MatchError:
    {
      char *terminal;
      Token token;

      terminal = va_arg(ap,char*);
      token = va_arg(ap,Token);
      gprintf(stdout,"(%d, %d): '%s' encountered when '%s' was expected\n",
        token->line,token->column,SymbolTable[token->type].text,terminal);
    }
    break;

  case PredictionError:
    {
      char *nonterminal;
      Token token;

      nonterminal = va_arg(ap,char *);
      token = va_arg(ap,Token);
      gprintf(stdout,"(%d, %d): '%s' cannot predict '%s'\n",token->line,
        token->column,nonterminal,token->text);
    }
    break;

  default:
    gprintf(stdout,"Error: Unknown error of unknown origin.\n");
  }

  va_end(ap);

  exit(1);
}

/*
**
** ParseInitialize
**
*/
PUBLIC
#ifdef __ANSI_C__
void ParseInitialize(void)
#else
void ParseInitialize()
#endif
{
  PredictionStack = AStackNew(PREDICTION_STACK_SIZE);
  SemanticStack = AStackNew(SEMANTIC_STACK_SIZE);
}

/*
**
** ParseTerminate
**
*/
PUBLIC
#ifdef __ANSI_C__
void ParseTerminate(void)
#else
void ParseTerminate()
#endif
{
  AStackDispose(PredictionStack,NULL);
  AStackDispose(SemanticStack,NULL);
}

/*
**
** PredictionAt
**
*/
PRIVATE
#ifdef __ANSI_C__
int PredictionAt(int nonTerminal, int terminal)
#else
int PredictionAt(nonTerminal,terminal)
int nonTerminal;
int terminal;
#endif
{
  PredictionTripleElement prediction;
  PredictionTripleElement start, stop;

  start = PredictionTriple + PredictIndexTable[nonTerminal];
  stop = PredictionTriple + PredictIndexTable[nonTerminal+1];

  for (prediction=start; prediction<stop; prediction++)
    if (prediction->terminal == terminal) return (prediction->production);

  return (ERROR);
}

/*
**
** ProductionAt
**
*/
PRIVATE
#ifdef __ANSI_C__
ProductionTableElement ProductionAt(int number)
#else
ProductionTableElement ProductionAt(number)
int number;
#endif
{
  return (&(ProductionTable[number]));
}

/*
**
** ResetDebugOption
**
*/
PUBLIC
#ifdef __ANSI_C__
void ResetDebugOption(ParseDebugOptions option)
#else
void ResetDebugOption(option)
ParseDebugOptions option;
#endif
{
  if (option >= LowOption && option < NumberOfParseDebugOptions)
    ParseDebugOption[option] = 0;
}

/*
**
** SetDebugOption
**
*/
PUBLIC
#ifdef __ANSI_C__
void SetDebugOption(ParseDebugOptions option)
#else
void SetDebugOption(option)
ParseDebugOptions option;
#endif
{
  if (option >= LowOption && option < NumberOfParseDebugOptions)
    ParseDebugOption[option] = 1;
}

/*
**
** SymbolTypeAt
**
*/
PRIVATE
#ifdef __ANSI_C__
SymbolType SymbolTypeAt(int symbol)
#else
SymbolType SymbolTypeAt(symbol)
int symbol;
#endif
{
  return (SymbolTable[symbol].type);
}
