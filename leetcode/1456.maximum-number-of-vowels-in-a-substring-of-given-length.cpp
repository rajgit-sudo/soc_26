#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll=long long;
class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
        int curr=0;
        for(int i=0;i<k;i++){
            if(vowels.contains(s[i]))
                curr++;
        }

        int ans = curr;
        for(int i=k; i<n; i++){
            if(vowels.contains(s[i-k]))
                curr--;
            if(vowels.contains(s[i]))
                curr++;
            ans = max(ans, curr);
        }
        return ans;
    }
};

/*
 * 1456. Maximum Number of Vowels in a Substring of Given Length
 * Difficulty: Medium
 * https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 *
 * ──────────────────────────────────────────────────
 *
 * Given a string s and an integer k, return the maximum number of vowel
 * letters in any substring of s with length k.
 *
 * Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.
 *
 *
 *
 * Example 1:
 *
 * Input: s = "abciiidef", k = 3
 * Output: 3
 * Explanation: The substring "iii" contains 3 vowel letters.
 *
 * Example 2:
 *
 * Input: s = "aeiou", k = 2
 * Output: 2
 * Explanation: Any substring of length 2 contains 2 vowels.
 *
 * Example 3:
 *
 * Input: s = "leetcode", k = 3
 * Output: 2
 * Explanation: "lee", "eet" and "ode" contain 2 vowels.
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= s.length <= 10^5
 *
 * 	• s consists of lowercase English letters.
 *
 * 	• 1 <= k <= s.length
*/
