#include <bits/stdc++.h>
#include <vector>
using namespace std;
using ll=long long;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isIt(vector<int>& nums){
        int i=0, j=int(nums.size())-1;
        while(i<=j){
            if(nums[i]!=nums[j])
                return false;
            i++; j--;
        }
        return true;
    }

    bool isPalindrome(ListNode* head) {
        vector<int> list;
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        return isIt(list);
    }
};

/*
 * 234. Palindrome Linked List
 * Difficulty: Easy
 * https://leetcode.com/problems/palindrome-linked-list/
 *
 * ──────────────────────────────────────────────────
 *
 * Given the head of a singly linked list, return true if it is a
 * palindrome or false otherwise.
 *
 *
 *
 * Example 1:
 *
 * Input: head = [1,2,2,1]
 * Output: true
 *
 * Example 2:
 *
 * Input: head = [1,2]
 * Output: false
 *
 *
 *
 * Constraints:
 *
 * 	• The number of nodes in the list is in the range [1, 10^5].
 *
 * 	• 0 <= Node.val <= 9
 *
 *
 *
 * Follow up: Could you do it in O(n) time and O(1) space?
*/
