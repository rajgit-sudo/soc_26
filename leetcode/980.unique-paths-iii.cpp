#include <bits/stdc++.h>
using namespace std;
using ll=long long;

/*
 * @lc app=leetcode id=980 lang=cpp
 *
 * [980] Unique Paths III
 */

// @lc code=start
class Solution {
    int n, m;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int totalCount=0;
public:
    void dfs(vector<vector<int>>& grid, int r, int c, int& ans, int visited=0){
        visited++;

        if(grid[r][c]==2){
            if(visited==totalCount) ans++;
            return;
        }

        for(const pair<int, int>& neighbour: neighbours){
            int rr = r + neighbour.first;
            int cc = c + neighbour.second;
            if(rr<0 || rr>=n || cc<0 || cc>=m) continue;
            if(grid[rr][cc]==-1) continue;

            int temp = grid[r][c];
            grid[r][c]=-1;
            dfs(grid, rr, cc, ans, visited);
            grid[r][c] = temp;
        }
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=(grid.front()).size();
        int totalVisit = 0;
        int r=-1, c=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    r = i; c=j;
                }

                if(grid[i][j]!=-1)
                    totalCount++;
            }
        }

        int ans=0;
        dfs(grid, r, c, ans);
        return ans;
    }
};
// @lc code=end

