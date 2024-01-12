#include<iostream>
#include<cstdio>
using namespace std;                                                       

int main(){
	int i,j;
	for(int i=1;i<=3;i++){
		for(int j=i;j<=3;j++){
			cout<<"  ";
		}
		for(int j=1;j<i;j++){
			cout<<"* ";
		}
		for(int j=1;j<=i;j++){
			cout<<"* ";
		}
		cout<<"\n";
	}
}
