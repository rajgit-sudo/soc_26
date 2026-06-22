#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(2, -1);
        if(n==0)
            return ans;
        int largestIndex = (upper_bound(nums.begin(), nums.end(), target) - nums.begin());
        largestIndex--;
        if(largestIndex<0 || nums[largestIndex]!=target)
            return ans;

        int smallestIndex = largestIndex;
        int low = 0, high = n-1, mid;
        while(low<=high){
            mid=midpoint(low, high);
            if(nums[mid] == target){
                smallestIndex = min(smallestIndex, mid);
                high = mid-1;
            }else if(nums[mid] < target)
                low = mid +1;
            else
                high = mid-1;
        }
        ans[0] = smallestIndex;
        ans[1] = largestIndex;
        return ans;
    }
};

/*
 * 34. Find First and Last Position of Element in Sorted Array
 * Difficulty: Medium
 * https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 *
 * ──────────────────────────────────────────────────
 *
 * Given an array of integers nums sorted in non-decreasing order, find
 * the starting and ending position of a given target value.
 *
 * If target is not found in the array, return [-1, -1].
 *
 * You must write an algorithm with O(log n) runtime complexity.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [5,7,7,8,8,10], target = 8
 * Output: [3,4]
 *
 * Example 2:
 *
 * Input: nums = [5,7,7,8,8,10], target = 6
 * Output: [-1,-1]
 *
 * Example 3:
 *
 * Input: nums = [], target = 0
 * Output: [-1,-1]
 *
 *
 *
 * Constraints:
 *
 * 	• 0 <= nums.length <= 10^5
 *
 * 	• -10^9 <= nums[i] <= 10^9
 *
 * 	• nums is a non-decreasing array.
 *
 * 	• -10^9 <= target <= 10^9
*/
