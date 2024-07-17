//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    int N;
    vector<int> NSRF(vector<int>&height){
        stack<int>st;
        st.push(N);
        vector<int>ans(N);
        for(int i=N-1;i>=0;i--){
            while(st.top()!=N && height[st.top()]>=height[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> NSLF(vector<int>&height){
        stack<int>st;
        st.push(-1);
        vector<int>ans(N);
        for(int i=0;i<N;i++){
            while(st.top()!=-1 && height[st.top()]>=height[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int findMaxArea(vector<int>&height){
        vector<int>NSR=NSRF(height);
        vector<int>NSL=NSLF(height);
        vector<int>width(N);
        for(int i=0;i<N;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int area=INT_MIN;
        for(int i=0;i<N;i++){
            int newArea=height[i]*width[i];
            area=max(area,newArea);
        }
        return area;
    }
    int maxArea(int M[MAX][MAX], int m, int n) {
        // Your code here
        N=n;
        vector<int>heights(n);
        for(int i=0;i<n;i++){
            heights[i]=M[0][i];
        }
        int maxArea=findMaxArea(heights);
        for(int row=1;row<m;row++){
            for(int col=0;col<n;col++){
                if(M[row][col]==0){
                    heights[col]=0;
                }
                else{
                    heights[col]+=1;
                }
            }
            maxArea=max(maxArea,findMaxArea(heights));
        }
        return maxArea;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends