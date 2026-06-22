#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int x; cin>>x;

    if((x&(x-1))==0){
        cout<<-1<<"\n";
        return;
    }

    bool flag1=false, flag2=false;

    int ans=0;
    for(int i=0;i<32;i++){
        if(flag1 && flag2){
            break;
        }

        if(x&(1<<i)){ // ith bit is set
            if(!flag1){
                ans|=(1<<i);
                flag1=true;
            }
        }else{
            if(!flag2){
                ans|=(1<<i);
                flag2=true;
            }
        }

    }

    if(flag1 && flag2)
        if(ans<x)
            cout<<ans;
        else
            cout<<-1;
    else
        cout<<-1;

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
