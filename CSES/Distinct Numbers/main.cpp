#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    set<int> set;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        set.insert(a);
    }
    cout<<set.size();
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
