#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int i=0, k=n-1, j=0;
        while(j<=k){
            if(nums[j]==0){
                swap(nums[i], nums[j]);
                i++; j++;
            }else if(nums[j]==2){
                swap(nums[j], nums[k]);
                k--;
            }else{
                j++;
            }
        }

    }
};
// @lc code=end