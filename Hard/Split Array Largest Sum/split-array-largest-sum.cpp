//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool ispossible(int arr[] ,int N, int K,int mid){
      int t=1;int sm=0;
      for(int i=0;i<N;i++){
          sm+=arr[i];
          if(arr[i]>mid)return false;
          if(sm>mid){
              t++;
              sm=arr[i];
          }
         
      }
      if(t<=K){
          return true;
      }
      else return false;
  }
    int splitArray(int arr[] ,int N, int K) {
        int sm=accumulate(arr,arr+N,0);
        int ans=-1;
        int l=0;int r=sm;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(ispossible(arr,N,K,mid)){
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
            }
            return ans;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends