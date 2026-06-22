#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=229 lang=cpp
 *
 * [229] Majority Element II
 */

// @lc code=start
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int count1=0, count2=0;
        int candidate1 = 2e9, candidate2 = 2e9;
        for(const int& i: nums){
            if(candidate1==i)
                count1++;
            else if(candidate2==i)
                count2++;
            else if(count1==0){
                candidate1=i;
                count1=1;
            }else if(count2==0){
                candidate2=i;
                count2=1;
            }else{
                count1--; count2--;
            }
        }

        count1=0; count2=0;
        for(const int& i: nums){
            if(candidate1==i)
                count1++;
            if(candidate2==i)
                count2++;
        }

        int minScore = n/3;
        vector<int> ans;
        if(count1>minScore)
            ans.push_back(candidate1);
        if(count2>minScore && candidate1!=candidate2)
            ans.push_back(candidate2);
        
        return ans;
    }
};
// @lc code=end

