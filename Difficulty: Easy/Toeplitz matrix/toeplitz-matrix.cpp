class Solution {
  public:
    bool isToeplitz(vector<vector<int>>& mat) {
    // code here
    int n=mat.size();
    int m=mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i!=0 && j!=0){
                if(mat[i][j]!=mat[i-1][j-1])return false; //Diagonal Element Check 
            }
        }
    }
    return true;
}
};