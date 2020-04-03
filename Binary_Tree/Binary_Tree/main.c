//
//  main.c
//  Binary_Tree
//
//  Created by 권택준 on 2020/03/30.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node * leftchild;
    struct _Node * rightchild;
    
}Node;


Node * InitNode(int data, Node * leftchild, Node * rightchild){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> leftchild = leftchild;
    node -> rightchild = rightchild;
    return node;
    
    
}

void preorder(Node * root){
    printf("%d",root -> data);
    preorder(root -> leftchild);
    preorder(root -> rightchild);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
