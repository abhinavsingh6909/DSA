//Search in a sorted 2D matrix

//Problem Statement: You have been given a 2-D array 'mat' of size 'N x M' where 'N' and 'M' denote 
//the number of rows and columns, respectively. The elements of each row are sorted in non-decreasing order. 
//Moreover, the first element of a row is greater than the last element of the previous row (if it exists). 
//You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

#include<iostream>
using namespace std;
int main(){

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int target = 16;
    bool mark = false;

    int m = matrix.size();
    int n = matrix[0].size();

    int start = 0;
    int end = (m*n) -1;

    while(start<=end){
        int mid = (start+end)/2;

        int row = mid/n;
        int col = mid%n;

        if(matrix[row][col] == target){
            cout<<"Element at index: ["<<row<<","<<col<<"]";
            mark = true;
            break;
        }

        else if(matrix[row][col] > target){
            end = mid - 1;
        }

        else{
            start = mid + 1;
        }

        mid = (start+end)/2;

    }

    if(mark == false){
        cout<<"Element not present in matrix";
    }

    return 0;
}