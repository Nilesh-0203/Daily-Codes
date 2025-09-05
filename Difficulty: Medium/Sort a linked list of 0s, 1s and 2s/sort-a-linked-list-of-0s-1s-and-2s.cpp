/* Node is defined as
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
    void insertAtEnd(Node* &head,Node* &tail,int data){
        Node* newNode=new Node(data);
        if(head==NULL){
            head=newNode;
            tail=newNode;
            return;
        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }
    Node* segregate(Node* head) {
        // code here
        Node* zeroHead=new Node(-1);
        Node* zeroTail=zeroHead;
        
        Node* oneHead=new Node(-1);
        Node* oneTail=oneHead;
        
        Node* twoHead=new Node(-1);
        Node* twoTail=twoHead;
        
        Node* temp=head;
        while(temp){
            int val=temp->data;
            if(val==0){
                insertAtEnd(zeroHead,zeroTail,val);
            }
            else if(val==1){
                insertAtEnd(oneHead,oneTail,val);
            }
            else if(val==2){
                insertAtEnd(twoHead,twoTail,val);
            }
            temp=temp->next;
        }
        
        if(oneHead->next!=NULL){
            zeroTail->next=oneHead->next;
        }
        else{
            zeroTail->next=twoHead->next;
        }
        oneTail->next=twoHead->next;
        twoTail->next=NULL;
        
        head=zeroHead->next;
        
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        
        return head;
        
    }
};