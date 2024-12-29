//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> intersectionWithDuplicates(vector<int>& a, vector<int>& b) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;
        vector<int>ans;
        while(i<a.size() && j<b.size()){
            while(i+1<a.size() && a[i]==a[i+1]){
                i++;
            }
            while(j+1<b.size() && b[j]==b[j+1]){
                j++;
            }
            if(a[i]==b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }
            else if(a[i]>b[j])j++;
            else i++;
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
        vector<int> arr1, arr2;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr1.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Solution ob;
        vector<int> res = ob.intersectionWithDuplicates(arr1, arr2);
        sort(res.begin(), res.end());

        if (res.size() == 0) {
            cout << "[]" << endl;
        } else {
            for (auto it : res)
                cout << it << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends