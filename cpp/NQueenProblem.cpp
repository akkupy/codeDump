
// https://www.codingninjas.com/codestudio/problems/the-n-queens-puzzle_981286?topList=love-babbar-dsa-sheet-problems&leftPanelTab=1&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

#include <bits/stdc++.h> 
void storeAns(vector<vector<int>> &ans, vector<vector<int>> &chessBoard){
    vector<int> tempAns;
    for(auto i : chessBoard){
        for(auto j : i){
            tempAns.push_back(j);
        }
    }
    ans.push_back(tempAns);
}
bool isSafe(int row, int col, int n, unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal, unordered_map<int, bool> &left){
    bool leftCheck= left[row];
    bool lowerDiagonalCheck= lowerDiagonal[row+col];
    bool upperDiagonalCheck= upperDiagonal[n-1+col-row];
    return !leftCheck&&!lowerDiagonalCheck&&!upperDiagonalCheck;
}
void solve(vector<vector<int>> &chessBoard, int currCol, int n, vector<vector<int>> &ans, unordered_map<int, bool> &upperDiagonal, unordered_map<int, bool> &lowerDiagonal, unordered_map<int, bool> &left){
    if(currCol==n){
        storeAns(ans, chessBoard);
        return;
    }
    
    for(int row=0; row<n; row++){
        if(isSafe(row, currCol, n, upperDiagonal, lowerDiagonal, left)){
            chessBoard[row][currCol]= 1;
            left[row]= true;
            lowerDiagonal[row+currCol]= true;
            upperDiagonal[n-1+currCol-row]= true;
            solve(chessBoard, currCol+1, n, ans, upperDiagonal, lowerDiagonal, left);
            chessBoard[row][currCol]= 0;
            left[row]= false;
            lowerDiagonal[row+currCol]= false;
            upperDiagonal[n-1+currCol-row]= false;
        }
    }
    
}
vector<vector<int>> nQueens(int n)
{
    
        vector<vector<int>> chessBoard(n, vector<int>(n,0));
        vector<vector<int>> ans;
        unordered_map<int, bool> upperDiagonal;
        unordered_map<int, bool> lowerDiagonal;
        unordered_map<int, bool> left;

        solve(chessBoard, 0, n, ans, upperDiagonal, lowerDiagonal, left);
    
        return ans;
        
        
}