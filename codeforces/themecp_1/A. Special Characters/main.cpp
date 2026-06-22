#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    string s="";
    string aa = "AAA";
    string bb = "BBB";

    int turn = 1;
    if(n%2==0){
        n/=2;
        while(n--){
            if(turn==1)
                s+=aa;
            else
                s+=bb;
            turn*=-1;
        }
        cout<<"YES\n";
        cout<<s<<"\n";
        return;
    }else{
        cout<<"NO\n";
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
