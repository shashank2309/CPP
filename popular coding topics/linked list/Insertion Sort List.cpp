/*
problem statement:-
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:

Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm. The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.


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

    ListNode* insertionSortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        
       
        vector <int> arr;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        
        sort(arr.begin(),arr.end());
        temp = head;
        int i=0;
        while(temp!=NULL)
        {
            temp ->val = arr[i++];
            temp = temp->next;
        }
        
        return head;
       
    }
};

//problem link :- https://leetcode.com/problems/insertion-sort-list/
