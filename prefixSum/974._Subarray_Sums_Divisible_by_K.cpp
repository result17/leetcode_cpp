class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        vector<int> count(K, 0);
        count[0] = 1;
        int prefixDiv = 0, ans = 0;
        for (int a : A) {
            prefixDiv = (prefixDiv + (a % K + K)) % K;
            ans += count[prefixDiv]++;
        }
        return ans;
    }
};