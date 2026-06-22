#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m, k; cin>>n>>m>>k;
    vector<int> desired(n), actual(m);
    for(int i=0;i<n;i++)
        cin>>desired[i];
    for(int i=0;i<m;i++)
        cin>>actual[i];

    sort(desired.begin(), desired.end());
    sort(actual.begin(), actual.end());

    int ans=0;
    int i=0; //index for the desired vector
    int j=0; //index for actual vector
    while(i<n && j<m){
        int desiredSize = desired[i], actualSize = actual[j];
        if((desiredSize-k <= actualSize) && (actualSize <= desiredSize+k)){
            ans++; i++; j++;
        }else if(desiredSize-k > actualSize){ // actualSize is too small, nobody can use it
            j++;
        }else{
            i++;
        }
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in2.txt", "r", stdin);
    // freopen("res2.txt", "w", stdout);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
