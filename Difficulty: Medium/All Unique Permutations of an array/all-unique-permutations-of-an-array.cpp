class Solution {
  public:
    void solve(vector<int>arr,int idx,set<vector<int>>&st){
        if(idx==arr.size()){
            st.insert(arr);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            swap(arr[idx],arr[i]);
            solve(arr,idx+1,st);
            swap(arr[idx],arr[i]);
        }
    }
    vector<vector<int>> uniquePerms(vector<int>& arr) {
        // code here
        int n=arr.size();
        set<vector<int>>st;
        solve(arr,0,st);
        vector<vector<int>>v;
        for(auto it:st){
            v.push_back(it);
        }
        return v;
    }
};