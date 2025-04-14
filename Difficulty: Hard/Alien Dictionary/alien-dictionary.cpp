//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        int n=words.size();
        vector<vector<int>>adj(26);
        vector<bool>visited(26,false);
        vector<int>indegree(26,0);
        
        for(auto word:words){
            for(char c:word){
                visited[c-'a']=true;
            }
        }
        
        for(int i=0;i<n-1;i++){
            string str1=words[i];
            string str2=words[i+1];
            int len=min(str1.length(),str2.length());
            bool check=false;
            
            for(int j=0;j<len;j++){
                if(str1[j]!=str2[j]){
                    adj[str1[j]-'a'].push_back(str2[j]-'a');
                    indegree[str2[j]-'a']++;
                    check=true;
                    break;
                }
            }
            if(!check && str1.length()>str2.length()){
                return "";
            }
        }
        
        string ans="";
        queue<int>q;
        for(int i=0;i<26;i++){
            if(visited[i] && indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            
            ans+=char(node+'a');
            for(auto neighbor:adj[node]){
                indegree[neighbor]--;
                if(indegree[neighbor]==0){
                    q.push(neighbor);
                }
            }
        }
        
        for(int i=0;i<26;i++){
            if(visited[i] && indegree[i]>0){
                return "";
            }
        }
        return ans;
    }
};




//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends