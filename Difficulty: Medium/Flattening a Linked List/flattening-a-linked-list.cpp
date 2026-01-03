/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* merge(Node* l1,Node* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        if(l1->data<=l2->data){
            l1->bottom=merge(l1->bottom,l2);
            return l1;
        }
        else if(l2->data<l1->data){
            l2->bottom=merge(l1,l2->bottom);
            return l2;
        }
        return NULL;
    }
    Node *flatten(Node *root) {
        // Your code here
        if(root==NULL){
            return NULL;
        }
        Node* result=flatten(root->next);
        return merge(root,result);
    }

};