//Longest Consecutive Sequence in an Array

// /Problem Statement: Given an array nums of n integers.

//Return the length of the longest sequence of consecutive integers. 
//The integers in this sequence can appear in any order.
#include<iostream>
using namespace std;
int main(){

    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};

            if(!nums.size()){
            return 0;
        }

        sort(nums.begin() , nums.end());

        int count = 0 , maxCount = 1;
        int lastElement = INT_MIN;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]-1 == lastElement){
                count+= 1;
                lastElement = nums[i];
            }
            else if(nums[i] != lastElement){
                count = 1;
                lastElement = nums[i];
            }

            maxCount = max(maxCount,count);

        }

        cout<<maxCount;

    return 0;
}