#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() , m = (grid[0]).size();
        queue<pair<int, int>> q;
        int ans=-1;
        vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        bool fresh = false;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                    visited[i][j] = true;
                }else if(grid[i][j]==1)
                    fresh = true;
            }
        }

        if(q.empty()){
            if(!fresh)
                return 0;
            return -1;
        }

        while(!q.empty()){
            ans++;
            int size = q.size();
            while(size--){
                pair<int, int> p = q.front(); q.pop();

                for(const pair<int, int>& neighbour: neighbours){
                    int r = p.first + neighbour.first;
                    int c = p.second + neighbour.second;

                    if(r<0 || r>=n || c<0 || c>=m) continue;
                    if(visited[r][c]) continue;
                    if(grid[r][c]==0) continue;

                    if(grid[r][c]==1)
                        grid[r][c] = 2;
                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ans;
    }
};
