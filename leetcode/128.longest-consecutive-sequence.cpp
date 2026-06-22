#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int len=0, ans=0;
        unordered_set<int> set(nums.begin(), nums.end());
        for(int i: set){
            if(!set.contains(i-1)){ //starting point
                len=0;
                int temp =i;
                while(set.contains(temp)){
                    len++;
                    temp++;
                }
            }
            ans=max(ans, len);
        }
        return ans;
    }
};
// @lc code=end

