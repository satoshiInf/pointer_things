//
//  main.cpp
//  pointer_p79_skip
//
//  Created by Satoshi on 7/19/25.
//
#include <stdio.h>
#include <iostream>

int main()
{
    // エスケープしたら終わり、
    //エスケープせずにchが英数字でなければ繰り返す
    //英数字でないものはスキップする
    
    //スペース、改行、記号などを無視して、単語の最初の英数字だけを拾いたい。
    int ch;
    do
    {
        //EOFになるのはエスケイプの時。それをを押したらreturn 0;
        if ((ch = std::getc(stdin)) == EOF) return 0;
        //std::cin >>不要
        //std::getc(stdin) ライブラリ　一文字入力させる
        
        //isalnum(chh)がfalseの間は繰り返す //chhが（a〜z, A〜Z, 0〜9）じゃなければ繰り返す
        //スペース、改行、記号などを無視して、単語の最初の英数字だけを拾いたい。
    } while (!std::isalnum(ch));//飛ばす

   
    return 0;
}
