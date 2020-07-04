class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, cur = 0;
        int t = threshold * k;
        vector<int> ps{0};
        for (int n : arr) {
            cur += n;
            ps.push_back(cur);
        }
        for (int i = 0; i < ps.size() - k; ++i) {
            if (ps[i + k] - ps[i] >= t) ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int ans = 0, cur = 0;
        int t = threshold * k;
        for (int i = 0; i < k; ++i) {
            cur += arr[i];
        }
        if (cur >= t) ans++;
        for (int i = k; i < arr.size(); ++i) {
            cur += arr[i];
            cur -= arr[i - k];
            if (cur >= t) ans++;
        }
        return ans;
    }
};