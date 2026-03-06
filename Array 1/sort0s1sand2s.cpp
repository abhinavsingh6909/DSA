//Sort an array of 0s, 1s and 2s
//DUTCH NATIONAL FLAG ALGORITHM

//Problem Statement: Given an array nums consisting of only 0, 1, or 2. 
//Sort the array in non-decreasing order. The sorting must be done in-place, 
//without making a copy of the original array.

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {1, 0, 2, 1, 0,1,0,0,0,2,1,2};

    int n = arr.size();

    int low = 0 , mid = 0 , high = n-1;

    while(mid <= high){

        if(arr[mid] == 0){
            swap(arr[mid] , arr[low]);
            mid++;
            low++;
        }

        else if(arr[mid] == 1){
            mid++;
        }

        else{
            swap(arr[mid] , arr[high]);
            high--;
        }
    }

    for(int i=0 ; i<n ; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}