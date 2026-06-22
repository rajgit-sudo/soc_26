#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n-1);

    vector<ll> ans(n, -1);
    for(ll i=0;i<n-1;i++){
        cin>>nums[i];
        ans[0] = max(ans[0], nums[i]);
    }
    ans[0]++;

    for(ll i=1; i<n; i++)
        ans[i] = ans[i-1] + nums[i-1];

    for(ll i: ans)
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
