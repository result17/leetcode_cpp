class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, ans = 0;
        unordered_map<int, int> s;
        s[0]++;
        for (int n : nums) {
            sum += n;
            if (s.count(sum - k)) {
                ans += s[sum-k];
            }
            s[sum]++;
        }
        return ans;
    }
};