#include <bits/stdc++.h>
#include <deque>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int leastInterval(vector<char>& nums, int cycleLength) {
        int n = nums.size();
        vector<int> freq(26, 0);
        for(char x: nums)
            freq[x-'A']++;

        priority_queue<int> pq;
        deque<pair<int, int>> dq;

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                pq.push(freq[i]);
        }

        ll time=0;
        while(!pq.empty() || !dq.empty()){
            time++;

            while(!dq.empty() && dq.front().second <= time){
                pq.push(dq.front().first);
                dq.pop_front();
            }

            if(!pq.empty()){
                if(pq.top()>1){
                    dq.push_back({pq.top()-1, time+cycleLength+1});
                }
                pq.pop();
            }
        }
        return time;
    }
};
