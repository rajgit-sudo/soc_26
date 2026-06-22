#include <bits/stdc++.h>
#include <cmath>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n; cin>>n;
    map<int, int> map;
    multiset<int> set;
    for (int i=0; i<n; i++){
        int a; cin>>a;
        map[a]++;
        set.insert(a);
    }
    // sort(nums.begin(), nums.end());

    int elementScoreTwo=-1;
    for(auto p: map){
        if(p.second >= 4){
            cout<<p.first<<" "<<p.first<<" "<<p.first<<" "<<p.first<<"\n";
            return;
        }

        if(p.second >= 2){
            if(elementScoreTwo==-1)
                elementScoreTwo = p.first;
            else{
                cout<<p.first<<" "<<p.first<<" "<<elementScoreTwo<<" "<<elementScoreTwo<<"\n";
                return;
            }
        }
    }

    if(elementScoreTwo==-1){
        cout<<"-1\n";
        return;
    }


    set.erase(set.find(elementScoreTwo));
    set.erase(set.find(elementScoreTwo));

    vector<int> nums(set.begin(), set.end());
    for(int i=0;i<int(nums.size())-1;i++){
        if(elementScoreTwo > (abs(nums[i] - nums[i+1])/2)){
            cout<<elementScoreTwo<<" "<<elementScoreTwo<<" "<<nums[i]<<" "<<nums[i+1]<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("in2.txt", "r", stdin);
    // freopen("res2.txt", "w", stdout);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
