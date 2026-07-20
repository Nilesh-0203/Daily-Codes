class Node{
    public:
    int count;
    vector<Node*>children;
    
    Node()
    {
        count = 0;
        children.resize(26);
    }
};
class Trie{
    public:
    Node* root;
    
    Trie()
    {
        root = new Node();
    }
    
    void insert(string s)
    {
        
        Node* curr =root;
        
        for(char ch:s)
        {
            int d = ch - 'a';
            
            if(curr->children[d]==nullptr)
            curr->children[d] = new Node();
            
            curr = curr->children[d];
            curr->count++;
        }
    }
    
    string check(string s)
    {
        Node* curr = root;
        string res = "";
        for(char ch :s)
        {
            int d = ch - 'a';
            
            curr = curr->children[d];
            res+=ch;
            if(curr->count == 1)
            {
                return res;
            }
        }
        return res;
    }
    
    
};

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        int n = (int)arr.size();
        Trie t;
        
        for(auto &s:arr)
        {
            t.insert(s);
        }
        
        vector<string>ans;
        
        for(auto &s:arr)
        {
            ans.push_back(t.check(s));
        }
        return ans;
    }
};