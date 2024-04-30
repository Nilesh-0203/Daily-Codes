//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    Node *reverseList(Node *head)
    {
        Node *p = head, *pre = NULL;
        while(p)
        {
            Node *nxt = p->next;
            p->next = pre;
            pre = p, p = nxt;
        }
        return pre;
    }
    Node* addTwoLists(Node* num1, Node* num2)
    {
        if(!num1)
            return num2;
        if(!num2)
            return num1;
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        Node *dummy = new Node(-1);
        Node *p = dummy;
        int carry = 0;
        while(num1 or num2 or carry) 
        {
            int sum = 0;
            if(num1) 
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if(num2) 
            {
                sum += num2->data;
                num2 = num2->next;
            }
            if(carry)
                sum += carry;
            int val = sum % 10;
            carry = sum / 10;
            p->next = new Node(val);
            p = p->next;
        }
        dummy->next = reverseList(dummy->next);
        p = dummy->next;
        while(p and p->data == 0)
            p = p->next;
        return !p ? new Node(0) : p;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends