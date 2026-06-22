#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    int maxElement=0, minElement=6;
    for(int i=0;i<n;i++){
        int a; cin>>a;
        maxElement = max(maxElement, a);
        minElement = min(minElement, a);
    }
    cout<<maxElement-minElement+1<<"\n";
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
