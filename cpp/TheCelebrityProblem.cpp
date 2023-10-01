
// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1

// TC-> O(N), SC->O(1)
class Solution {
public:
    // Function to find if there is a celebrity in the party
    // or not.
    int celebrity(int M[4][4], int n)
    {
        // r=row number
        int r = 0;
        for (int i = 1; i < n; i++) {
            // checking if r th person knows i th person
            if (M[r][i] == 1) {
                M[r][r] = 1;
                r = i;
            }
            else {
                M[i][i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            // checking if i th person can be a celebrity or
            // not
            if (M[i][i] == 0) {
                int flag = 0;
                // iterating in the i th column to check
                // whether everyone knows i th person or not
                for (int j = 0; j < n; j++) {
                    // checking if M[j][i] is not a diagonal
                    // element and if j th person knows i th
                    // person
                    if (j != i && M[j][i] == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                    return i;
            }
        }
        return -1;
    }
};


// TC-> O(N), SC-> O(N)
class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        stack<int> s;
        for(int i=0; i<n; i++)
            s.push(i);
            
        while(s.size()!=1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(M[a][b]==1)
                s.push(b);
            else
                s.push(a);
        }
        
        int candidate= s.top();
        
        for(int i=0; i<n; i++){
            
            if(candidate!=i){
                if(M[candidate][i]==1)
                    return -1;
                if(M[i][candidate]!=1)
                    return -1;
            }
            
        }
        
        return candidate;
        
    }
};