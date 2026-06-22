#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {

public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<ll> dp(target+1);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int num: nums){
                if(i>=num)
                    dp[i] += dp;
            }
        }
        return dp[target];
    }
};
