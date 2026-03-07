//Merge two Sorted Arrays Without Extra Space

#include<iostream>
using namespace std;
int main(){

    vector<int> nums1 = {1, 3, 5, 7, 9};
    vector<int> nums2 = {2, 4, 6, 8, 10};

    int left = 0;

    int right = nums2.size()-1;


    while(left < nums1.size() && right >= 0){
        if(nums1[left] < nums2[right]){
            swap(nums1[left] , nums2[right]);
            left++;
            right--;
        }
        else{
            break;
        }
    }

    sort(nums1.begin() , nums1.end());

    sort(nums2.begin() , nums2.end());

    for(int i=0 ; i< nums2.size() ; i++){
        cout<<nums2[i]<<" ";
    }

    for(int i=0 ; i< nums1.size() ; i++){
        cout<<nums1[i]<<" ";
    }




    return 0;
}

