#include <bits/stdc++.h>
#include <queue>
#include <unordered_set>
using namespace std;
using ll=long long;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives=0, tens=0;
        for(int bill: bills){
            if(bill==5){
                fives++;
            }else if(bill==10){
                if(fives<=0)
                    return false;
                fives--;
                tens++;
            }else{
                if(tens>0 && fives>0){
                    tens--; fives--;
                }else if(fives>2){
                    fives-=3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};
