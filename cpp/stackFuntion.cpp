#include<iostream>
#include<stdlib.h>
#define SIZE 5
using namespace std;
template<class T>
class stack
{
T stk[SIZE];
int top;
public:
stack()
{
top=-1;
}
void push(T data);
T pop();
void display();
T peek();
int stackempty();
int stackfull();
};
int main()
{
int ch,empty,full;
stack<int>st;
int data,item,pk;
do
{
cout<<"\n Enter your choice:\n 1:push \n 2:pop \n 3:display \n 4:peek \n 5:check stack is empty\n 6:check stack is full \n 7:exit \n";
cin>>ch;
switch(ch)
{
case 1:cout<<"\n Enter the elements to push:";
cin>>data;
st.push(data);
break;
case 2:item=st.pop();
cout<<"\n the item"<<item<<"is poped out from the stack";
break;
case 3:st.display();
break;
case 4:pk=st.peek();
if(pk !=-1)
cout<<"\n The top elements of the stack is :"<<pk;
else
cout<<"\n Stack is empty \n";
break;
case 5:empty=st.stackempty();
if(empty==1)
cout<<"\n Stack is empty!\n";
else
cout<<"\n Stack is not empty! \n";
break;
case 6:full=st.stackfull();
if(full==1)
cout<<"\n Stack is full! \n";
else
cout<<"\n Stack is not full! \n";
break;
case 7: exit(0);
break;
default:cout<<"\n Invalid choice!";
}
}
while(ch);
return 0;
}
template<class T>
void stack<T>::push(T data)
{
if(stackfull())
{
cout<<"\n STACK OVERFLOW!\n";
}
else
{
top=top+1;
stk[top]=data;
cout<<"\n Element"<<data<<"is pushed into the stack!";
}
}
template<class T>
T stack<T>::pop()
{
T item;
if(stackempty())
{
cout<<"\n STACK UNDER FLOW!\n";
}
else
{
item=stk[top];
top=top-1;
}
return(item);
}
template<class T>
void stack<T>::display()
{
int i;
if(! stackempty())
{
cout<<"\n STACK:";
for(i=top;i>=0;i--)
{
cout<<"\t"<<stk[i];
}
}
else
{
cout<<"Stack is empty! \n";
}
}
template<class T>
T stack<T>::peek()
{
if(! stackempty())
return stk[top];
else
return -1;
}
template<class T>
int stack<T>::stackempty()
{
if(top==-1)
return 1;
else
return 0;
}
template<class T>
int stack<T>::stackfull()
{
if(top==SIZE-1)
return 1;
else
return 0;
}


