//
//  main.c
//  Parenthesis_Checking_Using_Stack
//
//  Created by 권택준 on 2020/06/06.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct{
    char data[MAX_STACK_SIZE];
    int top;
    
}StackType;
void init_stack(StackType *s){
    s->top = -1;
}

int is_empty(StackType *s){
    return (s->top == -1);
    
}


int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
    
}

void push(StackType *s, char data){
    if(is_full(s)){
        fprintf(stderr, "STACK IS FULL");
        return;
        
    }
    else s->data[++(s->top)] = data;
    
}

char pop(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "STACK IS EMPTY");
        exit(1);
        
    }
    else return s->data[(s->top)--];
    
}

char peek(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "STACK IS EMPTY");
        exit(1);
    }
    else return s->data[s->top];
}

int check_matching(const char *in){
    StackType s;
    char ch, open_ch;
    int i,n = strlen(in);
    init_stack(&s);
    
    for(i = 0; i<n; i++){
        ch = in[i];
        switch(ch){
            case '(': case '[': case '{':
                push(&s, ch);
                break;
            
            case ')': case ']' : case '}':
                if(is_empty(&s)) return 0;
                else{
                    open_ch = pop(&s);
                    if((open_ch == '(' && ch != ')') || (open_ch =='[' && ch != ']') || (open_ch == '{' && ch != '}')){
                        return 0;
                    }
                    break;
                }
        }
    }
    if(!is_empty(&s)) return 0;
    return 1;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    
    
    char *p = "{A[(i+1)]=0;}";
    if(check_matching(p) == 1)
        printf("success");
    
    else
        printf("fail");

    return 0;
}

