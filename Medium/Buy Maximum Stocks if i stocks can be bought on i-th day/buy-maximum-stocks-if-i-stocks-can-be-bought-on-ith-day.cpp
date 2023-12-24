//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            vp.push_back({price[i],i+1});
        }
        int ans=0,ct=0;
        sort(vp.begin(),vp.end());
            int i=0;
            while(k && i<n){
                int p=min(vp[i].second,k/vp[i].first);
                ans=vp[i].first*p;
                ct+=p;
                k-=ans;
                i++;
            }
        
        return ct;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends