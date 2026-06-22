#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> nums;
    vector<int> prefixSum;
    int n;

    int recurse(int m, int idx, int player){
        if(idx==n)
            return 0;

        int ans = 0;
        for(int i=idx; i<=min(n-1, idx+2*m-1); i++){
            if(player==1)
                ans = max(ans, recurse(max(m, i-idx+1), i+1, player*-1) + prefixSum[i+1] - prefixSum[idx]);
            else
                ans = min(ans, recurse(max(m, i-idx+1), i+1, player*-1) + prefixSum[i+1] - prefixSum[idx]);
        }d

        if(player==-1)
            return 0;
        return ans;
    }

    int stoneGameII(vector<int>& input) {
        nums = input;
        n = nums.size();
        prefixSum.assign(n+1, 0);
        for(int i=1; i<=n; i++)
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        int m = 1;
        return recurse(m, 0, 1);
    }
};
