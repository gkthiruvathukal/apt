/******************************************************************
**
** AVLTREE.H:
**
**    ADT AVLTree Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

#ifndef AVLTREE_H
#define AVLTREE_H

/* ---------- Headers */

#include "apt.h"

/* ---------- Types */

typedef enum _AVLTreeBalanceTypes {
  LEFTHIGH, EQUALHIGH, RIGHTHIGH
} AVLTreeBalanceTypes;

typedef struct _AVLTreeItem {
  enum _AVLTreeBalanceTypes balance;
  int type;
  void *element;
  struct _AVLTreeItem *left;
  struct _AVLTreeItem *right;
} _AVLTreeItem, *AVLTreeItem;

typedef struct _AVLTree {
  int size;
  struct _AVLTreeItem *root;
} _AVLTree, *AVLTree;

/* ---------- Macros */

#ifndef MAX
#define MAX(a,b) (a>b?a:b)
#endif

/* ---------- Exported Function Prototypes */

#ifdef __ANSI_C__
int AVLTreeDelete(AVLTree, void*, ComparisonFunction, DisposeFunction);
void *AVLTreeDeleteLeftMost(AVLTree);
void *AVLTreeDeleteRightMost(AVLTree);
void AVLTreeDispose(AVLTree, DisposeFunction);
void *AVLTreeFind(AVLTree, void*, ComparisonFunction);
void *AVLTreeFindLeftMost(AVLTree);
void *AVLTreeFindRightMost(AVLTree);
int AVLTreeHeight(AVLTree);
void AVLTreeInorderApply(AVLTree, ApplyFunction);
int AVLTreeInsert(AVLTree, void*, int, ComparisonFunction);
AVLTreeBalanceTypes AVLTreeItemBalance(AVLTreeItem);
void *AVLTreeItemElement(AVLTreeItem);
AVLTreeItem AVLTreeItemLeft(AVLTreeItem);
AVLTreeItem AVLTreeItemRight(AVLTreeItem);
int AVLTreeItemType(AVLTreeItem);
int AVLTreeLeftHeight(AVLTree);
AVLTree AVLTreeNew(void);
void AVLTreePostorderApply(AVLTree, ApplyFunction);
void AVLTreePreorderApply(AVLTree, ApplyFunction);
int AVLTreeRightHeight(AVLTree);
AVLTreeItem AVLTreeRoot(AVLTree);
int AVLTreeSize(AVLTree);
#else
int AVLTreeDelete();
void *AVLTreeDeleteLeftMost();
void *AVLTreeDeleteRightMost();
void AVLTreeDispose();
void *AVLTreeFind();
void *AVLTreeFindLeftMost();
void *AVLTreeFindRightMost();
int AVLTreeHeight();
void AVLTreeInorderApply();
int AVLTreeInsert();
AVLTreeBalanceTypes AVLTreeItemBalance();
void *AVLTreeItemElement();
AVLTreeItem AVLTreeItemLeft();
AVLTreeItem AVLTreeItemRight();
int AVLTreeItemType();
int AVLTreeLeftHeight();
AVLTree AVLTreeNew();
void AVLTreePostorderApply();
void AVLTreePreorderApply();
int AVLTreeRightHeight();
AVLTreeItem AVLTreeRoot();
int AVLTreeSize();
#endif /* __ANSI_C__ */

#endif /* AVLTREE_H */
