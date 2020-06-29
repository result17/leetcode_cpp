class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> fac;
        int sqr = sqrt(n);
        for (int d = 1; d <= sqr; ++d) {
            if (n % d == 0) {
                if (--k == 0) return d;
                fac.push_back(d);
            }
        }
        // avoid n = 2
        if (sqr * sqr == n) ++k;
        return k > fac.size() ? -1 : n / fac[fac.size() - k];
    } 
};