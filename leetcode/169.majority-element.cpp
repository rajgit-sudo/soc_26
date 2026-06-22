#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 2e9;
        for(const int& i: nums){
            if(count==0){
                candidate=i;
                count=1;
            }else if(candidate==i){
                count++;
            }else{
                count--;
            }
        }
        return candidate;
    }
};
// @lc code=end

