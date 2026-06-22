#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    unordered_map<int, vector<int>> map;
    for(int i=1;i<=2*n;i++){
        int a; cin>>a;
        map[a].push_back(i);
    }

    int positionA=1, positionB=1;
    int num=0;

    ll ans=0;
    while(num!=n){
        int lookingFor = num+1;
        vector<int> positions = map[lookingFor];
        int nextPosition1 = positions[0], nextPosition2 = positions[1];

        ll distance1 = abs(positionA-nextPosition1) + abs(positionB-nextPosition2);
        ll distance2 = abs(positionA-nextPosition2) + abs(positionB-nextPosition1);

        if(distance1<=distance2){
            ans+=distance1;
            positionA = nextPosition1;
            positionB = nextPosition2;
        }else{
            ans+=distance2;
            positionA = nextPosition2;
            positionB = nextPosition1;
        }
        num++;
    }
    cout<<ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in1.txt", "r", stdin);
    // freopen("res1.txt", "w", stdout);


    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
