#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    void backtrack(string& ds, vector<string>& ans, int openLeft, int closeLeft){
        if(int(ds.size()) == 2*n){
            ans.push_back(ds);
            return;
        }

        if(openLeft>0){
            ds.push_back('(');
            backtrack(ds, ans, openLeft-1, closeLeft);
            ds.pop_back();
        }
        if(closeLeft>openLeft){
            ds.push_back(')');
            backtrack(ds, ans, openLeft, closeLeft-1);
            ds.pop_back();
        }
    }

    vector<string> generateParenthesis(int k) {
        n = k;
        vector<string> ans;
        string ds="";
        backtrack(ds, ans, n, n);
        return ans;
    }
};
