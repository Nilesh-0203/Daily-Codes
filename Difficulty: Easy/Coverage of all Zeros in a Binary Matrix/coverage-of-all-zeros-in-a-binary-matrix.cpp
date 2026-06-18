class Solution {
  public:
    int findCoverage(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(mat[i][j] == 1){
                    for(int k = j+1;k<m;++k){
                        if(mat[i][k] == 0) ans++;
                    }
                    break;
                }
            }
            // cout<<ans<<" ";
            for(int j=m-1;j>=0;--j){
                if(mat[i][j] == 1){
                    for(int k = j-1;k>=0;--k){
                        if(mat[i][k] == 0) ans++;
                    }
                    break;
                }
            }
            // cout<<ans<<" ";
        }
        for(int j=0;j<m;++j){
            for(int i=0;i<n;++i){
                if(mat[i][j] == 1){
                    for(int k = i+1;k<n;++k){
                        if(mat[k][j] == 0) ans++;
                    }
                    break;
                }
            }
            // cout<<ans<<" ";
            for(int i=n-1;i>=0;--i){
                if(mat[i][j] == 1){
                    for(int k = i-1;k>=0;--k){
                        if(mat[k][j] == 0) ans++;
                    }
                    break;
                }
            }
            // cout<<ans<<" ";
        }
        return ans;
    }
};
