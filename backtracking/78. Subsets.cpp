class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        if (!nums.size()) return ans;
        subsets(ans, nums, sub, 0);
        return ans;
    }
private:
    void subsets(vector<vector<int>> &ans, vector<int> nums, vector<int> &sub, int i) {
        ans.push_back(sub);
        for (; i < nums.size(); ++i) {
            sub.push_back(nums[i]);
            subsets(ans, nums, sub, i + 1);
            sub.pop_back();
        }
    }
};

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> sub;
        if (!nums.size()) return ans;
        subsets(ans, nums, sub, 0);
        return ans;
    }
private:
    void subsets(vector<vector<int>> &ans, vector<int> nums, vector<int> &sub, int i) {
        if (i == nums.size()) {
            ans.push_back(sub);
            return;
        }
        sub.push_back(nums[i]);
        subsets(ans, nums, sub, i + 1);
        sub.pop_back();
        subsets(ans, nums, sub, i + 1);
    }
};