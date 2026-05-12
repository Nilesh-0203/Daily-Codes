class Solution {
  long long lcm(long long a, long long b) {
        return ((a * b) / __gcd(a, b));
    }
    void build(int x, int lx, int rx, vector<int> &arr, vector<long long> &seg) {
        if(rx - lx == 1) {
            if(lx < arr.size()) seg[x] = arr[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(2 * x + 1, lx, m, arr, seg);
        build(2 * x + 2, m, rx, arr, seg);
        seg[x] = lcm(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void update(int x, int lx, int rx, int &idx, int &val, vector<long long> &seg) {
        if(rx - lx == 1) {
            seg[x] = val;
            return;
        }
        int m = (lx + rx) / 2;
        if(idx < m) update(2 * x + 1, lx, m, idx, val, seg);
        else update(2 * x + 2, m, rx, idx, val, seg);
        seg[x] = lcm(seg[2 * x + 1], seg[2 * x + 2]);
    }
    long long query(int x, int lx, int rx, int l, int r, vector<long long> &seg) {
        if(rx <= l || lx >= r) return 1;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return lcm(query(2 * x + 1, lx, m, l, r, seg), query(2 * x + 2, m, rx, l, r, seg));
    }
  public:
    vector<long long> RangeLCMQuery(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        int n = arr.size(), q = queries.size();
        vector<long long> seg(4 * n, 1), ans;
        build(0, 0, n, arr, seg);
        for(int i = 0; i < q; i++) {
            if(queries[i][0] == 1) update(0, 0, n, queries[i][1], queries[i][2], seg);
            else ans.push_back(query(0, 0, n, queries[i][1], queries[i][2] + 1, seg));
        }
        return ans;
    }
};