/******************************************************************
**
** AVLTREE.C:
**
**    ADT AVLTree Implementation
**
** This file is part of Apt Abstract Data Types (ADT)
** Copyright (c) 1991 -- Apt Technologies
** All rights reserved
**
******************************************************************/

/* ---------- C Headers */

#include "cheaders.h"

/* ---------- Headers */

#include "apt.h"

#include "allocate.h"
#include "avltree.h"

/* ---------- Private Globals */

PRIVATE AVLTreeItem AVLTreeDel;
PRIVATE int AVLTreeGrew;
PRIVATE AVLTreeItem AVLTreeIns;
PRIVATE int AVLTreeShrank;

/* ---------- Private Function Prototypes */

#ifdef __ANSI_C__
PRIVATE AVLTreeItem AVLTreeDeleteRec(AVLTreeItem, void*, ComparisonFunction);
PRIVATE void AVLTreeDisposeItem(AVLTreeItem, DisposeFunction);
PRIVATE void AVLTreeDisposeRec(AVLTreeItem, DisposeFunction);
PRIVATE AVLTreeItem AVLTreeFindLeftMostRec(AVLTreeItem);
PRIVATE AVLTreeItem AVLTreeFindRec(AVLTreeItem, void*, ComparisonFunction);
PRIVATE AVLTreeItem AVLTreeFindRightMostRec(AVLTreeItem);
PRIVATE int AVLTreeHeightRec(AVLTreeItem, int);
PRIVATE void AVLTreeInorderApplyRec(AVLTreeItem, ApplyFunction);
PRIVATE int AVLTreeInsertItem(AVLTree, AVLTreeItem, ComparisonFunction);
PRIVATE AVLTreeItem AVLTreeInsertRec(AVLTreeItem, AVLTreeItem,
                             ComparisonFunction);
PRIVATE AVLTreeItem AVLTreeNewItem(void*, int);
PRIVATE void AVLTreePostorderApplyRec(AVLTreeItem, ApplyFunction);
PRIVATE void AVLTreePreorderApplyRec(AVLTreeItem, ApplyFunction);
PRIVATE AVLTreeItem FindRightMostLeaf(AVLTreeItem);
PRIVATE AVLTreeItem FindLeftMostLeaf(AVLTreeItem);
PRIVATE AVLTreeItem LeftBalance(AVLTreeItem);
PRIVATE AVLTreeItem PruneGraft(AVLTreeItem);
PRIVATE AVLTreeItem RightBalance(AVLTreeItem);
PRIVATE AVLTreeItem RotateLeft(AVLTreeItem);
PRIVATE AVLTreeItem RotateRight(AVLTreeItem);
#else
PRIVATE AVLTreeItem AVLTreeDeleteRec();
PRIVATE void AVLTreeDisposeItem();
PRIVATE void AVLTreeDisposeRec();
PRIVATE AVLTreeItem AVLTreeFindLeftMostRec();
PRIVATE AVLTreeItem AVLTreeFindRec();
PRIVATE AVLTreeItem AVLTreeFindRightMostRec();
PRIVATE int AVLTreeHeightRec();
PRIVATE void AVLTreeInorderApplyRec();
PRIVATE int AVLTreeInsertItem();
PRIVATE AVLTreeItem AVLTreeInsertRec();
PRIVATE AVLTreeItem AVLTreeNewItem();
PRIVATE void AVLTreePostorderApplyRec();
PRIVATE void AVLTreePreorderApplyRec();
PRIVATE AVLTreeItem FindRightMostLeaf();
PRIVATE AVLTreeItem FindLeftMostLeaf();
PRIVATE AVLTreeItem LeftBalance();
PRIVATE AVLTreeItem PruneGraft();
PRIVATE AVLTreeItem RightBalance();
PRIVATE AVLTreeItem RotateLeft();
PRIVATE AVLTreeItem RotateRight();
#endif /* __ANSI_C__ */

/* ---------- Functions */

