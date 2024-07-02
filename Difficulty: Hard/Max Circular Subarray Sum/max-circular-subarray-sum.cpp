//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int kadans_max(int arr[],int num){
        int sum=arr[0];
        int maxSum=arr[0];
        for(int i=1;i<num;i++){
            sum=max(sum+arr[i],arr[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
    int kadans_min(int arr[],int num){
        int sum=arr[0];
        int minSum=arr[0];
        for(int i=1;i<num;i++){
            sum=min(sum+arr[i],arr[i]);
            minSum=min(minSum,sum);
        }
        return minSum;
    }
    int circularSubarraySum(int arr[], int num){
        
        // your code here
        int total=accumulate(arr,arr+num,0);
        int maxSum=kadans_max(arr,num);
        int minSum=kadans_min(arr,num);
        if(maxSum>0){
            return max(maxSum,total-minSum);
        }
        return maxSum;
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends