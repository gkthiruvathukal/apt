/*
 * a-int.c - functions to allocate arrays of int
 *
 * copyright (c) 1991, George K. Thiruvathukal
 * This file is distributed with the Apt Compiler Toolkit
 * see array.ht for instructions
 */

#include "a-int.h"

#include <stdio.h>
#ifdef __STDC__
#include <stdlib.h>
#endif

#ifdef __STDC__
int *New1DOfint (int l1, int h1)
#else
int *New1DOfint (l1, h1)
int l1, h1;
#endif
{
  int *x = (int *)calloc( (h1 - l1 + 1), sizeof(int));
  if (x == NULL) {
    fprintf(stderr,"New1DOfint: allocation failure.\n");
    return NULL;
  }
  return x - l1;
}

#ifdef __STDC__
int **New2DOfint (int l1, int h1, int l2, int h2)
#else
int **New2DOfint (l1, h1, l2, h2)
int l1, h1, l2, h2;
#endif
{
  int **x = (int **)calloc( (h1 - l1 + 1), sizeof(int *));
  int i;

  if (x == NULL) {
    fprintf(stderr,"New2DOfint: allocation failure; dimension 1\n");
    return NULL;
  }
  x -= l1;
  for (i=l1; i <= h1; i++) {
    x[i] = New1DOfint (l2, h2);
    if (x[i] == NULL) {
      gprintf(stderr,"New2DOfint: allocation failure; dimension 2\n");
      return NULL;
    }
  }
  return x;
} 
    
#ifdef __STDC__
int ***New3DOfint (int l1, int h1, int l2, int h2, int l3, int h3)
#else
int ***New3DOfint (l1, h1, l2, h2, l3, h3)
int l1, h1, l2, h2, l3, h3;
#endif
{
  int ***x = (int ***)calloc( (h1 - l1 + 1), sizeof(int **));
  int i;

  if (x == NULL) {
    fprintf(stderr,"New3DOfint: allocation failure; dimension 1\n");
    return NULL;
  }
  x -= l1;
  for (i=l1; i <= h1; i++) {
    x[i] = New2DOfint (l2, h2, l3, h3);
    if (x[i] == NULL) {
      gprintf(stderr,"New3DOfint: allocation failure; dimension 2\n");
      return NULL;
    }
  }
  return x;
}

#ifdef __STDC__
void Dispose1DOfint (int *a)
#else
void Dispose1DOfint (a)
int *a;
#endif
{
  free(a);
}

#ifdef __STDC__
void Dispose2DOfint (int **a, int l1, int h1)
#else
void Dispose2DOfint (a, l1, h1)
int **a;
int l1, h1;
#endif
{
  int i;

  for (i=l1; i <= h1; i++)
    Dispose1DOfint (a[i]);
}

#ifdef __STDC__
void Dispose3DOfint (int ***a, int l1, int h1, int l2, int h2)
#else
void Dispose3DOfint (a, l1, h1, l2, h2)
int ***a;
int l1, h1, l2, h2;
#endif
{
  int i;

  for (i=l1; i <= h1; i++)
    Dispose2DOfint (a[i],l2,h2);
}
