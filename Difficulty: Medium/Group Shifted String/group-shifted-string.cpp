//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string getHash(string s) {
  
      // Calculate the shift needed to normalize the string
    int shifts = s[0] - 'a'; 
    for (char &ch : s) { 
          // Adjust each character by the shift
        ch = ch - shifts; 
      
          // Wrap around if the character goes below 'a'
        if (ch < 'a') 
              ch += 26; 
    }
    return s;
}

// Function to group shifted string together
vector<vector<string>> groupShiftedString(vector<string> &arr) {
    vector<vector<string>> res; 
  
      // Maps hash to index in result
    unordered_map<string, int> mp; 
    
    for (string s : arr) { 
          // Generate hash representing the shift pattern
        string hash = getHash(s); 
          
          // If new hash, create a new group
        if (mp.find(hash) == mp.end()) { 
            mp[hash] = res.size(); 
            res.push_back({});
        }
          // Add string to its group
        res[mp[hash]].push_back(s); 
    }
    return res;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        vector<vector<string>> v = ob.groupShiftedString(a);
        int n = v.size();
        for (int i = 0; i < n; i++) {
            sort(v[i].begin(), v[i].end());
        }
        sort(v.begin(), v.end());
        for (auto x : v) {
            for (auto y : x)
                cout << y << " ";
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends