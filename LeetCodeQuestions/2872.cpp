//2872. Maximum Number of K-Divisible Components
//using simple DFS approach

class Solution {
public:
//int res=0;
int dfs(vector<vector<int>>&g,vector<int>& values, int k, int node, int par, int &res)
{
   int sum=values[node];
   for(int i:g[node])
   {
       if(i==par)
       continue;
       int childSum=dfs(g,values,k,i,node,res);
       sum+=childSum;
   }
       if(sum%k==0)
      { ++res;
       return 0;
      }
      return sum;
   

}
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>g(n);
        for(auto &edge:edges)
        {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int res=0;
        dfs(g,values,k,0,-1,res);
        return res;
    }
};