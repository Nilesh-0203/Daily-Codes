//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a solved Sudoku.
    int N = 9;
    bool isPossible(int currRow, int currCol, vector <vector <int>> &mat, int val){
        for(int i = 0; i < N; i++){
            if(mat[currRow][i] == val || mat[i][currCol] == val) return false;
        }
        
        for(int i = 0; i < N; i++){
            if(mat[3*(currRow/3) + i/3][3*(currCol/3) + (i%3)] == val) return false;
        }
            
        return true;
    }
    
    bool solve(vector<vector<int>> &mat){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(mat[i][j] == 0){
                    for(int val = 1; val <= 9; val++){
                        if(isPossible(i, j, mat, val)){
                            mat[i][j] = val;
                            bool nextCall = solve(mat);
                            if(nextCall){
                                return true;
                            }
                            else{
                                mat[i][j] = 0;
                            }
                        }
                    }
                    
                    if(!mat[i][j]) return false;
                }
            }
        }
        
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        solve(mat);
    }
};

//{ Driver Code Starts.

vector<int> inputLine() {
    string str;
    getline(cin, str);
    stringstream ss(str);
    int num;
    vector<int> res;
    while (ss >> num) {
        res.push_back(num);
    }
    return res;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<vector<int>> grid;
        for (int i = 0; i < 9; i++) {
            vector<int> v = inputLine();
            grid.push_back(v);
        }

        Solution ob;

        ob.solveSudoku(grid);

        for (auto v : grid) {
            for (auto elem : v) {
                cout << elem << " ";
            }
            cout << endl;
        }

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends