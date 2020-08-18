class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        vector<int> dp;
        for (int n : nums) {
            auto idx = std::lower_bound(dp.begin(), dp.end(), n);
            if (idx == dp.end()) dp.push_back(n);
            else *idx = n;
        }
        return dp.size();
    }
};