//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
  public:
    vector<int> arranged(int a[],int n)
    {
        vector<int>v1;
        vector<int>v2;
        for(int i=0;i<n;i++){
            if(a[i]>=0){
                v1.push_back(a[i]);
            }
            else{
                v2.push_back(a[i]);
            }
        }
        vector<int>v;
        for(int i=0;i<n/2;i++){
            v.push_back(v1[i]);
            v.push_back(v2[i]);
        }
        return v;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n,i,j;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> ans;
    Solution obj;
    ans=obj.arranged(a,n);
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<"\n";
    }
}

// } Driver Code Ends