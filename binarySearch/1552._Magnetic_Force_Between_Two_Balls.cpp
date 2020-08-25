class Solution {
public:
    int check(vector<int> & position, int mid, int n, int m) {
        int cnt = 1;
        int pre = position[0];
        for (int i = 1; i < n; ++i) {
            if (position[i] - pre >= mid) {
                cnt++;
                pre = position[i];
                if (cnt == m) return 1;
            }
        }
        return 0;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int left = 1;
        int right = position.back();
        int n = position.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (check(position, mid, n, m)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left - 1;
    }
    
};