#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int ceil(int a, int b){
    return (a+b-1)/b;
}

void solve() {
    int a, b, x; cin>>a>>b>>x;
    int ans = abs(a-b);
    int basecase = ceil(a, x) + ceil(b, x);
    if(a%x==0)
        basecase++;
    if(b%x==0)
        basecase++;
    ans = min(ans, basecase);
    if(a<b)
        swap(a, b);

    int c=0;
    while(true){
        if(a<b)
            swap(a, b);
        ans = min(ans, c + abs(a-b));
        if(a==b)
            break;

        a/=x;
        c++;
    }

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
