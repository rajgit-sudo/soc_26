#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n, c, d; cin>>n>>c>>d;
    unordered_map<ll, ll> map;
    ll a = 1e9+1;
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll x; cin>>x;
            map[x]++;
            a = min(a, x);
        }
    }

    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            ll element = a + i*c + d*j;
            if(!map.contains(element)){
                cout<<"NO\n";
                return;
            }else{
                map[element]--;
                if(map[element]==0)
                    map.erase(element);
            }
        }
    }
    cout<<"YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
