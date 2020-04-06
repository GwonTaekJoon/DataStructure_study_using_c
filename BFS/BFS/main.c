//
//  main.c
//  BFS
//
//  Created by 권택준 on 2020/04/06.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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
    q.count = 0;
    queuePush(&q, start);
    
}
int main(int argc, const char * argv[]) {
    // insert code here...fdfdfdfd
    printf("Hello, World!\n");
    return 0;
}
