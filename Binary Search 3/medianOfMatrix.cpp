//Matrix Median

// /Given a 2D array matrix that is row-wise sorted. The task is to find 
//the median of the given matrix.

#include <iostream>
using namespace std;

class Solution {
private:
    // Function to find the upper bound of an element in a sorted row
    int upperBound(vector<int>& arr, int x, int m) {
        int low = 0, high = m - 1;
        int ans = m; // Default answer is beyond the array size

        // Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;

            // If arr[mid] > x, it can be a possible upper bound
            if (arr[mid] > x) {
                ans = mid;
                // Look for smaller upper bound on the left
                high = mid - 1;
            } else {
                low = mid + 1; 
            }
        }
        return ans; // Return the upper bound
    }

    // Function to count how many elements in the matrix are less than or equal to x
    int countSmallEqual(vector<vector<int>>& matrix, int n, int m, int x) {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += upperBound(matrix[i], x, m); // Count the elements in each row
        }
        return cnt; // Return total count
    }

public:
    // Function to find the median element in a sorted matrix
    int findMedian(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Number of rows
        int m = matrix[0].size(); // Number of columns
        
        int low = INT_MAX, high = INT_MIN;

        // Initialize low and high to the first and last elements of the matrix
        for (int i = 0; i < n; i++) {
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][m - 1]);
        }

        // We need the element at the (n*m)/2th position
        int req = (n * m) / 2;

        // Perform binary search to find the median
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count how many elements are less than or equal to mid
            int smallEqual = countSmallEqual(matrix, n, m, mid);

            // Adjust search bounds based on the count
            if (smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }

        return low; // The answer is the low value after the binary search
    }
};

int main() {
    // Example matrix
    vector<vector<int>> matrix = {{1, 2, 3, 4, 5},
                                  {8, 9, 11, 12, 13},
                                  {21, 23, 25, 27, 29}};
    
    // Create an instance of Solution class
    Solution sol;

    // Call the function to find the median
    int ans = sol.findMedian(matrix);

    // Print the result
    cout << "The median element is: " << ans << endl;

    return 0;
}
