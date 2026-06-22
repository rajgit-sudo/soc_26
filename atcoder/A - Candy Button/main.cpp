#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, c; cin>>n>>c;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];
    int endTime = nums[0];
    int ans=1;
    for(int i=1; i<n; i++){
        if(nums[i] - endTime >= c){
            ans++;
            endTime = nums[i];
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
