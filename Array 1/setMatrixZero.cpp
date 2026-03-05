//Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix..

#include<iostream>
#include<vector>
using namespace std;



int main() {
    
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;


    //Marking the 0th row and col so they can help them mark the other elements of matrix
    for(int i=0 ; i<n; i++){
        for(int j=0 ; j<m ; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                
                if( j!= 0){
                   matrix[0][j] = 0; 
                }
                else{
                    col0 = 0;
                }
                
            }
        }
    }

    //marking other elements with help of 0th row and col

    for(int i=1 ; i<m ; i++){
        for (int j= 1 ; j<n ; j++){
            if(matrix[0][j] == 0 || matrix[i][0] == 0){
                matrix[i][j] = 0;
            }
        }
    }

    //marking the 0th row and col
    if(matrix[0][0] == 0){
        for(int i=0 ; i<n ; i++){
            matrix[0][i] = 0;
        }
    }

    if(col0 == 0){
        for(int i=0 ; i<n ; i++){
            matrix[i][0] = 0;
        }
    }





    
    return 0;
}
