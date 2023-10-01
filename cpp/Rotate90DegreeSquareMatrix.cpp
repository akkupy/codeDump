#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the rows/columns of square matrix: "<<endl;
    cin>>n;

    int mat[n][n];

    cout<<"Enter the elements of matrix :"<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>mat[i][j];
        }
    }

    //transpose of matrix 
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
           swap(mat[i][j], mat[j][i]);
        }
    }

    //swap diagonal element
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            swap(mat[i][j], mat[i][n-j-1]);
        }
    }

    cout<<endl;

    //printing the matrix
    cout<<"The 90 degree rotate Square Matrix : "<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<mat[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}
