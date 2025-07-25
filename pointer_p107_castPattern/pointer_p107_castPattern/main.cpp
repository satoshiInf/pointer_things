//
//  main.cpp
//  pointer_p107_castPattern
//
//  Created by Satoshi on 7/20/25.
//

#include <iostream>


/*

 例1：`double` → `int` にキャスト

 double d = 3.14;
 int i = (int)d;
 ```

 * `d` はキャスト前の型（double）
 * `(int)` はキャスト後の型（int）

 ---

 `int*` → `void*` にキャスト

 void* vp = (void*)p;
 ```

 * `p` の型は `int*`
 * `(void*)` にキャストして `vp` に代入

 ---

 ### 例3：アドレスをキャスト

 ```cpp
 double d = 3.14;
 int* p = (int*)&d;
 * `&d` は `double*`
 * `(int*)` にキャスト → `p` は `int*`


 | 式                        | キャスト後の型 | キャスト前の型   |
 | ------------------------ | ------- | --------- |
 | `(int)d`                 | `int`   | `double`  |
 | `(void*)p`               | `void*` | `int*`    |
 | `(int*)&d`               | `int*`  | `double*` |
 | `reinterpret_cast<T>(x)` | `T`（明示） | `x` の型    |

 ---

 ## ✅ 例：2回キャストの基本構文

 ```cpp
 (最終的な型)(中間型) 値
 ```

 つまり：

 * 最初に `値` を中間型にキャスト
 * その結果を最終的な型にキャスト

 ---

`double` → `void*` → `int*`

 double d = 3.14;
 int* p = (int*)(void*)&d;

 1. `&d` → `double*`
 2. `(void*)&d` → `void*` にキャスト（汎用ポインタ）
 3. `(int*)(void*)&d` → `int*` にキャスト

 ✅ これは「**汎用ポインタ経由で型変換**」している例です。

 ---

`int` → `float` → `char`

 int x = 65;
 char c = (char)(float)x;
 
 1. `x` → `float` に変換（→ 65.0f）
 2. `float` → `char` に変換（→ 'A' 相当のASCII）
 ⚠️ 情報が失われる可能性もある（例：小数点、ビット構造）

 ---

 ### ③ ポインタ → 整数値 → ポインタ（危険な例）

 int* p = ...;
 void* vp = (void*)p;
 uintptr_t addr = (uintptr_t)vp;     // ポインタ → 整数
 void* vp2 = (void*)addr;            // 整数 → ポインタ
 ```

 これは「ポインタ値を整数として一時保存して、再度ポインタに戻す」ような低レベルの操作。OSやハードウェア依存コードでは使われることがあります。

 ---

 ## ⚠️ 注意点

 | キャスト段階         | 安全性の目安    | 説明                    |
 | -------------- | --------- | --------------------- |
 | `T* → void*`   | ✅ 安全      | 標準的な操作（暗黙OK）          |
 | `void* → T*`   | ⚠️ 明示必要   | 正しい型である前提             |
 | `T1* → T2*`    | ⚠️ 危険     | メモリ構造が異なると未定義動作に      |
 | `T → int → T2` | ⚠️ 情報損失あり | 数値変換などは桁落ちやビット欠損の危険あり |

 ---

 ## 🧠 まとめ

 | キャスト形式            | 意味                              |
 | ----------------- | ------------------------------- |
 | `(最終型)(中間型) 値`    | 値を中間型にしてから最終型に変換する              |
 | `(int*)(void*)&d` | `&d` を `void*` にしてから `int*` に変換 |
 | `(char)(float)x`  | `x` を `float` にしてから `char` に変換  |
 | `(T2*)(T1*)ptr`   | ポインタ型を変換（型再解釈、要注意）              |

 ---

 もっと具体的な例で「2回キャストしてこれはどうなる？」というケースがあれば、ぜひ出してください。それに基づいて詳しく解説します！

 
 
*/

int main(int argc, const char * argv[])
{
    
    
    
    
    
    

    return 0;
}
