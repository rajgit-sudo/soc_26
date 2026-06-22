#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1, mid;
        while(i<=j){
            mid = midpoint(i, j);
            if(nums[mid]==target){
                return mid;
            }else if(nums[i] <= nums[mid]){ //left half sorted
                if(nums[i] <= target && nums[mid] >= target) // in left half
                    j = mid-1;
                else
                    i = mid+1;
            }else{ // right half sorted
                if(nums[mid] <= target && nums[j] >= target) // in right half
                    i = mid+1;
                else    
                    j = mid-1;
            }
        }
        return -1;
    }
};
// @lc code=end

