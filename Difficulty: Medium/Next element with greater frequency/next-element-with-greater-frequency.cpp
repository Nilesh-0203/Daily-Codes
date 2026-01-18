class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {

        stack<int> st;
        unordered_map<int,int> mp;
        for(int& elem : arr){
            mp[elem]++;
        }
        int n = arr.size();
        vector<int> ans(n,-1);
        for(int i = n-1;i>=0;i--){
            if(!st.empty() &&   mp[arr[i]]<mp[st.top()]){
                ans[i] = st.top();
            }else{
                while(!st.empty() && mp[arr[i]]>=mp[st.top()]){
                    st.pop();
                }
                if(!st.empty()){
                    ans[i] = st.top(); 
                }
            }
            st.push(arr[i]);
        }
        
        return ans;
         
    }
};
