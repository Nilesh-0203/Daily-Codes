//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int n,vector<int>&nums){
    	int sum=0;
    	for(int i=0;i<nums.size();i++){
    		if(nums[i]%n!=0){
    			sum+=(nums[i]/n)+1;
    		}
    		else{
    			sum+=nums[i]/n;
    		}
    	}
	    return sum;
    }
    int smallestDivisor(vector<int>& nums, int K) {
        // Write your code here.
        sort(nums.begin(),nums.end());
    	int i=1,j=*max_element(nums.begin(),nums.end());
    	int ans=0;
    	while(i<=j){
    		int mid=i+(j-i)/2;
    		int x=solve(mid,nums);
    		if(x<=K){
    			ans=mid;
    			j=mid-1;
    		}
    		else if(x>K){
    			i=mid+1;
    		}
    	}
    	return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n, k;
        cin >> n >> k;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) cin >> vec[i];

        Solution obj;
        cout << obj.smallestDivisor(vec, k) << endl;
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends