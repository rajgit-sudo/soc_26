#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    int player = -1;

    ll ans=0;
    while(n>0){
        player = -player;
        if(n%2==0){
            if(n>8 && n%4==0){
                if(player==1)
                    ans+=1;
                n-=1;
            }else{
                if(player==1)
                    ans+=n/2;
                n/=2;
            }
        }else{
            if(player==1)
                ans+=1;
            n-=1;
        }
    }
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
