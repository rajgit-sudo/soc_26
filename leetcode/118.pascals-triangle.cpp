#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> dp;
        for(int i=1; i<=n; i++){
            vector<int> row(i, 1);

            for(int j=1; j<i-1; j++){
                row[j] = dp[i-2][j-1] + dp[i-2][j];
            }
            dp.push_back(row);
        }
        return dp;
    }
};
// @lc code=end