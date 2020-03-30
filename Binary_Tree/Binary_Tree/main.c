//
//  main.c
//  Binary_Tree
//
//  Created by 권택준 on 2020/03/30.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int data;
    struct Node * leftchild;
    struct Node * rightchild;
    
}Node;


Node * InitNode(int data, Node * leftchild, Node * rightchild){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> leftchild = leftchild;
    node -> rightchild = rightchild;
    return node;
    
    
}

void preorder(Node * root){
    if(root){
        printf("")gdgdsfds
    }
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
