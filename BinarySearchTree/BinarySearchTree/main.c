//
//  main.c
//  BinarySearchTree
//
//  Created by 권택준 on 2020/04/08.
//  Copyright © 2020 권택준. All rights reserved.
//






/*이진탐색트리는 이진탐색과 연결리스트가 결합한 자료구조이며,
 이진탐색의 효율적인 탐색능력을 유지하면서도, 빈번한 자료 입력과 삭제를
 가능하게한다.*/

/*이진 탐색 트리의 성능을 최대로 끌어내기 위해서는 이진 탐색 트리가 완전 이진 트리에 가까워 질 수 있도록
 설계해야 한다. 왜냐? 높이가 낮을수록 탐색을 빨리 해서 균형이 잡힌 트리가 될 수 있도록 설계*/

/*트리를 사용하면 데이터를 처리함에 있어서 효율적이다. 트리에서 데이터의 개수가 N개일때 배열과 마찬가지로
 O(N)의 공간만이 소요되며 삽입 및 삭제에 있어서 일반적인 경우 기존의 배열을 이용하는 방식보다 효율적
 그래서 데이터베이스 등 대용량 저장 및 검색 자료구조로 많이 활용된다.*/

/*편향 이진 트리의 경우 탐색에 있어 O(N)의 시간복잡도를 가진다.
 따라서 이진 탐색 트리를 최대한 완전 이진 트리의 형태를 유지할 수 있도록 해야한다.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    int data;
    struct _Node * leftchild;
    struct _Node * rightchild;
    
}Node;

Node * insertNode (Node * root, int data){
    if(root == NULL){
        root = (Node *)malloc(sizeof(Node));
        root -> leftchild = root -> rightchild = NULL;
        root -> data = data;
        return root;
    }
    else{
        if(root -> data > data){
            root -> leftchild = insertNode(root->leftchild, data);
            
        }
        else{
            root -> rightchild = insertNode(root -> rightchild, data);
        }
    }
    
    return root;
}


Node * searchNode(Node * root, int data){
    if(root == NULL) return NULL;
    if(root -> data == data) return root;
    else if(root -> data > data) return searchNode(root -> leftchild, data);
    else return searchNode(root -> rightchild, data);
    
}

void Preorder(Node * root){
    if(root == NULL) return;
    printf("%d ",root -> data);
    Preorder(root -> leftchild);
    Preorder(root -> rightchild);
    
}

/*노드를 지우는 과정에서 쓰인다. 지우려는 노드의 자식이 2개일 때
 삭제할 노드의 자리에 자기 다음으로 큰 노드를 넣는다.
 그렇기에 자신의 노드에 오른쪽에 위치한 노드들 중 가장 작은 노드를 찾아야하기에
 이 함수가 필요하다*/
Node * findMinNode(Node * root){
    Node * node = root;
    while(node -> leftchild !=NULL){
        node = node -> leftchild;
    }
    return node;
    
}


Node * deleteNode(Node * root, int data){
    Node * node = NULL;
    if(root == NULL) return NULL;
    if(root -> data > data) root -> leftchild = deleteNode(root -> leftchild, data);
    else if(root -> data < data) root -> rightchild = deleteNode(root -> rightchild, data);
    else{
        if(root -> leftchild != NULL && root -> rightchild != NULL){
            node = findMinNode(root -> rightchild);
            root -> data = node -> data;
            root -> rightchild = deleteNode(root -> rightchild, node -> data);
        }
        else{
            node = (root -> leftchild != NULL) ? root ->leftchild : root -> rightchild;
            free(root);
            return node;
            
        }
    }
    
    return root;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Node * root = NULL;
    root = insertNode(root, 30);
    root = insertNode(root, 17);
    root = insertNode(root, 48);
    root = insertNode(root, 5);
    root = insertNode(root, 23);
    root = insertNode(root, 37);
    root = insertNode(root, 50);
    root = deleteNode(root, 30);
    Preorder(root);
    
    return 0;
}
