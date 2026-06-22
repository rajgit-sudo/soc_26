#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n);
    for(ll i=0;i<n;i++)
        cin>>nums[i];
    sort(nums.begin(), nums.end());

    cout<<"5\n";
    ll target = nums[n-1];
    bool flag = false;

    for(ll i=0;i<n-1;i++){
        if(nums[i+1]-nums[i] > 1){
            flag = true;
            break;
        }
    }

    if(flag)
        target++;

    nums.push_back(target);
    ll x = 0;
    for(ll i=0;i<n;i++){
        if(nums[i]!=target){
            x = gcd(x, target - nums[i]);
        }
    }

    ll ans = 0;
    for(ll i=0; i<n+1; i++)
        ans += ((target-nums[i])/x);
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
