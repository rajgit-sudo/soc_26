#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int houseRobber(span<int> nums){
        int n = nums.size();
        vector<int> dp(n+1);
        dp[0]=0;
        for(int i=1; i<=n; i++){
            if(i==1){
                dp[i] = nums[i-1];
                continue;
            }
            dp[i] = max(dp[i-1], dp[i-2] + nums[i-1]);
        }
        return dp[n];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        span<int> s(nums);
        return(max(houseRobber(s.subspan(0, n-1)), houseRobber(s.subspan(1, n-1))));
    }
};
