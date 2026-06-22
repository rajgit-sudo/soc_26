#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> ans(n, 0);
        set<int> setA;
        for(int i=0;i<n;i++){
            set<int> setB;
            setA.insert(A[i]);
            for(int j=0; j<=i; j++){
                setB.insert(B[j]);
            }

            int curr=0;
            for(int num: setA){
                if(setB.contains(num)){
                    curr++;
                }
            }
            ans[i] = curr;
        }
        return ans;
    }
};
