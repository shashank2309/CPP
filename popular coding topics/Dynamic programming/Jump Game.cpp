/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    vector<int>dp;
    bool canJump(vector<int>& nums) 
    {
        dp.resize(nums.size(),-1);
        int idx=0;
        return fun(nums,idx);        
    }
    bool fun(vector<int>&nums,int idx)
    {
        if(idx >=nums.size())
        return 0;

        if(idx == nums.size()-1)
        return 1;

        if(dp[idx]!=-1)
        {
            return dp[idx];
        }

        int k = nums[idx];

        for(int i=1;i<=k;i++)
        {
            if(fun(nums,idx+i)==true)
            {
                return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
};
