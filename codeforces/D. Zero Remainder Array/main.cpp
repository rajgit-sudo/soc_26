#include <bits/stdc++.h>
#include <cstdio>
#include <pthread.h>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    unordered_multiset<int> ms;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        if(a%k!=0)
            ms.insert(a%k);
    }

    if(ms.empty()){
        cout<<0<<"\n";
        return;
    }

    int ans=1;
    int x=1;
    while(!ms.empty()){
        if(ms.count(k-x) > 0){
            ms.erase(ms.find(k-x));
        }
        x = (x+1)%k;
        ans++;
    }
    cout<<ans<<"\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in2.txt", "r", stdin);
    // freopen("res2.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
