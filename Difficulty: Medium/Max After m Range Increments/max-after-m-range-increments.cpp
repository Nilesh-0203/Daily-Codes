class Solution {
  public:
    int findMax(int n, vector<int>& a, vector<int>& b, vector<int>& k) {
        // code here
        vector<int>v(n,0);
        int m = a.size();
        int sum = 0;
        int ans = 0;
        
        for(int i=0;i<m;i++){
            v[a[i]]+=k[i];
            if(b[i]+1<n)v[b[i]+1]-=k[i];
        }
        
        
        for(int i=0;i<n;i++){
            sum+=v[i];
            ans = max(ans,sum);
        }
        
        
        return ans;
        
    }
};