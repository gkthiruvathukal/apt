/*
 * array.ht - header file template for the parameterized array package
 *
 * author: George K. Thiruvathukal
 *
 * note: these routines are supplied with the Apt Compiler Toolkit
 *       copyright (c); 1991, George K. Thiruvathukal
 *
 * to make routines to allocate 1D, 2D, and 3D arrays of a named type,
 * use the Unix sed utility, replace <type-name> with an identifier.:
 *
 *  sed -e '1,$ s/int/<type-name>/g' array.ht > <type-name>-array.h
 */

#ifdef __ANSI_C__
int *New1DOfint (int l1, int h1);
#else
int *New1DOfint ();
#endif

#ifdef __ANSI_C__
int **New2DOfint (int l1, int h1, int l2, int h2);
#else
int **New2DOfint ();
#endif
    
#ifdef __ANSI_C__
int ***New3DOfint (int l1, int h1, int l2, int h2, int l3, int h3);
#else
int ***New3DOfint ();
#endif

#ifdef __ANSI_C__
void Dispose1DOfint (int *a);
#else
void Dispose1DOfint ();
#endif

#ifdef __ANSI_C__
void Dispose2DOfint (int **a, int l1, int h1);
#else
void Dispose2DOfint ();
#endif

#ifdef __ANSI_C__
void Dispose3DOfint (int ***a, int l1, int h1, int l2, int h2);
#else
void Dispose3DOfint ();
#endif
