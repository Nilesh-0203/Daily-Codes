//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
     int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
       
        int leftMin[n];
        int rightMax[n];
        
        leftMin[0] = a[0];
        for(int i =1; i<n; i++)
        {
            leftMin[i] = min(a[i], leftMin[i-1]);
        }
        
        rightMax[n-1] = a[n-1];
        for(int j = n-2; j>=0; j--)
        {
            rightMax[j] = max(a[j], rightMax[j+1]);
        }
        
        int i =0; 
        int j=0;
        int maxDiff  = -1;
        
        while(i<n && j<n)
        {
            if(leftMin[i] <= rightMax[j])
            {
                maxDiff = max(maxDiff, j-i);
                j = j+1;
            }
            
            else 
            {
                i = i +1;
            }
        }
        
        return maxDiff;
        
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends