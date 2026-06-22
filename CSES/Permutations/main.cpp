#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin>>n;
    if(n==1){
        cout<<1;
        return;
    }
    if(n<=3){
        cout<<"NO SOLUTION";
        return;
    }

    if(n==4){
        cout<<"2 4 1 3";
        return;
    }

    if(n%2==0){
        for(int i=n; i>=2; i-=2)
            cout<<i<<" ";
        for(int i=n-1; i>=1; i-=2)
            cout<<i<<" ";
    }else{
        for(int i=n; i>=1; i-=2)
            cout<<i<<" ";
        for(int i=n-1; i>=2; i-=2)
            cout<<i<<" ";
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
