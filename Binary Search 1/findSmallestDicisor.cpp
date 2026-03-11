//Find the smallest divisor

//Given an array of integers nums and an integer limit as the threshold value
//find the smallest positive integer divisor such that upon dividing all the elements of the array 
//by this divisor, the sum of the division results is less than or equal to the threshold value.

//After dividing each element by the chosen divisor, take the ceiling of the result 
//(i.e., round up to the next whole number)

#include<iostream>
using namespace std;

class Solution {
private:
    /* Helper function to find the
    summation of division values*/
    int sumByD(vector<int>& nums, int limit) {
        // Size of array
        int n = nums.size(); 
        
        // Find the summation of division values
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ceil((double)(nums[i]) / (double)(limit));
        }
        return sum;
    }

public:
    // Function to find the smallest divisor
    int smallestDivisor(vector<int>& nums, int limit) {
        int n = nums.size();
        if (n > limit) return -1;
        
        // Initialize binary search bounds
        int low = 1, high = *max_element(nums.begin(), nums.end());

        // Apply binary search
        while (low <= high) {
            int mid = (low + high) / 2;
            if (sumByD(nums, mid) <= limit) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int limit = 8;

    // Create an object of the Solution class
    Solution sol;

    int ans = sol.smallestDivisor(nums, limit);

    // Print the result
    cout << "The minimum divisor is: " << ans << "\n";

    return 0;
}
