//
//  main.c
//  AVL_TREE
//
//  Created by 권택준 on 2020/04/10.
//  Copyright © 2020 권택준. All rights reserved.
//


/*AVL트리는 균형이 갖춰진 이진트리를 의미한다.
 완전 이진 트리는 검색에 있어서 O(logN)의 시간복잡도를 유지할 수 있다.
 AVL트리는 간단한 구현과정으로 특정 이진 트리가
 완전 이진 트리에 가까운 형태를 유지하도록 해준다.*/


/*균형 인수 = |왼쪽 자식 높이 - 오른쪽 자식 높이|
 AVL트리는 모든 노드에 대한 균형 인수가 +1,0,-1인 트리
 균형 인수가 위 세가지 경우에 해당하지 않는 경우 회전을 통해 트리를 재구성*/



/*AVL트리는 총 4가지 형식에 의하여 균형이 깨진다
 균형 인수가 깨지는 노드를 X라고 했을 때
 LL형식 : X의 왼쪽 자식의 왼쪽에 삽입하는 경우
 LR형식 : X의 왼쪽 자식의 오른쪽에 삽입하는 경우
 RR형식 : X의 오른쪽 자식의 오른쪽에 삽입하는 경우
 RL형식 : X의 오른쪽 자식의 왼쪽에 삽입하는 경우*/

/*AVL트리의 각 노드는 '균형 인수'를 계산하기 위한 목적으로 자신의 '높이' 값을 가진다.*/



#include <stdio.h>
#include <stdlib.h>

int getMax(int a, int b){
    if(a>b) return a;
    return b;
}


typedef struct {
    int data;
    int height;
    struct Node * leftchild;
    struct Node * rightchild;
    
}Node;


int getHeight(Node * node){
    if(node == NULL) return 0;
    return node -> height;
    
}

/*setHeight함수는 노드를 회전시킨 이후에 다시 높이를 계산하는 함수
자신의 노드는 왼쪽 자식과 오른쪽 자식중 높이가 더 높은 것에 +1한 값이다.*/
void setHeight(Node * node){
    node -> height = getMax(getHeight(node -> leftchild), getHeight(node -> rightchild)) + 1;
}


/*getDifference함수는 균형인수를 구하는 함수로
 노드의 왼쪽 자식과 오른쪽 자식의 높이를 뺀 값이다.*/
int getDifference(Node * node){
    if(node == NULL) return 0;
    Node * leftchild = node -> leftchild;
    Node * rightchild = node -> rightchild;
    return getHeight(leftchild) - getHeight(rightchild);
    
}

Node * rotateLL(Node * node){
    Node * leftchild = node -> leftchild;
    node -> leftchild = leftchild -> rightchild;
    leftchild -> rightchild = node;
    setHeight(node);
    return leftchild;
    
}
int main(){
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}

