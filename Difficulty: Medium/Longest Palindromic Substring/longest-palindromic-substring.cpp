//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool solve(string &s,int i,int j,vector<vector<int>>&dp){
        if(i>j){
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return solve(s,i+1,j-1,dp);
        }
        return dp[i][j]=false;
    }
    string longestPalindrome(string s){
        // code here 
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        int maxLen=0;
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j,dp)==true){
                    if(j-i+1>maxLen){
                        maxLen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxLen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends