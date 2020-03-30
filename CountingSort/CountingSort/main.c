//
//  main.c
//  CountingSort
//
//  Created by 권택준 on 2020/03/29.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#define MAX_VALUE 10001
int a[MAX_VALUE];//배열은 무조건 전역으로하자 전역배열은 알아서 모든 요소가 0으로 초기화된다.
int main(int argc, const char * argv[]) {
    // insert code here...
    int n,m;
    
    
    scanf("%d",&n);
    for(int i= 0; i<n; i++){scanf("%d",&m); a[m]++;}
    for(int i= 0; i<n; i++){
        while(a[i]!=0){
            printf("%d ",i);
            a[i]--;
        }
    
    }
    
    return 0;
}
