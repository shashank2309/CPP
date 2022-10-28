/*
Leetcode Qno. 119
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/

class Solution {
public:
  vector<int> getRow(int rowIndex)
  {
  vector<vector<int>> result(rowIndex+1);
  int i;
  for(i=0;i<=rowIndex;i++)
  {
      result[i].resize(i+1);
      result[i][0]=result[i][i]=1;
      for(int j=1;j<i;j++)
      {
          result[i][j]=result[i-1][j-1]+result[i-1][j];
      }
  }
      return result[i-1]; 
    }
};
