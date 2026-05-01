class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans(n,-1);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            if(pq.size()>k){
                pq.pop();
            }
            if(pq.size()==k){
                ans[i]=pq.top();
            }
        }
        return ans;
    }
};