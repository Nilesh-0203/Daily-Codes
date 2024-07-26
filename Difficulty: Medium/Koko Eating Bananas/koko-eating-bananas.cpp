//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int find(int n,vector<int>&arr){
    	long long sum=0;
    	for(int i=0;i<arr.size();i++){
    		if(arr[i]%n!=0){
    			sum+=(arr[i]/n)+1;
    		}
    		else{
    			sum+=arr[i]/n;
    		}
    	}
    	return sum;
    }

    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        sort(piles.begin(),piles.end());
    	long long i=1,j=*max_element(piles.begin(),piles.end());
    	int ans=0;
    	while(i<j){
    		long long mid=i+(j-i)/2;
    		int x=find(mid,piles);
    		if(x<=H){
    			j=mid;
    		}
    		else if(x>H){
    			i=mid+1;
    		}
    	}
    	return i;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends