class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int a:arr){
            pq.push(a);
        }
        int ans=0;
        while(pq.size()!=1){
            int a=pq.top();pq.pop();
            int b=pq.top();pq.pop();
            
            ans+=(a+b);
            pq.push(a+b);
        }
        return ans;
    }
};