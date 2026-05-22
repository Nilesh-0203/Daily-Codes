class Solution {
  public:
    int n;
    int m;
    int row[4] = {-1,1,0,0};
    int col[4] = {0,0,-1,1};
    
    bool check(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    
    void DFS(vector<vector<int>>& grid,int i,int j){ // simple DFS only
        
        grid[i][j]=0;
        
        for(int k=0;k<4;k++){
            if(check(i+row[k],j+col[k]) && grid[i+row[k]][j+col[k]]){
                DFS(grid,i+row[k],j+col[k]);
            }
        }
    }
    
    int cntOnes(vector<vector<int>>& grid) {
        // code here
        n=grid.size();
        m=grid[0].size();
        
        for(int i=0;i<m;i++){ // remove bountdary one and its chain // first and last row.
            if(grid[0][i])DFS(grid,0,i);
            if(grid[n-1][i])DFS(grid,n-1,i);
        }
        
        for(int i=0;i<n;i++){ // first col and last col
            if(grid[i][0])DFS(grid,i,0);
            if(grid[i][m-1])DFS(grid,i,m-1);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){ // count the remaining ones.
            for(int j=0;j<m;j++){
                if(grid[i][j])ans++;
            }
        }
        
        return ans;
    }
};