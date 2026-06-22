#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    ll ans=0;
    for(int i=0;i<n-1;i++){
        if(nums[i] > nums[i+1]){
            ans+=(nums[i] - nums[i+1]);
            nums[i+1] = nums[i];
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
