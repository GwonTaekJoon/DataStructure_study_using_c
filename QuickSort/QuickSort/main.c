//
//  main.c
//  QuickSort
//
//  Created by 권택준 on 2020/03/29.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#define SIZE 1000



void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
    
}
//피봇(key)을 0번째 원소로 지정
void quickSort(int a[], int start, int end){
    if(start >= end) return;
    int key = start, i = start + 1, j = end;
    while(i <= j){
        while(i <= end && a[i] <= a[key]) i++;
        while(j > start && a[j] >= a[key]) j--;
        if(i > j) swap(&a[key], &a[j]);
        else swap(&a[i], &a[j]);
        
    }
    quickSort(a,start, j-1);
    quickSort(a,j + 1,end);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int n;
    int a[SIZE];
    
    scanf("%d",&n);
    for(int i = 0; i<n; i++) scanf("%d",&a[i]);
    quickSort(a,0, n-1);
    for(int i = 0; i<n; i++) printf("%d",a[i]);
    
    return 0;
}
