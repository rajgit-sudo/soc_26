#include <bits/stdc++.h>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, k;
    bool ans = false;

    void generate(vector<int>& nums, vector<ll>& ds, ll target, int index){
        if(index==n){
            ans = true;
            return;
        }

        if(ans)
            return;

        for(int i=0;i<k;i++){
            if(ds[i] + nums[index] > target) continue;
            if(i>0 && ds[i]==ds[i-1]) continue;

            ds[i] += nums[index];
            generate(nums, ds, target, index+1);
            ds[i] -= nums[index];
        }
    }

    bool canPartitionKSubsets(vector<int>& nums, int inputK) {
        n = nums.size();
        k = inputK;
        ll sum = accumulate(nums.begin(), nums.end(), 0LL);
        if(sum%k!=0)
            return false;
        ll target = sum/k;
        vector<ll> ds(k, 0);
        generate(nums, ds, target, 0);
        return ans;
    }
};
