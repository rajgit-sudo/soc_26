#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
            nums[i].push_back(i);

        sort(nums.begin(), nums.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // duration, index
        int i=0;
        ll time = nums[0][0];

        vector<int> ans; ans.reserve(n);
        while(!pq.empty() || i<n){
            while(i<n && nums[i][0] <= time){
                pq.push({nums[i][1], nums[i][2]});
                i++;
            }

            if(pq.empty())
                time = nums[i][0];
            else{
                int nextTask = pq.top().second;
                time += pq.top().first;
                pq.pop();
                ans.push_back(nextTask);
            }
        }
        return ans;
    }
};
