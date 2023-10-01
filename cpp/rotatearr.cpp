/*
@author: nandinisahu407
rotate array k times
pseudo code->
1. reverse(arr,0,n-1)     reversing entire array
2. reverse(arr,0,k-1)     reversing first k elements
3. reverse(arr,k,n-1)     reversing last  n-k elements
*/
#include<iostream>
using namespace std;

void reverse(int *ptr,int len){
    int mid=len/2;
    int temp;

    for(int i=0,j=len-1;i<mid;i++,j--){
        temp=*(ptr+i);
        *(ptr+i)=*(ptr+j);
        *(ptr+j)=temp;

    }

}

void specificreverse(int*ptr,int s,int e){
    
    int total_term=e-s+1;
    int half_term=total_term/2;
    int mid_index=half_term+s;

    int temp;

    for(int i=s,j=e;i<mid_index;i++,j--){
        temp=*(ptr+i);
        *(ptr+i)=*(ptr+j);
        *(ptr+j)=temp;

    }

}

void rotatearr(int*ptr,int len,int k){
    k=k%len;
    //reversing entire array
    reverse(ptr,len);
    
    //reversing first k elements
    /*cout<<"\nafter reversing:\n";
    for(int i=0;i<len;i++){
        cout<<*(ptr+i)<<"\t";
    }*/

    specificreverse(ptr,0,k-1);
    /*cout<<"\nafter reversing first k elements:\n";
    for(int i=0;i<len;i++){
        cout<<*(ptr+i)<<"\t";
    }*/

    specificreverse(ptr,k,len-1);
    /*cout<<"\nafter reversing last n-k elements:\n";
    for(int i=0;i<len;i++){
        cout<<*(ptr+i)<<"\t";
    }*/

}

int main(){
    int num;
    cout<<"enter length:";
    cin>>num;

    int arr[20];
    cout<<"enter array:";
    for(int i=0;i<num;i++){
        cin>>arr[i];
    }

    int k;
    cout<<"how many times to rotate:";
    cin>>k;

    rotatearr(arr,num,k);

    cout<<"\nafter rotating "<<k<<" times\n";
    for(int i=0;i<num;i++){
        cout<<arr[i]<<"\t";
    }

    return 0;

}