/* Structure of a Linked List node
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    Node *compute(Node *head)
    {
        // your code goes here
        if(head==NULL || head->next==NULL){
            return head;
        }
        head=reverse(head);
        Node* prev=head;
        Node* temp=head->next;
        while(temp!=NULL){
            if(prev->data > temp->data){
                if(temp->next!=NULL){
                    Node* next_next=temp->next;
                    temp->next=NULL;
                    delete temp;
                    temp=next_next;
                    prev->next=temp;
                }
                else{
                    prev->next=NULL;
                    break;
                }
            }
            else{
                 prev=temp;
                 temp=temp->next;  
            }
        }
        head=reverse(head);
        return head;
    }
};