//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>v;
    void solve(int n,int open,int close,string ans){
        if(ans.length()==2*n){
            v.push_back(ans);
            return;
        }
        if(open<n){
            ans.push_back('(');
            solve(n,open+1,close,ans);
            ans.pop_back();
        }
        if(close<open){
            ans.push_back(')');
            solve(n,open,close+1,ans);
            ans.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here
        int open=0,close=0;
        string ans="";
        solve(n,open,close,ans);
        return v;
    }
};

//{ Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends