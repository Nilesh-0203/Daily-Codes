//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    vector<string>result;
	    void solve(string &s,string &curr,int idx){
	        if(idx>=s.length()){
	            if(curr!=""){
	                result.push_back(curr);
	            }
	            return;
	        }
	        curr.push_back(s[idx]);
	        solve(s,curr,idx+1);
	        curr.pop_back();
	        solve(s,curr,idx+1);
	    }
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    string curr="";
		    solve(s,curr,0);
		    sort(result.begin(),result.end());
		    return result;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends