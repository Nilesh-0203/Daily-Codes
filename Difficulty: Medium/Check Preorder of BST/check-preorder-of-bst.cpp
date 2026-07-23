class Solution {
  public:
    bool canRepresentBST(vector<int> &arr) {
        // code here
        stack<int>st;
        int limit=INT_MIN;
        
        for(int &x:arr){
            if(x<limit){
                return false;
            }
            while(!st.empty() && x>st.top()){
                limit=st.top();
                st.pop();
            }
            st.push(x);
        }
        
        return true;
    }
};