//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool pairInSortedRotated(vector<int>& arr, int target) {
        // code here
        unordered_set<int>st;
        for(int i:arr){
            int d=target-i;
            if(st.find(d)!=st.end()){
                return true;
            }
            st.insert(i);
        }
        return false;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        vector<int> arr;
        while (ss >> num) {
            arr.push_back(num);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        bool ans = ob.pairInSortedRotated(arr, target);
        if (ans) {
            cout << "true\n";
        } else {
            cout << "false\n";
        }
    }
}
// } Driver Code Ends