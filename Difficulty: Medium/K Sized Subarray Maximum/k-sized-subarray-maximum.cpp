//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        vector<int>ans;
        deque<int>dq;
        int n=arr.size();
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){
            ans.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k)
            dq.pop_front();
            while(!dq.empty() && arr[i]>=arr[dq.back()])
            dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(arr[dq.front()]);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();

    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends