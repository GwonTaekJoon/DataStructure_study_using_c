//
//  main.c
//  Binary_Tree
//
//  Created by 권택준 on 2020/04/03.
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

void Preorder(Node * root){ // 전위순회
    if(root){
        printf("%d ",root -> data);
        Preorder(root -> leftchild);
        Preorder(root -> rightchild);
    }
}

void Inorder(Node * root){ //중위순회
    if(root){
        Inorder(root -> leftchild);
        printf("%d ",root -> data);
        Inorder(root -> rightchild);
        
    }
}

void Postorder(Node * root){
    if(root){
        Postorder(root -> leftchild);
        Postorder(root -> rightchild);
        printf("%d ",root -> data);
    }
}

int main(int argc, const char * argv[]) {
    Node * n7 = InitNode(50, NULL, NULL);
    Node * n6 = InitNode(37, NULL, NULL);
    Node * n5 = InitNode(23, NULL, NULL);
    Node * n4 = InitNode(5, NULL, NULL);
    Node * n3 = InitNode(48, n6, n7);
    Node * n2 = InitNode(17, n4, n5);
    Node * n1 = InitNode(30, n2, n3);
    
    Preorder(n1); //30 17 5 23 48 37 50
    printf("\n");
    Inorder(n1); // 5 17 23 30 37 48 50
    printf("\n");
    Postorder(n1);// 5 23 17 37 50 48 30
    
    return 0;
}

/*          30
    17          48
5      23    37     50*/
