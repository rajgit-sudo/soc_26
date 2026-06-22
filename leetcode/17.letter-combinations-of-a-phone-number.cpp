#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    string digits;
    unordered_map<char, string> keypad = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void generate(string& ds, vector<string>& ans, int index){
        if(index==n){
            ans.push_back(ds);
            return;
        }

        string curr = keypad[digits[index]];
        for(char x: curr){
            ds.push_back(x);
            generate(ds, ans, index+1);
            ds.pop_back();
        }
    }

    vector<string> letterCombinations(string input) {
        digits = input;
        n = digits.size();
        vector<string> ans;
        string ds="";
        generate(ds, ans, 0);
        return ans;
    }
};
