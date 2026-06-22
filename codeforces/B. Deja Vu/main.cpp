#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n, q; cin>>n>>q;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<ll> queries; queries.reserve(q);
    ll currMin = 1e9;
    for(int i=0;i<q;i++){
        ll a; cin>>a;
        if(a < currMin){
            queries.push_back(a);
            currMin = a;
        }
    }

    for(ll query: queries){
        for(int i=0;i<n;i++){
            if(nums[i] % (1LL<<query) == 0){
                nums[i] += (1LL<<(query-1));
            }
        }
    }

    for(ll i: nums)
        cout<<i<<" ";
    cout<<"\n";
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
