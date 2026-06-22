#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll=long long;
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        int ans=0;
        unordered_map<int, int> map;
        map[0]=-1;
        for(int i=0;i<n;i++){
            sum+=(nums[i]==1?1:-1);
            if(map.contains(sum))
                ans = max(ans, i - map[sum]);
            else
             map[sum]=i;
        }
        return ans;
    }
};

/*
 * 525. Contiguous Array
 * Difficulty: Medium
 * https://leetcode.com/problems/contiguous-array/
 *
 * ──────────────────────────────────────────────────
 *
 * Given a binary array nums, return the maximum length of a contiguous
 * subarray with an equal number of 0 and 1.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [0,1]
 * Output: 2
 * Explanation: [0, 1] is the longest contiguous subarray with an equal
 * number of 0 and 1.
 *
 * Example 2:
 *
 * Input: nums = [0,1,0]
 * Output: 2
 * Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with
 * equal number of 0 and 1.
 *
 * Example 3:
 *
 * Input: nums = [0,1,1,1,1,1,0,0,0]
 * Output: 6
 * Explanation: [1,1,1,0,0,0] is the longest contiguous subarray with
 * equal number of 0 and 1.
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= nums.length <= 10^5
 *
 * 	• nums[i] is either 0 or 1.
*/
