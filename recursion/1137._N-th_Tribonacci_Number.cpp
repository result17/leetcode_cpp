class Solution {
public:
    int tribonacci(int n) {
        if (n <= 2) {
            return  n ? 1 : 0;
        }
        
        int prev_p = 0;
        int prev = 1;
        int cur = 1;
        for (int i = 3; i <= n; ++i) {
            int temp1 = cur;
            int temp2 = prev;
            cur += prev + prev_p;
            prev = temp1;
            prev_p = temp2; 
        }
        return cur;
    }
};