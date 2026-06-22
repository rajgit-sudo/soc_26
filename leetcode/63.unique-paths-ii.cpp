#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = (obstacleGrid[0]).size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1)
            return 0;

        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i=n-1; i>=0; i--){
            if(obstacleGrid[i][m-1]==1)
                break;
            dp[i][m-1] = 1;
        }

        for(int i=m-1; i>=0; i--){
            if(obstacleGrid[n-1][i]==1)
                break;
            dp[n-1][i] = 1;
        }

        for(int i=n-2; i>=0; i--){
            for(int j=m-2; j>=0; j--){
                if(obstacleGrid[i][j]!=1)
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
};
