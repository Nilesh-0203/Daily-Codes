//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string S){
        // code here
        int left=0,right=0;
        int maxi=0;
        int n=S.length();
        for(int i=0;i<n;i++){
            if(S[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                maxi=max(maxi,left*2);
            }
            if(right>left){
                left=0,right=0;
            }
        }
        left=0,right=0;
        for(int i=n-1;i>=0;i--){
            if(S[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                maxi=max(maxi,left*2);
            }
            if(left>right){
                left=0,right=0;
            }
        }
        return maxi;
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
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends