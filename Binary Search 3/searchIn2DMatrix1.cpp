//Search in a 2D matrix

//Given a 2-D array mat where the elements of each row are sorted in non-decreasing order, 
//and the first element of a row is greater than the last element of the previous row 
//(if it exists), and an integer target, determine if the target exists in the given mat or not.

#include <iostream>
using namespace std;

class Solution {
public:
    //Function to search for a given target in matrix
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = n * m - 1;
        //Perform binary search
        while (low <= high) {
            int mid = (low + high) / 2;
                
            //Calculate the row and column
            int row = mid / m, col = mid % m;
                
            //If target is found return true
            if (mat[row][col] == target) return true;
            else if (mat[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        // Return false if target is not found
        return false; 
    }
};

int main() {
    
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int target = 8;
    
    //Create an instace of Solution class
    Solution sol;
    
    bool result = sol.searchMatrix(matrix, target);
    
    // Output the result
    result ? cout << "true\n" : cout << "false\n";
    
    return 0;
}


