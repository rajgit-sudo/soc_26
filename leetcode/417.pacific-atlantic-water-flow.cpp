#include <bits/stdc++.h>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, m;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, queue<pair<int, int>>& q){
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();

            for(const pair<int, int>& neighbour: neighbours){
                int r = p.first + neighbour.first;
                int c = p.second + neighbour.second;

                if(r<0 || r>=n || c<0 || c>=m) continue;
                if(visited[r][c]) continue;

                if(grid[r][c] >= grid[p.first][p.second]){
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        n = grid.size(), m = (grid[0]).size();
        vector<vector<bool>> pacific(n, vector<bool>(m, false)), atlantic(n, vector<bool>(m, false));
        vector<vector<int>> ans;

        queue<pair<int, int>> pacificQueue, atlanticQueue;
        for(int i=0;i<n;i++){
            pacific[i][0] = true;
            atlantic[i][m-1] = true;
            pacificQueue.push({i, 0});
            atlanticQueue.push({i, m-1});
        }
        for(int i=0;i<m;i++){
            pacific[0][i] = true;
            atlantic[n-1][i] = true;
            pacificQueue.push({0, i});
            atlanticQueue.push({n-1, i});
        }

        bfs(grid, pacific, pacificQueue);
        bfs(grid, atlantic, atlanticQueue);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};
