#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
    int n, m;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void dfs(vector<vector<char>>& grid, int r, int c, vector<vector<bool>>& visited){
        visited[r][c]=true;
        for(const pair<int, int>& neighbour: neighbours){
            int rr = r + neighbour.first;
            int cc = c + neighbour.second;
            if(rr<0 || rr>=n || cc<0 || cc>=m) continue;
            if(grid[rr][cc]=='0') continue;
            if(visited[rr][cc]) continue;

            dfs(grid, rr, cc, visited);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=(grid.front()).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    dfs(grid, i, j, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

