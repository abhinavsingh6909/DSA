//Find the elements that appears more than N/3 times in the array

// /Problem Statement: Given an integer array nums of size n. 
//Return all elements which appear more than n/3 times in the array.
// The output can be returned in any order.

#include<iostream>
using namespace std;
int main(){

    vector<int> nums = {1, 2, 1, 1, 3, 2, 2};
    vector<int> ans;

    int n = nums.size();

    int count1 = 0 , count2 = 0 , element1 = 0 , element2 = 0;
    
    for(int i=0 ; i<n ; i++){
        if(count1 == 0 && element2 != nums[i]){
            element1 = nums[i];
            count1++;
        }
        else if(count2 == 0 && element1 != nums[i]){
            element2 = nums[i];
            count2++;
        }
        else if(element1 == nums[i]){
            count1++;
        }
        else if(element2 == nums[i]){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    int mini = (int)(n/3) + 1;

     count1 = 0 , count2 = 0;

    for(int i=0 ; i<n ; i++){
        if(nums[i] == element1){
            count1++;
        }
        if(nums[i] == element2){
            count2++;
        }
    }

    if(count1 >= mini){
        ans.push_back(element1);
    }

    if(count2 >= mini){
        ans.push_back(element2);
    }

    cout<<"Elements occuring more than n/3 times: ";
    for(int i=0 ; i<ans.size() ; i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}