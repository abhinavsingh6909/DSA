//Find the repeating and missing numbers

//Problem Statement: Given an integer array nums of size n containing values from [1, n] and 
//each value appears exactly once in the array, except for A, which appears twice and B which is missing.
//Return the values A and B, as an array of size 2, where A appears in the 0-th index and B in the 1st index.

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {1, 2, 3, 6, 7, 5, 7};

    int n = arr.size();

    long long SN = (n*(n+1))/2;
    long long S2N = (n*(n+1)*((2*n)+1))/6;
    long long S = 0;
    long long S2 = 0;

    for(int i=0 ; i<n ; i++){
        S = S + arr[i];
        S2 = S2 + (arr[i]*arr[i]);

    }

    int val1 = S - SN;
    int val2 = S2 - S2N;
    val2 = val2/val1;

    long long x = (val1+val2)/2;

    long long y = x - val1;

    cout<<"Repeating Element: "<<x<<endl<<"Missing Element: "<<y<<endl;
    
    

    return 0;
}