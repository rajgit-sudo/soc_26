#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;
    vector<int> freq(26, 0);
    for(char x: s)
        freq[x-'a']++;

    cout<<n - freq[s.back()-'a']<<"\n";
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
