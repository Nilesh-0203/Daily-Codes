//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
    Node* reverse(Node *head){
        Node *p = NULL, *ptr = NULL, *curr = head;
        while(curr)
        {
            p = ptr;
            ptr = curr;
            curr = curr->next;
            ptr->next = p;
        }
        return ptr;
    }
    
    int count(Node *head)
    {
        int c = 0;
        while(head)
        {
            c++;
            head = head->next;
        }
        return c;
    }
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 && head1->data == 0)head1=head1->next;
        while(head2 && head2->data == 0)head2=head2->next;
        if(!head1 && !head2)return new Node(0);
        if(!head1)return head2;
        if(!head2)return head1;
        
        Node *p1, *p2;
        if(count(head1) > count(head2))
        {
            p1 = head1;
            p2 = head2;
        }
        else if(count(head1) < count(head2))
        {
            p1 = head2;
            p2 = head1;
        }
        else
        {
            while(head1 && head1->data == head2->data)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            if(!head1)return new Node(0);;
            
            if(head1->data > head2->data)
            {
                p1 = head1;
                p2 = head2;
            }
            else
            {
                p1 = head2;
                p2 = head1;
            }
        }
        
        
        p1 = reverse(p1);
        p2 = reverse(p2);
        
        int carry = 0;
        Node *head = new Node(-1);
        Node *tail = head;
        while(p2)
        {
            int temp = p1->data-p2->data-carry;
            carry = 0;
            if(temp<0)
            {
                carry = 1;
                temp+=10;
            }
            Node *node = new Node(temp);
            tail->next = node;
            tail = node;
            p1=p1->next;
            p2=p2->next;
        }
        
        while(carry)
        {
            int temp = p1->data-carry;
            carry = 0;
            if(temp<0)
            {
                carry = 1;
                temp+=10;
            }
            Node *node = new Node(temp);
            tail->next = node;
            tail = node;
            p1=p1->next;
        }
        
        tail->next = p1;
        
        Node *ans = head->next;
        head->next=NULL;
        
        ans = reverse(ans);
        while(ans && ans->data==0)ans=ans->next;
        if(!ans)return new Node(0);
        return ans;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends