#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        set<char> set;
        int i=0, j=0;
        int ans=0;
        while(j<n){
            while(!set.empty() && set.contains(s[j])){
                set.erase(s[i]);
                i++;
            }
            set.insert(s[j]);
            j++;
            ans=max(ans, j-i);
        }   
        return ans;
    }
};
// @lc code=end

