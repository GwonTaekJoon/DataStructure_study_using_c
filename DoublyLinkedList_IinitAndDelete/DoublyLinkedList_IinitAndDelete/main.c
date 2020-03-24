//
//  main.c
//  DoublyLinkedList_IinitAndDelete
//
//  Created by 권택준 on 2020/03/03.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    char data;
    struct _node * next;
    struct _node * prev;
    
}node;

node * p_head, * p_end, * temp;
node * p_node_1, * p_node_2, * p_node_3, * p_node_4;

void Init_LinkedList(void);
void InsertNODE(node *);
void DeleteNODE(node *);
void DisplayNODE(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    node * p_node;
    
    Init_LinkedList();
    DisplayNODE();
    p_node = (node *)malloc(sizeof(node));
    p_node -> data = 'C';
    
    /*노드의 삽입*/
    InsertNODE(p_node);
    DisplayNODE();
    
    /*노드의 삭제*/
    DeleteNODE(p_node);
    DisplayNODE();
    
    return 0;
}


void Init_LinkedList(void){
    node * p_node;
    p_head = (node *)malloc(sizeof(node));
    p_end = (node *)malloc(sizeof(node));
    p_node_1 = (node *)malloc(sizeof(node));
    p_node_1 -> data = 'A';
    p_head -> next = p_node_1;
    p_node_1 -> next = p_end;
    p_node_1 -> prev = p_head;
    p_end -> next = p_end;
    p_node = p_node_1;
    p_node_2 = (node *)malloc(sizeof(node));
    p_node_2 -> data = 'B';
    p_node -> next = p_node_2;
    p_node_2 -> next = p_end;
    p_node_2 -> prev = p_node;
    p_node = p_node_2;
    p_node_3 = (node *)malloc(sizeof(node));
    p_node_3 -> data = 'D';
    p_node -> next = p_node_3;
    p_node_3 -> next = p_end;
    p_node_3 -> prev = p_node;
    p_node = p_node_3;
    p_node_4 = (node *)malloc(sizeof(node));
    p_node_4 -> data = 'E';
    p_node -> next = p_node_4;
    p_node_4 -> next = p_end;
    p_node_4 -> prev = p_node;
    p_node = p_node_4;
    

}




void InsertNODE(node * p_node){
    
    node * start;
    for(start = p_head; start != p_end; start = start -> next){
        if(start -> data < p_node -> data && start -> next -> data > p_node -> data){
            break;
        }
    }
    p_node -> next = start -> next;
    start -> next -> prev = p_node;
    start -> next = p_node;
    p_node -> prev = start;
}

void DeleteNODE(node * p_node){
    node * start;
    node * del_node;
    
    for(start = p_head; start != p_end; start = start -> next){
        if(start -> next -> data == p_node -> data){
            del_node = start -> next;
            break;
        }
    }
    start -> next = start -> next -> next;
    start -> next -> next -> prev = start;
    
    free(del_node);
}

/*연결리스트의 노드에 저장한 데이터의 출력*/
void DisplayNODE(){
    node * p_node;
    p_node = p_head -> next;
    
    while(p_node != p_end){
        printf("%2c",p_node -> data);
        p_node = p_node -> next;
    }
    printf("\n");
}
