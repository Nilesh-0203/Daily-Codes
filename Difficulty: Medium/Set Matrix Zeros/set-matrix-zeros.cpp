class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        // code here
        int row=mat.size();
        int col=mat[0].size();
        set<pair<int,int>>st;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(mat[i][j]==0){
                    for(int k=0;k<row;k++){
                        st.insert({k,j});
                    }
                    for(int k=0;k<col;k++){
                        st.insert({i,k});
                    }
                }
            }
        }
        for(auto it:st){
            mat[it.first][it.second]=0;
        }
    }
};