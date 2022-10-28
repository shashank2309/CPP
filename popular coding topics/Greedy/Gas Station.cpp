class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        
    
        
        
        long  sum = 0 , total = 0;
        int idx= 0;
        
        for(int i = 0 ; i<n;i++)
        {
            sum+= gas[i] - cost[i];
            total += gas[i] - cost[i];
            
            if(total < 0)
            { idx = (i + 1) % n;  total = 0;}
        }        
       
        
        if(sum < 0)
            return -1;

        
        return idx;
    
    }
};
