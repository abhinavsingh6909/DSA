//Find the duplicate in an array of N+1 integers

//Problem Statement: Given an array of N + 1 size, where each element is between 1 and N.
//Assuming there is only one duplicate number, your task is to find the duplicate number.

#include<iostream>
using namespace std;
int main(){

    vector<int> nums = {1,3,4,2,5,6,6};

    int slow = 0;
    int fast = 0;

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    slow = 0;

    while(slow != fast ){
        slow = nums[slow];
        fast = nums[fast];
    }

    cout << slow;


    return 0;
}