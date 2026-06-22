#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    // sort(nums.begin(), nums.end());

    auto isValid = [&](ll capacity){
        int required=1;
        ll used = capacity;
        for(int i: nums){
            if(used>=i)
                used -= i;
            else{
                required++;
                used = capacity - i;
            }
        }
        return required<=k;
    };

    ll i = (ll)(*max_element(nums.begin(), nums.end())), j = accumulate(nums.begin(), nums.end(), 0LL), mid;
    ll ans = j;
    while(i<=j){
        mid = i + (j-i)/2;
        if(isValid(mid)){
            ans = min(ans, mid);
            j = mid-1;
        }else{
            i = mid+1;
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
