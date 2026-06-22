#include <bits/stdc++.h>
using namespace std;

void solve() {
    string s; cin>>s;
    int len=1, ans=1;
    int n = s.size();
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1])
            len++;
        else{
            ans = max(ans, len);
            len=1;
        }
    }
    ans = max(ans, len);
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
