#include <bits/stdc++.h>
#include <queue>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<char>> graph(n, vector<char>(m));
    pair<int, int> start, end;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>graph[i][j];
            if(graph[i][j]=='A')
                start = {i, j};
            else if(graph[i][j]=='B')
                end = {i, j};
        }
    }

    vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    string direction = "UDLR";

    bool found = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q; q.push(start);
    visited[start.first][start.second] = true;
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> movedTaken(n, vector<char>(m));

    while(!q.empty()){
        auto [x, y] = q.front(); q.pop();

        if(make_pair(x, y) == end){
            found = true;
            break;
        }

        for(int i=0;i<4;i++){
            int r = x + neighbours[i].first;
            int c = y + neighbours[i].second;

            if(r<0 || r>=n || c<0 || c>=m) continue;
            if(visited[r][c]) continue;
            if(graph[r][c]=='#') continue;

            visited[r][c]=true;
            parent[r][c] = {x, y};
            movedTaken[r][c] = direction[i];
            q.push({r, c});
        }
    }

    if(!found){
        cout<<"NO";
        return;
    }

    string path = "";
    pair<int, int> curr = end;
    while(curr!=start){
        path.push_back(movedTaken[curr.first][curr.second]);
        curr = parent[curr.first][curr.second];
    }

    reverse(path.begin(), path.end());
    cout<<"YES\n"<<int(path.size())<<"\n"<<path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
