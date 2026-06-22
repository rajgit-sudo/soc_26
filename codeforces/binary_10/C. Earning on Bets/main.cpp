#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for (int i=0; i<n; i++)
        cin>>nums[i];

    double condition =0.0;
    for(int i: nums)
        condition += (1.0/i);

    if(condition>=1){
        cout<<"-1\n";
        return;
    }

    ll L = nums.front();
    for(int i=1;i<n;i++)
        L = lcm(L, nums[i]);

    ll ans = 0;
    for(int i: nums){
        ans += (L/i);
    }
    if(ans>=L){
        cout<<"-1\n";
        return;
    }

    for(int i: nums){
        cout<<(L/i)<<" ";
    }
    cout<<"\n";
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
