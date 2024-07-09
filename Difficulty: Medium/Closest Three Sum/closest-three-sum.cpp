//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int closestSum=INT_MAX;
        int resultSum=0;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
                int currSum=arr[i]+arr[left]+arr[right];
                if(abs(target-currSum)<abs(target-closestSum)){
                    closestSum=currSum;
                    resultSum=currSum;
                }
                else if(abs(target-currSum)==abs(target-closestSum)){
                    resultSum=max(resultSum,currSum);
                }
                if(currSum<target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return resultSum;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends