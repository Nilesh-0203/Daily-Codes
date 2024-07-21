//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    public:
    
    int count = 0;
    
    bool solve(int a[], int n, int index, int curr_sum, int target, int visit[]) {
        
        if (index >= n) {
            return false;
        }
        
        if (curr_sum > target) {
            return false;
        }
        
        if (curr_sum == target) {
            count++;
            return true;
        }
        
        for (int i = index; i < n; i++) {
            if (visit[i] == 1) continue;
            
            visit[i] = 1;
            int completed = solve(a, n, index + 1, curr_sum + a[i], target, visit);
            
            if (completed) return true;
            visit[i] = 0;
        }
        
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        if (k == 1) return true;
        
        int sum = accumulate(a, a + n, 0);
        int visit[n] = {0}; // to keep track to alreday taken values
        
        // if odd not able to partition
        if (sum % k) return false;
        
        // sort in desc to avoid conditions where only larger values left in the array
        // who sum can be greater than the target.
        sort(a, a + n, greater<int>());
        
        for (int i = 0; i < k; i++) {
            solve(a, n, 0, 0, sum / k, visit);
        }
        
        if (count == k) return true;
        return false;
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends