bool cmp(string& a , string& b)
{
   string x = a+b , y = b+a;
   return x>y;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>t;
        
        for(auto& x : nums)
            t.push_back(to_string(x));
        
        sort(t.begin(),t.end(),cmp);
        string ans = "";
        
        for(auto& x : t)
         ans+=x;
        
        if(ans[0] == '0')
            return "0";
        return ans;
    }
};
