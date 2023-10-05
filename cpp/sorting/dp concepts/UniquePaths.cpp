/*You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 */
//Leetcode Problem
#include<bits/stdc++.h>
using namespace std;
int Paths(vector<vector<int>> obstacleGrid) {
       int m=obstacleGrid.size();
       int n=obstacleGrid[0].size();
       vector<vector<int>> dp(m,vector<int>(n,0));
      if(obstacleGrid[0][0]==0) 
                dp[0][0]=1;
       for(int i=0;i<obstacleGrid.size();i++)
       {
           for(int j=0;j<obstacleGrid[0].size();j++)
           {
                if(obstacleGrid[i][j]==1)
                    continue;
                if(i>0)   
                    dp[i][j]+=dp[i-1][j];
                if(j>0)
                    dp[i][j]+=dp[i][j-1];
            }
       }
       return dp[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
        
    }
     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         return Paths(obstacleGrid);
        
     }
