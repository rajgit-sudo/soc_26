#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;
using ll=long long;

int num(char x){
    return x-'0';
}

void solve() {
    string a, s; cin>>a>>s;
    string b="";
    int i = a.size()-1, j=s.size()-1;
    while(i>=0 && j>=0){
        int digitA = num(a[i]);
        int digitS = num(s[j]);

        int curr = digitS - digitA;
        if(digitA>digitS){
            curr+=10;
            j--;
        }
        b.append(to_string(curr));

        i--; j--;
    }

    reverse(b.begin(), b.end());
    ll ans = stoll(b);
    cout<<ans<<"\n";
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
