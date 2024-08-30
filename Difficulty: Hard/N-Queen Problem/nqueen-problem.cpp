//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool can_place(int i,int j,int n,vector<int>ans){
        for(int k=0;k<i;k++){
            if(ans[k]==j || (ans[k]-i+k > 0 and ans[k]-i+k==j) || (ans[k]+i-k<n+1 and ans[k]+i-k==j)){
                return false;
            }
        }
        return true;
    }
    
    void help(int i,int n,vector<vector<int>>&ans,vector<int>&curr_ans){
        if(i==n){
            ans.push_back(curr_ans);
        }
        for(int j=0;j<n;j++){
            if(can_place(i,j+1,n,curr_ans)){
                curr_ans[i]=j+1;
                help(i+1,n,ans,curr_ans);
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>>ans;
        vector<int>curr_ans(n);
        help(0,n,ans,curr_ans);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends