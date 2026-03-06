//Merge Overlapping Sub-intervals

//Problem Statement: Given an array of intervals where intervals[i] = [starti, endi],
//merge all overlapping intervals and return an array of the non-overlapping intervals 
//that cover all the intervals in the input.

#include<iostream>
using namespace std;
int main(){

    vector<vector<int>> arr = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> ans;

    sort(arr.begin() , arr.end());

    for(int i=0 ; i<arr.size() ; i++){

        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }

        else{
            ans.back()[1] = max(ans.back()[1] , arr[i][1]);
        }
    }

    for (auto v : ans) {
        cout << "[" << v[0] << "," << v[1] << "] ";
    }

    return 0;
}