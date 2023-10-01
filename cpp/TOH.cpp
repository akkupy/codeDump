#include <iostream>
using namespace std;
void solve(int s,int d,int h,int n){
    if(n==1){
        cout<<"Move plate "<<n<<" from "<<s<<" to "<<d<<"\n";
        return;
    }
    solve(s,h,d,n-1);
    cout<<"Move plate "<<n<<" from "<<s<<" to "<<d<<"\n";
    solve(h,d,s,n-1);
}
int main(){
    int n;
    cin>>n;
    int s=1;
    int d=3;
    int h=2;
    solve(s,d,h,n);
}
