//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

bool sortbycom(const pair<int,int>&a,const pair<int,int>&b){
        if(a.first==b.first){
            return a.second<b.second;
        }
        return a.first>b.first;
    }
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        unordered_map<int, int> mp;
        vector<pair<int, int>> vec;
        for(auto it: arr){
            mp[it]++;
        }
        for(auto it: mp){
            vec.push_back({it.second, it.first});
        }
        sort(vec.begin(), vec.end(), sortbycom);
        
        vector<int> ans;
        for(auto it: vec){
            ans.insert(ans.end(), it.first, it.second);
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

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends