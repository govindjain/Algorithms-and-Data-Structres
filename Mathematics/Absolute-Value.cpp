// Problem URL :- https://practice.geeksforgeeks.org/problems/absolute-value/1

#include<bits/stdc++.h>

using namespace std;

int absolute(int I);

int main() {
    int T;    // number of testcases
    cin >> T; // input number of testcases
    while (T--) {
        int I;
        cin >> I;
        cout << absolute(I) << endl; // print the output
    }
    return 0;
}/*This is a function problem.You only need to complete the function given below*/
// User function Template for C++
// Should return absolute value of I
// You need to complete this function
int absolute(int I) {
    if(I>0) {return I;}
    else {return (-1)*I; }
}

