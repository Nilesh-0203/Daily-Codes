//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};

bool help(Node* root, long long int up, long long int l) {
    if (root->data >= up || root->data <= l)
        return false;
    bool ans = true;
    if (root->left)
        ans = help(root->left, root->data, l);
    if (ans && root->right)
        ans = help(root->right, up, root->data);
    return ans;
}

bool isValidBST(Node* root) {
    return help(root, 3147483648, -3147483649);
}

int Height(Node* root) {

    if (root == NULL)
        return 0;

    int leftHeight = Height(root->left);

    int rightHight = Height(root->right);

    if (leftHeight == -1 || rightHight == -1 || abs(leftHeight - rightHight) > 1)
        return -1;

    return max(leftHeight, rightHight) + 1;
}

bool isBalanced(Node* root) {

    if (root == NULL)
        return true;

    if (Height(root) == -1)
        return false;
    return true;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

class Solution {
  public:
    Node* solve(vector<int>&nums,int i,int j){
        if(i>j){
            return NULL;
        }
        int mid=i+(j-i)/2;
        Node* root=new Node(nums[mid]);
        root->left=solve(nums,i,mid-1);
        root->right=solve(nums,mid+1,j);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        // Code here
        int n=nums.size();
        return solve(nums,0,n-1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        Node* a = ob.sortedArrayToBST(arr);
        if (!isValidBST(a)) {
            cout << "false" << endl;
            return 0;
        }
        bool f = isBalanced(a);

        if (f)
            cout << "true";
        else
            cout << "false";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends