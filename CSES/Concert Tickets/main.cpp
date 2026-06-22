#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;
    vector<int> actualPrice(n), maxPrice(m);
    for(int i=0;i<n;i++)
        cin>>actualPrice[i];
    for(int i=0;i<m;i++)
        cin>>maxPrice[i];

    multiset<int> maxPrices(actualPrice.begin(), actualPrice.end());
    for(int customerMaxPrice: maxPrice){
        auto it = maxPrices.upper_bound(customerMaxPrice);
        if(it==maxPrices.begin()){ // maxPrice is too low, cannot sell him ticket
            cout<<"-1\n";
            continue;
        }
        --it;
        cout<<*it<<"\n";
        maxPrices.erase(it);
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
