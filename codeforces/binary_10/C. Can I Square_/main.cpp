#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    ll num=0;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        num+=a;
    }

    ll i=1, j = 1e9, mid;
    while(i<=j){
        mid = midpoint(i, j);
        if(mid*mid == num){
            cout<<"YES\n";
            return;
        }else if(mid*mid < num){
            i = mid+1;
        }else{
            j = mid-1;
        }
    }
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
