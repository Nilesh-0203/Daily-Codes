class Solution {
  public:
    vector<int> prevGreater(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> prev(n, -1);
        for(int i = 0; i < n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                prev[i] = st.top();
            }
            st.push(i);
        }
        return prev;
    }
    
    vector<int> nextGreater(vector<int>& arr){
        int n = arr.size();
        stack<int> st;
        vector<int> next(n, n);
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            if(!st.empty()){
                next[i] = st.top();
            }
            st.push(i);
        }
        return next;
    }
  
    int longestSubarray(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> prev = prevGreater(arr);
        vector<int> next = nextGreater(arr);
        
        int maxLen = 0;
        for(int i = 0; i < n; i++){
            int len = next[i] - prev[i] - 1;
            if(arr[i] <= len){
                maxLen = max(maxLen, len);
            }
        }
        return maxLen;
    }
};