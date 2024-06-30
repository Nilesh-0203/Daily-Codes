//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
    //Function to rotate a linked list.
    Node* find(Node* head,int k){
        int cnt=1;
        Node* temp=head;
        while(cnt!=k){
            temp=temp->next;
            cnt++;
        }
        return temp;
    }
    Node* rotate(Node* head, int k)
    {
        // Your code here
        if(head==NULL){
            return NULL;
        }
        int len=1;
        Node* temp=head;
        while(temp->next){
            len++;
            temp=temp->next;
        }
        if(k%len==0){
            return head;
        }
        k=k%len;
        temp->next=head;
        Node* lastNode=find(head,k);
        head=lastNode->next;
        lastNode->next=NULL;
        return head;
    }
};
    


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends