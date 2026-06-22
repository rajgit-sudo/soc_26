#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, vector<int>& group){
    visited[node] = true;
    group.push_back(node);

    for(int nextNode: graph[node]){
        if(!visited[nextNode]){
            dfs(graph, visited, nextNode, group);
        }
    }
}

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int a, b; cin>>a>>b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }

    vector<bool> visited(n, false);
    vector<vector<int>> groups;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            vector<int> group;
            dfs(graph, visited, i, group);
            groups.push_back(group);
        }
    }

    int ans = groups.size();
    cout<<ans-1<<"\n";
    if(ans>=1){
        for(int i=0;i<ans-1;i++){
            cout<<groups[i][0]+1<<" "<<groups[i+1][0]+1<<"\n";
        }
    }
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
