
// https://leetcode.com/problems/minimum-cost-for-tickets/description/

class Solution {
public:
    // Simple Recursive Solution
    // int solve(int n, vector<int> &days, vector<int> &costs, int index){
    //     if(index>=n)
    //         return 0;
        
    //     int option1= costs[0] + solve(n, days, costs, index+1);
        
    //     int i=0;
    //     for(i= index; i<n && days[i]<days[index]+7; i++);
    //     int option2= costs[1] + solve(n, days, costs, i);

    //     for(i= index; i<n && days[i]<days[index]+30; i++);
    //     int option3= costs[2] + solve(n, days, costs, i);

    //     return min(option1, min(option2, option3));

    // }

    // Recursion + Memoization (Top-Down Approach)
    // int solve(int n, vector<int> &days, vector<int> &costs, int index, vector<int> &dp){
    //     if(index>=n)
    //         return 0;
        
    //     if(dp[index]!=-1)
    //         return dp[index];

    //     int option1= costs[0] + solve(n, days, costs, index+1, dp);
        
    //     int i=0;
    //     for(i= index; i<n && days[i]<days[index]+7; i++);
    //     int option2= costs[1] + solve(n, days, costs, i, dp);

    //     for(i= index; i<n && days[i]<days[index]+30; i++);
    //     int option3= costs[2] + solve(n, days, costs, i, dp);

    //     dp[index]= min(option1, min(option2, option3));

    //     return dp[index];
    // }

    // Tabulation Method (Bottom-Up Approach)
    // int solve(int n, vector<int> &days, vector<int> &costs){
    //     vector<int> dp(n+1, INT_MAX);
    //     dp[n]= 0;

    //     for(int index=n-1; index>=0; index--){
    //         int option1= costs[0] + dp[index+1];
            
    //         int i=0;
    //         for(i= index; i<n && days[i]<days[index]+7; i++);
    //         int option2= costs[1] + dp[i];

    //         for(i= index; i<n && days[i]<days[index]+30; i++);
    //         int option3= costs[2] + dp[i];

    //         dp[index]= min(option1, min(option2, option3));
    //     }

    //     return dp[0];
    // }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        // Simple Recursive Solution
        // return solve(days.size(), days, costs, 0);

        // Recursion + Memoization (Top-Down Approach)
        // vector<int> dp(days.size()+1, -1);
        // return solve(days.size(), days, costs, 0, dp);

        // Tabulation Method (Bottom-Up Approach)
        // return solve(days.size(), days, costs);

        int ans= 0;
        queue<pair<int, int>> weeks;
        queue<pair<int, int>> monthly;

        for(auto day: days){

            while(!weeks.empty() && weeks.front().first+7 <=day )
                weeks.pop();

            while(!monthly.empty() && monthly.front().first+30 <=day )
                monthly.pop();

            weeks.push(make_pair(day, ans + costs[1]));
            monthly.push(make_pair(day, ans + costs[2]));

            ans= min(ans + costs[0], min(weeks.front().second, monthly.front().second));

        }

        return ans;
    }
};