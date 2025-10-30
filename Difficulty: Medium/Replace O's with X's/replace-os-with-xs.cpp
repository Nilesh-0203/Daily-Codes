class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        
        queue<pair<int, int>>q;
        
        for(int i=0; i<n; i++){
            if(grid[i][0]=='O'){
                grid[i][0]='C';
                q.push({i, 0});
            }
            if(grid[i][m-1]=='O'){
                grid[i][m-1]='C';
                q.push({i, m-1});
            }
        }
        
        for(int j=0; j<m; j++){
            if(grid[0][j]=='O'){
                grid[0][j]='C';
                q.push({0, j});
            }
            if(grid[n-1][j]=='O'){
                grid[n-1][j]='C';
                q.push({n-1, j});
            }
        }
        
        int dr[4]={0, 1, 0, -1};
        int dc[4]={1, 0, -1, 0};
        
        while(!q.empty()){
            auto it=q.front();
            int r=it.first;
            int c=it.second;
            q.pop();
            
            for(int i=0; i<4; i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]=='O'){
                    grid[nr][nc]='C';
                    q.push({nr, nc});
                }
            }
        }
        
        for(int i=1; i<n-1; i++){
            for(int j=1; j<m-1; j++){
                if(grid[i][j]=='O') grid[i][j]='X';
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='C'){
                    grid[i][j]='O';
                }
            }
        }
    }
};