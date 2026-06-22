#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
using ll=long long;
class Solution {
public:
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        int left=0, ans=0;
        unordered_map<int, int> freq;
        for(int right = 0; right<n ; right++){
            freq[nums[right]]++;

            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]] == 0) freq.erase(nums[left]);
                left++;
            }

            ans += (right - left+1);
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k-1);
    }
};

/*
 * 992. Subarrays with K Different Integers
 * Difficulty: Hard
 * https://leetcode.com/problems/subarrays-with-k-different-integers/
 *
 * ──────────────────────────────────────────────────
 *
 * Given an integer array nums and an integer k, return the number of
 * good subarrays of nums.
 *
 * A good array is an array where the number of different integers in
 * that array is exactly k.
 *
 * 	• For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
 *
 * A subarray is a contiguous part of an array.
 *
 *
 *
 * Example 1:
 *
 * Input: nums = [1,2,1,2,3], k = 2
 * Output: 7
 * Explanation: Subarrays formed with exactly 2 different integers:
 * [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
 *
 * Example 2:
 *
 * Input: nums = [1,2,1,3,4], k = 3
 * Output: 3
 * Explanation: Subarrays formed with exactly 3 different integers:
 * [1,2,1,3], [2,1,3], [1,3,4].
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= nums.length <= 2 * 10^4
 *
 * 	• 1 <= nums[i], k <= nums.length
*/
