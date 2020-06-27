int lower_bound(vector<int> ary, int l, int r, int n) {
    int mid = l + (r - l) / 2;
    while (l < r) {
        if (ary[mid] < n) l = mid + 1;
        else r = mid;
    }
    return l;
}