/*
**
** AVLTreeDelete
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeDelete(AVLTree tree, void *element, ComparisonFunction cf,
                  DisposeFunction df)
#else
int AVLTreeDelete(tree,element,cf,df)
AVLTree tree;
void *element;
ComparisonFunction cf;
DisposeFunction df;
#endif
{
  AVLTreeItem root;

  if (tree) {
    AVLTreeShrank = FALSE;
    root = AVLTreeDeleteRec(tree->root,element,cf);
    if (AVLTreeDel != NULL) {
      tree->root = root;
      tree->size--;
      AVLTreeDisposeItem(AVLTreeDel,df);
      return (1);
    }
  }
  return (0);
}

/*
**
** AVLTreeDeleteLeftMostItem
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeDeleteLeftMost(AVLTree tree)
#else
void *AVLTreeDeleteLeftMost(tree)
AVLTree tree;
#endif
{
  void *element;
  AVLTreeItem item;

  if (tree) {
    if (tree->root) {
      item = FindLeftMostLeaf(tree->root);
      tree->root = item->right;
      tree->size--;
      element = item->element;
      AVLTreeDisposeItem(item,NULL);
      return (element);
    }
  }
  return (NULL);
}

/*
**
** AVLTreeDeleteRec
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeDeleteRec(AVLTreeItem root, void *element,
                             ComparisonFunction f)
#else
AVLTreeItem AVLTreeDeleteRec(root,element,f)
AVLTreeItem root;
void *element;
ComparisonFunction f;
#endif
{
  AVLTreeItem newRoot;

  if (root) {
    if ((*f)(element,root->element) < 0) {
      newRoot = AVLTreeDeleteRec(root->left,element,f);
      if (AVLTreeDel != NULL) {
        root->left = newRoot;
        if (AVLTreeShrank)
          switch (root->balance) {
          case LEFTHIGH:
            AVLTreeShrank = TRUE;
            root->balance = EQUALHIGH;
            break;
          case EQUALHIGH:
            root->balance = RIGHTHIGH;
            AVLTreeShrank = FALSE;
            break;
          case RIGHTHIGH:
            root = RightBalance(root);
            break;
          }
        else AVLTreeShrank = FALSE;
        return (root);
      }
      else return (NULL);
    }
    else if ((*f)(element,root->element) > 0) {
      newRoot = AVLTreeDeleteRec(root->right,element,f);
      if (AVLTreeDel != NULL) {
        root->right = newRoot;
        if (AVLTreeShrank)
          switch (root->balance) {
          case LEFTHIGH:
            root = LeftBalance(root);
            break;
          case EQUALHIGH:
            root->balance = LEFTHIGH;
            AVLTreeShrank = FALSE;
            break;
          case RIGHTHIGH:
            root->balance = EQUALHIGH;
            AVLTreeShrank = TRUE;
            break;
          }
        else AVLTreeShrank = FALSE;
        return (root);
      }
      else return (NULL);
    }
    else {
      newRoot = PruneGraft(root);
      AVLTreeDel = root;
      return (newRoot);
    }
  }
  else {
    AVLTreeShrank = FALSE;
    AVLTreeDel = NULL;
    return (NULL);
  }
}

/*
**
** AVLTreeDeleteRightMostItem
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeDeleteRightMost(AVLTree tree)
#else
void *AVLTreeDeleteRightMost(tree)
AVLTree tree;
#endif
{
  void *element;
  AVLTreeItem item;

  if (tree) {
    if (tree->root) {
      item = FindRightMostLeaf(tree->root);
      tree->root = item->left;
      tree->size--;
      element = item->element;
      AVLTreeDisposeItem(item,NULL);
      return (element);
    }
  }
  return (NULL);
}

/*
**
** AVLTreeDispose
**
*/
PUBLIC
#ifdef __ANSI_C__
void AVLTreeDispose(AVLTree tree, DisposeFunction f)
#else
void AVLTreeDispose(tree,f)
AVLTree tree;
DisposeFunction f;
#endif
{
  if (tree) {
    AVLTreeDisposeRec(tree->root,f);
    free(tree);
  }
}

