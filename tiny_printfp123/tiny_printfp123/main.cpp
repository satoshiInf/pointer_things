#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

void tiny_printf(char *format, ...)
{
    int i;
    va_list ap; //vast_listが型、apが変数
    //ap は「可変長引数を順番に読み取るためのカウンター（ポインタのようなもの）」です。
    //format は「固定の最後の引数」です。（この場合は char *format）
    //「最初の引数」**は関数に渡されるすべての引数の中の1番目のことを言うなら、
    //それは format のことです。
    //でも va_start(ap, format) の「format の次の引数を指す」という意味での
    //「最初の引数」とは、 可変長引数の中で一番最初に渡された引数のことです。

    va_start(ap, format);　//ap を format の次の引数にセット
    //ap を『format の後ろに続く可変長引数の最初の場所』にセット（指すようにする）」
    //でも va_start(ap, format) の「format の次の引数を指す」という意味での
    //「最初の引数」とは、 可変長引数の中で一番最初に渡された引数のことです。
    for (i = 0; format[i] != '\0'; i++)
    {
        switch (format[i])
        {
          case 's':
            printf("%s ", va_arg(ap, char*));
                //va_arg(ap, char*)    "result.." を文字列として読み取れる
            break;
          case 'd':
            printf("%d ", va_arg(ap, int));
            break;
          default:
            assert(0);
        }
    }
    va_end(ap);
    putchar('\n');
}

int main(void)
{
    tiny_printf("sdd", "result..", 3, 5);
    
    //位置    内容    型
    //1    "sdd"    char*（＝format）
    //2    "result.."    char* ← ここから可変引数部分（va_start後、apがここを指す）
    //3    3    int
    //4    5    int
    
    
    /*
    「なぜ `ap` は `format` の次の引数、つまり `"result.."` を指しているのか？」ということですね。
    ゆっくりわかりやすく説明します。

    ## 1. 関数の引数の並び
    呼び出し：

    ```c
    tiny_printf("sdd", "result..", 3, 5);
    ```
    この引数は順番に渡されます。
    関数の宣言は：
     
    ```c
    void tiny_printf(char *format, ...);
    ```

    * **`format` は1番目の固定引数**
    * `...` はそれ以降に続く可変長引数（ここでは `"result.."`, `3`, `5`）

    ---

    ## 2. `va_start(ap, format)` の役割

    `va_start` はこう言います：

     "sdd" は 固定引数
     "result.."、3、5 は 可変長引数
    > 「可変長引数の読み取りを始める位置は、**『固定引数の最後』の次からだよ」
    つまり、
    `format` という固定引数の「次に来る引数」から可変長引数は始まる、
    なので `ap` をその場所にセットする、ということです。
     その次にある "result.." が可変長引数のいちばん最初
     なので、可変長引数を読み取るための場所（ap）は
     "result.." の位置を指すようにセットされる

    ---

    ## 3. だからなぜ `"result.."` になる？

    呼び出し時の引数リストをもう一度：

    | 順番 | 引数           | コメント          |
    | -- | ------------ | ------------- |
    | 1  | `"sdd"`      | 固定引数 `format` |
    | 2  | `"result.."` | 可変長引数の1番目     |
    | 3  | `3`          | 可変長引数の2番目     |
    | 4  | `5`          | 可変長引数の3番目     |

    ---

    `va_start(ap, format)` により、
    `ap` は「`format` の次、つまり2番目の引数の場所を指す」ので、
    この例では `"result.."` の位置を指すことになるのです。
     va_start(ap, format) の意味
     ap は「可変長引数を順番に読み取るための目印（ポインタや状態）を入れる変数」です。
     format は「固定の最後の引数」です。
     だから、va_start(ap, format) はこういう命令：
     「ap に、『固定引数 format の次にある可変長引数の最初』の場所をセットしなさい」
     
     format は、関数 tiny_printf に渡される固定引数の名前です。
     この関数では次のように宣言されています：

     void tiny_printf(char *format, ...);
     char *format は 文字列へのポインタ（＝Cの文字列）

     ... は 可変長引数

     つまり、関数に渡された最初の引数 "sdd" を受け取るのが format です。

    ---

    ## 4. まとめると

    | 処理                           | 意味                     |
    | ---------------------------- | ---------------------- |
    | `format` の後ろ                 | 可変長引数が並んでいる部分の最初       |
    | `va_start(ap, format)`       | `ap` を「可変長引数の最初」にセットする |
    | そのため `ap` は `"result.."` を指す |                        |

    ---

    ## 5. ちょっとイメージしやすい例え

    * 固定引数が「1列目の席」
    * 可変長引数は「2列目以降の席」

    `va_start` は「2列目の最初の席（ここでは `"result.."`）」を指させる、ということ。

    ---

    これで「なぜ `ap` は `"result.."` を指すのか」のイメージは掴めましたか？
    もしまだわかりにくければ、具体的な図やコードで説明します！

     */

    

    return 0;
}
