#include <bits/stdc++.h>
#include <numeric>
using namespace std;
// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low=0, high = n-1, mid;
        int ans = nums[0];
        while(low<=high){
            mid = midpoint(low, high);
            if(nums[low] <= nums[mid]){ //left sorted
                ans = min(ans, nums[low]);
                low = mid + 1;
            }else{ //right sorted
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};

/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=end
