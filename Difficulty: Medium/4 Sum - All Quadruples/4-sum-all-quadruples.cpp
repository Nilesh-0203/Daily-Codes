//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // arr[] : int input array of integers
    // target : the quadruple sum required
    set<vector<int>>st;
    int n;
    int num41,num31;
    void twoSum(vector<int>&arr,long long t,int i,int j){
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum<t){
                i++;
            }
            else if(sum>t){
                j--;
            }
            else if(sum==t){
                while(i<j && arr[i]==arr[i+1]){
                    i++;
                }
                while(i<j && arr[j]==arr[j-1]){
                    j--;
                }
                st.insert({num41,num31,arr[i],arr[j]});
                i++;
                j--;
            }
        }
    }
    void threeSum(vector<int>&arr,long long tar,int idx){
        for(int i=idx;i<n;i++){
            num31=arr[i];
            long long tat=tar-num31;
            twoSum(arr,tat,i+1,n-1);
        }
    }
    vector<vector<int> > fourSum(vector<int> &arr, int target) {
        // Your code goes here
        n=arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            num41=arr[i];
            long long tar=target-num41;
            threeSum(arr,tar,i+1);
        }
        vector<vector<int>>ans;
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(arr, d);
        sort(ans.begin(), ans.end());
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << endl;
        }
        if (ans.empty()) {
            cout << -1 << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends