/*
problem statement:-
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

solution :-
*/

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
    ListNode* deleteDuplicates(ListNode* head) {
    ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        int duplicate;
        while (cur->next && cur->next->next) {
            if (cur->next->val == cur->next->next->val) {
                duplicate = cur->next->val;
                while (cur->next && cur->next->val == duplicate) {
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};


//problem link :- https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
