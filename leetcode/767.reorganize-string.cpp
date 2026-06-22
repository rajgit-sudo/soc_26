#include <bits/stdc++.h>
#include <pthread.h>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> freq(26, 0);
        for(char x: s)
            freq[x-'a']++;

        priority_queue<pair<int, char>> pq;
        deque<vector<int>> dq;

        for(int i=0;i<26;i++){
            if(freq[i]!=0)
                pq.push({freq[i], i+'a'});
        }

        int time=0;
        string ans="";
        while(!pq.empty() || !dq.empty()){
            time++;

            while(!dq.empty() && dq.front()[1] <= time){
                pq.push({dq.front()[0], dq.front()[2]});
                dq.pop_front();
            }

            if(!pq.empty()){
                if(pq.top().first>1){
                    ans.push_back(pq.top().second);
                    dq.push_back({pq.top().first-1, time+2, pq.top().second});
                }
                pq.pop();
            }
        }
        if(time!=n)
            return "";
        return ans;
    }
};
