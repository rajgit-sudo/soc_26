#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

bool valid(vector<ll>& nums, ll currHeight, const ll maxWaterCapacity){
    int n = nums.size();
    ll waterUsed = 0;
    for(int i=0;i<n;i++){
        waterUsed += max(0LL, currHeight - nums[i]);
        if(waterUsed > maxWaterCapacity)
            return false;
    }
x
    return waterUsed <= maxWaterCapacity;
}

void solve() {
    ll n, x; cin>>n>>x;
    vector<ll> nums(n, 0);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll low = 0, high = 1e18, mid;
    ll ans = low;
    while(low<=high){
        mid = midpoint(low, high);
        if(valid(nums, mid, x)){
            ans = max(ans, mid);
            low = mid+1;
        }else {
            high = mid-1;
        }
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
