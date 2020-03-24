//
//  main.c
//  Stack_Using_LinkedLIst
//
//  Created by 권택준 on 2020/03/06.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

/*스택의 자료 구조용 노드의 선언*/
typedef struct _NODE{
    int Data;
    struct _NODE *Next;
}NODE;

NODE *head, *end;
NODE *ptrNODE;

void Init_STACK(void);      /*스택 초기화 함수*/
void Push(int);            /*데이터의 삽입*/
void Display_STACK(void);   /*스택을 보여줌*/
int Pop(void);              /*데이터의 삭제*/
int main(int argc, const char * argv[]) {
    // insert code here...
    
    int ret;
    Init_STACK();

    Push(1);
    Push(3);
    Push(10);
    Push(20);
    Push(12);
    
    printf("다섯번의 Push()함수의 호출 후 실행 결과\n");
    Display_STACK();
    
    ret = Pop();
    ret = Pop();
    ret = Pop();
    
    printf("\n세번의 Pop()함수의 호출후 실행결과\n");
    
    Display_STACK();
    return 0;
}


void Init_STACK(void){
    head = (NODE *)malloc(sizeof(NODE));
    end = (NODE *)malloc(sizeof(NODE));
    head -> Next = end;
    end -> Next = end;
    
}


void Push(int num){
    ptrNODE = (NODE *)malloc(sizeof(NODE));
    ptrNODE -> Data = num;
    ptrNODE -> Next = head -> Next;
    head -> Next = ptrNODE;
}

int Pop(void){
    int ret;
    ptrNODE = head -> Next;
    head -> Next = head -> Next -> Next;
    ret = ptrNODE -> Data;
    free(ptrNODE);
    
    return ret;
}

void Display_STACK(void){
    NODE * currentNODE;
    printf("head -> ");
    
    for(currentNODE = head -> Next; currentNODE != end; currentNODE = currentNODE -> Next){
        printf("%d -> ",currentNODE-> Data);
        printf("end");
    }
}

