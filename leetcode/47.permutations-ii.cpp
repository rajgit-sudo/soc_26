#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    void backtrack(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& visited){
        if(int(ds.size())==n){
            ans.push_back(ds);
            return;
        }

        for(int i=0; i<n; i++){
            if(visited[i]) continue;
            if(i>0 && nums[i] == nums[i-1] && !visited[i-1]) continue;

            visited[i] = true;
            ds.push_back(nums[i]);
            backtrack(nums, ds, ans, visited);
            visited[i] = false;
            ds.pop_back();
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(n, false);
        backtrack(nums, ds, ans, visited);
        return ans;
    }
};
