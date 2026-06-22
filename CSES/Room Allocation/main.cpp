#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
using namespace std;
using ll=long long;

struct Interval{
    int start, end, idx;
};

void solve() {
    int n; cin>>n;
    vector<Interval> intervals; intervals.reserve(n);
    for(int i=0;i<n;i++){
        int start, end; cin>>start>>end;
        intervals.emplace_back(Interval(start, end, i));
    }

    sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b){
        if(a.start == b.start)
            return a.end < b.end;
        return a.start < b.start;
    });

    int length=0;
    vector<int> ans(n, -1);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(const Interval& i: intervals){
        if(pq.empty()){
            length++;
            int roomId = length;
            pq.push({i.end, roomId});
            ans[i.idx] = roomId;
        }else{
            if(pq.top().first >= i.start){ // room isnt empty
                length++;
                int roomId = length;
                pq.push({i.end, roomId});
                ans[i.idx] = roomId;
            }else{ // room is empty now
                int roomId = pq.top().second;
                pq.pop();
                pq.push({i.end, roomId});
                ans[i.idx] = roomId;
            }
        }

        length = max(length, int(pq.size()));
    }

    cout<<length<<"\n";
    for(int i: ans)
        cout<<i<<" ";
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
