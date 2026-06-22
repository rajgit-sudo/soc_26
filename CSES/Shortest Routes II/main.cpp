#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void dijkstras(vector<vector<pair<ll, ll>>>& graph, vector<ll>& dist, int startNode){
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    dist[startNode] = 0;
    pq.push({0, startNode});

    while(!pq.empty()){
        ll node = pq.top().second;
        ll prevDistance = pq.top().first;
        pq.pop();

        if(prevDistance > dist[node]) continue;

        for(auto nextNodePair: graph[node]){
            ll edgeCost = nextNodePair.first;
            ll nextNode = nextNodePair.second;

            ll newDistance = prevDistance + edgeCost;
            if(dist[nextNode] > newDistance){
                dist[nextNode] = newDistance;
                pq.push({newDistance, nextNode});
            }
        }
    }
}

void solve() {
    ll n, m, q; cin>>n>>m>>q;
    vector<vector<pair<ll, ll>>> graph(n);
    for(int i=0;i<m;i++){
        ll a, b, c; cin>>a>>b>>c; a--; b--;
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
    }

    const ll INF = 2e18 + 5;
    vector<vector<ll>> dist(n, vector<ll>(n, INF));
    for(int i=0;i<n;i++)
        dijkstras(graph, dist[i], i);


    for(int i=0;i<q;i++){
        int a, b; cin>>a>>b; a--; b--;

        ll ans = dist[a][b];
        cout<<(ans==INF?-1:ans)<<"\n";
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
