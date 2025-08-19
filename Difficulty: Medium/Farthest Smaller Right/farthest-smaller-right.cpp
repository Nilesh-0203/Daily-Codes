class Solution {
  public:
    vector<int> farMin(vector<int>& arr) {
        vector<pair<int, int>> vp;
        for(int i=0; i<arr.size(); i++) {
            vp.push_back({arr[i], i});
        }
        
        sort(vp.begin(), vp.end());
        
        priority_queue<int> pq;
        vector<int> ans = arr;
        
        ans[vp[0].second] = -1;
        pq.push(vp[0].second);
        
        for(int i=1; i<vp.size(); i++) {
            if(pq.top() > vp[i].second) {
                ans[vp[i].second] = pq.top();
            } else {
                ans[vp[i].second] = -1;
            }
            pq.push(vp[i].second);
        }

        return ans;
    }
};