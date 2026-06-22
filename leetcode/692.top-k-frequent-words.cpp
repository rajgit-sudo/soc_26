#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=692 lang=cpp
 *
 * [692] Top K Frequent Words
 */

// @lc code=start
class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, string>& a, const pair<int, string>& b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        vector<string> ans;
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        for(const string& s: words)
            freq[s]++;
        
        for(const auto& [key, value]: freq){
            pair<int, string> curr = make_pair(value, key);
            pq.push(curr);
            if(pq.size()>k)
                pq.pop();
        }

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end(), [&](const string& a, const string& b){
            if(freq[a]==freq[b])
                return a<b;
            return freq[a]>freq[b];
        });
        return ans;
    }
};
// @lc code=end

