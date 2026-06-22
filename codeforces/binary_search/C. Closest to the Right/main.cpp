#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    for(int i=0;i<k;i++){
        int a; cin>>a;
        auto it = lower_bound(nums.begin(), nums.end(), a);
        if(*it < a)
            cout<<n+1<<"\n";
        else
            cout<<distance(nums.begin(), it)+1<<"\n";
    }
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
