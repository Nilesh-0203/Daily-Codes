/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        // code here
        Node *a, *b, *H = head;
        a = b = NULL;
        while(H){
            if(--k == 0){
                a = H;
                b = head;
            }
            H = H -> next;
            if(b && H)
                b = b -> next;
        }
        if(a) {         // if(b) {
            int t = b -> data;
            b -> data = a -> data;
            a -> data = t;
        };
        return head;
    }
};