#include <bits/stdc++.h>
#include <iterator>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    map<ll, ll> map;
    for(int i=0;i<n;i++){
        ll l, r; cin>>l>>r;
        map[l]++;
        map[r+1]--;
    }

    vector<ll> ans(n+1, 0);
    ll curr = 0;
    ll prev_key = map.begin()->first;
    for(const auto& [curr_key, curr_value]: map){
        ll numPoints = curr_key - prev_key;
        if(curr>0)
            ans[curr] += numPoints;

        curr += curr_value;
        prev_key = curr_key;
    }

    for(int i=1; i<=n; i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
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
