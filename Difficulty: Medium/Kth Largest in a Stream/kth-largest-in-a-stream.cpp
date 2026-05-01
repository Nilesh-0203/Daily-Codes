class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        vector<int>ans(n);
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            if(i<(k-1)){
                ans[i]=-1;
                if(pq.size()<k){
                    pq.push(arr[i]);
                }
            }
            else{
                if(pq.size()>=k && pq.top()<=arr[i]){
                    pq.pop();
                }
                if(pq.size()<k){
                    pq.push(arr[i]);
                }
                ans[i]=pq.top();
            }
            
        }
        return ans;
    }
};