#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, m;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, bool& marked, int r, int c){
        if(r==0 || r==n-1 || c==0 || c==m-1) marked = false;

        for(const pair<int, int>& neighbour: neighbours){
            int rr = r + neighbour.first;
            int cc = c + neighbour.second;

            if(rr<0 || rr>=n || cc<0 || cc>=m) continue;
            if(visited[rr][cc]) continue;
            if(grid[rr][cc]=='X') continue;

            visited[rr][cc] = true;
            dfs(grid, visited, marked, rr, cc);
        }
    }

    void solve(vector<vector<char>>& grid) {
        n = grid.size() , m = (grid[0]).size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O' && !visited[i][j]){
                    bool marked = true;
                    visited[i][j] = true;
                    dfs(grid, visited, marked, i, j);

                    if(marked){
                        grid[i][j] = 'X';
                        q.push({i, j});
                    }
                }
            }
        }

        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();

            for(const pair<int, int>& neighbour: neighbours){
                int r = p.first + neighbour.first;
                int c = p.second + neighbour.second;

                if(r<0 || r>=n || c<0 || c>=m) continue;
                if(grid[r][c]=='X') continue;

                grid[r][c] = 'X';
                q.push({r, c});
            }
        }
    }
};
