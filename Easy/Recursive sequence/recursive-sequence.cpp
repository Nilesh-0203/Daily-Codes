//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long mod=1e9+7;
    long long sequence(int n){
        // code here
        long long ans=0;
        long long k=1;
        for(int i=1;i<=n;i++){
            int count=0;
            long long a=1;
            while(count<i){
                a=(a*k)%mod;
                k++;
                count++;
            }
            ans=(ans+a)%mod;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.sequence(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends