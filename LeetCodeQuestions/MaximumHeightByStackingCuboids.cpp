
// https://leetcode.com/problems/maximum-height-by-stacking-cuboids/description/

class Solution {
public:
    bool check(vector<int> base, vector<int> newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2])
            return true;
        else
            return false;
    }
    int solve(vector<vector<int>>& cuboids) {
        int n= cuboids.size();
        if(n==0)
            return 0;
        
        vector<int> current(n+1, 0);
        vector<int> next(n+1, 0);

        for(int curr= n-1; curr>=0; curr--){
            for(int prev= curr-1; prev>=-1; prev--){
                int include= 0;
                if(prev==-1 || check(cuboids[curr], cuboids[prev]))
                    include= cuboids[curr][2] + next[curr+1];
                
                int exclude= 0 + next[prev+1];

                current[prev+1]= max(include, exclude);
            }
            next= current;
        }
        return next[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        
        for(auto &dimensions : cuboids){
            sort(dimensions.begin(), dimensions.end());
        }
        sort(cuboids.begin(), cuboids.end());

        return solve(cuboids);
    }
};