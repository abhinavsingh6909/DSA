/* 4 Sum | Find Quads that add up to a target value

 Problem Statement: Given an array of N integers, your task is to find unique quads that add up 
 to give a target value. In short, you need to return an array of all the unique quadruplets 
[arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

Note: a, b, c and d are also distinct and lies between 0 to n-1 (both inclusive). */

// #include <iostream>
// using namespace std;

// class Solution {
// public:
//     //function to find quadruplets having sum equals to target
//     vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         // Vector to store the quadruplets that sum up to target
//         vector<vector<int>> ans;
        
//         int n = nums.size();
        
//         // Sort the input array nums
//         sort(nums.begin(), nums.end());
        
//         // Iterate through the array to find quadruplets
//         for (int i = 0; i < n; i++) {
//             // Skip duplicates for i
//             if (i > 0 && nums[i] == nums[i - 1])
//                 continue;
            
//             for (int j = i + 1; j < n; j++) {
//                 // Skip duplicates for j
//                 if (j > i + 1 && nums[j] == nums[j - 1])
//                     continue;
                
//                 // Two pointers approach
//                 int k = j + 1;
//                 int l = n - 1;
                
//                 while (k < l) {
//                     long long sum = nums[i] + nums[j] + nums[k] + nums[l];
                    
//                     if (sum == target) {
//                         // Found a quadruplet that sums up to target
//                         vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
//                         ans.push_back(temp);
                        
//                         // Skip duplicates for k and l
//                         k++;
//                         l--;
//                         while (k < l && nums[k] == nums[k - 1]) k++;
//                         while (k < l && nums[l] == nums[l + 1]) l--;
//                     } else if (sum < target) {
//                         k++;
//                     } else {
//                         l--;
//                     }
//                 }
//             }
//         }
        
//         return ans;
//     }
// };

// int main() {
//     vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
//     int target = 9;
    
//     // Create an instance of Solution class
//     Solution sol;
    
//     vector<vector<int>> ans = sol.fourSum(nums, target);
    
//     // Print the result
//     cout << "The quadruplets are: \n";
//     for (auto& it : ans) {
//         cout << "[";
//         for (auto& ele : it) {
//             cout << ele << " ";
//         }
//         cout << "] ";
//     }
//     cout << "\n";
    
//     return 0;
// }


#include<iostream>
using namespace std;
int main(){

    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    int n = nums.size();
    sort(nums.begin() , nums.end());

     vector<vector<int>> ans;

    for(int i=0 ; i<n ; i++){

        if(i>0 && nums[i] == nums[i-1]){
            continue;
        }

        for(int j=i+1 ; j<n ; j++){
            if(j > i+1 && nums[j] == nums[j-1]){
                continue;
            }

            int k = j+1;
            int l = n-1;

            while(k<l){
                int sum = nums[i] + nums[j];
                sum+= nums[k];
                sum+= nums[l];

                if(sum == target){
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);

                    k++;
                    l--;

                    while(k<l && nums[k] == nums[k-1]){
                        k++;
                    }

                    while(k<l && nums[l] == nums[l-1]){
                        l--;
                    }

                }
                else if(sum > target){
                    l--;
                }
                else{
                    k++;
                }
            }

        }

    }


     cout << "The quadruplets are: \n";
    for (auto& it : ans) {
        cout << "[ ";
        for (auto& ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";


    return 0;
}