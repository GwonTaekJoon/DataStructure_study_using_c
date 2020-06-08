//
//  main.c
//  BFS
//
//  Created by 권택준 on 2020/04/06.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001
typedef struct _NODE{
    int index;
    struct _NODE * next;
    
}Node;

typedef struct _queue{
    Node * front;
    Node * rear;
    int count;
    
}Queue;

Node ** a;
int c[MAX_SIZE];

void addfront(Node * root , int index){
    Node * node = (Node *)malloc(sizeof(node));
    node -> index = index;
    node -> next = root -> next;
    root -> next = node;
    
}

void queuePush(Queue * queue, int index){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> index = index;
    node -> next = NULL;
    if(queue -> count == 0){
        queue -> front = node;
        
    }
    
    else{
        queue -> rear -> next = node;
        
    }
    queue -> rear = node;
    queue -> count++;
    
}

int queuePop(Queue * queue){
    if(queue -> count == 0){
        printf("큐 언더플로우");
        return -9999;
    }
    Node * node = queue -> front;
    int index = node -> index;
    queue -> front = node -> next;
    free(node);
    queue -> count--;
    return index;
}


void bfs(int start){
    Queue q;
    q.front = q.rear = NULL;
    q.count = 0;
    queuePush(&q, start);
    c[start] = 1;
    while(q.count != 0){
        int x = queuePop(&q);
        printf("%d ",x);
        Node * cur = a[x] -> next;
        while(cur != NULL){
            int next = cur -> index;
            if(!c[next]){
                queuePush(&q, next);
                c[next] = 1;
            }
            cur = cur -> next;
        }
    }
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    int x,y;
    
    scanf("%d %d",&n,&m);
    a = (Node **)malloc(sizeof(Node *) * MAX_SIZE);
    for(int i = 1; i <= n; i++){
        a[i] = (Node *)malloc(sizeof(Node));
        a[i] -> next = NULL;
        
    }
    
    for(int i = 0; i<m; i++){
        
        scanf("%d %d",&x,&y);
        addfront(a[x], y);
        addfront(a[y], x);
    }
    
    
    bfs(1);
    
    
    
    return 0;
}
