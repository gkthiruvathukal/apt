/******************************************************************
**
** ADTERROR.H:
**
**    ADT Error Handler
**
** This file is part of Apt Abstrct Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
******************************************************************/
#ifndef ADTERROR_H
#define ADTERROR_H

#include "cheaders.h"

/* ADT Names */

#define ADT_AStack               "Array Stack"
#define ADT_AStackIter           "Array Stack Iterator"
#define ADT_Buffer               "Buffer"
#define ADT_BufferIO             "Buffered I/O"
#define ADT_Deque                "Deque"
#define ADT_DequeIter            "Deque Iterator"
#define ADT_HashTable            "Hash Table"
#define ADT_HashTableIter        "Hash Table Iterator"
#define ADT_Queue                "Queue"
#define ADT_QueueIter            "Queue Iterator"
#define ADT_Stack                "Stack"
#define ADT_StackIter            "Stack Iterator"
#define ADT_Table                "AVL Table"
#define ADT_TableIter            "AVL Table Iterator"
#define ADT_Tree                 "AVL Tree"
#define ADT_TreeIter             "AVL Tree Iterator"

/* ADT Error Codes */

typedef enum _ADTErrorCodes {
  E_Allocation,
  E_NullQueue,
  E_NullQueueIter,
  E_Seek,
  E_SeekOverflow,
  E_SeekUnderflow,

  E_Undefined
} ADTErrorCodes;

typedef enum _ADTWarningCodes {
  W_Undefined
} ADTWarningCodes;

/* ADT Error Handler */

#ifdef __ANSI_C__

void ADTError(char *name, ADTErrorCodes error, char *proc);
void ADTWarning(char *name, ADTWarningCodes warning, char *proc);

#else

void ADTError();
void ADTWarning();

#endif

#endif
