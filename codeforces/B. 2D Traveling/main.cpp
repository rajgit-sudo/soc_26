#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

ll pairDistance(const pair<ll, ll>& a, const pair<ll, ll>& b){
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve() {
    int n, k, start, end; cin>>n>>k>>start>>end;
    vector<pair<ll, ll>> cities(n);
    for(int i=0;i<n;i++)
        cin>>cities[i].first>>cities[i].second;

    ll startingDistance = 1e18, endingDistance = 1e18;
    start--; end--;
    ll ans = pairDistance(cities[start], cities[end]);
    for(int i=0;i<n;i++){
        if(i!=start && i<k){ // major city which is not start
            startingDistance = min(startingDistance, pairDistance(cities[start], cities[i]));
        }
        if(i!=end && i<k){ //major city which is not end
            endingDistance = min(endingDistance, pairDistance(cities[end], cities[i]));
        }
    }
    if(start<k)
        startingDistance = 0;
    if(end < k)
        endingDistance = 0;
    ans = min(ans, (startingDistance + endingDistance));
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}


//6 2 3 5
// 0 0
// 1 -2
// -2 1
// -1 3
// 2 -2
// -3 -3
