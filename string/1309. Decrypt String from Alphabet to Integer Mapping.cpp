// 从后面遍历更方便处理，注意char转化，char - '0' 转化为int
class Solution {
public:
    string freqAlphabets(string s) {
        int len = s.length();
        int i = len - 1;
        string ans;
        while (i >= 0) {
            int c = 0;
            if (s[i] == '#') {
                i--;
                c = s[i] - '0';
                i--;
                c += (s[i] - '0') * 10;
            } else {
                c = s[i] - '0';
            }
            i--;
            ans += (char) c - 1 + 'a';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};