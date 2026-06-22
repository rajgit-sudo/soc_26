#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    void combinations(vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans, int target, int index=0){
        if(target<0 || index>=n)
            return;
        if(target==0){
            ans.push_back(ds);
            return;
        }

        ds.push_back(candidates[index]);
        combinations(candidates, ds, ans, target - candidates[index], index);
        ds.pop_back();
        combinations(candidates, ds, ans, target, index+1);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        vector<vector<int>> ans;
        vector<int> ds;
        combinations(candidates, ds, ans, target);
        return ans;
    }
};
