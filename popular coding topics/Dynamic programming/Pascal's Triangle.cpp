/* Leetcode Qno.118
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>v;
        vector<int>vrr;
        vrr.push_back(1);
        v.push_back(vrr);
        if(numRows>1){
        vrr.push_back(1);
        v.push_back(vrr);
        for(int i=2;i<numRows;i++)
        {
            vector<int>vr;
            vr.push_back(1);
            int k=i;
            for(int j=2;j<i+1;j++)
            {
                int n = v[k-1][j-2]+v[i-1][j-1];
                vr.push_back(n);
            }
            vr.push_back(1);
            v.push_back(vr);
        }
        }
        return v;
    }
};
