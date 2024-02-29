//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
  
    public:
    pair<long long, int> maxNtype(long long arr[], long long n)
    {
        //code here.
        pair<int,int>p;
        long long  maxi=*max_element(arr,arr+n);
        p.first=maxi;
        
        int cnt1=0,cnt2=0;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        if(cnt1==(n-1)){
            p.second=1;
        }
        else if(cnt1==(n-2)){
            p.second=4;
        }
        else if(cnt2==(n-1)){
            p.second=2;
        }
        else if(cnt2==(n-2)){
            p.second=3;
        }
        return p;
    }

};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        pair<long long, int> pair = ob.maxNtype(arr, n);
        cout<<pair.first<<" "<<pair.second<<"\n";
    }
	return 0;
}
// } Driver Code Ends