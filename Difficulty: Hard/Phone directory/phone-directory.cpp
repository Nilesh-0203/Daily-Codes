//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
int N;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch){
        data=ch;
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        isTerminal=false;
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
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
    void insert(string word) {
        insertUtil(root,word);
    }
    void printSuggestions(TrieNode* curr,vector<string>&temp,string prefix){
        if(curr->isTerminal){
            temp.push_back(prefix);
        }
        for(char ch='a';ch<='z';ch++){
            TrieNode* next=curr->children[ch-'a'];
            if(next!=NULL){
                prefix.push_back(ch);
                printSuggestions(next,temp,prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string word){
        TrieNode* prev=root;
        vector<vector<string>>output;
        string prefix="";
        for(int i=0;i<word.length();i++){
            char ch=word[i];
            prefix.push_back(ch);
            TrieNode* curr=prev->children[ch-'a'];
            if(curr==NULL){
                break;
            }
            vector<string>temp;
            printSuggestions(curr,temp,prefix);
            output.push_back(temp);
            temp.clear();
            prev=curr;
        }
        int cnt=N-output.size();
        while(cnt){
            vector<string>temp;
            temp.push_back("0");
            output.push_back(temp);
            cnt--;
        }
        return output;
    }
};
class Solution{
public:
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        N=s.length();
        Trie* t=new Trie();
        for(int i=0;i<n;i++){
            string str=contact[i];
            t->insert(str);
        }
        return t->getSuggestions(s);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < ans.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends