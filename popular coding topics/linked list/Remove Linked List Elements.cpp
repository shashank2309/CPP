/*
problem statement:-
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL) 
        {
            
            return NULL;
        }
        
        
        
        //Induction step 
        
        head->next = removeElements(head->next, val);
        //and  Hypothesis
        
        
        return head->val == val ? head->next : head;
        
    }
};

//problem link :- https://leetcode.com/problems/remove-linked-list-elements/
