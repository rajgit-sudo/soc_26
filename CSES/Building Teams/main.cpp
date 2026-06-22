#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0;i<m;i++){
        int a, b; cin>>a>>b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> color(n, -1);
    for(int i=0; i<n; i++){
        if(color[i]!=-1) continue;

        queue<int> q;
        q.push(i);
        color[i] = 0;
        while(!q.empty()){
            int node = q.front(); q.pop();

            for(int nextNode: graph[node]){
                if(color[nextNode] == -1){
                    color[nextNode] = 1 - color[node];
                    q.push(nextNode);
                }else{
                    if(color[nextNode] == color[node]){
                        cout<<"IMPOSSIBLE";
                        return;
                    }
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<(color[i]==1?1:2)<<" ";
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
