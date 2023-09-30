//Contributed by:
//Suvrajeet Jash (iPHOENIX-matrix)

#include <iostream>
using namespace std;

class Solution {
public:
    bool isSafe(char value, vector<vector<char>>& board, int row, int col)
    {
        int n=board.size();
        for(int i=0; i<n;i++)
        {
            if(board[row][i]==value)
            return false;

            if(board[i][col]==value)
            return false;

            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value)
            return false;
        }
        return true;
    }


    bool solve(vector<vector<char>>& board)
    {
        int n = board.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == '.')
                {
                    for(char val='1'; val<='9';val++)
                    {
                        if(isSafe(val,board,i,j))
                        {
                            board[i][j]=val;
                            bool aks=solve(board);
                            if(aks==true)
                             return true;
                            else
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;

    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};