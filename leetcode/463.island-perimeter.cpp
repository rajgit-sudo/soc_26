#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = (grid[0]).size();
        int ans=0;
        bool found = false;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i, j});
                    found = true;
                    break;
                }
            }
            if(found)
                break;
        }

        vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[q.front().first][q.front().second] = true;
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();

            for(const pair<int, int>& neighbour: neighbours){
                int r = p.first + neighbour.first;
                int c = p.second + neighbour.second;
                if(r<0 || r>=n){ ans++; continue;}
                if(c<0 || c>=m){ ans++; continue;}
                if(grid[r][c]==0){ ans++; continue;}
                if(visited[r][c]) continue;

                q.push({r, c});
                visited[r][c]=true;
            }
        }
        return ans;
    }
};
