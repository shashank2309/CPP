/*
Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m non-empty substrings respectively, such that:

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
Note: a + b is the concatenation of strings a and b.
*/
class Solution {
public:
    // int dp[102][102];
    bool helper(string& s1, string& s2, string &s3, int l1, int l2, int l3, vector<vector<int>>&dp) {
        if(l1<0 && l2<0 && l3<0) {
            return true;
        }
        if(l1>=0 && l2>=0 && dp[l1][l2]!=-1) {
            return dp[l1][l2];
        }
        if(l1>=0 && s1[l1]==s3[l3] && l2>=0 && s2[l2]==s3[l3] ) {
            return dp[l1][l2] = (helper(s1, s2, s3, l1-1, l2, l3-1, dp) || helper(s1, s2, s3, l1, l2-1, l3-1, dp));
        }
        else if(l1>=0 && s1[l1]==s3[l3])
            return helper(s1, s2, s3, l1-1, l2, l3-1, dp);
        
        else if(l2>=0 &&s2[l2]==s3[l3])
            return helper(s1, s2, s3, l1, l2-1, l3-1, dp);
        
        else return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size())
			return false;
        vector<vector<int>>dp(s1.size()+1, (vector<int>(s2.size()+1, -1)));
        // memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3,s1.size()-1, s2.size()-1, s3.size()-1, dp);
    }
};
