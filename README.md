# one_commits__Samples__histogram

This is a sample so that I can commit this to the GitHub.

## 1. Question

項数Nと一行の数列anが与えられる。この数列を用いてヒストグラムをアスタリスクで表現せよ。
また階級は1から始まり10刻みとし、ヒストグラムは数値無しの一行で一つの度数とする。
さらにa(i)の値は1～100の範囲とする。

## 2. Conditions

1≦N≦10
1≦a(i)≦100

## 3. Inputs and Outputs

### 3.1. Inputs

```
N
a(1) a(2) a(3) ... a(N)
```

一行目に項数Nを、二行目に数列anの値が半角スペースを区切り文字として与えられる。

### 3.2. Outputs

```
****
********************
***
*******
...
```

一般的なヒストグラムの縦軸と横軸を反対にして一行で一つの階級としたヒストグラムを表示する。

### 3.3. Examples

#### 3.3.1. Inputs 1

```
12
1 2 9 6 10 12 32 12 42 23 27 14
```
#### 3.3.2. Outputs 1

```
*****
***
**
*
*
```

※ Inputs 1 は input1.txt, Output 1 は output1.txt に記述されているとする。

