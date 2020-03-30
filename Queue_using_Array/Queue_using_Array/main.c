//
//  main.c
//  Queue_using_Array
//
//  Created by 권택준 on 2020/03/29.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int queue[SIZE];
int front = 0;
int rear = 0;

void push(int data){
    if(rear >= SIZE){
        printf("오버 플로우");
        return;
        
    }
    queue[rear++] = data;
    
}

int pop(){
    if(front == rear){
        printf("언더 플로우");
        return -INF;
        
    }
    return queue[front++];
    
}

void show(){
    printf("--- 큐의 앞 ---\n");
    for(int i = front; i<rear; i++){
        printf("%d\n",queue[i]);
        
    }
    printf("--- 큐의 뒤 ---");
}

int main(int argc, const char * argv[]) {
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    pop();
    show();
    
    return 0;
}
