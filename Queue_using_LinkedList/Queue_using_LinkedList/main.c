//
//  main.c
//  Queue_using_LinkedList
//
//  Created by 권택준 on 2020/03/29.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define INF 99999999

typedef struct{
    int data;
    struct Node * next;
    
}Node;

typedef struct{
    Node * front;
    Node * rear;
    int count;
    
}Queue;

void push(Queue * queue, int data){
    Node * node = (Node *)malloc(sizeof(Node));
    node -> data = data;
    node -> next = NULL;
    if(queue -> count == 0){
        queue -> front = node;
        
    }
    else{
        queue -> rear -> next = node;
    }
    queue->rear = node;
    queue -> count++;
}

int pop(Queue * queue){
    if(queue -> count == 0){
        printf("언더플로우");
        return -INF;
        
    }
    Node * node = queue->front;
    int data = node -> data;
    queue -> front = node -> next;
    free(node);
    queue -> count--;
    return data;
    
}

void show(Queue * queue){
    Node * cur = queue -> front;
    printf("--- 큐의 앞 ---\n");
    while(cur != NULL){
        printf("%d\n",cur -> data);
        cur = cur -> next;
        
    }
    printf("--- 큐의 뒤 ---\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    Queue queue;
    queue.front = queue.rear = NULL;
    queue.count = 0;
    push(&queue, 7);
    push(&queue, 5);
    push(&queue, 4);
    pop(&queue);
    push(&queue, 6);
    pop(&queue);
    show(&queue);
    
    return 0;
}
