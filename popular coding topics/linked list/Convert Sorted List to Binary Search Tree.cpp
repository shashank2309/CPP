/*
problem link :-
Given the head of a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include<bits/stdc++.h>
class Solution {
private:
    TreeNode* bst(vector<int> &v,int s , int e)
    {
        //base case
        if(s>e) return NULL;
        int mid = (s+e+1)/2;
        
        TreeNode *temp = new TreeNode(v[mid]);
        temp->left = bst(v,s,mid-1);
        temp->right = bst(v,mid+1,e);
        
        return temp;
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        int len = 0;
        while(head)
        {
            v.push_back(head->val);
            head = head->next;
            len++;
        }
        int start = 0;
        int end = len -1;
        
        return bst(v,start,end);
    }
};


//problem link :- https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
