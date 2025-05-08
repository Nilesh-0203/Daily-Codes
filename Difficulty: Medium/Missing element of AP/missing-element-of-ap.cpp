//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        // code here
        int n=arr.size();
        if(n<3){
            return arr[n-1]+(arr[1]-arr[0]);
        }
        if(n==3){
            return arr[1]+(arr[1]-arr[0]);
        }
        int a=arr[1]-arr[0];
        int b=arr[2]-arr[1];
        int c=arr[3]-arr[2];
        int diff=0;
        if(a==b || b==c)diff=b;
        else if(a==b || a==c)diff=a;
        
        for(int i=0;i<n;i++){
            if(arr[i+1]!=arr[i]+diff){
                return arr[i]+diff;
            }
        }
        return arr[n-1]+diff;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends