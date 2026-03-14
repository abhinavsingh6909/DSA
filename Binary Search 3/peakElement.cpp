//Find peak element

//Given an array arr of integers. A peak element is defined as an element greater than both of its neighbors.
//Formally, if arr[i] is the peak element, arr[i - 1] < arr[i] and arr[i + 1] < arr[i].

//Find the index(0-based) of a peak element in the array. If there are multiple peak numbers, 
//return the index of any peak number.

#include <iostream>
using namespace std;

class Solution {
public:
    // Function to find the peak element in the array
    int findPeakElement(vector<int> &arr) {
        // Size of array
        int n = arr.size();
        
        // Edge cases:
        if (n == 1) return 0;
        if (arr[0] > arr[1]) return 0;
        if (arr[n - 1] > arr[n - 2]) return n - 1;

        int low = 1, high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;

            //If arr[mid] is the peak
            if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
                return mid;

            // If we are in the left
            if (arr[mid] > arr[mid - 1]) low = mid + 1;

            /* If we are in the right
            Or, arr[mid] is a common point*/
            else high = mid - 1;
        }
        /* Return -1 if no peak element
        found (dummy return) */
        return -1; 
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    
    // Create an instance of the Solution class
    Solution sol;
    
    int ans = sol.findPeakElement(arr);
    
    // Output the result
    cout << "The peak is at index: " << ans << "\n";
    
    return 0;
}


