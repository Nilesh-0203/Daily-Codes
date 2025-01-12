//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> LMF(vector<int>&arr){
        vector<int>v(arr.size());
        int maxi=0;
        for(int i=0;i<arr.size();i++){
            maxi=max(maxi,arr[i]);
            v[i]=maxi;
        }
        return v;
    }
    vector<int> RMF(vector<int>&arr){
        vector<int>v(arr.size());
        int maxi=0;
        for(int i=arr.size()-1;i>=0;i--){
            maxi=max(maxi,arr[i]);
            v[i]=maxi;
        }
        return v;
    }
    int maxWater(vector<int> &arr) {
        // code here
        vector<int>LeftMax=LMF(arr);
        vector<int>RightMax=RMF(arr);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            ans+=(min(LeftMax[i],RightMax[i]))-arr[i];
        }
        return ans;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends