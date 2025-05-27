class Solution {
  public:
    vector<int>ans;
    void solve(vector<int>&preorder){
        vector<int>left,right;
        int n=preorder.size();
        for(int i=1;i<n;i++){
            if(preorder[i]<preorder[0])left.push_back(preorder[i]);
            else right.push_back(preorder[i]);
        }
        if(left.size()==0 && right.size()==0){
            ans.push_back(preorder[0]);
            return;
        }
        if(left.size())solve(left);
        if(right.size())solve(right);
    }
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        int n=preorder.size();
        solve(preorder);
        return ans;
    }
};