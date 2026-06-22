#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++){
        int a, b; cin>>a>>b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    vector<int> parent(n);
    vector<bool> visited(n, false);
    visited[0] = true;
    while(!q.empty()){
        int node = q.front(); q.pop();
        if(node == n-1){
            break;
        }

        for(int nextNode: graph[node]){
            if(!visited[nextNode]){
                q.push(nextNode);
                visited[nextNode] = true;
                parent[nextNode] = node;
            }
        }
    }

    if(!visited[n-1]){
        cout<<"IMPOSSIBLE";
        return;
    }

    vector<int> path;
    int i = n-1;
    while(i!=0){
        path.push_back(i+1);
        i = parent[i];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    cout<<int(path.size())<<"\n";
    for(int i: path)
        cout<<i<<" ";
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
