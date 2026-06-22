#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n);
    ll deadlineSum = 0;
    for(ll i=0;i<n;i++){
        cin>>nums[i];
        ll a; cin>>a;
        deadlineSum+=a;
    }

    ll finishingTimes=0;
    sort(nums.rbegin(), nums.rend());
    for(ll i=0;i<n;i++)
        finishingTimes += (i+1) * (nums[i]);

    cout<<deadlineSum - finishingTimes;
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
