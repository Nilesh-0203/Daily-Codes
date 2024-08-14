//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    bool solve(int num){
    	int one=0,two=0,three=0;
    	while(num>0){
    		int digit=num%10;
    		if(digit!=1 && digit!=2 && digit!=3){
    			return false;
    		}
    		num=num/10;
    	}
    	return true;
    }
    vector<int> filterByDigits(const vector<int>& arr) {
        // code here
        vector<int>v;
        int n=arr.size();
    	for(int i=0;i<n;i++){
    		if(solve(arr[i])){
    			v.push_back(arr[i]);
    		}
    	}
    	return v;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> result = ob.filterByDigits(arr);
        for (int x : result) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends