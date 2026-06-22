#include <algorithm>
#include <bits/stdc++.h>
#include <cstdio>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    double tolerance = 1e-6;
    double low = 1e-9, high = *max_element(nums.begin(), nums.end()), mid;
    double ans = low;

    auto valid = [&](double currLength){
        ll ans = 0;
        for(int i: nums){
            ans+=floor(i/currLength);
            if(ans>=k)
                return true;
        }
        return false;
    };

    while(high-low>tolerance){
        mid = midpoint(low, high);
        if(valid(mid)){
            ans = max(ans, mid);
            low = mid;
        }else{
            high = mid;
        }
    }
    cout << fixed << setprecision(6) << ans;
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
