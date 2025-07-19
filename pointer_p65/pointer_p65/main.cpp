

#include <iostream>


int main()
{
    
    /*
     基本
     配列の扱い　＝　先頭のアドレスのポインタである
     よって
     arr = &arr[0]として扱われる
     arr[0]は値、arr+0 はアドレス
     
     arrがアドレスなので　arr+i もアドレス
     arr[0]が値なので　arr[i]も値。
     
     このうえで　配列がポインタという扱いであることから
     &arr[i] == &値　== i番目のアドレス
     *(arr + i) ==* 指し示す先のアドレス　＝＝指し示す値　＝＝i番目の値になる
     
     よって暗黙的に
     int* arr　アドレス
     int* arr+i　アドレス
     int &arr[i] アドレス
     int (*arr[i]) 値
     int arr[i] 値
    */
    
    
    //Cの仕様として
    //arr[i] = *arr[i] という定義がある
    
    //定義　//宣言中　は配列と読む
    int arr[5] ; //暗黙的にarr ==&arr[0] も実行される
    //式中は　arr[3] は三番目の値と読む
    
    
   
    
    
    return 0;
}
