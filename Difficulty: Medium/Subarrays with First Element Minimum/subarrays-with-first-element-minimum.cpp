class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n = arr.size();
        long long count = 0;
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                count += i - st.top();
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            count += n - st.top();
            st.pop();
        }
        
        return count;
    }
};