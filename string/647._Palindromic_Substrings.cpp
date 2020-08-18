class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        if (!s.size()) return ans;
        for (int i = 0; i < s.size(); ++i) {
//             回文的对称中心只能是一个字符，或者是两个字符如aba abba
            helper(s, i, i, ans);
            helper(s, i, i + 1, ans);
        }
        return ans;
    }
private:
    void helper(string s, int l, int r, int& count) {
        while (l >= 0 && r <= s.size() - 1 && s[l] == s[r]) {
            l--;
            r++;
            count++;
        }
    }
};