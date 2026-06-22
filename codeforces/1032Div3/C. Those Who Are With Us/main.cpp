#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;

void solve() {
    int n, m; cin>>n>>m;

    vector<vector<int>> nums(n, vector<int>(m));
    int maxValue = 0, maxValueFreq=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>nums[i][j];

            if(nums[i][j] > maxValue){
                maxValue = nums[i][j];
                maxValueFreq = 1;
            }else if(nums[i][j] == maxValue){
                maxValueFreq++;
            }
        }
    }
    if(n==1 && m==1){
        cout<<nums[0][0]-1<<"\n";
        return;
    }

    if(maxValueFreq==1){
        cout<<maxValue-2<<"\n";
    }else if(maxValuef{
        cout<<maxValue-1<<"\n";
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
