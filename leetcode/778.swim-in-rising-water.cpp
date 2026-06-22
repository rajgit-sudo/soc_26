#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int i=1, j=2500, mid;


        auto valid = [&](int maxElement){
            vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            visited[0][0]=true;
            queue<pair<int, int>> q; q.push({0, 0});

            while(!q.empty()){
                auto p = q.front(); q.pop();
                if(p.first==n-1 && p.second==n-1)
                    return true;

                for(const pair<int, int>& neighbour: neighbours){
                    int r = p.first + neighbour.first;
                    int c = p.second + neighbour.second;

                    if(r<0 || r>=n || c<0 || c>=n) continue;
                    if(visited[r][c]) continue;
                    if(grid[r][c]>maxElement) continue;

                    visited[r][c] = true;
                    q.push({r, c});
                }
            }
            return false;
        };

        while(i<=j){
            mid = midpoint(i, j);
            if(valid(mid)){
                ans = mid;
                j=mid-1;
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};
