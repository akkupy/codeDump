#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;

//First method--
char names(char name[10],int n){
	if(n<0)
	return '\0';
	
	printf("%c\n",name[n]);
	return names(name,n-1);
}
int main(){
	char name[10];
	cout<<"Enter Name:";
	cin>>name;
	names(name,6);
}


//Second method--
int rev(char arr[],int n){
	if(n<=strlen(arr)){
		rev(arr,n+1);
		printf("%c\n",arr[n]);
	}
}

int main(){
	rev("kirti",0);
}


//Third method--
void reverse(string s){
	if(s.length()==0){
		return;
	}
	string rev=s.substr(1);
	reverse(rev);
	cout<<s[0]<<endl;
}
int main(){
	reverse("kirti");
}
