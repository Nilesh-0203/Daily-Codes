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
        priority_queue<int>maxHeap;
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto i:mp){
            maxHeap.push(i.second);
        }
        while(k!=0){
            int rootElement=maxHeap.top();
            maxHeap.pop();
            rootElement--;
            maxHeap.push(rootElement);
            k--;
        }
        
        int sum=0;
        while(!maxHeap.empty()){
            int rootElement=maxHeap.top();
            maxHeap.pop();
            
            sum+=(rootElement*rootElement);
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