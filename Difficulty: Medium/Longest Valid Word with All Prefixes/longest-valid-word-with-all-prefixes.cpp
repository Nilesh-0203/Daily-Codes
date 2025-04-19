//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        unordered_set<string> wordSet(words.begin(), words.end());
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            if (a.length() != b.length())
                return a.length() > b.length();
            return a < b;
        });
        for (const string& word : words) {
            bool valid = true;
            for (int i = 1; i < word.length(); ++i) {
                if (wordSet.find(word.substr(0, i)) == wordSet.end()) {
                    valid = false;
                    break;
                }
            }
            if (valid)
                return word;
        }
        return "";
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character left by the previous input
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        string ans = ob.longestValidWord(arr);

        // Handling empty string output by printing an empty line
        cout << ans << endl;
        cout << "~\n";
    }
}

// } Driver Code Ends