/*
**
** AVLTreeDisposeItem
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTreeDisposeItem(AVLTreeItem item, DisposeFunction f)
#else
void AVLTreeDisposeItem(item,f)
AVLTreeItem item;
DisposeFunction f;
#endif
{
  if (item) {
    if (f) (*f)(item->element);
    free(item);
  }
}

/*
**
** AVLTreeDisposeRec
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTreeDisposeRec(AVLTreeItem root, DisposeFunction f)
#else
void AVLTreeDisposeRec(root,f)
AVLTreeItem root;
DisposeFunction f;
#endif
{
  if (root) {
    AVLTreeDisposeRec(root->left,f);
    AVLTreeDisposeRec(root->right,f);
    AVLTreeDisposeItem(root,f);
  }
}

/*
**
** AVLTreeFind
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeFind(AVLTree tree, void *element, ComparisonFunction f)
#else
void *AVLTreeFind(tree,element,f)
AVLTree tree;
void *element;
ComparisonFunction f;
#endif
{
  AVLTreeItem item;

  if (tree) {
    item = AVLTreeFindRec(tree->root,element,f);
    if (item) return (item->element);
  }
  return (NULL);
}

/*
**
** AVLTreeFindLeftMost
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeFindLeftMost(AVLTree tree)
#else
void *AVLTreeFindLeftMost(tree)
AVLTree tree;
#endif
{
  AVLTreeItem item;

  if (tree) {
    item = AVLTreeFindLeftMostRec(tree->root);
    if (item != NULL) return (item->element);
  }
  return (NULL);
}

/*
**
** AVLTreeFindLeftMostRec
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeFindLeftMostRec(AVLTreeItem root)
#else
AVLTreeItem AVLTreeFindLeftMostRec(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem item;

  item = NULL;
  while (root) {
    item = root;
    root = root->left;
  }
  return (item);
}

/*
**
** AVLTreeFindRec
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeFindRec(AVLTreeItem root, void *element,
                              ComparisonFunction f)
#else
AVLTreeItem AVLTreeFindRec(root,element,f)
AVLTreeItem root;
void *element;
ComparisonFunction f;
#endif
{
  AVLTreeItem item;

  if (root) {
    if ((*f)(element,root->element) == 0) return (root);
    item = AVLTreeFindRec(root->left,element,f);
    if (item) return (item);
    item = AVLTreeFindRec(root->right,element,f);
    if (item) return (item);
  }
  return (NULL);
}

/*
**
** AVLTreeFindRightMost
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeFindRightMost(AVLTree tree)
#else
void *AVLTreeFindRightMost(tree)
AVLTree tree;
#endif
{
  AVLTreeItem item;

  if (tree) {
    item = AVLTreeFindRightMostRec(tree->root);
    if (item != NULL) return (item->element);
  }
  return (NULL);
}

/*
**
** AVLTreeFindRightMostRec
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeFindRightMostRec(AVLTreeItem root)
#else
AVLTreeItem AVLTreeFindRightMostRec(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem item;

  item = NULL;
  while (root) {
    item = root;
    root = root->right;
  }
  return (item);
}

/*
**
** AVLTreeHeight
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeHeight(AVLTree tree)
#else
int AVLTreeHeight(tree)
AVLTree tree;
#endif
{
  if (tree) return (AVLTreeHeightRec(tree->root,0));
  return (0);
}

/*
**
** AVLTreeHeightRec
**
*/
PRIVATE
#ifdef __ANSI_C__
int AVLTreeHeightRec(AVLTreeItem root, int depth)
#else
int AVLTreeHeightRec(root,depth)
AVLTreeItem root;
int depth;
#endif
{
  int left;
  int right;

  if (root) {
    left = AVLTreeHeightRec(root->left,depth+1);
    right = AVLTreeHeightRec(root->right,depth+1);
    return (MAX(left,right));
  }
  return (depth);
}

