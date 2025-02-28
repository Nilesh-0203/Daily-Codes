//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int solve(int a,int b,string& t){
        if(t=="+"){
            return a+b;
        }
        else if(t=="-"){
            return a-b;
        }
        else if(t=="*"){
            return a*b;
        }
        else if(t=="/"){
            return a/b;
        }
    }
    int evaluate(vector<string>& arr) {
        // code here
        stack<int>st;
        for(string t:arr){
            if(t=="+" || t=="-" || t=="*" || t=="/"){
                int b=st.top();st.pop();
                int a=st.top();st.pop();
                int ans=solve(a,b,t);
                st.push(ans);
            }
            else{
                st.push(stoi(t));
            }
        }
        return st.top();
    }
};




//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<string> arr;
        while (ss >> str) {
            arr.push_back(str);
        }
        Solution ob;
        cout << ob.evaluate(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends