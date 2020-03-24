//
//  main.c
//  LinkedList_Delete
//
//  Created by 권택준 on 2019/11/26.
//  Copyright © 2019 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char data;
    struct _node * link;
}node;

node * p_head, *p_end, *temp;
node * p_node_1, *p_node_2, *p_node_3, *p_node_4;

void Init_linkedList(void);
void InsertNODE(node *);
void DisplayNODE(void);
void DeleteNODE(node *);

int main(){
    
    node * p_node;
    Init_linkedList();
    DisplayNODE();
    
    /*새로운 노드의 생성*/
    p_node = (node *)malloc(sizeof(node));
    p_node -> data = 'C';
    
    /*새로 생성한 노드의 삽입*/
    InsertNODE(p_node);
    DisplayNODE();
    
    /*노드의 삭제*/
    DeleteNODE(p_node);
    DisplayNODE();
    
    return 0;
}

/*연결 리스트의 노드에 저장한 데이터의 출력*/

void DisplayNODE(){
    node * p_node;
    p_node = p_head -> link;
    
    while(p_node != p_end){
        printf("%2c",p_node->data);
        p_node = p_node -> link;
        
    }
    printf("\n");
}

void Init_linkedList(void){
    node * p_node;
    p_head = (node *)malloc(sizeof(node));
    p_end = (node *)malloc(sizeof(node));
    p_node_1 = (node *)malloc(sizeof(node));
    p_node_1 -> data = 'A';
    p_head -> link = p_node_1;
    p_node_1 -> link = p_end;
    p_end -> link = p_end;
    p_node = p_node_1;
    p_node_2 = malloc(sizeof(node));
    p_node_2 -> data = 'B';
    p_node -> link = p_node_2;
    p_node_2 -> link = p_end;
    p_node = p_node_2;
    p_node_3 = (node *)malloc(sizeof(node));
    p_node_3 -> data = 'D';
    p_node -> link = p_node_3;
    p_node_3 -> link = p_end;
    p_node = p_node_3;
    p_node_4 = malloc(sizeof(node));
    p_node_4 -> data = 'E';
    p_node -> link = p_node_4;
    p_node_4 -> link = p_end;
    p_node = p_node_4;
}


void InsertNODE(node * p_node){
    node * start;
    
    
    for(start = p_head; start != p_end; start = start -> link){
        if(start -> link  -> data > p_node -> data){
            break;
        }
    }
        p_node -> link = start -> link;
        start -> link = p_node;
        
    
}


void DeleteNODE(node * p_node){
    node * start;
    node * del_node;
    
    char del_data = p_node -> data;
    start = p_head;
    
    while(start != p_end){
        if(start -> link -> data == del_data){
            
            del_node = start -> link;
            break;
        }
        else{
            start = start -> link;
        }
        
    }
    start -> link = start -> link -> link;
    free(del_node);
        
}
