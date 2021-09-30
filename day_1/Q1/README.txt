コンパイル & 実行方法
make -f Makefile.hello run

実行結果
output.txtに記載

Makefileのターゲットの説明
- all 実行ファイルを生成する
- hello allと同様
- clean コンパイルで生成したオブジェクトファイルを削除する
- clean_target 実行ファイルを削除する
- clean_all cleanとclean_targetを実行する
- run コンパイルして実行する

