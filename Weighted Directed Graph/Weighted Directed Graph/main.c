//
//  main.c
//  Weighted Directed Graph
//
//  Created by 권택준 on 2020/04/05.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int index;
    int distance;
    struct Node * next;
}Node;


void add(Node * root, int index, int distance){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> index = index;
    node -> distance = distance;
    node -> next = root -> next;
    root -> next = node;
    
}

void showAll(Node * root){
    Node * cur = root -> next;
    while(cur != NULL){
        printf("%d(거리: %d)",cur -> index, cur -> distance);
        cur = cur -> next;
        
    }
}
int main(int argc, const char * argv[]) {
    int n,m;
    int x,y,distance;
    printf("정점과 간선의 갯수를 입력하세요 : ");
    scanf("%d %d",&n,&m);
    Node ** a = (Node **)malloc(sizeof(Node *) * (n+1));
    for(int i = 1; i <= n; i++){
        a[i] = (Node *)malloc(sizeof(Node));
        a[i] -> next = NULL;
        
    }
    
    
    for(int i = 0; i < m; i++){
        printf("이어질 정점 2개와 가중치를 입력하세요 : ");
        scanf("%d %d %d",&x,&y,&distance);
        add(a[x], y, distance);
        
    }
    
    for(int i = 1; i <= n; i++){
        printf("원소 [%d]: ",i);
        showAll(a[i]);
        printf("\n");
    }
    
    return 0;
}
