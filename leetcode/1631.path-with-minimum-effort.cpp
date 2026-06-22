#include <bits/stdc++.h>
#include <numeric>
#include <type_traits>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int minimumEffortPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = (matrix[0]).size();
        int i=0, j=1e6, mid;
        int ans = j;

        auto valid = [&](int maxDiff){
            queue<pair<int, int>> q;
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[0][0]=true;
            q.push({0, 0});

            while(!q.empty()){
                auto p = q.front(); q.pop();
                if(p.first==n-1 && p.second==m-1)
                    return true;

                for(const pair<int, int>& neighbour: neighbours){
                    int r = p.first + neighbour.first;
                    int c = p.second + neighbour.second;

                    if(r<0 || r>=n || c<0 || c>=m) continue;
                    if(visited[r][c]) continue;
                    if(abs(matrix[p.first][p.second] - matrix[r][c])>maxDiff) continue;

                    visited[r][c]=true;
                    q.push({r, c});
                }
            }
            return false;
        };

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
