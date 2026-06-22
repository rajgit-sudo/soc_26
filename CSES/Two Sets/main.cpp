#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    ll n; cin>>n;
    if((n*(n+1))%4!=0){
        cout<<"NO";
        return;
    }

    cout<<"YES\n";
    if(n%2==0){
        cout<<n/2<<"\n";
        ll i=1, j=n;
        ll c=0;
        while(i<j){
            if(c==n/2)
                cout<<"\n"<<n/2<<"\n";
            cout<<i<<" "<<j<<" ";
            c+=2;
            i++; j--;
        }
    }else{
        unordered_set<ll> set1;
        ll targetSum = (n*(n+1))/4;
        ll j=n;
        while(targetSum){
            while(targetSum < j)
                j--;
            targetSum -= j;
            set1.insert(j);
            j--;
        }
        cout<<set1.size()<<"\n";
        for(int i: set1)
            cout<<i<<" ";
        cout<<"\n"<<n-set1.size()<<"\n";
        for(int i=1; i<=n; i++){
            if(!set1.contains(i)){
                cout<<i<<" ";
            }
        }
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
