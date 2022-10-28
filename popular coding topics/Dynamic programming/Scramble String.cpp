/*
We can scramble a string s to get a string t using the following algorithm:
If the length of the string is 1, stop.
If the length of the string is > 1, do the following:
Split the string into two non-empty substrings at a random index, i.e., if the string is s, divide it to x and y where s = x + y.
Randomly decide to swap the two substrings or to keep them in the same order. i.e., after this step, s may become s = x + y or s = y + x.
Apply step 1 recursively on each of the two substrings x and y.
Given two strings s1 and s2 of the same length, return true if s2 is a scrambled string of s1, otherwise, return false.
*/
class Solution {
   public:
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        bool dp[n][n][n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (s1[i] == s2[j]) {
                    dp[i][j][0] = true;
                }
            }
        }

        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                for (int j = 0; j <= n - len; j++) {
                    for (int len1 = 1; len1 <= len - 1; len1++) {
                        int len2 = len - len1;
                        dp[i][j][len - 1] |= dp[i][j][len1 - 1] && dp[i + len1][j + len1][len2 - 1];
                        dp[i][j][len - 1] |= dp[i][j + len2][len1 - 1] && dp[i + len1][j][len2 - 1];
                    }
                }
            }
        }
        return dp[0][0][n - 1];
    }
};
