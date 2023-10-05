
// When n = 4

// Output: 
// ********
// ***  ***
// **    **
// *      *
// *      *
// **    **
// ***  ***
// ******** 

// when n = 6

// Output:   
// ************
// *****  *****
// ****    ****
// ***      ***
// **        **
// *          *
// *          *
// **        **
// ***      ***
// ****    ****
// *****  *****
// ************



#include <bits/stdc++.h>
using namespace std;

void pattern(int N)
{
      
      int iniS = 0;
      for(int i=0;i< N;i++){
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=N-i;j++){
              cout<<"*";
          }
          
          // The spaces increase by 2 every time we hit a new row.
          iniS+=2;
          
          cout<<endl;
      }
      
      // for lower half of the pattern
      
      // initial spaces.
      iniS = 2*N -2;
      for(int i=1;i<=N;i++){
          

          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          //for printing the spaces in the row.
          for(int j=0;j<iniS;j++){
              cout<<" ";
          }
          
          //for printing the stars in the row.
          for(int j=1;j<=i;j++){
              cout<<"*";
          }
          
          iniS-=2;
          
          cout<<endl;
      }
      
}

int main()
{   
    // Here, we are taking the input from the user.
    int N ;
      cout << "\nEnter number of rows: ";
    cin>>N;
    
    pattern(N);

    return 0;
}
