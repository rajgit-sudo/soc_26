#include <bits/stdc++.h>
#include <cstdint>
using namespace std;
using ll=long long;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i=0;
        ll ans=0;

        while(i<n && s[i]==' ')
            i++;

        int sign = 1;
        if(i<n && (s[i]=='+' || s[i]=='-')){
            i++;
            if(s[i]=='-')
                sign=-1;
        }

        while(i<n){
            int num = s[i] - '0';
            if(num<0 || num>9)
                return sign * ans;

            if(ans > (INT32_MAX - num)/10){
                if(sign==1)
                    return INT32_MAX;
                return INT32_MIN;
            }
        }
        return sign*ans;
    }
};
