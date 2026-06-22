#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;

class Solution {
public:
    int mySqrt(int x) {
        ll low = 0, high = x, mid;
        int ans = 0;
        while(low<=high){
            mid = midpoint(low, high);
            if(mid*mid <= (ll)x){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid-1;
            }
        }
        return ans;
    }
};

/*
 * 69. Sqrt(x)
 * Difficulty: Easy
 * https://leetcode.com/problems/sqrtx/
 *
 * ──────────────────────────────────────────────────
 *
 * Given a non-negative integer x, return the square root of x rounded
 * down to the nearest integer. The returned integer should be
 * non-negative as well.
 *
 * You must not use any built-in exponent function or operator.
 *
 * 	• For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 *
 *
 *
 * Example 1:
 *
 * Input: x = 4
 * Output: 2
 * Explanation: The square root of 4 is 2, so we return 2.
 *
 * Example 2:
 *
 * Input: x = 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since we round
 * it down to the nearest integer, 2 is returned.
 *
 *
 *
 * Constraints:
 *
 * 	• 0 <= x <= 2^31 - 1
*/
