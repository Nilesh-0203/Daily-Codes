//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool checkSorted(vector<int> &arr) {
        // code here.
        int n = arr.size();
        int cnt = 0;
        bool flag = true;
        for(int i=0;i<n;i++){
            while(arr[i]!=i+1){
                flag = false;
                swap(arr[i],arr[arr[i]-1]);
                cnt++;
            }
        }
        
        if(flag) return true;
        
        return cnt ==2 ? true : false;
    }
};

//{ Driver Code Starts.

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
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends