#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0), outDegree(n, 0);
        for(const vector<int>& row: trust){
            inDegree[row[1]-1]++;
            outDegree[row[0]-1]++;
        }

        for(int i=0;i<n;i++){
            if(inDegree[i]==n-1 && outDegree[i]==0)
                return i+1;
        }
        return -1;
    }
};
