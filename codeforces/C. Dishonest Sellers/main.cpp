#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n, k; cin>>n>>k;
    vector<pair<ll, ll>> nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i].first;
    for(ll i=0;i<n;i++)
        cin>>nums[i].second;
    sort(nums.begin(), nums.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        return a.first - a.second < b.first - b.second;
    });

    ll ans=0;
    for(ll i=0;i<k;i++){
        ans+=nums[i].first;
    }
    for(ll i=k; i<n; i++){
        ans+=min(nums[i].first, nums[i].second);
    }
    cout<<ans;
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
