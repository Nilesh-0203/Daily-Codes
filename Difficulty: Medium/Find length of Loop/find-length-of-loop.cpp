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
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow=head;
        Node* fast=head;
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
            if(fast->next){
                fast=fast->next;
            }
            if(slow==fast){
                int len=0;
                Node* temp=slow->next;
                while(temp!=slow){
                    temp=temp->next;
                    len++;
                }
                return len+1;
            }
        }
        return 0;
    }
};