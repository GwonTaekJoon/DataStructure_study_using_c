//
//  main.c
//  LinkedList_Insert
//
//  Created by 권택준 on 2020/03/03.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>



typedef struct _node{
    char data;
    struct _node * link;
    
}node;

node * p_head, *p_end, *temp;
node *p_node_1, *p_node_2, *p_node_3, *p_node_4;

void Init_LinkedList(void);
void InsertNODE(node *);

int main(int argc, const char * argv[]) {
    // insert code here...
    node * p_node;
    
    Init_LinkedList();
    
    /*연결리스트의 노드에 저장한 데이터 출력*/
    
    
    /*반복 실행에서 기준이 되는 노드를 설정하고 헤드노드를 가리킨 후, 기준노드가 엔드노드를 가리킬 때 까지 실행시키는 방법*/
    for(node * start = p_head; start != p_end; start = start -> link){
        printf("%2c", start -> data);
    }
    /*단순히 n번의 반복을 통해 실행시키는 방법 (책에 있는 그대로)
     p_node = p_head -> link;
     for(int i = 0; i>5; i++){
     printf("%2c",p_node -> data);
     p_node = p_node -> link;
     
     }
     */
    
    /* ---------------------------- */
    printf("\n");
    /*새로운 노드의 생성*/
    p_node = (node *)malloc(sizeof(node));
    p_node -> data = 'C';
    
    /*새로 생성한 노드의 삽입*/
    InsertNODE(p_node);
    
    /*연결리스트의 노드에 저장한 데이터의 출력*/
    p_node = p_head -> link;
    for(int i = 0; i<5; i++){
        printf("%2c", p_node -> data);
        p_node = p_node -> link;
    }
    
    return 0;
}



void Init_LinkedList(void){
    
    node * p_node;
    p_head = (node *)malloc(sizeof(node));
    p_end = (node *)malloc(sizeof(node));
    p_node_1 = (node *)malloc(sizeof(node));
    p_node_1 -> data = 'A';
    p_head -> link = p_node_1;
    p_node_1 -> link = p_end;
    p_end -> link = p_end;
    p_node = p_node_1;
    p_node_2 = (node *)malloc(sizeof(node));
    p_node_2 -> data = 'B';
    p_node -> link = p_node_2;
    p_node = p_node_2;
    p_node_3 = (node *)malloc(sizeof(node));
    p_node_3 -> data = 'D';
    p_node -> link = p_node_3;
    p_node_3 -> link = p_end;
    p_node = p_node_3;
    p_node_4 = (node *)malloc(sizeof(node));
    p_node_4 -> data = 'E';
    p_node -> link = p_node_4;
    p_node_4 -> link = p_end;
    p_node = p_node_4;
    
    
    
}


void InsertNODE(node * p_node){
    
    node * start;
    for(start = p_head; start != p_end; start = start -> link){
        /* C데이터를 가진 노드를 B데이터를 가진 노드와 D데이터를 가진 노드 사이에 삽입해야하는데 start가 가리키는 노드가 D일 때, D앞에 C를 삽입할 수 가 없게 되기 때문에 start -> data 대신에 start -> link -> data를 사용한다*/
        if(start -> link -> data > p_node -> data){
            break;
        }
    }
        p_node -> link = start -> link;
        start -> link = p_node;
            
}
