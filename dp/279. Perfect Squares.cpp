class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n + 1; i++) {
            for (int j = 1; j * j <= i; ++j) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp.back();
    }
};

// 为什么优化这么多？
class Solution {
public:
    int numSquares(int n) {
        static vector<int> dp({0});
        while (dp.size() < n + 1) {
            int val = INT_MAX;
            int s = dp.size();
            for (int i = 1; i * i <= s; ++i) val = min(val, dp[s - i * i] + 1);
            dp.push_back(val);
        }
        return dp[n];
    }
};