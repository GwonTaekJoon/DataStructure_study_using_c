//
//  main.c
//  Sequential_Search_And_Binary_Search
//
//  Created by 권택준 on 2020/04/04.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 100
int main(int argc, const char * argv[]) {
    int n;
    char ** array;
    int founded;
    char * word;
    
    word = malloc(sizeof(char)*LENGTH);
    printf("입력할 문자열 갯수와 찾을 문자열을 입력하세요\n");
    scanf("%d %s",&n,word);
    array = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i<n; i++){
        array[i] = malloc(sizeof(char) * LENGTH);
        scanf("%s",array[i]);
        
    }
    
    for(int i = 0; i<n; i++){
        if(!strcmp(array[i], word)){
            printf("%d번쩨 원소입니다.\n",i);
            founded = 1;
            
        }
    }
    
    if(!founded){
        printf("원소를 찾을 수 없습니다.\n");
        
    }
    return 0;
}
