class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
          int sum = 0;
        
        for(int i=0;i<prices.size()-1;i++)
        {
              int temp = prices[i+1] -prices[i];
              
            if(temp>0)
                sum+=temp;
        }
        
       
       
        return sum;
        
    }
};
// p link :- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
