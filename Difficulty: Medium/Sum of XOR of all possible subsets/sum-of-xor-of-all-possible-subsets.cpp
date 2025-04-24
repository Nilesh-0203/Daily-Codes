//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int subsetXORSum(vector<int>& arr) {
        // code here
        int result=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            result|=arr[i];
        }
        return result<<(n-1);
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
        cout << obj.subsetXORSum(a) << endl;
    }

    return 0;
}

// } Driver Code Ends