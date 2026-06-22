#include <bits/stdc++.h>
using namespace std;
using ll=long long;

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

/*
 * 242. Valid Anagram
 * Difficulty: Easy
 * https://leetcode.com/problems/valid-anagram/
 *
 * ──────────────────────────────────────────────────
 *
 * Given two strings s and t, return true if t is an anagram of s, and
 * false otherwise.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "anagram", t = "nagaram"
 *
 * Output: true
 *
 * Example 2:
 *
 * Input: s = "rat", t = "car"
 *
 * Output: false
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= s.length, t.length <= 5 * 10^4
 *
 * 	• s and t consist of lowercase English letters.
 *
 *
 *
 * Follow up: What if the inputs contain Unicode characters? How would
 * you adapt your solution to such a case?
*/
