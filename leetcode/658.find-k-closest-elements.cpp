#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=658 lang=cpp
 *
 * [658] Find K Closest Elements
 */

// @lc code=start
class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        int n=nums.size();
        int i=0, j=n-1;
        while(j-i+1 > k){
            if(abs(nums[i] - x) > abs(nums[j]-x))
                i++;
            else
                j--;
        }
        return vector<int>(nums.begin()+i, nums.begin()+j+1);
    }
};
// @lc code=end

