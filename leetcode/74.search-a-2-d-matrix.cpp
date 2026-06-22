#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=(matrix[0]).size();

        int low=0, high=n*m-1, mid;
        while(low<=high){
            mid = midpoint(low, high);
            
            int r = mid/m;
            int c = mid%m;
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return false;
    }
};
// @lc code=end

