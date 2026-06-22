#include <bits/stdc++.h>
#include <functional>
#include <iterator>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<vector<pair<ll, ll>>> graph(n);
    for(int i=0;i<m;i++){
        ll a, b, c; cin>>a>>b>>c; a--; b--;
        graph[a].push_back(make_pair(c, b));
    }

    const ll INF = 2e18 + 5;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    vector<ll> dist(n, INF);
    dist[0] = 0;
    pq.push({0, 0});

    while(!pq.empty()){
        ll node = pq.top().second;
        ll prevDistance = pq.top().first;
        pq.pop();

        if(prevDistance > dist[node]) continue;

        for(const pair<ll, ll>& nextNodePair: graph[node]){
            ll nextNode = nextNodePair.second;
            ll edgeCost = nextNodePair.first;

            ll newDistance = prevDistance + edgeCost;
            if(dist[nextNode] > newDistance){
                dist[nextNode] = newDistance;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    for(ll i: dist){
        cout<<i<<" ";
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
