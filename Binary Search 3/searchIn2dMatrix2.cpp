//Search in 2D matrix - II

//Given a 2D array matrix where each row is sorted in ascending order from left to right 
//and each column is sorted in ascending order from top to bottom, write an efficient algorithm 
//to search for a specific integer target in the matrix.

#include <iostream>
using namespace std;

class Solution {
public:
    //Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        //Intialize the row and col
        int row = 0, col = m - 1;

        //Traverse the matrix from (0, m-1):
        while (row < n && col >= 0) {
            
            //Return true of target is found
            if (matrix[row][col] == target) return true;
            else if (matrix[row][col] < target) row++;
            else col--;
        }
        //Return false if target not found
        return false;
    }
};

int main() {
    
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, 
                                  {2, 5, 8, 12, 19},
                                  {3, 6, 9, 16, 22},
                                  {10, 13, 14, 17, 24},
                                  {18, 21, 23, 26, 30}};
    int target = 8;
    
    //Create an instace of Solution class
    Solution sol;
    
    bool result = sol.searchMatrix(matrix, target);
    
    // Output the result
    result ? cout << "true\n" : cout << "false\n";
    
    return 0;
}
