#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

struct Interval{
    int start;
    int end;
    int originalIndex;

    Interval(int start, int end, int originalIndex) : start(start), end(end), originalIndex(originalIndex) {}
};

void solve() {
    int n; cin>>n;
    vector<Interval> nums;
    for(int i=0;i<n;i++){
        int start, end;
        cin>>start>>end;
        nums.emplace_back(Interval(start, end, i));
    }

    sort(nums.begin(), nums.end(), [](const Interval& a, const Interval& b){
        if(a.start == b.start)
            return a.end > b.end;
        return a.start < b.start;
    });

    vector<bool> containedInAnother(n, false), containingAnother(n, false);
    int maxSoFar = -1;
    for(int i=0;i<n;i++){
        Interval& curr = nums[i];
        if(maxSoFar >= curr.end)
            containedInAnother[curr.originalIndex] = true;
        maxSoFar = max(maxSoFar, curr.end);
    }

    int minSoFar = 1e9+5;
    for(int i=n-1; i>=0; i--){
        Interval& curr = nums[i];
        if(minSoFar <= curr.end)
            containingAnother[curr.originalIndex] = true;
        minSoFar = min(minSoFar, curr.end);
    }

    for(bool i: containingAnother)
        cout<<(i==true?1:0)<<" ";
    cout<<"\n";
    for(bool i: containedInAnother)
        cout<<(i==true?1:0)<<" ";
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
