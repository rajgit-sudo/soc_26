#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    string s;
    int n;

    bool isPalindrome(string& s){
        int i =0, j = int(s.size()) -1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            i++; j--;
        }
        return true;
    }

    void backtrack(vector<string>& ds, vector<vector<string>>& ans, string curr="", int index=0){
        if(index==n){
            if(!curr.empty() && isPalindrome(curr)){
                ds.push_back(curr);
                ans.push_back(ds);
                ds.pop_back();
            }
            return;
        }

        curr.push_back(s[index]);
        if(isPalindrome(curr)){
            ds.push_back(curr);
            string temp="";
            backtrack(ds, ans, temp, index+1);
            ds.pop_back();
        }
        backtrack(ds, ans, curr, index+1);
    }

    int minCut(string input) {
        s = input;
        n = s.size();
        vector<vector<string>> ans;
        vector<string> ds;
        backtrack(ds, ans);

        int soln = 2000;
        for(auto i: ans)
            soln = min(soln, int(i.size()));
        return soln-1;
    }
};
