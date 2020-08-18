class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans = 0, sum = 0;
        vector<int> p(nums.size() + 1, 0);
        p[0] = 1;
        for (int n : nums) {
            if (n % 2) {
                sum++;
            }
            p[sum]++;
            if (sum >= k) ans += p[sum - k];
        }
        return ans;
    }
};