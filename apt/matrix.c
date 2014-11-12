/******************************************************************
**
** MATRIX.C:
**
**    APT Matrix Routines
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
#include "allocate.h"
#include "matrix.h"
#include "gprintf.h"

/* ---------- Functions */

short **cmultiply(m1,m2,n)
MATRIX *m1;
short **m2;
int n;
{
  short **y;
  int i,j,k;

  y = imatrix(0,n,0,n);
  for (k=0; k < n; k++) /* for all columns */
    for (i=0; i < n; i++) /* for all rows */
      for (j=m1->ia[i]; j < m1->ia[i+1]; j++)
        if (!y[i][k])
#ifdef SHORT_MATRIX
          y[i][k] |= y[i][k] + m1->matrix[j] * m2[m1->ja[j]][k];
#else
          y[i][k] |= m2[m1->ja[j]][k];
#endif
  return (y);
}

/*
** compress():
**
**   transform a matrix "matrix" of dimension "n" squared into a compressed
**   matrix "cmatrix".  "cmatrix" points to a record supplied by the caller
*/
void compress(matrix,n,cmatrix)
short **matrix;
int n;
MATRIX *cmatrix;
{
  int inz, nz, i, j;

  nz = n * n - Zeroes(matrix,n);
#ifdef SHORT_MATRIX
  cmatrix->matrix = (short *)Allocate((nz+1) * sizeof(short));
#endif
  cmatrix->ia = (short *)Allocate((n+1) * sizeof(short));
  cmatrix->ja = (short *)Allocate((nz+1) * sizeof(short));
  for (inz=0, i=0; i < n; i++) {
    for (j=0; j < n; j++)
      if (matrix[i][j]) {
#ifdef SHORT_MATRIX
        cmatrix->matrix[inz] = matrix[i][j];
#endif
        cmatrix->ja[inz++] = j;    /* inz++ since starting index is 0 */
      }
    cmatrix->ia[i+1] = inz;
  }
}

void free_cmp(m)
MATRIX *m;
{
#ifdef SHORT_MATRIX
  free(m->matrix);
#endif
  free((void *)m->ia);
  free((void *)m->ja);
}

void free_matrix(m,nrl,nrh,ncl,nch)
short **m;
int nrl,nrh,ncl,nch;
{
  int i;

  for (i=nrh; i >= nrl; i--) free((void *)(m[i] + ncl));
  free((void *)(m + nrl));
}

short **imatrix(nrl,nrh,ncl,nch)
int nrl,nrh,ncl,nch;
{
  int i;
  short **m;

  m = (short **)Allocate((int)(nrh-nrl+1)*sizeof(short *));
  if (m == NULL) {
    gprintf(stderr,"Allocation error #1: LL(1) Aborted.\n");
    exit(1);
  }
  m -= nrl;
  for (i=nrl; i <= nrh; i++) {
    m[i] = (short *)Allocate((int)(nch-ncl+1)*sizeof(short));
    if (m[i] == NULL) {
      gprintf(stderr,"Allocation error #2: LL(1) Aborted.\n");
      exit(1);
    }
    m[i] -= ncl;
  }
  return (m);
}

void Product(matrix1,matrix2,product,n)
short **matrix1, **matrix2, **product;
int n;
{
  int i, j, k;

  for (i=0; i < n; i++)
    for (j=0; j < n; j++) {
      product[i][j] = FALSE;
      for (k=0; k < n; k++)
        product[i][j] |= matrix1[i][k] & matrix2[k][j];
    }
}

void Transpose(matrix, n)
short **matrix;
int n;
{
  int i, j;
  short t;

  for (i=0; i < n; i++)
    for (j=i+1; j < n; j++) {
      t = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = t;
    }
}

int Zeroes(matrix,n)
short **matrix;
int n;
{
  int i,j,nz;

  for (i=nz=0; i < n; i++) for (j=0; j < n; j++) nz += !matrix[i][j];
  return (nz);
}
