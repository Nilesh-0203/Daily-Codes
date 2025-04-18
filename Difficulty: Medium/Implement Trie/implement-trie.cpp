//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class TrieNode{
    public:
    char ch;
    bool isTerminal;
    TrieNode* children[26];
    TrieNode(char data){
        ch=data;
        isTerminal=false;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
class Trie {
  public:
    TrieNode* root;
    Trie() {
        // implement Trie
        root=new TrieNode('\0');
    }
    void insertUtil(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal=true;
            return;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertUtil(child,word.substr(1));
    }
    void insert(string &word) {
        // insert word into Trie
        insertUtil(root,word);
    }
    bool searchUtil(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }
        
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool search(string &word) {
        // search word in the Trie
        return searchUtil(root,word);
    }
    bool prefixUtil(TrieNode* root,string word){
        if(word.length()==0){
            return true;
        }
        int index=word[0]-'a';
        TrieNode* child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }
        return prefixUtil(child,word.substr(1));
    }
    bool isPrefix(string &word) {
        // search prefix word in the Trie
        return prefixUtil(root,word);
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends