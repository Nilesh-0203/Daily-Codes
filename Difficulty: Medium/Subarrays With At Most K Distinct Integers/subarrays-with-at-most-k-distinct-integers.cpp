//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      int atMostK(vector<int> &arr, int k) {
        // code here
        int left=0,right=0;
        int count=0;
        map<int,int>m;
        while(right<arr.size()){
            m[arr[right]]++;
            while(m.size()>k){
                m[arr[left]]--;
                if(m[arr[left]]==0)m.erase(arr[left]);
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.atMostK(arr, k) << endl;
    }
    return 0;
}
// } Driver Code Ends