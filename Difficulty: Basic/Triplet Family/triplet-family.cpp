//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool findTriplet(vector<int>& arr) {
        // Your code
        sort(arr.begin(), arr.end());
        int sz = arr.size();
        for(int i = sz - 1; i >= 0; i--){
            int ele = arr[i];
            int lw = 0;
            int hg = i - 1;
            while(lw < hg){
                if(arr[lw] + arr[hg] == ele){
                    return true;
                }else if(arr[lw] + arr[hg] > ele){
                    hg--;
                }else{
                    lw++;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        bool res = obj.findTriplet(arr);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends