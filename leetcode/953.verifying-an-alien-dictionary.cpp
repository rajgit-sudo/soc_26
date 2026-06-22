#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26, 0);
        for(int i=0;i<26;i++){
            rank[order[i]-'a'] = i;
        }

        vector<string> temp = words;
        sort(temp.begin(), temp.end(), [&](const string& a, const string& b){
            int n = min(a.size(), b.size());
            for (int i=0;i<n;i++){
                if (a[i] != b[i]) {
                    return rank[a[i]-'a']<rank[b[i]-'a'];
                }
            }
            return a.size() < b.size();
        });
        return words==temp;
    }
};
