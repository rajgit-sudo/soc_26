#include <bits/stdc++.h>
#include <numbers>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    string s; cin>>s;

    auto flip = [&](int i){
        if(s[i]=='1')
            s[i]='0';
        else
            s[i]='1';
    };

    for(int i=0; i<n-k; i++){
        if(s[i]=='1'){
            flip(i); flip(i+k);
        }
    }

    bool ans = true;
    for(char x: s){
        if(x=='1')
            ans=false;
    }

    cout<<(ans==true?"YES\n":"NO\n");
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
