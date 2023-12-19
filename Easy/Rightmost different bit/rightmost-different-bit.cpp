//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find the first position with different bits.
    void decToBinary(int n,vector<int>&v) 
    { 
    // Size of an integer is assumed to be 32 bits 
      for (int i = 31; i >= 0; i--) { 
        int k = n >> i; 
        if (k & 1) 
            v.push_back(1);
        else
            v.push_back(0);
        } 
    } 
    int posOfRightMostDiffBit(int m, int n)
    {
        // Your code here
        vector<int>v1,v2;
        decToBinary(m,v1);
        decToBinary(n,v2);
        
        int a=v1.size();
        int b=v2.size();
        
        for(int i=max(a,b) - 1;i>=0;i--){
            if(v1[i]!=v2[i]){
                return 32-i;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{   
    int t;
    cin>>t; //input number of testcases
    while(t--)
    {
         int m,n;
         cin>>m>>n; //input m and n
         Solution ob;
         cout << ob.posOfRightMostDiffBit(m, n)<<endl;
    }
    return 0;     
} 
// } Driver Code Ends