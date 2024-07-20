//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int operate(int a,int b,char ch){
        if(ch=='+'){
            return a+b;
        }
        else if(ch=='-'){
            return a-b;
        }
        else if(ch=='*'){
            return a*b;
        }
        else if(ch=='/'){
            return a/b;
        }
        else{
            return 0;
        }
    }
    int evaluatePostfix(string S)
    {
        // Your code here
        stack<int>st;
        for(char ch:S){
            if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int res=operate(a,b,ch);
                st.push(res);
            }
            else{
                
                st.push(ch-48);
            }
        }
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends