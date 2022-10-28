/*
Given two strings s and t, return the number of distinct subsequences of s which equals t.
A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).
The test cases are generated so that the answer fits on a 32-bit signed integer.
*/
int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<double>dp(m+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = m; j > 0; j--) {
                if(s[i-1] == t[j-1]) dp[j] = dp[j-1] + dp[j];
            }
        }
        return dp[m];    
    }
