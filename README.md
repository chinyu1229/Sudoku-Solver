# Sudoku Solver

## LEETCODE-37 

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.


![image](https://github.com/chinyu1229/Sudoku-Solver/blob/main/Example.png)


## 解題思想

### function解釋
1. calsol function 計算是否可以每一格可行解
2. pos 放空格（'.'的位置）
3. dfs搜尋可解（回溯法）
4. longjmp => 強制跳出dfs 循環

### dfs解釋
1. 首先，需要填數字，從左到右，從上到下的格子
2. 站在某一格上，並計算可行解，放在vector<char> feasol中 （可行解可能有多個）
3. for循環依序放入可行解，因此在進入下一個格子 => dfs(下一格)
4. 若此格的可行解為0 => 回溯 對應 if(feasol.size() == 0) return ;
5. 因為失敗結束之後需要再還原成 '.' 才可以正確的計算下一格的可行解
6. 再來思考結束點 => 當所有的格子都填上結束
   1. 這邊有個leetcode的限制，因此強制使用longjmp跳出
   2. 普通的情況可以在此直接使用print 把 board 印出




   