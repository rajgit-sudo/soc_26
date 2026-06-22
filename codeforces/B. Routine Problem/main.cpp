#include <bits/stdc++.h>
using namespace std;
using ll=long long;

void solve() {
    int a,b,c,d; cin>>a>>b>>c>>d;

    int alpha = b*c;
    int beta = a*d;

    if(alpha==beta){
        cout<<"0/1";
        return;
    }

    if(alpha<beta)
        swap(alpha, beta);

    int nume = alpha - beta;
    int deno = alpha;
    int divisor = gcd(nume, deno);
    cout<<nume/divisor<<"/"<<deno/divisor;
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
