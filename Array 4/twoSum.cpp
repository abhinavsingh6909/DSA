//Two Sum : Check if a pair with given sum exists in Array

//Problem Statement: Given an array of integers arr[] and an integer target.
//Return YES if there exist two numbers such that their sum is equal 
//to the target. Otherwise, return NO.

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {2,6,5,8,11};
    int target = 14;
    sort(arr.begin() , arr.end());
    bool b = false;

    int start = 0;
    int end = arr.size()-1;

    while(start<end){
        if(arr[start] + arr[end] == target){
            b = true;
            cout<<"YES";
            break; 
        }
        else if(arr[start] + arr[end] > target){
            end--;
        }
        else{
            start++;
        }
    }

    if(b == false){
        cout<<"No";
    }

    return 0;
}