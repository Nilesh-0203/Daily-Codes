//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #include <bits/stdc++.h> 
    bool checkPrime(int n){
        int cnt=0;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i==0){
                cnt++;
            }
        }
        return cnt==0;
    }
    int primeAdjacent(int N){
        // code here
        if(N==1 || N==2){
            return false;
        }
        return checkPrime(N-1) && checkPrime(N+1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        if(ob.primeAdjacent(N))
            cout<<"Y\n";
        else
            cout<<"N\n";
    }
    return 0;
}
// } Driver Code Ends