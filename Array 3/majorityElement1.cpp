//Find the Majority Element that occurs more than N/2 times

//Problem Statement: Given an integer array nums of size n, return the majority element of the array.

//The majority element of an array is an element that appears more than n/2 times in the array. 
//The array is guaranteed to have a majority element.

#include<iostream>
using namespace std;
int main(){

    vector<int> nums = {2,2,1,1,1,2,2};

    int n = nums.size();

        int element = 0;
        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(count == 0){
                element = nums[i];
                count++;
            }
            else if(element == nums[i]){
                count ++;
            }
            else{
                count--;
            }
        }

        cout<<element;
    return 0;
}
