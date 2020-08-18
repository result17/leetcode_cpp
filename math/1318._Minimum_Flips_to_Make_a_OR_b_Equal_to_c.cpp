class Solution {
public:
    int minFlips(int a, int b, int c) {
        int d = a | b;
        int ans = 0;
        for (int i = 31; i >= 0; --i) {
            if (((d >> i) & 1) == ((c >> i) & 1)) continue;
            if ((c >> i) & 1) ans++;
            else {
                if ((a >> i) & 1) ans++;
                if ((b >> i) & 1) ans++;
            }
        }
        return ans;
    }
};