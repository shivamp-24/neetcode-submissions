class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int pick = 0;
                if(text1[i] == text2[j]) pick = 1 + dp[i+1][j+1];

                int skip = max(dp[i+1][j], dp[i][j+1]);

                dp[i][j] = max(pick, skip);
            }
        }
        return dp[0][0];
    }
};
