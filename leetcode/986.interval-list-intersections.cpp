#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int n1 = firstList.size();
        int n2 = secondList.size();
        int i=0, j=0;
        vector<vector<int>> ans;
        while(i<n1 && j<n2){
            int startA = firstList[i][0];
            int startB = secondList[j][0];
            int endA = firstList[i][1];
            int endB = secondList[j][1];
            if((startA <= endB) && (startB <= endA)){
                ans.push_back({max(startA, startB),  min(endA, endB)});
            }

            if(endA < endB)
                i++;
            else if(endA > endB)
                j++;
            else{
                i++; j++;
            }
        }
        return ans;
    }
};

/*
 * 986. Interval List Intersections
 * Difficulty: Medium
 * https://leetcode.com/problems/interval-list-intersections/
 *
 * ──────────────────────────────────────────────────
 *
 * You are given two lists of closed intervals, firstList and
 * secondList, where firstList[i] = [starti, endi] and secondList[j] =
 * [startj, endj]. Each list of intervals is pairwise disjoint and in
 * sorted order.
 *
 * Return the intersection of these two interval lists.
 *
 * A closed interval [a, b] (with a <= b) denotes the set of real
 * numbers x with a <= x <= b.
 *
 * The intersection of two closed intervals is a set of real numbers
 * that are either empty or represented as a closed interval. For
 * example, the intersection of [1, 3] and [2, 4] is [2, 3].
 *
 *
 *
 * Example 1:
 *
 * Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList =
 * [[1,5],[8,12],[15,24],[25,26]]
 * Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
 *
 * Example 2:
 *
 * Input: firstList = [[1,3],[5,9]], secondList = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 * 	• 0 <= firstList.length, secondList.length <= 1000
 *
 * 	• firstList.length + secondList.length >= 1
 *
 * 	• 0 <= starti < endi <= 10^9
 *
 * 	• endi < starti+1
 *
 * 	• 0 <= startj < endj <= 10^9
 *
 * 	• endj < startj+1
*/
