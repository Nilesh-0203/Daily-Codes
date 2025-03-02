//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    stack<int>st;
    stack<int>maxStack;
    Solution() {
        // code here
    }

    // Add an element to the top of Stack
    void push(int x) {
        // code here
        st.push(x);
        if(maxStack.empty() || x>=maxStack.top()){
            maxStack.push(x);
        }
    }

    // Remove the top element from the Stack
    void pop() {
        // code here
        if(!st.empty()){
            if(st.top()==maxStack.top()){
                maxStack.pop();
            }
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        // code here
        if(!st.empty()){
            return st.top();
        }
        return -1;
    }

    // Finds minimum element of Stack
    int getMax() {
        // code here
        if(!maxStack.empty()){
            return maxStack.top();
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    while (t--) {
        int q;
        cin >> q;

        Solution ob;

        while (q--) {
            int qt;
            cin >> qt;

            if (qt == 1) {
                // push
                int att;
                cin >> att;
                ob.push(att);
            } else if (qt == 2) {
                // pop
                ob.pop();
            } else if (qt == 3) {
                // peek
                cout << ob.peek() << " ";
            } else if (qt == 4) {
                // getMin
                cout << ob.getMax() << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends