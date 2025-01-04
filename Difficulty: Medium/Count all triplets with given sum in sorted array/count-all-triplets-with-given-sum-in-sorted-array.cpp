//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
        int cnt=0;
        int n=arr.size();
        for(int i=0;i<=n-3;i++){
            int s=i+1;
            int e=n-1;
            while(s<e){
                int sum=arr[i]+arr[s]+arr[e];
                if(sum>target)e--;
                else if(sum<target)s++;
                else if(sum==target){
                    cnt++;
                    int temp=s+1;
                    while(temp<e&&arr[temp]==arr[temp-1]){
                        cnt++;
                        temp++;
                    }
                    e--;
                }
 
            }
            
        }
        return cnt;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends