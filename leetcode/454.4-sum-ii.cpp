#include <bits/stdc++.h>
using namespace std;
using ll=long long;

/*
 * @lc app=leetcode id=454 lang=cpp
 *
 * [454] 4Sum II
 */

// @lc code=start
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
        unordered_map<int, int> map1, map2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map1[nums1[i]+nums2[j]]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                map2[nums3[i]+nums4[j]]++;
            }
        }

        int ans=0;
        for(const auto& [key1, value1]: map1){
            for(const auto& [key2, value2]: map2){
                if(key1 + key2 == 0){
                    ans += (value1 * value2);
                }
            }
        }
        return ans;
    }
};
// @lc code=end

