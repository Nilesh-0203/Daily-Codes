//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
    void insertAtEnd(Node* &tail,int data){
        Node* newNode=new Node(data);
        tail->next=newNode;
        tail=newNode;
    }
    Node* divide(int N, Node *head){
        // code here
        if(head==NULL){
            return NULL;
        }
        Node* smallHead=new Node(-1);
        Node* smallTail=smallHead;
        Node* largeHead=new Node(-1);
        Node* largeTail=largeHead;

        Node* temp=head;
        while(temp!=NULL){
            if(temp->data%2==0){
                insertAtEnd(smallTail,temp->data);
            }
            else{
                insertAtEnd(largeTail,temp->data);
            }
            temp=temp->next;
        }
        smallTail->next=largeHead->next;
        return smallHead->next;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends