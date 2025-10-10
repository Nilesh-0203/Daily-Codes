/*
class Node {
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
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>result;
    	if(root==NULL){
    	    return result;
    	}
    	queue<Node*>q;
    	q.push(root);
    	bool leftToright=true;
    	while(!q.empty()){
    	    int size=q.size();
    	    vector<int>ans(size);
    	    for(int i=0;i<size;i++){
    	        Node* frontNode=q.front();
    	        q.pop();
    	        int index=leftToright ? i : size-i-1;
    	        ans[index]=frontNode->data;
    	        
    	        if(frontNode->left!=NULL){
    	            q.push(frontNode->left);
    	        }
    	        if(frontNode->right!=NULL){
    	            q.push(frontNode->right);
    	        }
    	    }
    	    leftToright=!leftToright;
    	    for(auto i : ans){
    	        result.push_back(i);
    	    }
    	}
    	return result;
    }
};