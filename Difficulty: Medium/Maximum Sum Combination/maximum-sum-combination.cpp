class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& A, vector<int>& B, int K) {
        // code here
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int N=A.size();
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<N;i++)
        {
            int sum = A[i]+B[N-1];
            pq.push({sum,N-1});
        }
        
        while(!pq.empty() and K--)
        {
            int sum = pq.top().first;
            int idx = pq.top().second;
            pq.pop();
            ans.push_back(sum);
            if(idx-1>=0)
            pq.push({sum-B[idx]+B[idx-1], idx-1});
        }
        return ans;
    }
};