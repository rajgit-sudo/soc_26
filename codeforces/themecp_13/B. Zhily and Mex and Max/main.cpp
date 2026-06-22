#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    vector<ll> nums(n);
    map<ll, ll> map;
    for (ll i=0; i<n; i++){
        cin>>nums[i];
        map[nums[i]]++;
    }

    sort(nums.begin(), nums.end());
    ll ans = n * nums.back();
    map[nums.back()]--;
    if(map[nums.back()]==0)
        map.erase(nums.back());

    // nums.pop_back();

    ll curr = 0;
    int duplicates=0;
    for(auto p: map){
        if(p.first == curr){
            ans += (curr+1);
            duplicates += (p.second-1);
        }
        else{
            int idx = abs(lower_bound(nums.begin(), nums.end(), curr) - nums.begin());
            ans += (n-idx + duplicates) * curr;
            duplicates=0;
            break;
        }
        curr++;
    }

    if(duplicates)
        ans+=(duplicates*curr);
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in4.txt", "r", stdin);
    // freopen("res4.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
