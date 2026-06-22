#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, l; cin>>n>>l;
    vector<string> strs(n);
    for(int i=0;i<n;i++)
        cin>>strs[i];
    sort(strs.begin(), strs.end());
    string ans="";
    for(string s: strs)
        ans.append(s);
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
