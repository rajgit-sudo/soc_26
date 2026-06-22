#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    string s; cin>>s;
    string t = "hello";

    int n = s.size(), m = t.size();
    int i=0, j=0;
    while(i<n && j<m){
        if(s[i]==t[j]){
            j++;
        }
        i++;
    }

    if(j!=m)
        cout<<"NO";
    else
        cout<<"YES";
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
