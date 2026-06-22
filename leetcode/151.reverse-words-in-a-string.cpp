#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        vector<string> words;

        int start =-1;
        for(int i=0;i<n;i++){
            if(start==-1 && s[i]!=' '){
                start = i;
            }else if(start!=-1 && s[i]==' '){
                words.push_back(s.substr(start, i-start));
                start = -1;
            }
        }
        if(s.back()!=' ' && start!=-1)
            words.push_back(s.substr(start));

        string ans = "";
        reverse(words.begin(), words.end());
        for(string s: words){
            ans.append(s);
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};

/*
 * 151. Reverse Words in a String
 * Difficulty: Medium
 * https://leetcode.com/problems/reverse-words-in-a-string/
 *
 * ──────────────────────────────────────────────────
 *
 * Given an input string s, reverse the order of the words.
 *
 * A word is defined as a sequence of non-space characters. The words in
 * s will be separated by at least one space.
 *
 * Return a string of the words in reverse order concatenated by a
 * single space.
 *
 * Note that s may contain leading or trailing spaces or multiple spaces
 * between two words. The returned string should only have a single space
 * separating the words. Do not include any extra spaces.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "the sky is blue"
 * Output: "blue is sky the"
 *
 * Example 2:
 *
 * Input: s = "  hello world  "
 * Output: "world hello"
 * Explanation: Your reversed string should not contain leading or
 * trailing spaces.
 *
 * Example 3:
 *
 * Input: s = "a good   example"
 * Output: "example good a"
 * Explanation: You need to reduce multiple spaces between two words to
 * a single space in the reversed string.
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= s.length <= 10^4
 *
 * • s contains English letters (upper-case and lower-case), digits,
 * and spaces ' '.
 *
 * 	• There is at least one word in s.
 *
 *
 *
 * Follow-up: If the string data type is mutable in your language, can
 * you solve it in-place with O(1) extra space?
*/
