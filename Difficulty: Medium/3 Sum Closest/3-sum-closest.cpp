//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int closest3Sum(vector<int> &arr, int target) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int closetSum=INT_MAX;
        int res=0;
        for(int k=0;k<=n-3;k++){
            int i=k+1,j=n-1;
            while(i<j){
                int sum=arr[k]+arr[i]+arr[j];
                if(abs(sum-target)<closetSum){
                    closetSum=abs(sum-target);
                    res=sum;
                }
                else if(abs(sum-target)==closetSum){
                    res=max(res,sum);
                }
                if(sum<target){
                    i++;
                }
                else{
                    j--;
                }
            }
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        int target = stoi(input);

        Solution obj;
        cout << obj.closest3Sum(arr, target) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends