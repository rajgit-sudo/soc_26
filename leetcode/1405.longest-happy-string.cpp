#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll=long long;
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int, char>> pq;
        if(a)
            pq.push({a, 'a'});
        if(b)
            pq.push({b, 'b'});
        if(c)
            pq.push({c, 'c'});

        while(!pq.empty()){
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            if(int(ans.size())>=2 && ans[ans.size()-1]==ch1 && ans[ans.size()-2]==ch1){ //most frequently was jus used
                if(pq.empty())
                    break;

                auto [cnt2, ch2] = pq.top(); pq.pop();
                cnt2--;
                ans.push_back(ch2);

                if(cnt2)
                    pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            }else{
                ans.push_back(ch1);
                cnt1--;
                if(cnt1)
                    pq.push({cnt1, ch1});
            }
        }
        return ans;
    }
};
