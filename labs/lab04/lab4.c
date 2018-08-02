#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 200

enum Color {RED, BLACK};

struct node {

  char color;
  int blackHeight;
  int key;
  struct node *left;
  struct node *right;

};

void
preorder_print(struct node *ptr) {
   if(ptr!=NULL) {
      printf("%c", ptr->color);
      preorder_print(ptr->left);
      preorder_print(ptr->right);
   }
   else
    printf(".");
}

void
input(char *charArray) {
  int i;
  for (i=0; i<MAX_NODES+1; i++) {
    charArray[i]=0;
  }
  scanf("%s", charArray);
  return;
}


struct node*
createNode(char c) {
  struct node *newNode;
  newNode = malloc(sizeof(struct node));
  newNode -> color = c;
  newNode -> left = NULL;
  newNode -> right = NULL;

  return newNode;
}

struct node*
preorder_insert(char inArray[]) {
  static int index=0;
  struct node *nPtr;
  struct node *returnPtr = NULL;

  
  if(inArray[index] != '\0') {

    if(inArray[index] == '.') {
      returnPtr = NULL;
      index++;
    }
    else {
      nPtr = createNode(inArray[index]);
      index++;
      nPtr -> left = preorder_insert(inArray); 
      nPtr -> right = preorder_insert(inArray); 
      returnPtr = nPtr;
    }
  }  

  return returnPtr;
}

int
main(void) {

  char in[MAX_NODES+1];
  struct node *root;

  input(in);

  printf("Input:  %s\n", in);

  root = preorder_insert(in);
  printf("Output: ");
  preorder_print(root);
  printf("\n");

}
