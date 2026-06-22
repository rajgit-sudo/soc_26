#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    vector<ll> prefixSum(n);
    prefixSum[0] = nums[0];
    for(int i=1; i<n; i++)
        prefixSum[i] = prefixSum[i-1] + nums[i];

    vector<int> divisors; divisors.reserve(sqrt(n));
    for(ll i=1; i*i<=n; i++){
        if(n%i==0){
            divisors.push_back(i);
            if(i*i != n) divisors.push_back(n/i);
        }
    }

    ll ans = 0;
    for(int k: divisors){
        ll maxTruck = -2e18, minTruck = 2e18;
        for(int i=k-1; i<n; i+=k){
            ll currWeight;
            if(i==k-1)
                currWeight = prefixSum[i];
            else
                currWeight = prefixSum[i] - prefixSum[i-k];

            maxTruck = max(maxTruck, currWeight);
            minTruck = min(minTruck, currWeight);
        }
        ans = max(ans, maxTruck-minTruck);
    }
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
