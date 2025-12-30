/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
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