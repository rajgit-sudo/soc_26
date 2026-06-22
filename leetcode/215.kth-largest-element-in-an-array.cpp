#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
};
// @lc code=end

// 10 9 5 3 7
// 6  6 3 3 2