#include <atomic>
#include <bits/stdc++.h>
#include <queue>
#include <utility>
using namespace std;
using ll=long long;
class Solution {
public:
    int findMaximizedCapital(int k, int currCapital, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> nums(n);
        for(int i=0;i<n;i++)
            nums[i] = make_pair(capital[i], profits[i]);

        sort(nums.begin(), nums.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            if(a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        priority_queue<int> pq;
        int i=0;
        while(k && i<n){
            while(i<n && nums[i].first <= currCapital){
                pq.push(nums[i].second);
                i++;
            }

            currCapital += pq.top();
            pq.pop();
            k--;
        }
        return currCapital;
    }
};
