class Solution {
public:
    string removeDuplicateLetters(string str) {
        string ans = "";
        set<char>s;
        
     
        for(auto& x : str)
        {
            if(!s.count(x)){
                ans.push_back(x);
                s.insert(x);
            }
            
            else
            {
                int j = 0 ,idx = 0;
                
                while(ans[j] != x) j++;
                idx = j;
                j++;
                bool p = 0, xx = 1;
                while(j<ans.size())
                {
                    if(ans[j++] < x && xx) p = 1;
                    else xx = 0;
                }
                if(p)
                {
                    ans.erase(ans.begin() + idx);
                    ans.push_back(x);
                }
            }
            

            // cout<<ans<<endl;
         }

  
        return ans;
    }
};
