#include <algorithm>
#include <bits/stdc++.h>
#include <csignal>
#include <type_traits>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int n, m;
    string word;
    bool reached=false;
    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int rr, int cc, int index=1){
        if(index==word.size()){
            reached = true;
            return;
        }

        for (const pair<int, int>& neighbour : neighbours) {
            int r = rr + neighbour.first;
            int c = cc + neighbour.second;

           if (r<0 || r>=n || c<0 || c>=m) continue;
           if(visited[r][c]) continue;
           if(board[r][c] != word[index]) continue;

           visited[r][c]=true;
           dfs(board, visited, r, c, index+1);
           visited[r][c]=false;
        }
    }

    bool exist(vector<vector<char>>& board, string wordInput) {
        n = board.size(), m = (board[0]).size();
        word = wordInput;
        vector<pair<int, int>> startingPositions;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word.front())
                    startingPositions.push_back({i, j});
            }
        }

        for(auto p: startingPositions){
            vector<vector<bool>> visited(n, vector<bool>(m, false));
            visited[p.first][p.second] = true;
            dfs(board, visited, p.first, p.second);
            if(reached)
                return true;
        }
        return false;
    }
};
