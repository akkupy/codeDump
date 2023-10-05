
// https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool safeToGo(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited){
        
        if(x>=0 && x<n && y>=0 && y<n && m[x][y]==1 && visited[x][y]==0)
            return true;
        else
            return false;
        
    }
    
    void solve(vector<vector<int>> &m, int n, int x, int y, vector<vector<int>> visited, 
                string path, vector<string> &ans){
        if(x==n-1 && y==n-1){
            ans.push_back(path);
            return;
        }
        
        visited[x][y]= 1;
        
        //Right
        if(safeToGo(m,n,x,y+1,visited)){
            path.push_back('R');
            solve(m,n,x,y+1,visited,path,ans);
            path.pop_back();
        }
        
        //Left
        if(safeToGo(m,n,x,y-1,visited)){
            path.push_back('L');
            solve(m,n,x,y-1,visited,path,ans);
            path.pop_back();
        }
        
        //Down
        if(safeToGo(m,n,x+1,y,visited)){
            path.push_back('D');
            solve(m,n,x+1,y,visited,path,ans);
            path.pop_back();
        }
        
        //Up
        if(safeToGo(m,n,x-1,y,visited)){
            path.push_back('U');
            solve(m,n,x-1,y,visited,path,ans);
            path.pop_back();
        }
        
        visited[x][y]=0;
                    
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<int>> visited= m;
        vector<string> ans;
        string path="";
        
        if(m[0][0]==0)
            return ans;
            
        int srcX=0, srcY=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                visited[i][j]=0;
            }
        }
        
        solve(m, n, srcX, srcY, visited, path, ans);
        
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends