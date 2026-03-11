//Lower Bound

//Given a sorted array of nums and an integer x, write a program to find the lower bound of x

//The lower bound algorithm finds the first and smallest index in a sorted array where the value 
//at that index is greater than or equal to a given key i.e. x

//If no such index is found, return the size of the array

#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find the lower bound
    int lowerBound(vector<int>& nums, int x)
    {
        int low = 0, high = nums.size() - 1;
        int ans = nums.size(); 

        while (low <= high) {
            int mid = (low + high) / 2; 

            /* Check if mid element 
               is a potential answer */
            if (nums[mid] >= x) {
                ans = mid; 

                // Search left half
                high = mid - 1; 
            } 
            else {
                // Search right half
                low = mid + 1; 
            }
        }
        return ans; 
    }
};

int main()
{
    vector<int> nums = {1, 2, 2, 3};
    int x = 2;

    // Create an instance of the Solution class
    Solution sol;

    // Function call to find the lower bound
    int ind = sol.lowerBound(nums, x);

    cout << "The lower bound is the index: " << ind << "\n";
    return 0;
}