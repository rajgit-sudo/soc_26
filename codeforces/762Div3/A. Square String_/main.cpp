#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    string s; cin>>s;
    int n = s.size();
    cout<<(s.substr(0, n/2)==s.substr(n/2)?"YES\n":"NO\n");
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
