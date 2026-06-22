#include <bits/stdc++.h>
#include <ios>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    void backtrack(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, int elementsLeftToPick, int index=0){
        if(elementsLeftToPick==0){
            ans.push_back(ds);
            return;
        }
        if(elementsLeftToPick<0 || index>=n)
            return;

        ds.push_back(nums[index]);
        backtrack(nums, ds, ans, elementsLeftToPick-1, index+1);
        ds.pop_back();
        backtrack(nums, ds, ans, elementsLeftToPick, index+1);
    }

    vector<vector<int>> combine(int size, int k) {
        n = size;
        vector<int> nums(n);
        iota(nums.begin(), nums.end(), 1);
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(nums, ds, ans, k);
        return ans;
    }
};
