//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
     Node* reverse(Node* head){
        Node* curr=head;
        Node* next=NULL;
        Node* prev=NULL;
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    Node * solve(Node* list1,Node* list2){
      if(list1->next==NULL){
          list1->next=list2;
          return list1;
      }

      Node* curr1=list1;
      Node* next1=list1->next;
      Node* curr2=list2;
      Node* next2=list2->next;

      while(next1!=NULL && curr2!=NULL){
          if((curr2->data>=curr1->data) && (curr2->data<=next1->data)){
              curr1->next=curr2;
              next2=curr2->next;
              curr2->next=next1;

              curr1=curr2;
              curr2=next2;
          }
          else{
              curr1=next1;
              next1=next1->next;
              if(next1==NULL){
                  curr1->next=curr2;
                  return list1;
              }
          }
      }
      return list1;
  }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        // your code goes here
        Node* temp=NULL;
        if(node1==NULL){
            temp= node2;
            temp=reverse(temp);
            return temp;
        }
        if(node2==NULL){
            temp= node1;
            temp=reverse(temp);
            return temp;
        }

        if(node1->data<node2->data){
            temp= solve(node1,node2);
            temp=reverse(temp);
            return temp;
        }
        else{
            temp= solve(node2,node1);
            temp=reverse(temp);
            return temp;
        }
    }   
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends