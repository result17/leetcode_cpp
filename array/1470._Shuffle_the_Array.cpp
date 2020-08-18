// in-place is diffcult
// https://leetcode.com/problems/shuffle-the-array/discuss/675956/In-Place-O(n)-Time-O(1)-Space-With-Explanation-and-Analysis

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = n - 1;
        for (auto j = nums.size() - 1; j >= n; --j) {
            nums[j]<<=10;
            nums[j] |= nums[i];
            i--;
        }
        i = 0;
        for (int j = n; j < nums.size(); ++j) {
            const int num1 = nums[j] & 1023;
            const int num2 = nums[j] >> 10;
            nums[i] = num1;
            nums[i + 1] = num2;
            i += 2;
        }
        return nums;
    }
};