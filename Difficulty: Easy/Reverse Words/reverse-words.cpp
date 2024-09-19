//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        istringstream k(str);
        string word;
        vector<string>v;
        while(getline(k, word, '.'))
        {
            v.push_back(word);
        }
        string res;
        for(int i = v.size() - 1;i >= 0;i--)
        {
            res += v[i];
            res += ".";
        }
        res.pop_back();
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends