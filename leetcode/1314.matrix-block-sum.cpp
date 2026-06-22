#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, m;
    void populatePrefixMatrix(vector<vector<int>>& prefixMatrix, vector<vector<int>>& matrix){
        for(int i=1; i<=n; i++){
            vector<int> prefixRow(m+1, 0);
            for(int j=1; j<=m; j++){
                prefixRow[j] = prefixRow[j-1] + matrix[i-1][j-1];
                prefixMatrix[i][j] = prefixMatrix[i-1][j] + prefixRow[j];
            }
        }
    }

    int sumRegion(vector<vector<int>>& prefixMatrix, int r1, int c1, int r2, int c2){
        return prefixMatrix[r2+1][c2+1] - prefixMatrix[r1][c2+1] - prefixMatrix[r2+1][c1] + prefixMatrix[r1][c1];
    }

    vector<vector<int>> matrixBlockSum(vector<vector<int>>& matrix, int k) {
        n = matrix.size(), m = (matrix[0].size());
        vector<vector<int>> prefixMatrix(n+1, vector<int>(m+1, 0));
        populatePrefixMatrix(prefixMatrix, matrix);

        vector<vector<int>> ans(n, vector<int>(m, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = sumRegion(prefixMatrix, max(i-k, 0), max(j-k, 0), min(i+k, n-1), min(j+k, m-1));
            }
        }
        return ans;
    }
};
