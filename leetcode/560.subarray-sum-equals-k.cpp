#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        unordered_map<int, int> map;
        map[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(map.contains(sum-k))
                ans+=map[sum-k];
            map[sum]++;
        }
        return ans;
    }
};
// @lc code=end

