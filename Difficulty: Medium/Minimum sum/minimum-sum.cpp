//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<int>a1,a2;
        int i=0;
        while(i<arr.size()){
            a1.push_back(arr[i++]);
            if(i<arr.size()){
                a2.push_back(arr[i++]);
            }
        }
        reverse(a1.begin(),a1.end());
        reverse(a2.begin(),a2.end());
        i=0;
        int j=0,carry=0;
        vector<int>ans;
        while(i<a1.size() && j<a2.size()){
            int sum=a1[i++]+a2[j++]+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit);
        }
        while(i<a1.size()){
            int sum=a1[i++]+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit);
        }
        while(j<a2.size()){
            int sum=a2[j++]+carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit);
        }
        while(carry>0){
            int sum=carry;
            int digit=sum%10;
            carry=sum/10;
            ans.push_back(digit);
        }
        reverse(ans.begin(),ans.end());
        i=0;
        while(i<ans.size() && ans[i]==0)i++;
        
        if(i==ans.size())return "0";
        string res="";
        while(i<ans.size()){
            res+='0'+ans[i++];
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
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends