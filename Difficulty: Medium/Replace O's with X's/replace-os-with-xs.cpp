//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int m,n;
    void dfs(vector<vector<char>>& grid,int i,int j){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]!='O'){
            return;
        }
        grid[i][j]='$';
        for(auto &dir:directions){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            dfs(grid,new_i,new_j);
        }
    }
    vector<vector<char>> fill(int M, int N, vector<vector<char>> board)
    {
        // code here
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){  //First Columne
                dfs(board,i,0);
            }
            if(board[i][n-1]=='O'){ //Last Columne
                dfs(board,i,n-1);
            }
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){  //First Row
                dfs(board,0,i);
            }
            if(board[m-1][i]=='O'){ //Last Row
                dfs(board,m-1,i);
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                   board[i][j]='X';
                }
                else if(board[i][j]=='$'){
                    board[i][j]='O';
                }
            }
        }
        return board;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends