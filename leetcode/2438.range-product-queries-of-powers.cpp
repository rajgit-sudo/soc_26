#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

const int MOD = 1e9+7;

class Solution {
public:
    vector<ll> makePowers(int n){
        vector<ll> ans;
        for (int i = 0; i <= 30; ++i) {
            if ((n >> i) & 1) {
                ans.push_back(1LL << i);
            }
        }
        return ans;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int q = queries.size();
        vector<ll> powers = makePowers(n);
        int size = powers.size();
        vector<ll> prefixMul(size+1);
        for(int i=0; i<size; i++)
            prefixMul[i+1] = ((prefixMul[i]%MOD) * (powers[i]%MOD))%MOD;

        vector<int> ans(q);
        for(int i=0; i<q; i++){
            int l = queries[q][0], r = queries[q][1];
            ans[i] = (prefixMul[r+1] / prefixMul[l]);
        }
        return ans;
    }
};

/*
 * 2438. Range Product Queries of Powers
 * Difficulty: Medium
 * https://leetcode.com/problems/range-product-queries-of-powers/
 *
 * ──────────────────────────────────────────────────
 *
 * Given a positive integer n, there exists a 0-indexed array called
 * powers, composed of the minimum number of powers of 2 that sum to n.
 * The array is sorted in non-decreasing order, and there is only one way
 * to form the array.
 *
 * You are also given a 0-indexed 2D integer array queries, where
 * queries[i] = [lefti, righti]. Each queries[i] represents a query where
 * you have to find the product of all powers[j] with lefti <= j <=
 * righti.
 *
 * Return an array answers, equal in length to queries, where answers[i]
 * is the answer to the i^th query. Since the answer to the i^th query
 * may be too large, each answers[i] should be returned modulo 10^9 + 7.
 *
 *
 *
 * Example 1:
 *
 * Input: n = 15, queries = [[0,1],[2,2],[0,3]]
 * Output: [2,4,64]
 * Explanation:
 * For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be
 * a smaller size.
 * Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
 * Answer to 2nd query: powers[2] = 4.
 * Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] =
 * 1 * 2 * 4 * 8 = 64.
 * Each answer modulo 10^9 + 7 yields the same answer, so [2,4,64] is
 * returned.
 *
 * Example 2:
 *
 * Input: n = 2, queries = [[0,0]]
 * Output: [2]
 * Explanation:
 * For n = 2, powers = [2].
 * The answer to the only query is powers[0] = 2. The answer modulo 10^9
 * + 7 is the same, so [2] is returned.
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= n <= 10^9
 *
 * 	• 1 <= queries.length <= 10^5
 *
 * 	• 0 <= starti <= endi < powers.length
*/
