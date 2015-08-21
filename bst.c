/*
 Program to create and display a binary search tree
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX_NODES 100

struct node{
  struct node *lChild;
  int data;
  struct node *rChild;
};
struct node *root=NULL;

/*Adding Element to a Binary Search Tree*/
void addElement(struct node *parent,int num)
{
  struct node *newNode;
  newNode=(struct node *)malloc(sizeof(struct node));
  newNode->lChild=NULL;
  newNode->rChild=NULL;
  newNode->data=num;
  if(root==NULL){
    root=newNode;
    return;
  }
  else{
    if(parent->data>num){  // go left
      if(parent->lChild==NULL){
        parent->lChild=newNode;
      }
      else{
        addElement(parent->lChild,num);
      }
    }
    else{                //go right
      if(parent->rChild==NULL){
        parent->rChild=newNode;
      }
      else{
        addElement(parent->rChild,num);
      }
    }
  }
  return;
}
/*Inorder Traversal with recursion*/
void inorder(struct node *parent)
{
  if(root==NULL){
    printf("No Element in Tree\n");
  }
  else{
    
    if(parent->lChild!=NULL){
      inorder(parent->lChild);
    }
    printf("%d ",parent->data);
    if(parent->rChild!=NULL){
      inorder(parent->rChild);
    }
  }
  return;
}

/*Binary Search Operation*/
struct node * search(struct node *parent,int num)
{
  if(root==NULL){
    printf("Empty Tree\n");
    return NULL;
  }
  else{
    if(parent->data==num){
      return parent;
    }
    else if(parent->data>num){
      if(parent->lChild!=NULL){
        search(parent->lChild,num);
      }
      else{
        printf("Element not found\n");
        return NULL;
      }
    }
    else{
      if(parent->rChild!=NULL){
        search(parent->rChild,num);
      }
      else{
        printf("Element not found\n");
        return NULL;
      }
    }
  }
}

/*Push pop for stack*/
void push(struct node **stack,int *top,struct node *child){
  if(*top<MAX_NODES-1){
    stack[++(*top)]=child;
  }
}

struct node *pop(struct node **stack,int *top){
  if(*top>-1){
    return stack[(*top)--];
  }
  else{
    printf("stack empty");
    return NULL;
  }
}


/*Pre order Traversal without using recursion*/
void preorder(){
  struct node * stack[MAX_NODES];
  struct node *p;
  int top=-1;
  if(root==NULL){
    printf("Tree is empty");
    return;
  }
  push(stack,&top,root);
  while(top!=-1){
    p=pop(stack,&top);
    printf("%d ",p->data);
    if(p->rChild!=NULL)
      push(stack,&top,p->rChild);
    if(p->lChild!=NULL)
      push(stack,&top,p->lChild);
  }
}

/*Post Order Traversal without using recursion*/
void postOrder(){
  struct node *stack[MAX_NODES];
  struct node *stack2[MAX_NODES];
  struct node*p;
  int top1=-1,top2=-1;
  if(root==NULL){
    printf("Tree is empty");
    return;
  }
  push(stack,&top1,root);
  while(top1!=-1){
    p=pop(stack,&top1);
    push(stack2,&top2,p);
    if(p->lChild!=NULL)
      push(stack,&top1,p->lChild);
    
    if(p->rChild!=NULL)
      push(stack,&top1,p->rChild);
  }
  while(top2!=-1){
    p=pop(stack2,&top2);
    printf("%d ",p->data);
  }
}


/*In order Traversal Without using Recursion*/
void inorderWithoutRecursion(){
  int arrIndex=-1;
  struct node *arr[MAX_NODES];
  struct node *stack[MAX_NODES];
  struct node *p;
  int top=-1,i;
  int flag=0;
  if(root==NULL){
    printf("Tree is empty\n");
    return;
  }
  push(stack,&top,root);
  while(top!=-1){
    p=pop(stack,&top);
    flag=0;
    for(i=0;i<=arrIndex;i++){
      if(arr[i]==p){
        printf("%d\n",p->data);
        flag=1;
        break;
      }
    }
    if(flag==0){
      if(p->rChild!=NULL)
        push(stack,&top,p->rChild);
      push(stack,&top,p);
      arr[++arrIndex]=p;
      if(p->lChild!=NULL)
        push(stack,&top,p->lChild);
    }
  }
}


/*Test Program to run the code*/
int main()
{
  struct node *p;
  int num,choice;
  while(1)
  {
    printf("\nEnter the choice\n");
    printf("1)Add element\n");
    printf("2)Inorder\n");
    printf("3)Search\n");
    printf("4)Preorder Traverse\n");
    printf("5)Post Order Traverse\n");
    printf("6)Inorder Traversal Without Recursion\n");
    printf("7)Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("Enter the number\n");
             scanf("%d",&num);
             addElement(root,num);
        break;
      case 2:inorder(root);
        break;
      case 3:printf("Enter element to search\n");
             scanf("%d",&num);
             p=search(root,num);
        break;
      case 4:preorder();
        break;
      
      case 5:postOrder();
        break;
      case 6:inorderWithoutRecursion();
        break;
      case 7:exit(0);
        break;
      default:printf("Enter valid choice\n");
    }
  }
  return 0;
}
