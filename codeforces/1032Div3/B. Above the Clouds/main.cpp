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

    for(int i=1; i<n-1; i++){
        if(freq[s[i]-'a']>=2){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in2.txt", "r", stdin);
    // freopen("res2.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
