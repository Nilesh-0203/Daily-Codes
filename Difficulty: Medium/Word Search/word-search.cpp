class Solution {
  vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>> &mat,string &word,vector<vector<bool>> &visited,int r,int c, int ptr){
        if(r<0 or c<0 or r>=mat.size() or c>=mat[0].size() or mat[r][c]!=word[ptr] or visited[r][c])return false;
        //what if all leters of the word is matched
        if(ptr==word.length()-1)return true;
        
        //now mark it and run the dfs
        
        visited[r][c]=true;
        for(auto it:dir){
            if(dfs(mat,word,visited,r+it.first,c+it.second,ptr+1))return true;
        }
        
        visited[r][c]=false;//back track
        return false;//other wise 
        
    }
  public:
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
        /*
        its a clear dfs approach 
        first find the first match then go all four direction matching next letter of word
        and make sure to unmark the letter after the dfs call
        */
        vector<vector<bool>>visited(mat.size(),vector<bool>(mat[0].size(),false));
        
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==word[0]){
                    bool ans=dfs(mat,word,visited,i,j,0);
                    if(ans)return ans;
                }
            }
        }
        return false;
    }
};