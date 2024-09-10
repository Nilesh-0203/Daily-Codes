//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void DFS(vector<int>&visit,int u,vector<int>adj[]){
      visit[u]=true;
      for(auto v:adj[u]){
          if(visit[v]==false)
          DFS(visit,v,adj);
      }
  }
  bool Solve(vector<int>&mark,int src,vector<int>adj[]){
      
      vector<int>visit(26,0);
      DFS(visit,src,adj);
      for(int i=0;i<26;i++){
          if(visit[i]==false && mark[i]==true)
          return false;
      }
      return true;
  }
    int isCircle(vector<string> &arr) {
       vector<int>adj[26];
       vector<int>in_degree(26,0);
       vector<int>out_degree(26,0);
       int src=INT_MAX;
       vector<int>mark(26,0);
       for(int i=0;i<arr.size();i++){
           
           string str=arr[i];
           int u=int(str[0]-'a');
           int v=int(str.back()-'a');
           in_degree[u]++;
           out_degree[v]++;
           if(i==0)
           src=u;
           adj[u].push_back(v);
           mark[u]=mark[v]=1;
       }
       if(in_degree!=out_degree)
       return 0;
       return Solve(mark,src,adj);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends