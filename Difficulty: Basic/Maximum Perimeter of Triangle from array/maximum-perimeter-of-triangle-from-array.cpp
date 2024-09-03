//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxPerimeter(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        int maxi=-1;
        int n=arr.size();
        for(int i=0;i<n-2;i++){
            if(arr[i]+arr[i+1]>arr[i+2]){
                maxi=max(maxi,arr[i]+arr[i+1]+arr[i+2]);
            }
        }
        return maxi;
    }
};

//{ Driver Code Starts.

// Driver Program
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        cout << ob.maxPerimeter(arr) << endl;
    }
}

// } Driver Code Ends