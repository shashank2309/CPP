/*
problem statement:-
Given the head of a singly linked list, reverse the list, and return the reversed list.

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
    ListNode* reverseList(ListNode* head) {
      //recursive solution
        
        if(head==NULL||head->next==NULL) return head;
        
        //induciton step
        ListNode *newHead = reverseList(head->next);
        
        //Induction Hypothesis
        ListNode *headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        
        
        return newHead;
        
    }
};

//problem link :- https://leetcode.com/problems/reverse-linked-list/
