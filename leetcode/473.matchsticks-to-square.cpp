#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    bool ans = false;

    void generate(vector<int>& nums, vector<ll>& ds, ll target, int index){
        if(index==n){
            ans = true;
            return;
        }

        for(int i=0;i<4;i++){
            if(ds[i] + nums[index] > target) continue;

            ds[i] += nums[index];
            generate(nums, ds, target, index+1);
            ds[i] -= nums[index];
        }
    }

    bool makesquare(vector<int>& nums) {
        n = nums.size();
        sort(nums.rbegin(), nums.rend());
        ll size = accumulate(nums.begin(), nums.end(), 0LL);
        if(size%4!=0)
            return false;
        ll target = size/4;

        vector<ll> ds(4, 0);
        generate(nums, ds, target, 0);
        return ans;
    }
};
