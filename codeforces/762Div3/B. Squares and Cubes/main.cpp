#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    set<int> ans;
    for(int i=1; i*i<=n; i++)
        ans.insert(i*i);
    for(int i=1; i*i*i<=n; i++)
        ans.insert(i*i*i);

    cout<<int(ans.size())<<"\n";
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
