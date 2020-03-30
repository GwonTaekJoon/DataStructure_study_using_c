//
//  main.c
//  Stack_using_array
//
//  Created by 권택준 on 2020/03/25.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#define SIZE 10000
#define INF 99999999

int stack[SIZE];
int top = -1;


void push(int data){
    if(top == SIZE -1){
        printf("overflow");
        return;
        
    }
    stack[++top] = data;
    
}

int pop(){
    if(top == -1){
        printf("underflow");
        return -INF;
        
    }
    return stack[top--];
}

void show(){
    printf("--- 스택의 최상단 ---\n");
    for(int i = top; i >= 0; i--){
        printf("%d\n",stack[i]);
    }
    printf("--- 스택의 최하단 ---\n");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    push(7);
    push(5);
    push(4);
    pop();
    push(6);
    show();
    return 0;
}
