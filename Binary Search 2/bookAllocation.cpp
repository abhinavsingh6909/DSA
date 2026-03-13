//Book Allocation Problem

// /Given an array nums of n integers, where nums[i] represents the number of pages in the 
//i-th book, and an integer m representing the number of students, allocate all the books to 
//the students so that each student gets at least one book, each book is allocated to only 
//one student, and the allocation is contiguous.



//Allocate the books to m students in such a way that the maximum number of pages assigned 
//to a student is minimized. If the allocation of books is not possible, return -1.


#include <iostream>
#include<numeric>
using namespace std;

class Solution {
private:
    /* Function to count the number of 
    students required given the maximum 
    pages each student can read */
    int countStudents(vector<int>& nums, int pages) {
        // Size of array
        int n = nums.size();
        
        int students = 1;
        int pagesStudent = 0;
        
        for (int i = 0; i < n; i++) {
            if (pagesStudent + nums[i] <= pages) {
                // Add pages to current student
                pagesStudent += nums[i];
            } else {
                // Add pages to next student
                students++;
                pagesStudent = nums[i];
            }
        }
        return students;
    }
public:
    /*Function to allocate the book to ‘m’ 
    students such that the maximum number 
    of pages assigned to a student is minimum */
    int findPages(vector<int>& nums, int m) {
        int n = nums.size();
        
        // Book allocation impossible
        if (m > n) return -1;

        // Calculate the range for binary search
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        // Binary search for minimum maximum pages
        while (low <= high) {
            int mid = (low + high) / 2;
            int students = countStudents(nums, mid);
            if (students > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return low;
    }
};

int main() {
    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5; 
    int m = 4;

    // Create an instance of the Solution class
    Solution sol;

    int ans = sol.findPages(arr, m);

    // Output the result
    cout << "The answer is: " << ans << "\n";

    return 0;
}
