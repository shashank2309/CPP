/*
problem link:-
Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

Do not modify the linked list.

solution:-
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return NULL;
        ListNode *tortoise = head, *rabbit = head;
        
        bool cycle = false;
        while (rabbit->next && rabbit->next->next) {
            tortoise = tortoise->next;
            rabbit = rabbit->next->next;
            if (tortoise == rabbit)
            {
                cycle = true;
                break;
            }
                
        }
        if(cycle)
        {
            ListNode *temp = head;
        
            while(temp!=tortoise){
            tortoise = tortoise->next;
            temp = temp->next;
            }
        
            return temp;
        }
        return NULL;  
    }
};


        
        
//problem link :- https://leetcode.com/problems/linked-list-cycle-ii/
