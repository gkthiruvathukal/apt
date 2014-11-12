/******************************************************************
**
** PREDICT.H:
**
**    APT Prediction Table Construction
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef PREDICT_H
#define PREDICT_H

/* ---------- Headers */

#include "apt.h"

/* ---------- Exported Variables */

EXTERN short **ll_predict;
EXTERN int PredictionCount;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
int ComputeLLPredictionTable(void);
#else
int ComputeLLPredictionTable();
#endif /* __ANSI_C__ */

#endif /* PREDICT_H */
