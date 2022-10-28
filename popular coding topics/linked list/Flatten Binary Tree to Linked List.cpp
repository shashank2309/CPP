/*
problem statement:-
Given the root of a binary tree, flatten the tree into a "linked list":

The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
The "linked list" should be in the same order as a pre-order traversal of the binary tree.

solution:_
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
class Solution {
public:
    void flatten(TreeNode* root) {
        
        TreeNode *cur = root;
        
        while(cur!=NULL)
        {
            if(cur->left!=NULL)
            {
                TreeNode * prev = cur -> left;
                while(prev->right)
                {
                    prev = prev -> right;
                }
                prev->right = cur -> right;
                cur->right = cur ->left;
                cur->left = NULL;
            }
            cur = cur->right;
        }
        
    }
};

//problem link :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
