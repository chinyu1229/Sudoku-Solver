#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
static jmp_buf jmp;
class Solution
{
public:
    vector<pair<int, int>> pos;
    vector<char> calsol(int a, int b, vector<vector<char>> &board)
    {
        vector<char> ss;
        vector<bool> s(10, true);

        for (int i = 0; i < 9; i++)
        {
            if (board[a][i] != '.')
                s[board[a][i] - '0'] = false;
            if (board[i][b] != '.')
                s[board[i][b] - '0'] = false;
        }
        int x = (a / 3) * 3, y = (b / 3) * 3;
        for (int i = x; i < x + 3; i++)
        {
            for (int j = y; j < y + 3; j++)
            {
                if (board[i][j] != '.')
                    s[board[i][j] - '0'] = false;
            }
        }
        for (int i = 1; i < 10; i++)
        {
            if (s[i] == true)
            {
                char buf[10];
                sprintf(buf, "%d", i);
                ss.push_back(buf[0]);
            }
        }
        return ss;
    }
    void dfs(int idx, vector<vector<char>> &board)
    {
        if (idx > pos.size() - 1)
        {
            longjmp(jmp, 1);
            //return ;
        }
        vector<char> feasol;
        feasol = calsol(pos[idx].first, pos[idx].second, board);
        int n = feasol.size();

        if (!n)
            return;

        for (int i = 0; i < n; i++)
        {
            board[pos[idx].first][pos[idx].second] = feasol[i];
            dfs(idx + 1, board);
            board[pos[idx].first][pos[idx].second] = '.';
        }
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    pos.push_back({i, j});

        if (!setjmp(jmp))
            dfs(0, board);

        return;
    }
};