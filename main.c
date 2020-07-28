#include<stdio.h>
#include<conio.h>
typedef struct node
{
  char data;
  //data=getchar();
  struct node *left;
  struct node *right;
} node;

node *create()
{
    node *p;
    char x;
    x = getchar();
    printf("Please Enter a chracter (-1 for no node):");
    scanf("%c",x);

    if(x==-1)
	return NULL;

    p=(node*)malloc(sizeof(node));
    p->data=x;
    printf("Please Enter left child of %c:\n",x);
    p->left=create();
    printf("Please Enter right child of %c:\n",x);
    p->right=create();
    return p;
}
void preorder(node *t)
{
  if(t!=NULL)
  {
    printf("  %c",t->data);
    preorder(t->left);
    preorder(t->right);
  }
}
void inorder(node *t)
{
  if(t!=NULL)
  {
    inorder(t->left);
    printf("  %c",t->data);
    inorder(t->right);
  }
}
void postorder(node *t)
{
  if(t!=NULL)
  {
    postorder(t->left);
    postorder(t->right);
    printf("  %c",t->data);
  }
}
void main()
{
  node *root;
  root=create();
  printf("\nThe pre-order traversal of tree is: ");
  preorder(root);
  printf("\nThe in-order traversal of tree is: ");
  inorder(root);
  printf("\nThe post-order traversal of tree is: ");
  postorder(root);
  getch();
}

