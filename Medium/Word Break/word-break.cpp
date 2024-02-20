//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int N;
    int t[1101];
    unordered_set<string>st;
    int solve(int idx,string &s){
        if(idx>=N){
            return 1;
        }
        if(t[idx]!=-1){
            return t[idx];
        }
        if(st.find(s)!=st.end()){
            return t[idx]=1;
        }
        for(int i=1;i<=N;i++){
            string temp=s.substr(idx,i);
            if(st.find(temp)!=st.end() && solve(idx+i,s)){
                return t[idx]=1;
            }
        }
        return t[idx]=0;
    } 
    int wordBreak(int n, string s, vector<string> &dictionary) {
        //code here
        N=s.length();
        memset(t,-1,sizeof(t));
        for(string &word:dictionary){
            st.insert(word);
        }
        return solve(0,s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends