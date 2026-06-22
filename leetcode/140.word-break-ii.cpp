#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    unordered_set<string> set;
    vector<vector<string>> cache;
    vector<bool> visited;

    vector<string> solve(string& s, int idx){
        if(idx==n)
            return {""};
        if(visited[idx])
            return cache[idx];

        vector<string> result;
        string currWord = "";

        for(int i=idx; i<n; i++){
            currWord.push_back(s[i]);
            if(set.contains(currWord)){
                vector<string> subResult = solve(s, i+1);
                for(const string& sub: subResult){
                    if(sub.empty())
                        result.push_back(currWord);
                    else
                        result.push_back(currWord+" "+sub);
                }
            }
        }

        visited[idx] = true;
        cache[idx] = result;
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        cache.resize(n);
        visited.assign(n, false);
        for(string& s: wordDict)
            set.insert(s);

        return solve(s, 0);
    }
};
