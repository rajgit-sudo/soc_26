#include <bits/stdc++.h>
#include <functional>
#include <string>
#include <vector>
using namespace std;
using ll=long long;

int n, m;
vector<pair<int, int>> neighbours = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(vector<string>& graph, vector<vector<bool>>& visited, int i, int j){
    visited[i][j] = true;
    for(const pair<int, int>& neighbour: neighbours){
        int r = i + neighbour.first;
        int c = j + neighbour.second;
        if(r<0 || r>=n || c<0 || c>=m) continue;
        if(graph[r][c] == '#') continue;
        if(visited[r][c]) continue;

        dfs(graph, visited, r, c);
    }
}

void solve() {
    cin>>n>>m;
    vector<string> graph(n);
    for(int i=0;i<n;i++)
        cin>>graph[i];

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j]=='.' && !visited[i][j]){
                ans++;
                dfs(graph, visited, i, j);
            }
        }
    }
    cout<<ans;
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