/*
**
** AVLTreeInorderApply
**
*/
PUBLIC
#ifdef __ANSI_C__
void AVLTreeInorderApply(AVLTree tree, ApplyFunction f)
#else
void AVLTreeInorderApply(tree,f)
AVLTree tree;
ApplyFunction f;
#endif
{
  if (tree) AVLTreeInorderApplyRec(tree->root,f);
}

/*
**
** AVLTreeInorderApplyRec
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTreeInorderApplyRec(AVLTreeItem root, ApplyFunction f)
#else
void AVLTreeInorderApplyRec(root,f)
AVLTreeItem root;
ApplyFunction f;
#endif
{
  if (root) {
    AVLTreeInorderApplyRec(root->left,f);
    (*f)(root->element);
    AVLTreeInorderApplyRec(root->right,f);
  }
}

/*
**
** AVLTreeInsert
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeInsert(AVLTree tree, void *element, int type,
                  ComparisonFunction f)
#else
int AVLTreeInsert(tree,element,type,f)
AVLTree tree;
void *element;
int type;
ComparisonFunction f;
#endif
{
  AVLTreeItem item;

  item = AVLTreeNewItem(element,type);
  return (AVLTreeInsertItem(tree,item,f));
}

/*
**
** AVLTreeInsertItem
**
*/
PRIVATE
#ifdef __ANSI_C__
int AVLTreeInsertItem(AVLTree tree, AVLTreeItem item,
                      ComparisonFunction f)
#else
int AVLTreeInsertItem(tree,item,f)
AVLTree tree;
AVLTreeItem item;
ComparisonFunction f;
#endif
{
  AVLTreeItem root;

  if (tree) {
    root = AVLTreeInsertRec(tree->root,item,f);
    if (AVLTreeIns != NULL) {
      tree->root = root;
      tree->size++;
      return (1);
    }
  }
  else {
    tree = AVLTreeNew();
    return (AVLTreeInsertItem(tree,item,f));
  }
  return (0);
}

/*
**
** AVLTreeInsertRec
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeInsertRec(AVLTreeItem root, AVLTreeItem item,
                             ComparisonFunction f)
#else
AVLTreeItem AVLTreeInsertRec(root,item,f)
AVLTreeItem root;
AVLTreeItem item;
ComparisonFunction f;
#endif
{
  AVLTreeItem newRoot;

  if (root) {
    if ((*f)(item->element,root->element) < 0) {
      newRoot = AVLTreeInsertRec(root->left,item,f);
      if (AVLTreeIns != NULL) {
       	root->left = newRoot;
        if (AVLTreeGrew)
          switch (root->balance) {
          case LEFTHIGH:
            root = LeftBalance(root);
            AVLTreeGrew = FALSE;
	    break;
          case EQUALHIGH:
            root->balance = LEFTHIGH;
            AVLTreeGrew = TRUE;
            break;
	  case RIGHTHIGH:
            root->balance = EQUALHIGH;
            AVLTreeGrew = FALSE;
            break;
          }
        else AVLTreeGrew = FALSE;
        return (root);
      }
      else return (newRoot);
    }
    else if ((*f)(item->element,root->element) > 0) {
      newRoot = AVLTreeInsertRec(root->right,item,f);
      if (AVLTreeIns != NULL) {
        root->right = newRoot;
        if (AVLTreeGrew)
          switch (root->balance) {
          case LEFTHIGH:
            root->balance = EQUALHIGH;
            AVLTreeGrew = FALSE;
            break;
          case EQUALHIGH:
            root->balance = RIGHTHIGH;
            AVLTreeGrew = TRUE;
            break;
          case RIGHTHIGH:
            root = RightBalance(root);
            AVLTreeGrew = FALSE;
            break;
          }
        else AVLTreeGrew = FALSE;
        return (root);
      }
      else return (newRoot);
    }
    else {
      AVLTreeGrew = FALSE;
      AVLTreeIns = NULL;
      return (root);
    }
  }
  else {
    AVLTreeGrew = TRUE;
    AVLTreeIns = item;
    return (item);
  }
}

/*
**
** AVLTreeItemBalance
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTreeBalanceTypes AVLTreeItemBalance(AVLTreeItem item)
#else
AVLTreeBalanceTypes AVLTreeItemBalance(item)
AVLTreeItem item;
#endif
{
  return (item ? item->balance : EQUALHIGH);
}

/*
**
** AVLTreeItemElement
**
*/
PUBLIC
#ifdef __ANSI_C__
void *AVLTreeItemElement(AVLTreeItem item)
#else
void *AVLTreeItemElement(item)
AVLTreeItem item;
#endif
{
  return (item ? item->element : NULL);
}

