//Problem Statement: Given an integer array nums, find the subarray with 
//the largest sum and return the sum of the elements present in that subarray.

//A subarray is a contiguous non-empty sequence of elements within an array.

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {-2,-3,4,-1,-2,1,5,-3};

    long long sum = 0;

    long long maxSum = INT_MIN;

    int start, ansStart, ansEnd;


    for(int i=0 ; i<arr.size(); i++){
        if(sum == 0){
            start = i;
        }
        sum = sum + arr[i];

        if(sum > maxSum){
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if(sum < 0){
            sum = 0;
        }
    }


    cout<<"SubArray with the largest sum is: "<<endl;
    for(int i=ansStart; i<=ansEnd ; i++){
        cout<<arr[i]<<" ";
    }   

    cout<<endl<<"Whoose sum is: "<<maxSum<<endl;

    return 0;
}