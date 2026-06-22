#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        if(s.front()==')' || s.back()=='(')
            return false;

        int low = 0, high = 0;
        for(int i=0;i<n;i++){
            char x = s[i];
            if(x=='('){
                low++;
                high++;
            }else if(x==')'){
                low--;
                high--;
            }else{
                low = max(0, low-1);
                high++;
            }

            if(high<0) return false;
        }
        return low==0;
    }
};

/*
 * 678. Valid Parenthesis String
 * Difficulty: Medium
 * https://leetcode.com/problems/valid-parenthesis-string/
 *
 * ──────────────────────────────────────────────────
 *
 * Given a string s containing only three types of characters: '(', ')'
 * and '*', return true if s is valid.
 *
 * The following rules define a valid string:
 *
 * • Any left parenthesis '(' must have a corresponding right
 * parenthesis ')'.
 *
 * • Any right parenthesis ')' must have a corresponding left
 * parenthesis '('.
 *
 * • Left parenthesis '(' must go before the corresponding right
 * parenthesis ')'.
 *
 * • '*' could be treated as a single right parenthesis ')' or a single
 * left parenthesis '(' or an empty string "".
 *
 *
 *
 * Example 1:
 *
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 *
 * Input: s = "(*)"
 * Output: true
 *
 * Example 3:
 *
 * Input: s = "(*))"
 * Output: true
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= s.length <= 100
 *
 * 	• s[i] is '(', ')' or '*'.
*/
