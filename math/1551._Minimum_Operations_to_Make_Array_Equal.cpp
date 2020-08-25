class Solution {
public:
    int minOperations(int n) {
        int avg = n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int temp = 2 * i + 1;
            if (temp >= n) break;
            else ans += n - temp;
        }
        return ans;
    }
};