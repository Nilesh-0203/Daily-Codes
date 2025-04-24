//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int totHammingDist(vector<int>& arr) {
        // code here
        int ans=0, n=arr.size();
        for(int i=31; i>=0; i--){
            int bits=0;
            for(int j: arr)
                if((j>>i)&1) bits++;
            
            ans += bits*(n-bits);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.totHammingDist(a) << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends