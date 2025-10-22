class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = arr.size();
        int index = 0;
        
        for (int i = 0; i < n; i++) {
            pq.push(arr[i]);
            
            if (pq.size() > k) {
                arr[index++] = pq.top();
                pq.pop();
            }
        }
        
        while (!pq.empty()) {
            arr[index++] = pq.top();
            pq.pop();
        }
    }
};