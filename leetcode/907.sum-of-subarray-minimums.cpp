#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int sumSubarrayMins(vector<int>& nums) {
        int n = nums.size();
        const ll INF = 1e9 + 7;
        vector<ll> left(n, -1), right(n, n);
        ll ans=0;
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>= nums[i])
                st.pop();
            if(!st.empty())
                left[i] = st.top();
            st.push(i);
        }

        while(!st.empty())
            st.pop();

        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()]> nums[i])
                st.pop();
            if(!st.empty())
                right[i] = st.top();
            st.push(i);
        }

        for(int i=0;i<n;i++)
            ans = (ans + (i-left[i])*(right[i]-i)*nums[i])%INF;
        return ans;
    }
};
