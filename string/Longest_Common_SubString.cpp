class Solution {
public:
    int longestCommonSubString(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));
        int ans;
        for (int i = 0; i < text1.size(); ++i) {
            for (int j = 0; j < text2.size(); ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    ans = max(dp[i + 1][j + 1], ans);
                } else {
                    dp[i + 1][j + 1] = 0
                }
            }
        }
    }
    return ans;
}