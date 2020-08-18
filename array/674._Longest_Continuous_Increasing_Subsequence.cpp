class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (!nums.size()) return 0;
        int res = 1, cout = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] < nums[i]) res = max(res, ++cout);
            else cout = 1;
        }
        return res;
    }
};