class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& A) {
        int n = A[0].size(), m = A.size();
        vector<vector<int>> ans(n, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                ans[j][i] = A[i][j];
            }
        }
        return ans;
    }
};