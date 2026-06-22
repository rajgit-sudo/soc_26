#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans=0;
        int currMin = prices.front();
        for(int i=0;i<n;i++){
            currMin = min(currMin, prices[i]);
            ans = max(ans, prices[i] - currMin);
        }
        return ans;
    }
};
// @lc code=end

