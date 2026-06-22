#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    vector<bool> cols, mainDiag, antiDiag;

    void backtrack(int& ans, int queensRemaining, int r=0){
        if(queensRemaining==0){
            ans++;
        }

        for(int c=0;c<n;c++){
            if(cols[c]) continue;
            if(mainDiag[r-c+n]) continue;
            if(antiDiag[r+c]) continue;

            cols[c] = true;
            mainDiag[r-c+n] = true;
            antiDiag[r+c] = true;
            backtrack(ans, queensRemaining-1, r+1);
            cols[c] = false;
            mainDiag[r-c+n] = false;
            antiDiag[r+c] = false;
        }
    }

    int totalNQueens(int N) {
        n = N;
        cols.assign(n, false);
        mainDiag.assign(2*n, false);
        antiDiag.assign(2*n, false);

        int ans=0;
        backtrack(ans, n);
        return ans;
    }
};
