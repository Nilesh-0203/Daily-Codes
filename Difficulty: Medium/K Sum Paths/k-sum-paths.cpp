/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int preorder(Node* node, int& curr_sum, int& k, unordered_map<int,int> &mp){
        if(node == NULL) return 0;
        curr_sum += node->data;
        int ans = 0;
        if(mp.find(curr_sum-k)!=mp.end()) ans+=mp[curr_sum-k];
        mp[curr_sum]++;
        ans+= preorder(node->left,curr_sum,k,mp);
        ans+= preorder(node->right,curr_sum,k,mp);
        if(mp[curr_sum]==1) mp.erase(curr_sum);
        else mp[curr_sum]--;
        curr_sum-=node->data;
        return ans;
    }
    int countAllPaths(Node *root, int k) {
        // code here
        int curr_sum = 0;
        unordered_map<int,int> mp;
        Node* temp = root;
        mp[0]=1;
        return preorder(temp,curr_sum,k,mp);
    }
};