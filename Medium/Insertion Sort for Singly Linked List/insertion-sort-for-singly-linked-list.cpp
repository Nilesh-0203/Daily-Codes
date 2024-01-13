//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* help(Node* pre,Node* root)
    {
        //base case
        if(!root)
        return root;
        
        //recurisve calls
        //small calculation
        Node* temp=help(root,root->next);
        root->next=temp;
        
        Node* next_node=root->next;
        Node* root2=root;
        Node* pre_2=NULL;
        root=root->next;
        bool flag=0;
        while(root and root2->data>(root->data))
        {
            flag=1;
            pre_2=root;
            root=root->next;
        }
        
        if(flag)
        {
            if(pre==NULL)
            {
                
            }
            root2->next=root;
            pre_2->next=root2;
            
            if(pre)
            pre->next=next_node;
              
            return next_node;
        }
        
        return root2;
    }
    Node* insertionSort(struct Node* head_ref)
    {
        if(!head_ref)
        return NULL;
        
        Node* head=help(NULL,head_ref);
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends