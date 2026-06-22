#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll=long long;

ll TEN(int x) {return (x==0?1:10*TEN(x-1));}

void solve() {
    ll n; cin>>n;
    if(n==1){
        cout<<0;
        return;
    }
    n--;
    int d = 1;
    while(true){
        int x = (d+1)/2;
        ll count = 9 * TEN(x-1);
        if(n <= count){
            string ans = to_string(TEN(x-1) + n - 1);

            if(d%2==0){
                ans.insert(ans.end(), ans.rbegin(), ans.rend());
            }else{
                ans.insert(ans.end(), ans.rbegin()+1, ans.rend());
            }
            cout<<ans;
            return;
        }
        d++;
        n-=count;
    }
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
