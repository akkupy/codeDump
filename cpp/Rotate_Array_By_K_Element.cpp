#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cout<<"Enter the size of Array : ";
    cin>>n;
    vector<int> v(n);

    cout<<"Enter the element of Array : "<<endl;
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int k;
    cout<<"Enter the value of K : ";
    cin>>k;
    k=k%v.size();

    reverse(v.begin(), v.end());
    reverse(v.begin(), v.begin()+k);
    reverse(v.begin()+k, v.end());

    for(int a:v){
        cout<<a<<" ";
    }
    return 0;
}
