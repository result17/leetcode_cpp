// https://www.bilibili.com/video/BV1PJ411j7in
// 异或运算也满足结合律，所以能使用前缀和这种形式
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(1, 0);
        for (int e : arr) {
            prefix.push_back(prefix.back() ^ e);
        }
        vector<int> ans;
        for (auto q : queries) {
            ans.push_back(prefix[q[0]] ^ prefix[q[1] + 1]);
        }
        return ans;
    }
};