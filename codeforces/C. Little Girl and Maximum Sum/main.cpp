#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, q; cin>>n>>q;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<ll> diff(n+1, 0);
    for(int i=0;i<q;i++){
        int l, r; cin>>l>>r;
        diff[l-1]++;
        diff[r]--;
    }

    for(int i=0; i<n; i++)
        diff[i+1] += diff[i];

    sort(diff.begin(), diff.end());
    sort(nums.begin(), nums.end());
    ll ans=0;

    for(int i=0;i<n;i++)
        ans += (diff[i+1] * nums[i]);

    cout<<ans<<"\n";
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
