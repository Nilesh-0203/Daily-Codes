//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Node{
    Node* link[2];
    public:
    bool containsKey(int bit){
        return link[bit];
    }
    void put(int bit, Node* node){
        link[bit] = node;
    }
    
    Node* get(int bit){
        return link[bit];
    }
};

class Trie{
    private:
        Node *root;
    public:
        Trie(){
            root = new Node();
        }
        
        void insert(int number){
            Node* node = root;
            for (int i = 31; i >= 0 ; i--){
                int bit = (number >> i) & 1;
                if (!node->containsKey(bit)){
                    node->put(bit, new Node());
                }
                node = node->get(bit);
            }
        }
        
        int maxOf(int x){
            Node* node = root;
            int output = 0;
            for (int i = 31; i >= 0; i--){
                int bit = (x >> i) & 1;
                if (node->containsKey(!bit)){
                    output = output | (1 << i);
                    node = node->get(!bit);
                }else{
                    node = node->get(bit);
                }
            }
            return output;
        }
};

 

class Solution {
  public:
    typedef pair<int, pair<int,int>> ppi;
    vector<int> maxXor(vector<int> &arr, vector<vector<int>> &queries) {
        int N=arr.size();
        int Q=queries.size();
        vector<ppi> offlineQueries;
        Trie T;
        vector<int> output(queries.size(),0);
        //load all the queries into offline queries and sort the function
        for (int i = 0; i < Q; i++){
            offlineQueries.push_back(make_pair(queries[i][1],make_pair(queries[i][0],i)));
        }
        sort(offlineQueries.begin(),offlineQueries.end());
        sort(arr.begin(),arr.end()); //sort the array
        int iterator = 0;

        
        int i = 0;
        for (auto it: offlineQueries) {
            while (i < N && arr[i] <= it.first) {
              T.insert(arr[i]);
              i++;
            }
            if (i != 0) output[it.second.second] = T.maxOf(it.second.first);
            else output[it.second.second] = -1;
        }
        
        return output;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string s;
        getline(cin, s);
        stringstream ss(s);
        int val;
        while (ss >> val) {
            arr.push_back(val);
        }

        int q;
        cin >> q;
        cin.ignore();
        vector<vector<int>> queries(q, vector<int>(2));
        for (int i = 0; i < q; i++) {
            cin >> queries[i][0] >> queries[i][1];
        }
        cin.ignore();
        Solution obj;
        vector<int> ans = obj.maxXor(arr, queries);
        for (auto &it : ans)
            cout << it << ' ';
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends