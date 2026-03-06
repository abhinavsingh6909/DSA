//BUY AND SELL STOCK

//Problem Statement: You are given an array of prices where prices[i] is the price of a given stock
// on an ith day. You want to maximize your profit by choosing a single day to buy one stock 
//and choosing a different day in the future to sell that stock. Return the maximum profit you 
//can achieve from this transaction. If you cannot achieve any profit, return 0.

#include<iostream>
using namespace std;
int main(){

    vector<int> arr = {7,1,5,3,6,4};

    int n = arr.size();

    int mini = INT_MAX;
    int maxProfit = 0;

    for(int i=0 ; i<n; i++){
        mini = min(mini,arr[i]);
        int cost = arr[i]-mini;
        if(cost > maxProfit){
            maxProfit = cost;
        }
    }

    cout<<maxProfit;

    


    return 0;
}