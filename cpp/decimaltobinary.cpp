#include<iostream>
#include "stack.cpp"
using namespace std;
template<class T>
class binary
{
	T num,bit,dec;
	stack<int> st;
	public:
		void read();
		void display();};
template<class T>
void binary<T>::read()
{
	cout<<"enter decimal number:";
	cin>>num;
	dec=num;
	while(num>0)
	{
		bit=num%2;
		st.push(bit);
		num=num/2;}}

template<class T>
void binary<T>::display()
{
	cout<<"\n the binary of decimal number "<<dec<<" is : ";
	while(!st.stackempty()){
	cout<<st.pop();}
	cout<<endl;
		st.display();}

int main()
{
	binary<int> h;
	
	h.read();
	h.display();
	return 0;}
