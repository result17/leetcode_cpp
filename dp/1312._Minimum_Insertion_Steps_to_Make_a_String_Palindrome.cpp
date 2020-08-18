// 此题关键在于寻找最长回文子串
class Solution {
public:
    int minInsertions(string s) {
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i)
            dp[i][i] = 1;
        for (int n = 2; n <= len; ++n) {
            for (int l = 0, r = n - 1; r < len; ++l, ++r) {
                dp[l][r] = max(dp[l + 1][r], dp[l][r - 1]);
                if (s[l] == s[r]) {
                    int tmp = l + 1 <= r -1 ? dp[l + 1][r - 1] : 0;
                    dp[l][r] = max(dp[l][r], tmp + 2);
                }
            }
        }
        return len - dp[0][len - 1];
    }
};