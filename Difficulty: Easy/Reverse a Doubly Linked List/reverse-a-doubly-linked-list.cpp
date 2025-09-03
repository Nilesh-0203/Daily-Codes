/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        while(head->next!=NULL){
            head=head->next;
            
        }
         Node *temp1=head;
         Node *temp2=head;
         Node *p=NULL;
        while(temp2->prev!=NULL){
            temp2->next=temp2->prev;
            temp2->prev=p;
            p=temp2;
            temp2=temp2->next;
        }
        temp2->prev=p;
        temp2->next=NULL;
        return head;
    }
};