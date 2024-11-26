//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int kadans_max(vector<int> &arr,int num){
        int sum=arr[0];
        int maxSum=arr[0];
        for(int i=1;i<num;i++){
            sum=max(sum+arr[i],arr[i]);
            maxSum=max(maxSum,sum);
        }
        return maxSum;
    }
    int kadans_min(vector<int> &arr,int num){
        int sum=arr[0];
        int minSum=arr[0];
        for(int i=1;i<num;i++){
            sum=min(sum+arr[i],arr[i]);
            minSum=min(minSum,sum);
        }
        return minSum;
    }
    int circularSubarraySum(vector<int> &arr) {

        // your code here
        int num=arr.size();
        int total=accumulate(arr.begin(),arr.end(),0);
        int maxSum=kadans_max(arr,num);
        int minSum=kadans_min(arr,num);
        if(maxSum>0){
            return max(maxSum,total-minSum);
        }
        return maxSum;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends