class Solution {
    int dp[101][101];
    public: Solution(){
        for(int i=0;i<101;i++)
            for(int j=0;j<101;j++)
                dp[i][j]=-1;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
            dp[i][0]=1;
        for(int i=0;i<n;i++)
            dp[0][i]=1;
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
                dp[j][i]=dp[j-1][i]+dp[j][i-1];
        return dp[m-1][n-1];
    }
};