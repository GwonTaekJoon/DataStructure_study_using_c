//
//  main.c
//  Graph
//
//  Created by 권택준 on 2020/04/04.
//  Copyright © 2020 권택준. All rights reserved.
//

#include <stdio.h>




int main(int argc, const char * argv[]) {
    // insert code here...
    int a[1001][1001];
    int n,m;
    int x,y;
    
    scanf("%d %d",&n,&m);
    
    for(int i  = 0; i<m; i++){
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
        a[y][x] = 1;
    }
    
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=n; j++){
            printf("%d",a[j][i]);
            
        }
        printf("\n");
    }
    
    return 0;
}
