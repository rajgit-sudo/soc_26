#include <bits/stdc++.h>
using namespace std;
using ll=long long;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& grid) {
        int n = grid.size();
        int i=1, j=1e9, mid;

        auto valid = [&](int time){
            vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            visited[0][0]=true;
            queue<pair<int, int>> q; q.push({0, 0});

            int steps=0;
            bool flag=false;

            while(!q.empty()){
                int size = q.size();
                steps++;
                while(size--){
                    if(steps>time)
                        return false;

                    auto p = q.front(); q.pop();
                    steps+=grid[p.first][p.second];
                    if(p.first==n-1 && p.second==n-1){
                        flag=true;
                        break;
                    }

                    for(const pair<int, int>& neighbour: neighbours){
                        int r = p.first + neighbour.first;
                        int c = p.second + neighbour.second;

                        if(r<0 || r>=n || c<0 || c>=n) continue;
                        if(visited[r][c]) continue;
                        if(grid[r][c]<=time) continue;

                        visited[r][c] = true;
                        q.push({r, c});
                    }
                }

                if(flag) break;
            }
            return steps<=time;
        };

        int ans = j;
        while(i<=j){
            mid = midpoint(i, j);
            if(valid(mid)){
                ans = min(ans, mid);
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};
