class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        // code here
        unordered_map<int, int> freq;
        for(auto i : arr){
            freq[i]++;
        }
        int size = arr.size();
        stack<int> st;
        vector<int> result(size, -1);
        for(int i = size - 1; i >= 0; i--){
            while(!st.empty() && freq[st.top()] <= freq[arr[i]]){
                st.pop();
            }
            
            if(!st.empty()){
                result[i] = st.top();
            }
            
            st.push(arr[i]);
        }
        return result;
    }
};
