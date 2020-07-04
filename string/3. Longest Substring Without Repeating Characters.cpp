class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // start应该为-1，想想单个字符的情况
        int ans = 0, start = -1, end = 0;
        if (!s.size()) return ans;
        vector<int> charIdx(128, -1);
        for (;end < s.size(); ++end) {
            // 利用char转为int构建了一个特殊的hash table
            start = max(start, charIdx[s[end]]);
            ans = max(ans, end - start);
            charIdx[s[end]] = end;
        }
        return ans;
    }
};