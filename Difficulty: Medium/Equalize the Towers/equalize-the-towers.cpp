class Solution {
  public:
    int minCost(vector<int>& heights, vector<int>& cost) {
        // code here
         vector<pair<int,int>> v;
        for (int i = 0; i < heights.size(); i++) {
            v.push_back({heights[i], cost[i]});
        }
        sort(v.begin(), v.end());

        long long total = 0;
        for (auto &p : v) total += p.second;

        long long prefix = 0;
        int targetHeight = 0;
        for (auto &p : v) {
            prefix += p.second;
            if (prefix * 2 >= total) {
                targetHeight = p.first;
                break;
            }
        }

        long long ans = 0;
        for (int i = 0; i < heights.size(); i++) {
            ans += 1LL * abs(heights[i] - targetHeight) * cost[i];
        }
        return (int)ans;
    }
};
