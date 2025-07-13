//
//  main.cpp
//  pointer_p142
//
//  Created by Satoshi on 7/13/25.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //int *p = malloc(sizeof(int) *3); //int byte *3 for C
    int *p = (int*) malloc(sizeof(int) *3);//for c++
    
    if(p == NULL)
    {
        printf("FAILED\n");
        return 1;
    }
    
    p[0]=10;
    p[1]=20;
    p[2]=30;
    
    for(int i =0; i< 3; i++)
    {
        printf("p[%d] = %d, Address:%p\n", i , p[i],p[i]);//%d= value
    }
    
    free(p);
    
    
    return 0;
}

/*
 
 ステップ1：malloc
 ┌──────┐
 │ p    │──────────────┐
 └──────┘              ↓
               ┌────┬────┬────┐（ヒープ領域）
               │ 10 │ 20 │ 30 │
               └────┴────┴────┘

 ステップ2：free
 ┌──────┐
 │ p    │──X→（もう無効！アクセスすると未定義）
 └──────┘

 */
