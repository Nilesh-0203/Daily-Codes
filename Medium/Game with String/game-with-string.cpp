//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        map<int,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        vector<int>v;
        for(auto i:mp){
            v.push_back(i.second);
        }
        int n=v.size()-1;
        while(k!=0){
            sort(v.begin(),v.end());
            v[n]=v[n]-1;
            k--;
        }
        int sum=0;
        for(int i=0;i<n+1;i++){
            sum+=(v[i]*v[i]);
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends