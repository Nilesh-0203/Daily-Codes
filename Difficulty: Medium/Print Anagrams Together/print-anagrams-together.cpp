//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string solve(string word){
        vector<int>v(26,0);
        for(int i=0;i<word.length();i++){
            v[word[i]-'a']++;
        }
        string temp="";
        for(int i=0;i<26;i++){
            int freq=v[i];
            temp+=string(freq,i+'a');
        }
        return temp;
    }
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<arr.size();i++){
            string word=arr[i];
            string new_word=solve(word);
            mp[new_word].push_back(word);
        }
        for(auto i:mp){
            ans.push_back(i.second);
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

        vector<string> arr;
        string input_line;
        getline(cin, input_line);
        stringstream ss(input_line);
        string word;
        while (ss >> word) {
            arr.push_back(word);
        }

        Solution ob;
        vector<vector<string> > result = ob.anagrams(arr);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends