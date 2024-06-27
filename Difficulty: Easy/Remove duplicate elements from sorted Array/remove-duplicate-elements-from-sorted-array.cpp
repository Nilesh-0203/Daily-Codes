//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int remove_duplicate(int arr[],int n){
        // code here
        vector<int>v1;
        for(int i=0;i<n;i++){
            v1.push_back(arr[i]);
        }
        v1.erase(unique(v1.begin(), v1.end()), v1.end());
        for(int i=0;i<n;i++)
        {
            if(v1[i]!=NULL)
            {
                arr[i] = v1[i];
            }
            else
            {
                arr[i] = NULL;
            }
        }
        return v1.size();
    }
};

//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    Solution ob;
    int n = ob.remove_duplicate(a,N);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}
// } Driver Code Ends