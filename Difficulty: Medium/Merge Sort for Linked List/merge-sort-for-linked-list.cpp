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
    Node* mid(Node* head){
        Node* slow=head;
        Node* fast=head->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    Node* merge(Node* left,Node* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }
        Node* ans=new Node(-1);
        Node* temp=ans;
        while(left!=NULL && right!=NULL){
            if(left->data<right->data){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        return ans->next;
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head==NULL || head->next==NULL){
            return head;
        }
        //break ll
        Node* middle=mid(head);
        
        Node* left=head;
        Node* right=middle->next;
        middle->next=NULL;
        
        //recursive call for break
        left=mergeSort(left);
        right=mergeSort(right);
        
        Node* result=merge(left,right);
        
        return result;
        
        
        
    }
};