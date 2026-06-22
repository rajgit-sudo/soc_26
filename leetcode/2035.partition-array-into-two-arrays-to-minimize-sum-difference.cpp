#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, sum;

    int minDiff(vector<int>& nums, int target){
        vector<bool> dp(target+1, false);
        dp[0] = true;

        for(int i: nums){
            for(int x = target; x>=i; x--)
                dp[x] = (dp[x]|dp[x-i]);
        }

        int subsetSum = -1;
        for(int i=target; i>=0; i--){
            if(dp[i]){
                subsetSum = i;
                break;
            }
        }
        return abs(sum - 2*subsetSum);
    }

    int minimumDifference(vector<int>& nums) {
        n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum%2==0)
            return minDiff(nums, sum/2);
        else{
            return min(minDiff(nums, sum/2), minDiff(nums, sum/2 + 1));
        }
    }
};
