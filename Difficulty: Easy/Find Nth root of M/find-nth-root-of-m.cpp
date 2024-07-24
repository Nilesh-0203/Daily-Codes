//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	    // Code here.
	     int start=0;
        int end=m;
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(pow(mid,n)==m)
             return mid;
            else if(pow(mid,n)<m){
                start=mid+1;
                ans=mid;
            }
            else{
                end=mid-1;
            }
        }
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends