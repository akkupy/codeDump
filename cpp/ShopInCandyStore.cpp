
// https://practice.geeksforgeeks.org/problems/shop-in-candy-store1145/1

class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        
        sort(candies, candies + N);
        
        int buy= 0;
        int free= N-1;
        int mini= 0;
        
        while(buy <= free){
            mini+= candies[buy];
            buy++;
            free-= K;
        }
        
        buy= N-1;
        free= 0;
        int maxi= 0;
        
        while(free<=buy){
            maxi+= candies[buy];
            buy--;
            free+= K;
        }
        
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};