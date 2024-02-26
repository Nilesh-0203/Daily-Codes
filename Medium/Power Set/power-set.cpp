//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		 void solve(string& s,string temp,vector<string>&ans,int index){
            if(index==s.length()){
                if(temp.length()>=1)
                ans.push_back(temp);
                return;
            }
            solve(s,temp,ans,index+1);
            solve(s,temp+s[index],ans,index+1);
        }
        vector<string> AllPossibleStrings(string s){
            vector<string>ans;
            solve(s,"",ans,0);
            sort(ans.begin(),ans.end());
            return ans;
            
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