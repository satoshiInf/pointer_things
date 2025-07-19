//わからぬ

#include <stdio.h>
//#include <ctype.h>
//#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int main()
{
    //1)
    int ch;
    ch = getc(stdin);
    std::cout << ch << std::endl;//入力をASCIIコーdに変換する。cf. Aを入れたら65を返す
    
    //2)is-alnum:is -かどうか、alnumはアルファベットと数字・・引数がアルファベットと数字であればtrue

    char buff[16];
    int chh, len;

    while (true)
    {
        // 空白・記号のスキップ
        do
        {
            //エスケイプを押したらreturn 0;
            if ((chh = std::getc(stdin)) == EOF) return 0;
            
            //isalnum(chh)がfalseの間は繰り返す //chhが（a〜z, A〜Z, 0〜9）じゃなければ繰り返す
            //スペース、改行、記号などを無視して、単語の最初の英数字だけを拾いたい。
        } while (!std::isalnum(chh));

        // 単語の読み取り
        len = 0;
        
        do
        {
            if (len < 16) buff[len++] = chh;
            ch = std::getc(stdin);
        }
        while (chh != EOF && std::isalnum(chh));

        buff[len] = '\0';

        std::cout << "<<" << buff << ">>\n";

        if (chh == EOF) break;
    }

    return 0;
}
