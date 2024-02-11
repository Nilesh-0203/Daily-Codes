//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        // code here
        unordered_set<int>st;
        vector<int>v(n+1);
        v[0]=0;
        st.insert(0);
        for(int i=1;i<=n;i++){
            v[i]=v[i-1]-i;
            if(v[i]<0 || st.find(v[i])!=st.end()){
                v[i]=v[i-1]+i;
            }
            st.insert(v[i]);
        }
        return v;
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
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends