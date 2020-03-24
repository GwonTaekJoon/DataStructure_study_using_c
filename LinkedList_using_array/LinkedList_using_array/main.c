//
//  main.c
//  LinkedList_using_array
//
//  Created by 권택준 on 2020/03/24.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>

int arr[10000];
int count = 0;

void insertBack(int data){
    arr[count] = data;
    count++;
    
}

void insertFirst(int data){
    for(int i = count; i>=1; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = data;
    count++;
}

void show(){
    for(int i = 0; i<count; i++){
        printf("%d",arr[i]);
    }
}

void removeAt(int index){
    for(int i = index; i<count - 1; i++){
        arr[i] = arr[i+1];
        
    }
    count--;
}

void insertAt(int index, int data){
    
    for(int i = count - 1; i>= index; i--){
        arr[i+1] = arr[i];
        
    }
    count++;
    arr[index] = data;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    insertFirst(4);
    insertFirst(5);
    insertFirst(1);
    insertBack(7);
    insertBack(6);
    insertBack(8);
    show();
    printf("\n");
    
    
    insertAt(3, 9);
    show();
    
    
    
    printf("\n");
    removeAt(3);
    show();
    
    
    return 0;
}
