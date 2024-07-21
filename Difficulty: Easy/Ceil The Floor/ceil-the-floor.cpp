//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
   
    vector<int> getFloorAndCeil(int x, vector<int> a) {
        // code here
        int n=a.size();
        sort(a.begin(),a.end());
        int i=0,j=n-1;
    	int left=-1,right=-1;
    	while(i<=j){
    		int mid=i+(j-i)/2;
    		if(a[mid]==x){
    			return {a[mid],a[mid]};
    		}
    		else if(a[mid]<x){
    			left=a[mid];
    			i=mid+1;
    		}
    		else if(a[mid]>x){
    			right=a[mid];
    			j=mid-1;
    		}
    	}
    	return {left,right};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends