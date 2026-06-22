#include <bits/stdc++.h>
using namespace std;
using ll=long long;

/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double pow(double x, ll n){
        if(n==0)
            return 1;
        if(n==1)
            return x;
        
        if(n%2==0)
            return pow(x*x, n/2);
        else
            return x * pow(x*x, (n-1)/2);
    }

    double myPow(double x, int n) {
        ll exponent = (ll)n;
        if(exponent<0)
            return 1/pow(x, -exponent);
        return pow(x, exponent);
    }
};
// @lc code=end

