/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

class Solution {
  public:
    bool isPalindrome(Node *head) {
        // Your code here
        vector<int>ans;
        Node* temp=head;
        while(temp){
            ans.push_back(temp->data);
            temp=temp->next;
        }
        int i=0,j=ans.size()-1;
        while(i<=j){
            if(ans[i]!=ans[j])return false;
            i++;
            j--;
        }
        return true;
    }
};