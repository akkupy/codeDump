#include<iostream>
#include<string.h>
#include "stack1.cpp"
using namespace std;
class postfixevaluation{
	char exp[25];
	int i,j,k,len;
	int op1,op2,val,result;
	stack<char> st;
	public:
		void read();
		void display();
		void doevaluation();};



void postfixevaluation :: read(){
	cout<<"enter the postfix expression:\n";
	cin>>exp;
	len = strlen(exp);
         }

void postfixevaluation::display(){
	result=st.pop();
	cout<<"\n the evaluated value of the postfix expression  "<<exp<<"   is  "<<result<<endl;}

void postfixevaluation::doevaluation(){
	for(i=0;i<len;i++){
		if(isdigit(exp[i]))
                  	{
			st.push(exp[i]-'0');

                        }
		else{
			op1=st.pop();
			op2=st.pop();
			//cout<<"op1=";
			
			switch(exp[i]){
				case'+':val=op2+op1;
					break;
				case'-':val=op2-op1;
					break;
				case'*':val=op2*op1;
					break;
				case'/':val=op2/op1;
					break;
				default:cout<<"\n invalid values found in postfix expression"<<endl;}
		st.push(val);}}}

int main(){
	postfixevaluation post;
	post.read();
	post.doevaluation();
	post.display();
	return 0;}


