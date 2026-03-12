//Aggressive Cows

//Given an array nums of size n, which denotes the positions of stalls, and an integer k, 
//which denotes the number of aggressive cows, assign stalls to k cows such that the 
//minimum distance between any two cows is the maximum possible. 
//Find the maximum possible minimum distance.

#include <iostream>
using namespace std;

class Solution {
private:
    /* Function to check if we can place 'cows' cows
    with at least 'dist' distance apart in 'stalls' */
    bool canWePlace(vector<int> &nums, int dist, int cows) {
        
        // Size of array
        int n = nums.size(); 
        
        // Number of cows placed
        int cntCows = 1; 
        
        // Position of last placed cow
        int last = nums[0]; 
        
        for (int i = 1; i < n; i++) {
            if (nums[i] - last >= dist) {
                
                // Place next cow
                cntCows++; 
                
                // Update the last location
                last = nums[i]; 
            }
            if (cntCows >= cows) return true;
        }
        return false;
    }

public:
    /* Function to find the maximum possible minimum
    distance 'k' cows can have between them in 'stalls' */
    int aggressiveCows(vector<int> &nums, int k) {
        
        // Size of array
        int n = nums.size(); 
        // Sort the nums
        sort(nums.begin(), nums.end());

        int limit = nums[n - 1] - nums[0];
        for (int i = 1; i <= limit; i++) {
            if (canWePlace(nums, i, k) == false) {
                return (i - 1);
        }
    }
    //Retrun the answer
    return limit;
    }
};

int main() {
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int k = 4;

    // Create an instance of the Solution class
    Solution sol;

    int ans = sol.aggressiveCows(nums, k);

    // Output the result
    cout << "The maximum possible minimum distance is: " << ans << "\n";

    return 0;
}
