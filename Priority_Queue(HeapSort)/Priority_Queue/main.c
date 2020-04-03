//
//  main.c
//  Priority_Queue
//
//  Created by 권택준 on 2020/04/04.
//  Copyright © 2020 권택준. All rights reserved.
//





/* 우선순위 큐(힙 정렬)는 트리구조로서 우선순위를 가지고있는 데이터를 저장하는 큐이다.
 데이터를 꺼낼 때는 우선순위가 높은 데이터가 가장 먼저 나온다.
 우선순위 큐는 '최대 힙'이라는 것을 이용하여 구현한다.
 최대 힙이란 모든 부모노드가 자식노드들 보다 값이 큰 완전이진트리를 말한다.
 최대 힙의 루트노드는 제일 큰 값을 가진다.*/


/*우선순위 큐의 삽입은 완전이진트리를 유지하는 형태로 순차적으로 삽입된다.
 삽입된 값이 가장 크다면 삽입된 이후에 루트노드까지 거슬러 올라가면서 최대 힙을 구성한다. (상향식)*/

/*우선순위 큐의 삭제는 루트 노드를 제거하고 가장 마지막 원소를 루트노드로 옮겨준다.
 삭제 이후에는 루트부터 내려가면서 루트인 자신보다 값이 큰 노드를 만나면 바꾸어 최대 힙을 구성한다. (하향식)*/




/*삽입시에는 상향식 삭제시에는 하향식*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

void swap(int * a, int * b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


typedef struct {
    int heap[MAX_SIZE];
    int count;
    
}PriorityQueue;


void push(PriorityQueue * pq, int data){
    if(pq -> count >= MAX_SIZE) return;
    pq -> heap[pq -> count] = data;
    /*메인함수에서 pq의 count를 0으로 초기화하고 푸시를 할때마다 count를 늘리면서 head배열에 count인덱스에 데이터를 넣으면 항상 완전이진트리의 마지막원소로서 들어가게 된다.*/
    int now = pq -> count;
    int parent = (now - 1) / 2;
    /*노드 자신의 부모 노드는 자신의 인덱스에 -1을 하고 나누기 2를 한 인덱스를 가진다.*/
    
    //상향식
    while(now > 0 && pq -> heap[now] > pq -> heap[parent]){
        //자신이 부모 노드보다 값이 크다면 바꿔준다.
        swap(&(pq -> heap[now]), &(pq -> heap[parent]));
        now = parent;
        parent = (parent - 1) / 2;
        //바꾼 후 원래의 parent를 가리키고 parnet의 parent와 비교할 수 있게 now와 parent변수의 값을 바꿔준다.
        
    }
    pq -> count++;
    
    
}


int pop(PriorityQueue * pq){
    if(pq -> count <= 0) return -9999;
    int res = pq -> heap[0]; //처음에 루트노드 담기
    pq -> count--;
    pq->heap[0] = pq -> heap[pq -> count]; //루트노드 빼고 그 자리에 마지막 원소 넣기
    int now = 0, leftchild = 1, rightchild = 2;
    int target = now; // 바꾸고자 하는 노드를 가리키는 용도
    
    //하향식
    while(leftchild < pq -> count){
        if(pq -> heap[target] < pq -> heap[leftchild]) target = leftchild;
        //처음에 루트노드와 왼쪽자식노드를 비교해서 왼쪽자식노드가 더 크다면 타겟을 왼쪽자식노드로 바꿔서 우선순위 변경
        if(pq -> heap[target] < pq -> heap[rightchild] && rightchild < pq -> count) target = rightchild;
        //왼쪽자식과 오른쪽자식노드를 비교해서 오른쪽자식노드가 더 크다면 타겟을 오른쪽자식노드로 바꿔서 우선순위 변경
        if(target == now) break;
        //더이상 내려가지 않아도 될때 종료
        else{
            swap(&pq -> heap[now], &pq -> heap[target]);
            now = target;
            leftchild = now * 2 + 1;
            rightchild = now * 2 + 2;
            
        }
    }
    return res;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int n, data;
    scanf("%d",&n);
    PriorityQueue pq;
    pq.count = 0;
    for(int i = 0; i<n; i++){
        scanf("%d",&data);
        push(&pq, data);
    }
    for(int i = 0; i<n; i++){
        int data = pop(&pq);
        printf("%d ",data);
        
    }
    
    
    return 0;
    
}