/*
**
** AVLTreeItemLeft
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTreeItem AVLTreeItemLeft(AVLTreeItem item)
#else
AVLTreeItem AVLTreeItemLeft(item)
AVLTreeItem item;
#endif
{
  return (item ? item->left : NULL);
}

/*
**
** AVLTreeItemRight
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTreeItem AVLTreeItemRight(AVLTreeItem item)
#else
AVLTreeItem AVLTreeItemRight(item)
AVLTreeItem item;
#endif
{
  return (item ? item->right : NULL);
}

/*
**
** AVLTreeItemType
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeItemType(AVLTreeItem item)
#else
int AVLTreeItemType(item)
AVLTreeItem item;
#endif
{
  return (item ? item->type : 0);
}

/*
**
** AVLTreeLeftHeight
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeLeftHeight(AVLTree tree)
#else
int AVLTreeLeftHeight(tree)
AVLTree tree;
#endif
{
  return (tree && tree->root ? AVLTreeHeightRec(tree->root->left,0) : 0);
}

/*
**
** AVLTreeNew
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTree AVLTreeNew(void)
#else
AVLTree AVLTreeNew()
#endif
{
  AVLTree tree;

  tree = ((AVLTree)Allocate(sizeof(_AVLTree)));
  if (tree) {
    tree->size = 0;
    tree->root = NULL;
  }
  return (tree);
}

/*
**
** AVLTreeNewItem
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem AVLTreeNewItem(void *element, int type)
#else
AVLTreeItem AVLTreeNewItem(element,type)
void *element;
int type;
#endif
{
  AVLTreeItem item;

  item = ((AVLTreeItem)Allocate(sizeof(_AVLTreeItem)));
  if (item) {
    item->balance = EQUALHIGH;
    item->element = element;
    item->type = type;
    item->left = item->right = NULL;
  }
  return (item);
}

/*
**
** AVLTreePostorderApply
**
*/
PUBLIC
#ifdef __ANSI_C__
void AVLTreePostorderApply(AVLTree tree, ApplyFunction f)
#else
void AVLTreePostorderApply(tree,f)
AVLTree tree;
ApplyFunction f;
#endif
{
  if (tree) AVLTreePostorderApplyRec(tree->root,f);
}

/*
**
** AVLTreePostorderApplyRec
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTreePostorderApplyRec(AVLTreeItem root, ApplyFunction f)
#else
void AVLTreePostorderApplyRec(root,f)
AVLTreeItem root;
ApplyFunction f;
#endif
{
  if (root) {
    AVLTreePostorderApplyRec(root->left,f);
    AVLTreePostorderApplyRec(root->right,f);
    (*f)(root->element);
  }
}

/*
**
** AVLTreePreorderApply
**
*/
PUBLIC
#ifdef __ANSI_C__
void AVLTreePreorderApply(AVLTree tree, ApplyFunction f)
#else
void AVLTreePreorderApply(tree,f)
AVLTree tree;
ApplyFunction f;
#endif
{
  if (tree) AVLTreePreorderApplyRec(tree->root,f);
}

