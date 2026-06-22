#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll atMost(const string& s, ll k){
    ll n = s.size();
    ll ans=0, left=0;
    ll used=0;
    for(ll right = 0; right<n; right++){
        if(s[right]=='1')
            used++;

        while(used>k){
            if(s[left]=='1')
                used--;
            left++;
        }

        ans += (right - left+1);
    }
    return ans;
}

void solve() {
    ll k; cin>>k;
    string s; cin>>s;
    ll ans = atMost(s, k);
    if(k!=0)
        ans -= atMost(s, k-1);
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
