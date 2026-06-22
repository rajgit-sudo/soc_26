#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans; ans.resize(n1);
        unordered_map<int, int> orderMap, freqMap;
        for(int i=0;i<n2;i++)
            orderMap[nums2[i]]=i;
        for(int i: nums1)
            freqMap[i]++;

        for(int i: nums2){
            int count = freqMap[i];
            while(count--){
                ans.push_back(i);
            }
        }

        //need to fill in the leftovers now
        vector<int> leftOvers; leftOvers.reserve(n1);
        for(int i: nums1){
            if(!orderMap.contains(i))
                leftOvers.push_back(i);
        }
        sort(leftOvers.begin(), leftOvers.end());
        ans.insert(ans.end(), leftOvers.begin(), leftOvers.end());
        return ans;
    }
};

/*
 * 1122. Relative Sort Array
 * Difficulty: Easy
 * https://leetcode.com/problems/relative-sort-array/
 *
 * ──────────────────────────────────────────────────
 *
 * Given two arrays arr1 and arr2, the elements of arr2 are distinct,
 * and all elements in arr2 are also in arr1.
 *
 * Sort the elements of arr1 such that the relative ordering of items in
 * arr1 are the same as in arr2. Elements that do not appear in arr2
 * should be placed at the end of arr1 in ascending order.
 *
 *
 *
 * Example 1:
 *
 * Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
 * Output: [2,2,2,1,4,3,3,9,6,7,19]
 *
 * Example 2:
 *
 * Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
 * Output: [22,28,8,6,17,44]
 *
 *
 *
 * Constraints:
 *
 * 	• 1 <= arr1.length, arr2.length <= 1000
 *
 * 	• 0 <= arr1[i], arr2[i] <= 1000
 *
 * 	• All the elements of arr2 are distinct.
 *
 * 	• Each arr2[i] is in arr1.
*/
