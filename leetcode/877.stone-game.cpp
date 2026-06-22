#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<vector<int>> cache;

    int recurse(vector<int>& nums, int i, int j){
        int n = nums.size();
        if(i>j)
            return 0;

        if(cache[i][j]!=-1)
            return cache[i][j];

        int case1=0, case2=0;
        case1+=nums[i];
        if(nums[i+1] > nums[j])
            case1+=recurse(nums, i+1, j);
        else
            case1+=recurse(nums, i+1, j-1);
        case2+=nums[j];
        if(nums[i] > nums[j-1])
            case2+= recurse(nums, i+1, j-1);
        else
            case2+=recurse(nums, i, j-2);

        cache[i][j] = max(case1, case2);
        return cache[i][j];
    }

    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        cache.assign(n, vector<int>(n, -1));
        return recurse(nums, 0, n-1)>=(sum/2);
    }
};
