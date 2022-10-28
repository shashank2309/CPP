class Solution {
public:
    bool canJump(vector<int>& nums) {
        
       
        
        int n = nums.size();
        
        
        if( n!=1 && !nums[0])
            return false;
        
//         vector<bool>visited(n,false);
//         visited[0]=true;
        
        int maxm = 0;
        for(int i=0;i<n;i++)
        {
            if(maxm<i)
                return false;
            
            if(maxm<i+nums[i])
                maxm=i+nums[i];
            
            if(maxm>=n-1)
                return true;
        }
        
        return false;
        
    }
};

//https://leetcode.com/problems/jump-game/
