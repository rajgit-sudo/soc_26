#include <bits/stdc++.h>
#include <set>
using namespace std;
using ll=long long;

void solve() {
    int x, n; cin>>x>>n;
    set<int> lights;
    multiset<int> lengths;
    lights.insert(0); lights.insert(x);
    lengths.insert(x);
    for(int i=0;i<n;i++){
        int a; cin>>a;
        auto it2 = lights.upper_bound(a);
        auto it1 = it2; --it1;
        lengths.erase(lengths.find(*it2-*it1));
        lengths.insert(a-*it1);
        lengths.insert(*it2-a);
        lights.insert(a);
        cout<<*lengths.rbegin()<<" ";
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
