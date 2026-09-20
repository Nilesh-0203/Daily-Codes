class Solution {
  public:
    int largestSubsquare(vector<vector<char>> &mat) {
            // code here
            vector<vector<int>>hor(mat.size() ,vector<int>(mat[0].size() , 0));
            vector<vector<int>>ver = hor;
            ver[0][0] = hor[0][0]= (mat[0][0] == 'X');
            for(int j = 1 ;j<mat[0].size() ; j++){
                hor[0][j] = hor[0][j-1] + (mat[0][j] == 'X');
                ver[0][j] = mat[0][j] == 'X';
            }
            for(int i = 1 ; i<mat.size() ; i++){
                hor[i][0] =(mat[i][0] == 'X');
                ver[i][0] = ver[i-1][0] + (mat[i][0] == 'X');
                for(int j = 1 ; j<mat[0].size() ; j++){
                hor[i][j] = hor[i][j-1] + (mat[i][j] == 'X');
                ver[i][j] = ver[i-1][j] + (mat[i][j] == 'X');
                }
            }
            int ans = 0;
            for(int i = 0 ;i<mat.size() ; i++){
                for(int j = 0 ; j<mat[0].size() ; j++){
                    for(int k = i + ans ; k <=min((int)mat.size()-1 , (int)mat[0].size() + i - j -1) ;k++){
                       if( (ver[k][j] - (i==0 ? 0 : ver[i-1][j]) == k - i +1)  && (hor[i][j + k-i] - (j==0 ? 0 : hor[i][j-1]) == k - i +1)){
                        if((ver[k][j + k-i] - (i==0 ? 0 : ver[i-1][j + k-i]) == k - i +1) && (hor[k][j + k-i] - (j==0 ? 0 : hor[k][j-1]) == k - i +1))ans = k - i +1;
                       }else break;
                    }
                }
            }
            return ans;
        }
};