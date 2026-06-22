#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for(char digit: num){
            while(!st.empty() && k>0 && st.top() > digit){
                st.pop();
                k--;
            }
            st.push(digit);
        }

        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }

        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        int i = int(ans.size()) - 1;
        while(i>=0 && ans[i]==' '){
            ans.pop_back();
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
