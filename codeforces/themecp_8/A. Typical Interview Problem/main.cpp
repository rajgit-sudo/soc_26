#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    string s; cin>>s;

    string ans="";
    for(int i=0;i<1000;i++){
        if(i%3==0) ans.push_back('F');
        if(i%5==0) ans.push_back('B');
    }

    if(ans.find(s)!=string::npos)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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
