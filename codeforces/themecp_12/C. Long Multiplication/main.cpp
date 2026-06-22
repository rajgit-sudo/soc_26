#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int convert(char x){
    return (x-'0');
}

void solve() {
    string x, y; cin>>x>>y;
    int n = x.size();

    int start=0;
    while(x[start] == y[start])
        start++;

    if(start<n && convert(x[start]) < convert(y[start]))
        swap(x, y);

    for(int i=start+1; i<n;i++){
        char str1 = x[i];
        char str2 = y[i];

        if(convert(str1) > convert(str2)){
            x[i] = str2;
            y[i] = str1;
        }
    }

    cout<<x<<"\n"<<y<<"\n";
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
