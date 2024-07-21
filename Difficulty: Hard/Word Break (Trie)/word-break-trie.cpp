//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class TrieNode {
public:
    char character;
    TrieNode* children[26];
    bool isEndOfWord;

    TrieNode(char c) {
        character = c;
        for (int i = 0; i < 26; i++) children[i] = nullptr;
        isEndOfWord = false;
    }
};
class Solution{
    public:
    // A : given string to search
    // B : vector of available strings
    TrieNode* root;

    Solution() {
        root = new TrieNode('\0');
    }
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* currentNode = root;
        for (char c : word) {
            int index = c - 'a';
            if (currentNode->children[index] == nullptr) {
                currentNode->children[index] = new TrieNode(c);
            }
            currentNode = currentNode->children[index];
        }
        currentNode->isEndOfWord = true;
    }
    bool canSegmentString(TrieNode* root,string& A, int idx, vector<int>&dp) {
        if (idx == A.size()) return true; 

        if (dp[idx] != -1){
            return dp[idx];
        } 

        TrieNode* curr = root;
        for (int i = idx; i < A.size(); ++i) {
            int index = A[i] - 'a';
            if (curr->children[index] == NULL) {
                dp[idx] = 0;
                return false; 
            }
            curr = curr->children[index];
            if (curr->isEndOfWord && canSegmentString(root, A, i + 1, dp)) {
                dp[idx] = 1;
                return true;
            }
        }
        dp[idx] = 0; 
        return false;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        for (string& word : B) {
            insertWord(root, word); 
        }
        int n=A.size();
        vector<int> dp(n, -1);
        return canSegmentString(root, A, 0, dp);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends