

class Solution {
public:
    int n , m ;
    vector<vector<int>>dp;
    bool recurr(int i , int j , string& s , string& p)
    {
        if(i >= n && j >= m)
            return dp[i][j] = true;
        
        if(j >= m)
            return dp[i][j] = false;
        
        if(i>=n)
        {
            for(int l = j;l<m;l++)
                if(p[l] != '*')
                    return false;
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        bool curr =  (s[i] == p[j]  || p[j] == '?');
        dp[i][j] = false;
        
        
        if(curr)
        { dp[i][j] = recurr(i+1,j+1,s,p);}
        
        else  if(p[j] == '*')
        dp[i][j] = recurr(i,j+1,s,p) | recurr(i+1,j,s,p);
        
        
        else
            return dp[i][j] = false;
        
            return dp[i][j];
    }
    
    bool isMatch(string s, string p) {
        n = s.length() , m = p.length();
        dp.resize(n+5,vector<int>(m+5,-1));
        
        return recurr(0,0 , s ,p);
    }
};
P.link:-https://leetcode.com/problems/wildcard-matching/
