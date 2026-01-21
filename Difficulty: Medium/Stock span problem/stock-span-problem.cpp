class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> res(arr.size());
        stack<int> st;
        for(int i = 0;i<arr.size();i++)
        {
            while(!st.empty() and arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.empty())res[i] = i+1;
            else res[i] = (i-st.top());
            st.push(i);
        }
        return res;
    }
};