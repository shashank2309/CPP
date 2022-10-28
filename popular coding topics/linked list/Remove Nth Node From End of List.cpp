/*
problem statement:-
Given the head of a linked list, remove the nth node from the end of the list and return its head.

solution:-

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        
        int len=1;
        
        ListNode *temp = head, *temp2=head;
        
        while(temp!=NULL)
        {
            len++;
            temp = temp->next;
        }
        
        
        
        if(len==n)
        {
            temp2 = temp2->next;
            return temp2;
        }
        len = len-n;
        for(int i=1;i<len-1;i++)
        {
            temp2 = temp2->next;
        }
        temp2->next = temp2->next->next;
        
        return head;
    }
};


//problem link :- https://leetcode.com/problems/remove-nth-node-from-end-of-list/
