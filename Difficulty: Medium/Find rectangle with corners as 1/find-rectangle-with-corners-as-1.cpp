class Solution {
  public:
    int n, m;
    
    vector<int>rowF(int r, int c, vector<vector<int>>&mat){
        vector<int>ans;
        for(int j=c+1; j<m; j++){
            if(mat[r][j]==1){
                ans.push_back(j);
            }
        }
        return ans;
    }
    
    vector<int>colF(int r, int c, vector<vector<int>>&mat){
        vector<int>ans;
        for(int i=r+1; i<n; i++){
            if(mat[i][c]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
  
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
        n=mat.size();
        m=mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==1){
                    vector<int>row=rowF(i, j, mat);
                    vector<int>col=colF(i, j, mat);
                    
                    for(auto &x:row){
                        for(auto &y:col){
                            if(mat[y][x]==1) return 1;
                        }
                    }
                }
            }
        }
        
        return 0;
    }
};