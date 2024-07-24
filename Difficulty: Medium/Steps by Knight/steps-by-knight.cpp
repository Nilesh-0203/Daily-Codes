//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    int bfs(int x,int y, int target_x,int target_y,int N,vector<vector<int>> &vis){        // int mini=INT_MAX;
        queue<pair<pair<int,int>,int>> q;
        vector<pair<int, int>> directions = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {1, -2}, {-1, 2}, {-1, -2}
    };
        q.push({{x,y},0});
        vis[x][y]=1;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int cnt=q.front().second;
            q.pop();
            if(row==target_x && col==target_y){
                return cnt;
            }
            for (auto dir : directions) {
                int r = row + dir.first;
                int c = col + dir.second;
                if(r>=0 && r<N && c>=0 && c<N && !vis[r][c]){
                    q.push({{r,c},cnt+1});
                    vis[r][c]=1;
                }
            }
        }
        return -1;
        
	}
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int row=N;
	    int col=N;
	    vector<vector<int>> vis(row,vector<int>(N,0));
	    
	    int knight_x=KnightPos[0]-1;
	    int knight_y=KnightPos[1]-1;
	    int target_x=TargetPos[0]-1;
	    int target_y=TargetPos[1]-1;
	    return bfs(knight_x,knight_y,target_x,target_y,N,vis); 
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends