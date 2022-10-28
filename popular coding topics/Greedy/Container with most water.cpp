class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int i=0,j=height.size()-1;
        int max_area = 0;
        int area = 0;
        while(i!=j)
        {
          area = (j-i)*min(height[j],height[i]);
          
         max_area = max(area,max_area);
            
            if(height[j]>height[i])
                i++;
            
            else
                j--;
        
        }
        
        return max_area;
        
        
        
    }
};
P.Link :- https://leetcode.com/problems/container-with-most-water/
