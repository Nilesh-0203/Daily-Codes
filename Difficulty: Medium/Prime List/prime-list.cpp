//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int val;
    Node* next;

    Node(int x) {
        val = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends

// User function Template for C++

/*
class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};
*/

class Solution {
  public:
    bool isPrime(int num){
        for(int i=2;i<=sqrt(num);i++){
            if(num%i==0)return false;
        }
        return true;
    }
    Node *primeList(Node *head) {
        // code here
        Node* temp=head;
        while(temp!=NULL){
            int num=temp->val;
            if(num==1)temp->val=2;
            if(!isPrime(num)){
                int left=2;
                for(int i=num-1;i>=2;i--){
                    if(isPrime(i)){
                        left=i;
                        break;
                    }
                }
                int right=num+1;
                for(int i=num+1;;i++){
                    if(isPrime(i)){
                        right=i;
                        break;
                    }
                }
                if(num-left<=right-num){
                    temp->val=left;
                }
                else{
                    temp->val=right;
                }
            }
            temp=temp->next;
        }
        return head;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.primeList(head);
        printList(head);
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends