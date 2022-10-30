#include<iostream>
#include<stdio.h>
#define size 5
using namespace std;
template <class T>
class queue
{
   T q[size];
   int front,rear;
   public:
        queue()
             {
                front=-1;
                rear=-1;
             }
             void insert (T data);
             void del();
 	     void display();
};
template <class T>
void queue<T>::insert(T data)
{
    if((rear==size-1)&&(front==0))
    {
      cout<<"Queue is full";
     }
     else
     {
        rear=rear+1;
        q[rear]=data;
        cout<<data<<"enterd";
	
      }
}
template <class T> 
void queue<T>::del()
{
int y;
	if((front==rear+1 && front==-1)){
	cout<<"queue is empty"<<endl;}
	else{
		y=q[front];
		front++;
		cout<<"the deleted element is"<<y<<endl;}			
}
/*{ 
   if((front=-1)&&(rear=-1))
   {
      cout<<"Queue is empty";
   }
   else 

    {
      int y;
      y=q[front];
      front=front+1;
      cout<<"Deleted element"<<y;

   }
}*/
template <class T>
void queue<T>::display()
{
   int z;
    if((front==-1)&&(rear==-1))
    {
      cout<<"Queue is empty";
    }
    else
    {
      cout<<"elements are";
      for(z=0;z<=rear;z++)
      {
       cout<<"\n"<<q[z]<<endl;
      } 
    }
}
int main()
{
   int ch;
   queue<int>q1;
   int data;
   do
   {
     cout<<"\n enter your choice:\n 1.insert \n 2.delete \n 3.display\n";
     cin>>ch;
      switch(ch)
       {
         case 1:cout<<"\n enter the element to insert";
                cin>>data;
                q1.insert(data);
                break;
         case 2:q1.del();
                break;
         case 3:q1.display();
                break;
        default:cout<<"wrong input";
       }
     }
     while(ch);
return 0;
}
