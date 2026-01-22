class Solution {
  public:
    int subarrayRanges(vector<int> &nums) {
        // code here
        int n = nums.size(), ans = 0;
        
        vector<int> nge(n, n), nse(n, n), pge(n, -1), pse(n, -1);
        stack<int> s1, s2;
        
        for(int i = 0; i < n; i++) {
            while(!s1.empty() && nums[s1.top()] > nums[i]) s1.pop();
            if(!s1.empty()) pse[i] = s1.top();
            s1.push(i);
            
            while(!s2.empty() && nums[s2.top()] < nums[i]) s2.pop();
            if(!s2.empty()) pge[i] = s2.top();
            s2.push(i);
        }
        
        while(!s1.empty()) s1.pop();
        while(!s2.empty()) s2.pop();
        
        for(int i = n - 1; i >= 0; i--) {
            while(!s1.empty() && nums[s1.top()] >= nums[i]) s1.pop();
            if(!s1.empty()) nse[i] = s1.top();
            s1.push(i);
            
            while(!s2.empty() && nums[s2.top()] <= nums[i]) s2.pop();
            if(!s2.empty()) nge[i] = s2.top();
            s2.push(i);
        }
        
        for(int i = 0; i < n; i++) {
            // cout << pse[i] << " " << nse[i] << endl;
            // cout << pge[i] << " " << nge[i] << endl;
            // cout << "----------------" << endl;
            ans += (nums[i] * ((nge[i] - i) * (i - pge[i])));
            ans -= (nums[i] * ((nse[i] - i) * (i - pse[i])));
        }
        
        return ans;
    }
};