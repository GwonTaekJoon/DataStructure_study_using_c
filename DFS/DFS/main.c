//
//  main.c
//  DFS
//
//  Created by 권택준 on 2020/04/05.
//  Copyright © 2020 권택준. All rights reserved.
//

//모든 경우의 수를 빠르게 탐색하고자 할 때
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
typedef struct _node{
    int index;
    int check;
    struct _node * next;
}Node;

Node ** a;
int n,m;

void add(Node * root, int index){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> index = index;
    node -> next = root -> next;
    root -> next = node;
    
}

void dfs(int x){
    if(a[x] -> check) return;
    a[x] -> check = 1;
    
    printf("%d ",x);
    Node * cur = a[x] -> next;
    while(cur != NULL){
        int next = cur -> index;
        dfs(next);
        cur = cur -> next;
    }
}

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&m);
    a = (Node **)malloc(sizeof(Node *) * MAX_SIZE);
    for(int i  = 1; i <= n; i++){
        a[i] = (Node *)malloc(sizeof(Node));
        a[i] -> next = NULL;
        a[i] -> check = 0;
        
    }
    
    for(int i = 0; i < m; i++){
        int x,y;
        scanf("%d %d",&x,&y);
        add(a[x], y);
        add(a[y], x);
        
        
    }
    
    
    dfs(1);
    
    
    return 0;
}
