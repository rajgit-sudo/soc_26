#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int i=0, j=n-1, mid;
        while(i<=j){
            mid = midpoint(i, j);
            if(nums[mid]==target)
                return true;
            else if(is_sorted(nums.begin()+i, nums.begin()+mid+1)){ //left sorted
                if(nums[i] <= target && nums[mid] >= target) //found in left half
                    j=mid-1;
                else
                    i=mid+1;
            }else{ // right sorted
                if(nums[mid] <= target && nums[j] >= target) //found in right half
                    i=mid+1;
                else
                    j=mid-1;
            }
        }
        return false;
    }
};
// @lc code=end

