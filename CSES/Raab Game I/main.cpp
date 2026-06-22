#include <bits/stdc++.h>
#include <complex>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, a, b; cin>>n>>a>>b;
    if((a+b)>n || (a==0 && b!=0) || (a!=0 && b==0)){
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    vector<int> p1(n), p2(n);
    for(int i=1; i<=n; i++)
        p1[i-1] = p2[i-1] = i;


    if(a+b>0){
        int draws = n- (a+b);
        rotate(p1.begin() + draws, p1.begin()+ draws + b, p1.end());
    }

    for(int i=0;i<n;i++)
        cout<<p1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<p2[i]<<" ";
    cout<<"\n";
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


// 4 1 2
// 1 2 3 4
// 2 3 1 4
//
// 4 2 2
// 1 2 3 4
// 4 3 2 1
