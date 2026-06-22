#include <bits/stdc++.h>
#include <sys/types.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    ll ans=nums[0], sum=0;

    for(int i: nums){
        sum+=i;
        ans = max(ans, sum);
        if(sum<0)
            sum=0;
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
