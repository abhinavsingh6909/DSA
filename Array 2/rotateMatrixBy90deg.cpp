//Rotate Image by 90 degree

// /Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise.
// The rotation must be done in place, meaning the input 2D matrix must be modified directly.

#include<iostream>
using namespace std;
int main(){

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };


    int n = matrix.size();

    //Transpose of matrix
    for(int i = 0 ; i<n-1 ; i++){
        for(int j=i+1 ; j<n ; j++){
            swap(matrix[i][j] , matrix[j][i]);
        }
    }

    //Reversing Each row to get the rotated Matrix

    for(int i=0 ; i<n ; i++){
        reverse(matrix[i].begin() , matrix[i].end());
    }

    cout<<"Matrix after rotating it by 90deg: "<<endl;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}