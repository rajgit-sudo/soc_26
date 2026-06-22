#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, m;
    vector<vector<bool>> visited;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int r, int c, int& ans){
        for(const pair<int, int>& neighbour: neighbours){
            int rr = r + neighbour.first;
            int cc = c + neighbour.second;

            if(rr<0 || rr>=n || cc<0 || cc>=m) continue;
            if(visited[rr][cc]) continue;
            if(grid[rr][cc]==0) continue;

            visited[rr][cc]=true;
            ans++;
            dfs(grid, rr, cc, ans);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(), m = (grid[0]).size();
        visited.assign(n, vector<bool>(m, false));

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int currAns=1;
                    visited[i][j] = true;
                    dfs(grid, i, j, currAns);
                    ans = max(ans, currAns);
                }
            }
        }
        return ans;
    }
};
