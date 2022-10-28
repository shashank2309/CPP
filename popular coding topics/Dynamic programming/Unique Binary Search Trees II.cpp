/*
Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.
*/
static const auto speedup = []()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution
{
public:
    vector<TreeNode*> f(int start, int end)
    {
        // if no more children  
        if(start > end)
        {
            // need NULL so size > 0 (if size == 0, l and r for loops won't iterate)
            // NOTE: {} = size 0, {NULL} = size 1, {NULL, NULL} = size 2, etc.
            return {NULL};
        }
        vector<TreeNode*> v;  // vector to store nodes
        // for all root values [start-end]
        for(int i = start; i <= end; i++)
        {
            vector<TreeNode*> l = f(start, (i - 1));  // vector to store left subtrees
            vector<TreeNode*> r = f((i + 1), end);  // vector to store right subtrees
            // left subtrees
            for(int j = 0; j < l.size(); j++)
            {
                // right subtrees
                for(int k = 0; k < r.size(); k++)
                {
                    // connect subtrees to head (i)
                    v.push_back(new TreeNode(i, l[j], r[k]));
                }
            }
        }
        return v;
    }
    
    vector<TreeNode*> generateTrees(int n)
    {
        return f(1, n);
    }
};
