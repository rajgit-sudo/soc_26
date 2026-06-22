#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
#include <numeric>
using namespace std;
using ll=long long;

ll transform(ll x, ll c, ll k, ll times = 1) {
    if(k==1){
        return max(0LL, x-times*c);
    }

    while (times-- && x > 0) {
        x = max(0LL, (x - c) / k);
    }
    return x;
}

void solve() {
    int n, q; cin>>n>>q;
    string s; cin>>s;

    int c=0, k=1;
    for(char x: s){
        if(x=='A'){
            c+=k;
        }else{
            k*=2;
        }
    }

    for(int i=0;i<q;i++){
        ll a; cin>>a;

        ll low = 0, high = 1e9+1, mid;
        ll ans = high;
        while(low<=high){
            mid = midpoint(low, high);
            int completeCycle = mid/n;
            int restOfTheCycle = mid%n;

            ll newA = transform(a, c, k, completeCycle);
            if(newA == 0){
                ans = min(ans, mid);
                high = mid-1;
            }else{
                for(int i=0;i<restOfTheCycle;i++){
                    if(s[i]=='A')
                        newA--;
                    else
                        newA/=2;

                    if(newA==0)
                        break;
                }

                if(newA==0){
                    ans = min(ans, mid);
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
        }

        cout<<ans<<"\n";
    }
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
