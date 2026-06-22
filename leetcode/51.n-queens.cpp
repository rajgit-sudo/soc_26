#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n;
    vector<bool> cols, mainDiag, antiDiag;
    string positionBuilder(int c){
        string curr="";
        for(int i=0;i<n;i++){
            if(c==i)
                curr.push_back('Q');
            else
                curr.push_back('.');
        }
        return curr;
    }

    void backtrack(vector<string>& ds, vector<vector<string>>& ans, int queensRemaining, int r=0){
        if(queensRemaining==0){
            ans.push_back(ds);
            return;
        }

        for(int c=0;c<n;c++){
            if(cols[c] || mainDiag[r-c+n] || antiDiag[r+c]) continue;

            cols[c] = true;
            mainDiag[r-c+n] = true;
            antiDiag[r+c] = true;
            ds.push_back(positionBuilder(c));
            backtrack(ds, ans, queensRemaining-1, r+1);
            cols[c] = false;
            mainDiag[r-c+n] = false;
            antiDiag[r+c] = false;
            ds.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int N)  {
        n = N;
        cols.assign(n, false);
        mainDiag.assign(2*n-1, false);
        antiDiag.assign(2*n-1, false);

        vector<vector<string>> ans;
        vector<string> ds;
        backtrack(ds, ans, n);
        return ans;
    }
};
