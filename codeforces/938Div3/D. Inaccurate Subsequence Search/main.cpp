#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

vector<int> freq2(1e6+1, 0), freq1(1e6+1, 0);

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<int> a(n), b(m);
    for(int i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<m;i++){
        cin>>b[i];
        freq2[b[i]]++;
    }

    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(i>=m){
            int prev = a[i-m];
            if(freq1[prev] <= freq2[prev])
                count--;
            freq1[prev]--;
        }

        int curr = a[i];
        if(freq1[curr] < freq2[curr])
            count++;
        freq1[curr]++;

        if(i>=m-1){
            if(count>=k)
                ans++;
        }
    }
    cout<<ans<<"\n";

    for(int i = 0; i < m; i++) {
        freq2[b[i]] = 0;
    }
    for(int i = 0; i < n; i++) {
        freq1[a[i]] = 0;
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
