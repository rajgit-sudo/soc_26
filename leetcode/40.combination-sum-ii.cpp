#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    void backtrack(vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans, int target, int index=0){
        if(target==0){
            sort(ds.begin(), ds.end());
            ans.push_back(ds);
            return;
        }

        if(target<0 || index>=n)
            return;

        for(int i=index; i<n; i++){
            if(i>index && candidates[i-1]==candidates[i]) continue;

            ds.push_back(candidates[i]);
            backtrack(candidates, ds, ans, target-candidates[i], i+1);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(candidates, ds, ans, target);
        return ans;
    }
};
