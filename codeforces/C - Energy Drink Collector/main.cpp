#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<pair<ll, ll>> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i].first>>nums[i].second;

    sort(nums.begin(), nums.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b){
        if(a.first == b.first)
            return a.second > b.second;
        return a.first < b.first;
    });

    ll ans=0;
    for(int i=0;i<n;i++){
        if(m>nums[i].second){
            m-=nums[i].second;
            ans+=(nums[i].first*nums[i].second);
        }else{
            ans+=(nums[i].first * m);
            break;
            m=0;
        }
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
