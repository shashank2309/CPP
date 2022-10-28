/*
problem link :-

Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

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
        if(head == NULL){
            return NULL;
        }
        
        ListNode *temp= head;
        ListNode *nextPtr;
        
        while(temp->next != NULL){
            if(temp->val == temp->next->val){
                nextPtr= temp->next->next;
                delete(temp->next);
                temp->next= nextPtr;
            }
            else{
                temp= temp->next;
            }
        }
        
        return head;
    }
};

//probelm link :- https://leetcode.com/problems/remove-duplicates-from-sorted-list/
