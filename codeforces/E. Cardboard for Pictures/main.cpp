#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

ll calcValue(vector<ll>& nums, ll w, ll target){
    ll ans=0;
    for(ll i: nums){
        ans += (i+2*w)*(i+2*w);
        if(ans > target)
            return target+1;
    }
    return ans;
}

void solve() {
    ll n, target; cin>>n>>target;
    vector<ll> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll low = 1, high = 1e9, mid;
    while(low<=high){
        mid = midpoint(low, high);
        ll value = calcValue(nums, mid, target);
        if(value==target){
            cout<<mid<<"\n";
            return;
        }else if(value<target)
            low = mid+1;
        else
            high = mid-1;
    }
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
