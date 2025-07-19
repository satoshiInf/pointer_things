

#include <iostream>


//仕様として　arr[i] == *(arr+i)として機械は解釈する。
//*(arr+i) ≡*(i + arr)なので　arr[i] ≡i[arr]になる

//宣言　定義した時　int arr[];
//int arr[3];をint型の配列型として宣言。arr = ＊arr[0]として扱われる
//arr == *arr[0]


//以後式として扱われる。
//式で使うとき　暗黙的にint*に変換される。
//配列からポインタへの変換に見える。しかし型はそのままなので定義した方が良い
//int arr[3] ={10,20,30};
//int*p = arr;でpに先頭のアドレスを保持させる。

/*
 ✅ まとめから言うと：
 「arrがポインタのように使える」＝「ポインタ変数が存在する」ではない
 配列名 arr は、式の中でポインタに 「変換される」 だけであって、
 *ポインタ型の変数（int）として「保持されている」わけではない**のです。
 🔍 なぜ arr[1] や *(arr + 1) が使えるの？
 それは✅ arr は 式の中で 自動的に int* に変換される（ポインタへの「暗黙変換」）
 からです。
 */

void printArray(int* p, int size)
{
    for (int i = 0; i < size; ++i)
        std::cout << p[i] << " ";
}


#include <iostream>
using namespace std;

int main() {
    int arr[3] = {10, 20, 30};

    // これはOK
    cout << arr[1] << endl;       // 20
    cout << *(arr + 1) << endl;   // 20

    // これはNG
    // arr = arr + 1;  // ❌ エラー：配列名には代入できない

    
    
    
    //ポインタを使わないといけない
    int* p = arr;       // ✅ 明示的にポインタ変数を作る
    
    //1)関数で配列を扱うとき
    printArray(arr, 3);
    
    //2)ポインタの再代入をしたいとき
    //arr = arr + 2; みたいなことは配列では不可能。→ 再代入できるのはポインタ変数のみ。
    p= p+2;
    std::cout<< p << std::endl;
    
    //3) 文字列
    //charポインタのsは頭の文字のアドレスをs[0]と解釈する
    
    const char* s ="Hello";
    //暗黙的にconst char[6]=（'H','e','l','l','o','\0'）;
    
    std::cout << s[1] <<std::endl;
    
    //charポインタのsは頭の文字のアドレスをs[0]と解釈する。
    //つまりこのchar*配列は各々の要素の頭の文字のアドレスを格納する
    //charでは
    const char* ss[] ={"Hello", "GoodMOrning"};
    
    std::cout << ss[0][0] <<std::endl;
    std::cout << ss[1] <<std::endl;
    
    /*
     
     * `const char* s = "Hello";`
       → `s` は「文字列 "Hello" の先頭文字（'H'）のアドレス」
       → `s[1]` は `'e'`
     ✔️ ✅ 完璧です！

     ---
     ## 🔄 では次：
     const char* ss[] = {"Hello", "GoodMorning"};
     ## ✅ `const char* ss[]` は「**ポインタの配列**」
     ss[0] → "Hello"       → 'H'
     ss[1] → "GoodMorning" → 'G'
     ss[0][1] → 'e'         （"Hello" の2文字目）
     ss[1][4] → 'M'         （"GoodMorning" の5文字目）
     ```

     つまり：

     | 型         | 意味                  |
     | --------- | ------------------- |
     | `char*`   | 文字列（先頭文字へのポインタ）     |
     | `char*[]` | 文字列を複数格納した「ポインタの配列」 | //要素が複数の時に[]をつける

     ---

     ## ✅ コード例

     ```cpp
     #include <iostream>
     int main() {
         const char* ss[] = {"Hello", "GoodMorning"};

         std::cout << ss[0] << std::endl;     // Hello
         std::cout << ss[1] << std::endl;     // GoodMorning

         std::cout << ss[0][1] << std::endl;  // 'e'
         std::cout << ss[1][4] << std::endl;  // 'M'
     }
     ```

     ---

     ## ✅ 「ややこしい」理由は、2重構造だから

     * `ss[0]` → 1つの文字列（"Hello"）の先頭アドレス（＝`char*`）
     * `ss[0][1]` → その文字列の2文字目（`'e'`）

     > **配列の中にポインタ**が入っていて、
     > そのポインタの先には\*\*また配列（文字列）\*\*がある。

     ---

     ## 🧠 ざっくり整理

     | 宣言                          | 意味                       |
     | --------------------------- | ------------------------ |
     | `const char* s = "Hello";`  | 1つの文字列の先頭を指すポインタ         |
     | `const char* ss[] = {...};` | 複数の文字列を指すポインタの配列（文字列リスト） |

     ---
     ## 🔚 最後にイメージで整理：
     const char* ss[] = { "Hello", "GoodMorning" };
     // ポインタの配列 ss[0], ss[1]
     ss[0] → "Hello"        → ['H','e','l','l','o','\0']
     ss[1] → "GoodMorning"  → ['G','o','o','d','M','o',...]
     ```

     ---

     ### ✅ よく使う場面
     この `const char* ss[]` という形式は、
     * メニュー項目のリスト
     * エラーメッセージ一覧
     * 簡単な辞書データ
     などでよく使います。

     ---
     > 「ややこしい」と思ったら、「**ポインタの配列＋各要素が文字列**」という2層構造で考えるとクリアになります！
     もし次に進みたいなら、`char**` と `char*[]` の違いとか、`argv` の意味なども面白いですよ。聞きたければいつでも！

     */
    
    
    
    cout << *p << endl; // → 20
}
