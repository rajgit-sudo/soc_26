#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<pair<ll, ll>> nums(n);
    ll total = 0;
    for(ll i=0;i<n;i++){
        cin>>nums[i].first>>nums[i].second;
        total += (nums[i].first + nums[i].second);
    }

    sort(nums.begin(), nums.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        ll pairSum1 = 2*a.first + a.second;
        ll pairSum2 = 2*b.first + b.second;

        return pairSum1<pairSum2;
    });

    ll other=0;
    ll i=0;
    while(total>other){
        total -= (nums[i].first + nums[i].second);
        other += nums[i].first;
        i++;
    }

    cout<<n-i+1;
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
