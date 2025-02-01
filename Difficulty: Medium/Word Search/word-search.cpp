//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int m,n;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool find(vector<vector<char>>&mat,int i,int j,int idx,string& word){
        if(idx==word.length()){
            return true;
        }
        if(i<0 || j<0 || i>=m || j>=n || mat[i][j]=='$'){
            return false;
        }
        if(mat[i][j]!=word[idx]){
            return false;
        }
        char temp=mat[i][j];
        mat[i][j]='$';
        for(auto dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(find(mat,new_i,new_j,idx+1,word)){
                return true;
            }
        }
        mat[i][j]=temp;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        m=mat.size();
        n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==word[0] && find(mat,i,j,0,word)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends