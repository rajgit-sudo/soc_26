#include <bits/stdc++.h>
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
            if(visited[i]==false){
                visited[i] = true;
                ds.push_back(nums[i]);
                backtrack(nums, ds, ans, visited);
                ds.pop_back();
                visited[i] = false;
            }
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<vector<int>> ans;
        vector<int> ds;
        vector<bool> visited(n, false);
        backtrack(nums, ds, ans, visited);
        return ans;
    }
};
