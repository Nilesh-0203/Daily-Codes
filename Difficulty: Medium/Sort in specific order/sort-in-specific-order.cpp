class Solution {
  public:
     void sortIt(vector<int>& arr) {
        // code here
        priority_queue<int>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;
        for(auto i:arr) {
            if (i&1) {
                pq1.push(i);
            } else {
                pq2.push(i);
            }
        }
        for(int i=0;i<arr.size();i++) {
            if(!pq1.empty()) {
                arr[i]=pq1.top();
                pq1.pop();
            } else {
                arr[i]=pq2.top();
                pq2.pop();
            }
        }
    }
};