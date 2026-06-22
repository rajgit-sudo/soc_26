#include <bits/stdc++.h>
using namespace std;
using ll=long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

// s.find_by_order(k) : returns iterator to kth element (0-indexed)
// s.order_of_key(x)  : returns count of elements strictly less than x

void solve() {
    int n, k; cin>>n>>k;
    ordered_set nums;
    for(int i=1; i<=n; i++)
        nums.insert(i);

    int pos = 0;
    while(!nums.empty()){
        pos = (pos+k)%(nums.size());
        auto it = nums.find_by_order(pos);
        cout<<*it<<" ";
        nums.erase(it);
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
