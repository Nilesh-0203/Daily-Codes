class Solution {
  public:
    int shortestPath(vector<vector<int>> &mat) {
            // code here
            int dr[4]={0, 1, 0, -1};
            int dc[4]={1, 0, -1, 0};

            int n=mat.size();
            int m=mat[0].size();

            for(int r=0; r<n; r++){
                for(int c=0; c<m; c++){
                    if(mat[r][c]==0){
                        for(int i=0; i<4; i++){
                            int nr=r+dr[i];
                            int nc=c+dc[i];

                            if(nr>=0 && nr<n && nc>=0 && nc<m && mat[nr][nc]==1){
                                mat[nr][nc]=-1;
                            }
                        }
                    }
                }
            }

            queue<pair<int, int>>q;
            set<pair<int, int>>vis;

            for(int r=0; r<n; r++){
                if(mat[r][0]==1){
                    q.push({r, 0});
                    vis.insert({r, 0});
                }
            }

            int steps=1;

            while(!q.empty()){
                int sz=q.size();
                while(sz--){
                    auto [r, c]=q.front();
                    q.pop();

                    if(c==m-1){
                        return steps;
                    }

                    for(int i=0; i<4; i++){
                        int nr=r+dr[i];
                        int nc=c+dc[i];

                        if(nr>=0 && nr<n && nc>=0 && nc<m && 
                        mat[nr][nc]==1 && vis.find({nr, nc})==vis.end()){
                            q.push({nr, nc});
                            vis.insert({nr, nc});
                        }
                    }
                }
                steps++;
            }

            return -1;
        }
};