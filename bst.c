/*
 Program to create and display a binary search tree
*/

#include<stdio.h>
#include<stdlib.h>
struct node{
  struct node *lChild;
  int data;
  struct node *rChild;
};
struct node *root=NULL;

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

void display(struct node *parent)
{
  if(root==NULL){
    printf("No Element in Tree\n");
  }
  else{
    printf("%d ",parent->data);
    if(parent->lChild!=NULL){
      display(parent->lChild);
    }
    if(parent->rChild!=NULL){
      display(parent->rChild);
    }
  }
  return;
}
    

int main()
{
  int num,choice;
  while(1)
  {
    printf("\nEnter the choice\n1)Add element\n2)Display Tree\n3)Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("Enter the number\n");
             scanf("%d",&num);
             addElement(root,num);
        break;
      case 2:display(root);
        break;
      case 3:exit(0);
        break;
      default:printf("Enter valid choice\n");
    }
  }
  return 0;
}
