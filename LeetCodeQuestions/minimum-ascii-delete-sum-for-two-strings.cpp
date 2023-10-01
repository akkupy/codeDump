class Solution {
public:
    // int n, m;
    // vector<vector<int>> dp;

    int minimumDeleteSum(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        for(int j=1;j<=m;++j){
            dp[0][j] = dp[0][j-1]+ s2[j-1];
        }
        for(int i=1;i<=n;++i){
            dp[i][0] = dp[i-1][0]+ s1[i-1];
        }
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(dp[i][j-1] + s2[j-1], dp[i-1][j]+s1[i-1]);
                }
            }
        }
        return dp[n][m];
        
    }

    // 1st Approach

    // int minimumDeleteSum(string s1, string s2){
    //     n = s1.length();
    //     m = s2.length();
    //     dp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
    //     return rec(s1, s2, 0, 0);
    // }

    // int rec(string s1, string s2, int i , int j ){
    //     if(i>= n && j>= m ) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(i>= n){
    //         return dp[i][j] = rec(s1, s2, i, j+1) + s2[j];
    //     }else if(j>= m){
    //         return dp[i][j] = rec(s1, s2, i+1, j) + s1[i];
    //     }else if(s1[i]==s2[j]){
    //         return dp[i][j] = rec(s1, s2, i+1, j+1);
    //     }
    //     int del1 = rec(s1, s2, i, j+1)+s2[j];
    //     int del2 = rec(s1, s2, i+1, j)+s1[i];
    //     return dp[i][j] = min(del1, del2) ;
    // }
};