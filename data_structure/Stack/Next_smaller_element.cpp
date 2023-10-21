#include <iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr, int n){
    stack<int>s;

    s.push(-1);
    vector<int>ans(n);

    for(int i=n-1; i>=0; i--){
        int cur = arr[i];

        while(s.top() >= cur){
            s.pop();
        }
        //ans is stack ka top 
        ans[i]=s.top();
        s.push(cur);
    }
    return ans;
}

int main(){

    int n= 4;
    vector<int> arr= {2,1,4,3};
    
    vector<int>ans =nextSmallerElement(arr,n);

    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}