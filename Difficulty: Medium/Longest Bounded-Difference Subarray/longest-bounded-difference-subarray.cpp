//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestSubarray(vector<int>& arr, int x) {
        // code here
         multiset<int>st;
        
        int l=0,r=0,maxlen =0,ind =0;
        
         while(r<arr.size()){
             
             st.insert(arr[r]);
             
             while(*st.rbegin()-*st.begin()>x){
                 st.erase(st.find(arr[l]));
                 l++;
             }
             int len = r-l+1;
             if(maxlen < len){
                 maxlen = len;
                 ind = l;
             }
             r++;
             
        }
        return vector<int>(arr.begin()+ind,arr.begin()+ind+maxlen);
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        vector<int> ans = ob.longestSubarray(arr, k);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends