#include <stdio.h>
#include <stdlib.h>
typedef struct BSTNode{
char key;
int element;
struct BSTNode *left;
struct BSTNode *right;
}BSTNode;
typedef struct BST{
BSTNode *root;
int nodecount;
}BST;
BST *create_bst(){
  BST *bst = (BST*) malloc(sizeof(BST));
  bst->root = NULL;
  bst->nodecount = 0;
  return bst;
}
void clear(BST *bst){
  bst->root = NULL;
  bst->nodecount = 0;
}
int size(BST *bst){
  return bst->nodecount;
}
int findhelp(BSTNode* rt, char k){
  if(rt==NULL) return 0;
  if(rt->key > k) return findhelp(rt->left, k);
  else if(rt->key==k) return rt->element;
  else return findhelp(rt->right, k);
}
int find(BST *bst, char k){
  return findhelp(bst->root, k);
}
BSTNode *create_bstnode(int e, char k){
  BSTNode *node = (BSTNode*) malloc(sizeof(BSTNode));
  node->right=NULL;
  node->left=NULL;
  node->element=e;
  node->key=k;
  return node;
}
BSTNode *inserthelp(BSTNode *rt,char k, int e){
  if(rt==NULL) return create_bstnode(e, k);
  if(rt->key>k){
    rt->left=inserthelp(rt->left, k, e);
  }
  else{
    rt->right=inserthelp(rt->right, k, e);
  }
  return rt;
}
void insert(BST *bst, char k, int e){
  bst->root=inserthelp(bst->root, k, e);
  (bst->nodecount)++;
}
BSTNode *getmin(BSTNode *rt){
  if(rt->left==NULL) return rt;
  return getmin(rt->left);
}
BSTNode *deletemin(BSTNode* rt){
if(rt->left==NULL) return rt->right;
rt->left=deletemin(rt->left);
return rt;
}BSTNode *removehelp(BSTNode *rt, char k){
  if(rt==NULL) return 0;
  if(rt->key>k) rt->left = removehelp(rt->left, k);
  else if(rt->key<k) rt->right = removehelp(rt->right, k);
  else{
    if(rt->left==NULL) return rt->right;
    else if(rt->right==NULL) return rt->left;
    else{
    BSTNode *temp = getmin(rt->right);
    rt->element = temp->element;
    rt->key = temp->key;
    rt->right = deletemin(rt->right);
  }
  }
  return rt;
}
int removeAny(BST *bst){
  if(bst->root==NULL) return 0;
  int temp = bst->root->element;
  bst->root = removehelp(bst->root, bst->root->key);
  (bst->nodecount)--;
  return temp;
}
int remover(BST *bst, char k){
  int temp =findhelp(bst->root, k);
  if(temp!=0){
    bst->root = removehelp(bst->root, k);
    (bst->nodecount)--;
  }
  return temp;
}
int main(void) {
 BST *bst = create_bst();
 insert(bst, 'a', 0);
 insert(bst, 'b', 1);
 insert(bst, 'c', 2);
 insert(bst, 'd', 3);
 printf("find: %d\n", find(bst, 'a')); 
 printf("find: %d\n", find(bst, 'b')); 
 printf("find: %d\n", find(bst, 'c')); 
 printf("find: %d\n", find(bst, 'd')); 
 clear(bst);
 printf("find: %d\n", find(bst, 'a')); 
 printf("find: %d\n", find(bst, 'b')); 
 printf("find: %d\n", find(bst, 'c')); 
 printf("find: %d\n", find(bst, 'd')); 
  return 0;
}
