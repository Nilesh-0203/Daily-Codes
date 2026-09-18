/* Binary Tree Node Structure
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; 
*/

class Solution {
  public:
    void inorder(Node* node, Node*& prev, int& minDiff) {
            if (node == nullptr) return;

            inorder(node->left, prev, minDiff);

            if (prev != nullptr) {
                minDiff = min(minDiff, node->data - prev->data);
            }
            prev = node;

            inorder(node->right, prev, minDiff);
        }

    int absDiff(Node *root) {
        // code here
        int minDiff = INT_MAX;
            Node* prev = nullptr;
            inorder(root, prev, minDiff);
            return minDiff;
        
    }
};