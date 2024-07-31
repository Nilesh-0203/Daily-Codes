//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        string ans="";
        bool match=true;
        for(int i=0;i<arr[0].length();i++){
            char ch=arr[0][i];
            for(int j=1;j<arr.size();j++){
                if(arr[j].length()<i || ch!=arr[j][i]){
                    match=false;
                    break;
                }
            }
            if(match==false){
                break;
            }
            else{
                ans.push_back(ch);
            }
        }
        return ans=="" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends