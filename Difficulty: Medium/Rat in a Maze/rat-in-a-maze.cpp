class Solution {
  public:
    int m,n;
    vector<string>result;
    map<int,char>mp = {{0,'D'},{1,'U'},{2,'R'},{3,'L'}};
    vector<int>dx = {1,-1,0,0};
    vector<int>dy = {0,0,1,-1};
    void solve(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&vis,string &temp){
        if(i<0 || j<0 || i>=m || j>=n || mat[i][j]==0 || vis[i][j]==1){
            return;
        }
        if(i==m-1 && j==n-1){
            result.push_back(temp);
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int new_i=i+dx[k];
            int new_j=j+dy[k];
            temp.push_back(mp[k]);
            solve(mat,new_i,new_j,vis,temp);
            temp.pop_back();
        }
        vis[i][j]=0;
    }
    vector<string> ratInMaze(vector<vector<int>>& mat) {
        // code here
        if(mat[0][0]==0){
            return {};
        }
        m=mat.size();
        n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        string curr="";
        solve(mat,0,0,vis,curr);
        sort(begin(result), end(result));
        return result;
    }
};