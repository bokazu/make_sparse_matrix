# COO形式を採用した疎行列の行列-ベクトル積のコード

## 1. 内容
このコードでは、COO形式を採用した疎行列の行列-ベクトル積を計算する。計算に使用する行列のデータは`sample/sample1.txt`に入っている。データは以下のような形式で格納されている。
~~~
#sample1.txt
3 3 9   #行数 列数 非ゼロの要素数
0 0 3   #(非ゼロの要素の)行番号 列番号 値
0 1 2   #以下同様
0 2 1   
... 
~~~

## 2. 動作確認
なお、今回はサンプルとして次のような行列を用意した。疎行列ではないが、作成したコードが正しく動作しているかはこれでも確認できるのでよしとする。<br><br>
<img src="https://latex.codecogs.com/gif.latex?A&space;=&space;\left[&space;\begin{matrix}&space;3&space;&&space;2&space;&&space;1\\&space;1&space;&&space;2&space;&&space;3\\&space;2&space;&&space;1&space;&&space;3&space;\end{matrix}&space;\right]">
<br><br>
また、ベクトルとしてx = [1 2 3]を考え、v=Axを計算する。これは手でも計算でき、結果は
v=[10 14 13]
となるはずである。