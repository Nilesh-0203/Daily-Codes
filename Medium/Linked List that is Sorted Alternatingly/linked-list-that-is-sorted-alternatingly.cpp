//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/*
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/

class Solution
{
    public:
    // your task is to complete this function
    void reverse(Node** head) {
        Node* currPtr = *head, *prevPtr = NULL;
        
        while(currPtr != NULL) {
            Node* nextPtr = currPtr -> next;
            
            currPtr -> next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
        }
        *head = prevPtr;
        return;
    }
    
    void sort(Node **head)
    {
         // Code here 
        // Split the linked list into ascending part and descending part
        Node* asc = *head, *desc = asc -> next;
        Node* descStart = desc;
        
        while(asc -> next && desc -> next) {
            asc -> next = desc -> next;
            asc = asc -> next;
            
            desc -> next = asc -> next;
            desc = desc -> next;
        }
        reverse(&descStart); // reverse the descending part to make it ascending
        
        Node* ans = new Node(-1);
        Node* ptr = ans;
        Node* temp = *head;
        

        // Store in sorted order
        while(temp != asc -> next && descStart != NULL) {
            if(temp -> data < descStart -> data) {
                ptr -> next = new Node(temp -> data);
                temp = temp -> next;
            } else {
                ptr -> next = new Node(descStart -> data);
                descStart = descStart -> next;
            }
            ptr = ptr -> next;
        }
        
        while(temp != asc -> next){
            ptr -> next = new Node(temp -> data);
            temp = temp -> next;
            ptr = ptr -> next;
        }
        
        while(descStart) {
            ptr -> next = new Node(descStart -> data);
            descStart = descStart -> next;
            ptr = ptr -> next;
        }
        
        *head = ans -> next;
        
        return;
    }
};

//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends