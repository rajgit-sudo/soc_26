#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> nums(n);
    vector<int> pos(n+1);
    for(int i=0;i<n;i++){
        cin>>nums[i];
        pos[nums[i]] = i;
    }

    int ans=1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1])
            ans++;
    }

    for(int i=0;i<m;i++){
        int l, r; cin>>l>>r;
        if(l==n){
            cout<<ans<<"\n";
            continue;
        }

        int a = nums[l-1], d = nums[r-1];
        if(l==r-1){
            if(a>d) // was not set
                ans--;
            else
                ans++;

            cout<<ans<<"\n";
            continue;
        }

        int b = nums[l];
        int c = nums[r-2];
        if(a<b){ // was already set
            if(b<d)
                ans++;
        }else if(a>b){ // was not set
            if(d<b)
                ans--;
        }

        if(c<d){ // was already set
            if(c>a)
                ans++;
        }else{ // was not set
            if(c<a)
                ans--;
        }

        cout<<ans<<"\n";
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
