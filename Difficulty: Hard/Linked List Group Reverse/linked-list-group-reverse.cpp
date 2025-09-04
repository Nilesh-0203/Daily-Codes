/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* ReverseinKgroup(Node* head,int k){
        Node* curr=head;
        Node* next=NULL;
        Node* prev=NULL;
        int count=0;
        while(curr!=NULL && count<k){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            count++;
        }
        if(next!=NULL){
            head->next=ReverseinKgroup(next,k);
        }
        return prev;
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL || head->next==NULL || k==0){
            return head;
        }
        return ReverseinKgroup(head,k);
    }
};