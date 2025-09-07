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
    Node* merge(Node* l1,Node* l2){
        if(l1==NULL){
            return l2;
        }
        if(l2==NULL){
            return l1;
        }
        
        if(l1->data<=l2->data){
            l1->next=merge(l1->next,l2);
            return l1;
        }
        else{
            l2->next=merge(l1,l2->next);
            return l2;
        }
        return NULL;
    }
    Node* partation(vector<Node*>& arr,int i,int j){
        if(i==j){
            return arr[i];
        }
        if(i>j){
            return NULL;
        }
        int mid=(i+j)/2;
        Node* l1=partation(arr,i,mid);
        Node* l2=partation(arr,mid+1,j);
        
        return merge(l1,l2);
    }
    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        int i=0,j=arr.size();
        if(j==0){
            return NULL;
        }
        return partation(arr,i,j-1);
    }
};