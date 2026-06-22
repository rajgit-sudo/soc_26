#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int maxProfit(vector<int>& nums) {                // 0 - can buy but cant sell
        int n = nums.size();                          // 1 - cant buy but can sell
        vector<vector<int>> dp(n+1, vector<int>(3, 0)); // 2 - cant buy or sell
        for(int i=n-1;i>=0;i--){
            dp[i][0] = max(dp[i+1][0], -nums[i] + dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1], nums[i] + dp[i+1][2]);
            dp[i][2] = dp[i+1][0];
        }

        return dp[0][0];
    }
};
