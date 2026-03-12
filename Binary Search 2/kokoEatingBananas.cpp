//Koko eating bananas

//A monkey is given n piles of bananas, where the 'ith' pile has nums[i] bananas. 
//An integer h represents the total time in hours to eat all the bananas.



//Each hour, the monkey chooses a non-empty pile of bananas and eats k bananas. 
//If the pile contains fewer than k bananas, the monkey eats all the bananas in that pile 
//and does not consume any more bananas in that hour.



//Determine the minimum number of bananas the monkey must eat per hour to finish 
//all the bananas within h hours.

#include <iostream>
using namespace std;

class Solution {
private:
    /* Helper function to find the
    maximum element in the vector */
    int findMax(vector<int>& nums) {
        int maxi = INT_MIN;
        int n = nums.size();
        
        // Find the maximum element
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    /* Helper function to calculate total 
    hours required at given hourly rate */
    long long calculateTotalHours(vector<int>& nums, int hourly) {
        long long totalH = 0;
        int n = nums.size();
        
        // Calculate total hours required
        for (int i = 0; i < n; i++) {
            totalH += ceil((double) nums[i] / (double) hourly);
        }
        return totalH;
    }

public:
    
    int minimumRateToEatBananas(vector<int>& nums, int h) {
       
        int low = 1, high = findMax(nums);

        
        while (low <= high) {
            int mid = (low + high) / 2;
            long long totalH = calculateTotalHours(nums, mid);
            if (totalH <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> nums = {7, 15, 6, 3};
    int h = 8;

    
    Solution sol;

    int ans = sol.minimumRateToEatBananas(nums, h);

    
    cout << "Koko should eat at least " << ans << " bananas/hr.\n";

    return 0;
}