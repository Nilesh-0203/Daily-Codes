//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int>&arr,int n,int k,int mid){
        int studentCount=1;
        int pageSum=0;
        for(int i=0;i<n;i++){
            if(pageSum+arr[i]<=mid){
                pageSum+=arr[i];
            }
            else{
                studentCount++;
                if(studentCount>k || arr[i]>mid){
                    return false;
                }
                pageSum=arr[i];
            }
        }
        return true;
    }
    int findPages(vector<int>&arr, int k) {
        // code here
        int n=arr.size();
        if(n<k){
            return -1;
        }
        int start=0;
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(isPossible(arr,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends