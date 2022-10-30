#include<iostream>
#include "stack.cpp"
using namespace std;
class binary{
	int num,bit,del;
	stack<int>st;
	public:
		void read();
		void display();};

void binary::read(){
	cout<<"enter the decimal number\n";
	cin>>num;
	dec=num;
	while(num>0){
		bit=num%2;
		s1.push(bit);
		num=num/2;}}

void binary::displaty(){
	cout<<"\n the binary of the vdecimal number"<<dec<<"is:";
	while(!stactempty()){
		cout<<st.pop();}
	cout<<"\n";}

int main(){
	binary b;
	b.read();
	b.display();
	return 0;}



