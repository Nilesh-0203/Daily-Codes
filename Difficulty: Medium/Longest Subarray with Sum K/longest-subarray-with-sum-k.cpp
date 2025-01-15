//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& A, int K) {
        // code here
        map<int,int>mp;
        int maxLen=0;
        int sum=0;
        int N=A.size();
        for(int i=0;i<N;i++){
            sum=sum+A[i];
            if(sum==K){
                maxLen=max(maxLen,i+1);
            }
            int rem=sum-K;
            if(mp.find(rem)!=mp.end()){
                int len=i-mp[rem];
                maxLen=max(maxLen,len);
            }
            if(mp.find(sum)==mp.end()){
                mp[sum]=i;
            }
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends