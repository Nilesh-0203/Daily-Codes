//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int heapHeight(int N, int arr[]){
        // code here
        int count=0;
        int i=0;
        while(i<N){
            i=2*i+1;
            count++;
        }
        return count-1;
    }
};

//{ Driver Code Starts.

int main() { 
    int t;
    cin>>t;
    while(t--){
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.heapHeight(N, arr) << endl;
    }
    return 0; 
} 

// } Driver Code Ends