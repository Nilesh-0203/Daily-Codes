class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        priority_queue<int>pq;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                pq.push(mat[i][j]);
            }
        }
        int n=pq.size();
        int m=(n/2);
        while(m>0){
            pq.pop();
            m--;
        }
        return pq.top();
    }
};
