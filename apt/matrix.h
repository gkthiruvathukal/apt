/******************************************************************
**
** MATRIX.H:
**
**    APT Matrix Routines
**
** This file is part of Apt Parsing Tool (APT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef MATRIX_H
#define MATRIX_H

/* ---------- Types */

typedef struct _MATRIX {
	short *matrix;
  short *ia;
  short *ja;
} MATRIX;

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
short **cmultiply(struct _MATRIX*, short **, int);
void compress(short**, int, struct _MATRIX*);
void free_cmp(struct _MATRIX*);
void free_matrix(short**, int, int, int, int);
short **imatrix(int, int, int, int);
void Product(short**, short**, short**, int);
void Transpose(short**, int);
int Zeroes(short**, int);
#else
short **cmultiply();
void compress();
void free_cmp();
void free_matrix();
short **imatrix();
int Zeroes();
void Transpose();
#endif /* __ANSI_C__ */

#endif /* MATRIX_H */
