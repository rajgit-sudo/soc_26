#include <bits/stdc++.h>
using namespace std;
using ll=long long;

/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for(int i=0;i<n-3;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            if(nums[i] > target/4) break;

            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;

                int k = j+1, p = n-1;
                while(k<p){
                    ll sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[k] + (ll)(nums[p]);
                    if(sum==(ll)target){
                        ans.push_back({nums[i], nums[j], nums[k], nums[p]});
                        while(k<p && nums[k]==nums[k+1]) k++; k++;
                        while(k<p && nums[p]==nums[p-1]) p--; p--;
                    }else if(sum<(ll)target){
                        while(k<p && nums[k]==nums[k+1]) k++;
                        k++;
                    }else{
                        while(k<p && nums[p]==nums[p-1]) p--;
                        p--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

