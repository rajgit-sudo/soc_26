#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, k; cin>>n>>k;
    vector<int> a(n), b(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        cin>>b[i];

    sort(a.begin(), a.end());
    int ans=0;
    b.insert(b.end(), a.begin(), a.begin()+k);
    sort(b.rbegin(), b.rend());

    for(int i=0;i<k;i++)
        ans+=b[i];
    for(int i=k; i<n;i++)
        ans+=a[i];
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
