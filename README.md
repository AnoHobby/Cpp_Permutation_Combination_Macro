# PerCoM (Permutation_Combination_Macro)

`PerCoM` は、数学的な順列（Permutation）や組み合わせ（Combination）を簡潔に表現できるC++のヘッダーオンリーライブラリです。このライブラリを使用することで、`9P4` や `5C3` といった数学的表記を、C++のコード内で`9 P 4`、`5 C 3`のように(ほぼ)そのまま書くことができます。

## 使用例

```cpp
import "PerCoM.hpp";
import <print>;

auto main() -> int {
    // コンパイル時にも使用可能
    static_assert(9 P 4 == 3024);
    static_assert(5 C 3 == 10);

    // 計算結果を出力
    std::println("9P4 = {}", 9 P 4);  // 9P4 = 3024
    std::println("5C3 = {}", 5 C 3);  // 5C3 = 10

    return EXIT_SUCCESS;
}
```
## ライセンス

このプロジェクトはMITライセンスの下で公開されています。詳細は[LICENSE](./LICENSE)ファイルをご覧ください。
