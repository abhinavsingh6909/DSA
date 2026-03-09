//Grid Unique Paths : DP on Grids (DP8)

//Problem Statement: Given two integers m and n, representing the number of rows and columns of a 
//2d array named matrix. Return the number of unique ways to go from the top-left cell (matrix[0][0])
//to the bottom-right cell (matrix[m-1][n-1]).

//Movement is allowed only in two directions from a cell: right and bottom.

#include<iostream>
using namespace std;
int main(){

    int m = 53;
    int n = 4;

    int N = m + n - 2;
    int r = m-1;

    long long ans = 1;

    for(int i=1 ; i<=r ; i++){
        ans = ans * (N-r+i)/(i);
       
    }

    cout<<ans;


    return 0;
}