/*
**
** AVLTreePreorderApplyRec
**
*/
PRIVATE
#ifdef __ANSI_C__
void AVLTreePreorderApplyRec(AVLTreeItem root, ApplyFunction f)
#else
void AVLTreePreorderApplyRec(root,f)
AVLTreeItem root;
ApplyFunction f;
#endif
{
  if (root) {
    (*f)(root->element);
    AVLTreePreorderApplyRec(root->left,f);
    AVLTreePreorderApplyRec(root->right,f);
  }
}

/*
**
** AVLTreeRightHeight
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeRightHeight(AVLTree tree)
#else
int AVLTreeRightHeight(tree)
AVLTree tree;
#endif
{
  return (tree && tree->root ? AVLTreeHeightRec(tree->root->right,0) : 0);
}

/*
**
** AVLTreeRoot
**
*/
PUBLIC
#ifdef __ANSI_C__
AVLTreeItem AVLTreeRoot(AVLTree tree)
#else
AVLTreeItem AVLTreeRoot(tree)
AVLTree tree;
#endif
{
  return (tree ? tree->root : NULL);
}

/*
**
** AVLTreeSize
**
*/
PUBLIC
#ifdef __ANSI_C__
int AVLTreeSize(AVLTree tree)
#else
int AVLTreeSize(tree)
AVLTree tree;
#endif
{
  return (tree ? tree->size : 0);
}

/* ---------- Tree Balancing Functions */

