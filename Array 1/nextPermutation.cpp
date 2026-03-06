//Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array 
//into the lexicographically next greater permutation of numbers.

//If such an arrangement is not possible, it must rearrange to the lowest possible order 
//(i.e., sorted in ascending order).

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {2,3,1,6,4};

    int index = -1;

    int n = arr.size();

    for(int i=n-2 ; i>=0 ; i--){
        if(arr[i] < arr[i+1]){
            index = i;
            break;
        }
    }

    if(index == -1){
        reverse(arr.begin() , arr.end());
    }

    else{

        for(int i = n-1 ; i>index ; i--){
            if(arr[index] < arr[i]){
                swap(arr[i] , arr[index]);
                break;
            }
        }

        reverse(arr.begin()+index+1 , arr.end());

    }

    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }




    return 0;
}