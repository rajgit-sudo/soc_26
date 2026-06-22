#include <bits/stdc++.h>
#include <unordered_set>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++)
        cin>>nums[i];

    multiset<int> ms;
    for(int i: nums){
        auto it = ms.upper_bound(i);
        if(it!=ms.end()){
            ms.erase(it);
        }
        ms.insert(i);
    }
    cout<<ms.size();
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
