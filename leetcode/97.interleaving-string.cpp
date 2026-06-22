#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<vector<int>> cache;

    bool interleave(string& s1, string& s2, span<char> s3, int i, int j){
        if(i==-1 && j==-1)
            return true;

        if(cache[i+1][j+1]!=-1)
            return cache[i+1][j+1];

        if(i>=0 && s1[i]==s3.back()){
            if(interleave(s1, s2, s3.first(int(s3.size())-1), i-1, j)){
                cache[i+1][j+1] = true;
                return true;
            }
        }

        if(j>=0 && s2[j]==s3.back()){
            if(interleave(s1, s2, s3.first(int(s3.size())-1), i, j-1)){
                cache[i+1][j+1] = true;
                return true;
            }
        }
        cache[i+1][j+1] = false;
        return false;
    }

    bool isInterleave(string s1, string s2, string inputS3) {
        int n = s1.size(), m = s2.size(), t = inputS3.size();
        if(n+m != t)
            return false;
        span<char> s3(inputS3);
        cache.assign(n+1, vector<int>(m+1, -1)); // 0 means false, 1 means true
        return interleave(s1, s2, s3, n-1, m-1);
    }
};
