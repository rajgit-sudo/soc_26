#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = (image[0]).size();
        queue<pair<int, int>> q;
        q.push({sr, sc});

        int originalColour = image[sr][sc];
        vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        visited[sr][sc]=true;
        while(!q.empty()){
            pair<int, int> p = q.front(); q.pop();
            image[p.first][p.second] = color;

            for(const pair<int, int>& neighbour: neighbours){
                int r = p.first + neighbour.first;
                int c = p.second + neighbour.second;

                if(r<0 || r>=n || c<0 || c>=m) continue;
                if(visited[r][c]) continue;
                if(image[r][c]!=originalColour) continue;

                q.push({r, c});
                visited[r][c] = true;
            }
        }
        return image;
    }
};
