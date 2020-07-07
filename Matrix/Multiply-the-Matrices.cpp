// Problem URL :- https://practice.geeksforgeeks.org/problems/multiply-the-matrices-1587115620/1

#include <bits/stdc++.h>
using namespace std;
#define SIZE 30


 // } Driver Code Ends
/*  Function to multiply matrices
*   n1, m1, n2, m2: rows and cols of matrices
*   arr1[][], arr2[][]: input matrices
*   SIZE: defined globally
*/
void multiplyMatrix(int n1, int m1, int n2, int m2, long long arr1[SIZE][SIZE], long long arr2[SIZE][SIZE]){
    
    // Your code here
    // Input data
	int sum=0;
// Processing
if(m1!=n2)cout<<-1;
else {
    for(int i=0; i<n1; i++) {
		for(int j=0; j<m2; j++) {
			sum = 0;
			for(int k=0; k<m1; k++) sum+=arr1[i][k]*arr2[k][j];
			cout<<sum<<' '; 
		}
	}
}
	
}

// { Driver Code Starts.

int main() {
    long long t;
    cin>>t; //inputting testcases
    while(t--) //while testcases exist
    {
        int n1,m1; //input rows and columns of matrix 1
        cin>>n1>>m1;
        long long arr1[SIZE][SIZE]; //declare the matrix 1
        for(long long i=0;i<n1;i++)
        for(long long j=0;j<m1;j++)
        cin>>arr1[i][j]; //input the matrix 1
        
        int n2,m2;
        cin>>n2>>m2; //inputting the rows and columns of matrix 2
        long long arr2[SIZE][SIZE]; //declare the matrix 2
        for(long long i=0;i<n2;i++)
        for(long long j=0;j<m2;j++)
        cin>>arr2[i][j]; //input the elements of matrix 2
        
        multiplyMatrix(n1, m1, n2, m2, arr1, arr2);
        cout<<endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