/*
**
** FindLeftMostLeaf
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem FindLeftMostLeaf(AVLTreeItem root)
#else
AVLTreeItem FindLeftMostLeaf(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem item;

  if (root) {
    item = FindLeftMostLeaf(root->left);
    if (item != NULL) {
      root->left = item->right;
      if (AVLTreeShrank) {
        switch (root->balance) {
        case LEFTHIGH:
          root->balance = EQUALHIGH;
          AVLTreeShrank = TRUE;
          break;
        case EQUALHIGH:
          root->balance = RIGHTHIGH;
          AVLTreeShrank = FALSE;
          break;
        case RIGHTHIGH:
          root = RightBalance(root);
          break;
        }
      }
      item->right = root;
      return (item);
    }
    else {
      AVLTreeShrank = TRUE;
      return (root);
    }
  }
  else {
    AVLTreeShrank = TRUE;
    return (NULL);
  }
}

/*
**
** FindRightMostLeaf
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem FindRightMostLeaf(AVLTreeItem root)
#else
AVLTreeItem FindRightMostLeaf(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem item;

  if (root) {
    item = FindRightMostLeaf(root->right);
    if (item != NULL) {
      root->right = item->left;
      if (AVLTreeShrank) {
        switch (root->balance) {
        case LEFTHIGH:
          root = LeftBalance(root);
          break;
        case EQUALHIGH:
          root->balance = LEFTHIGH;
          AVLTreeShrank = FALSE;
          break;
        case RIGHTHIGH:
          root->balance = EQUALHIGH;
          AVLTreeShrank = TRUE;
          break;
        }
      }
      item->left = root;
      return (item);
    }
    else {
      AVLTreeShrank = TRUE;
      return (root);
    }
  }
  else {
    AVLTreeShrank = TRUE;
    return (NULL);
  }
}

/*
**
** LeftBalance
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem LeftBalance(AVLTreeItem root)
#else
AVLTreeItem LeftBalance(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem child, grandchild;

  child = root->left;
  switch (child->balance) {
  case LEFTHIGH:
    AVLTreeGrew = FALSE;
    AVLTreeShrank = TRUE;
    root->balance = EQUALHIGH;
    child->balance = EQUALHIGH;
    return (RotateRight(root));
  case EQUALHIGH:
    AVLTreeGrew = TRUE;
    AVLTreeShrank = FALSE;
    root->balance = LEFTHIGH;
    child->balance = RIGHTHIGH;
    return (RotateRight(root));
  case RIGHTHIGH:
    AVLTreeGrew = FALSE;
    AVLTreeShrank = TRUE;
    grandchild = child->right;
    switch (grandchild->balance) {
    case EQUALHIGH:
      root->balance = EQUALHIGH;
      child->balance = EQUALHIGH;
      break;
    case LEFTHIGH:
      root->balance = RIGHTHIGH;
      child->balance = EQUALHIGH;
      break;
    case RIGHTHIGH:
      root->balance = EQUALHIGH;
      child->balance = LEFTHIGH;
      break;
    }
    grandchild->balance = EQUALHIGH;
    root->left = RotateLeft(child);
    return (RotateRight(root));
  }
  return (root);
}

/*
**
** PruneGraft
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem PruneGraft(AVLTreeItem root)
#else
AVLTreeItem PruneGraft(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem item;

  switch (root->balance) {
  case LEFTHIGH:
    item = FindRightMostLeaf(root->left);
    if (item != NULL) {
      item->balance = root->balance;
      if (AVLTreeShrank) {
        item->balance = EQUALHIGH;
        AVLTreeShrank = TRUE;
      }
      item->right = root->right;
    }
    return (item);
  case EQUALHIGH:
    item = FindRightMostLeaf(root->left);
    if (item != NULL) {
      item->balance = root->balance;
      if (AVLTreeShrank) {
        item->balance = RIGHTHIGH;
        AVLTreeShrank = FALSE;
      }
      item->right = root->right;
    }
    return (item);
  case RIGHTHIGH:
    item = FindLeftMostLeaf(root->right);
    if (item != NULL) {
      item->balance = root->balance;
      if (AVLTreeShrank) {
        item->balance = EQUALHIGH;
        AVLTreeShrank = TRUE;
      }
      item->left = root->left;
    }
    return (item);
  }
  return (NULL);
}

/*
**
** RightBalance
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem RightBalance(AVLTreeItem root)
#else
AVLTreeItem RightBalance(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem child, grandchild;

  child = root->right;
  switch (child->balance) {
  case RIGHTHIGH:
    AVLTreeGrew = FALSE;
    AVLTreeShrank = TRUE;
    root->balance = EQUALHIGH;
    child->balance = EQUALHIGH;
    return (RotateLeft(root));
  case EQUALHIGH:
    AVLTreeGrew = TRUE;
    AVLTreeShrank = FALSE;
    root->balance = RIGHTHIGH;
    child->balance = LEFTHIGH;
    return (RotateLeft(root));
  case LEFTHIGH:
    AVLTreeGrew = FALSE;
    AVLTreeShrank = TRUE;
    grandchild = child->left;
    switch (grandchild->balance) {
    case EQUALHIGH:
      root->balance = EQUALHIGH;
      child->balance = EQUALHIGH;
      break;
    case LEFTHIGH:
      root->balance = EQUALHIGH;
      child->balance = RIGHTHIGH;
      break;
    case RIGHTHIGH:
      root->balance = LEFTHIGH;
      child->balance = EQUALHIGH;
      break;
    }
    grandchild->balance = EQUALHIGH;
    root->right = RotateRight(child);
    return (RotateLeft(root));
  }
  return (root);
}

/*
**
** RotateLeft
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem RotateLeft(AVLTreeItem root)
#else
AVLTreeItem RotateLeft(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem child;

  if (root && root->right) {
    child = root->right;
    root->right = child->left;
    child->left = root;
    return (child);
  }
  return (root);
}

/*
**
** RotateRight
**
*/
PRIVATE
#ifdef __ANSI_C__
AVLTreeItem RotateRight(AVLTreeItem root)
#else
AVLTreeItem RotateRight(root)
AVLTreeItem root;
#endif
{
  AVLTreeItem child;

  if (root && root->left) {
    child = root->left;
    root->left = child->right;
    child->right = root;
    return (child);
  }
  else return (root);
}

