#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans; ans.reserve(n);
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        });

        // for(const vector<int>& curr: intervals){
        //     cout<<curr[0]<<" "<<curr[1]<<"\n";
        // }
        // return ans;

        for(const vector<int>& curr: intervals){
            if(ans.empty()){
                ans.emplace_back(curr);
                continue;
            }

            vector<int>& prev = ans.back();
            if(prev[1] >= curr[0]){ // will merge
                prev[1] = max(prev[1], curr[1]);
            }else{
                ans.emplace_back(curr);
            }
        }
        return ans;
    }
};
// @lc code=end

