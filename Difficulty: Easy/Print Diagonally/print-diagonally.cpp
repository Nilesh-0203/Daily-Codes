class Solution {
  public:
    vector<int> diagView(vector<vector<int>> mat) {
        vector<int>ans;
        for(int i=0, k=0, j=0; i<2*mat.size()-1; i++, k++){
            if(i>mat.size()-1){
                j++;
            }
            k=min(k, (int)mat.size()-1);
            int ii=j, jj=k;
            while(ii<mat.size() and jj>=0){
                ans.push_back(mat[ii][jj]);
                ii++; jj--;
            }
        }
        return ans;
    }
};