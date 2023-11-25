//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	    // Your code goes here
	     int a=0,b=n/2,mod=1e4,ele;
        for(int i=0;i<n;i++){
            
            if(i%2==0){
                ele=arr[a++]%mod;
                arr[i]+=(ele*mod);
            }else {
                ele=arr[b++]%mod;
                arr[i]+=(ele*mod);
            }
        }
        for(int i=0;i<n;i++)arr[i]=arr[i]/mod;
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends