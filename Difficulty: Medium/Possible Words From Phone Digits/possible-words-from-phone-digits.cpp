//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    void solve(string mp[10],vector<string>&ans,string output,int idx,vector<int>&arr){
        if(idx>=arr.size()){
            ans.push_back(output);
            return;
        }
        string temp=mp[arr[idx]];
        for(int i=0;i<temp.length();i++){
            output.push_back(temp[i]);
            solve(mp,ans,output,idx+1,arr);
            output.pop_back();
        }
    }
    vector<string> possibleWords(vector<int> &arr) {
        // code here
        vector<string>ans;
        if(arr.size()==0){
            return ans;
        }
        string output="";
        string mp[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(mp,ans,output,0,arr);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        vector<string> v = obj.possibleWords(a);
        sort(v.begin(), v.end());
        Array::print(v);
        cout << "~" << endl;
    }
}

// } Driver Code Ends