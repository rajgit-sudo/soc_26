#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    unordered_set<string> set;

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(const string& s: wordDict)
            set.insert(s);

        vector<bool> dp(n+1, false);
        dp[n] = true;
        for(int i=n-1; i>=0; i--){
            string curr="";
            for(int j=i; j<n; j++){
                curr.push_back(s[j]);

                if(set.contains(curr) && dp[j+1]){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
