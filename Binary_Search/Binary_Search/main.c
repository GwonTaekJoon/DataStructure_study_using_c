//
//  main.c
//  Binary_Search
//
//  Created by 권택준 on 2020/04/04.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#define MAX_SIZE 10000

int Binary_Search(int * array, int start, int end, int target){
    if(start > end) return -9999;
    int mid = (start + end) / 2;
    if(array[mid] == target) return mid;
    else if(array[mid] > target) return Binary_Search(array, start, mid - 1, target);
    else return Binary_Search(array, mid + 1, end, target);
}
int main(int argc, const char * argv[]) {
    int array[MAX_SIZE];
    int n;
    int target;
    scanf("%d %d",&n,&target);
    for(int i = 0; i < n; i++) scanf("%d",&array[i]);
    
    int result = Binary_Search(array, 0, n-1, target);
    if (result != -9999) printf("%d번째 원소입니다.\n", result);
    else printf("원소를 찾을 수 없습니다.");
    
    
    return 0;
}
