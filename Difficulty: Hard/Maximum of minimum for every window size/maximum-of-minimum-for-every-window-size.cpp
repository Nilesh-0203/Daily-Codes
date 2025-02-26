//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n;
    vector<int> NSLF(vector<int>&arr){
        vector<int>v(n);
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && arr[st.top()]>=arr[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> NSRF(vector<int>&arr){
        vector<int>v(n);
        stack<int>st;
        st.push(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && arr[st.top()]>=arr[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        // Your code here
        n=arr.size();
        vector<int>NSL=NSLF(arr);
        vector<int>NSR=NSRF(arr);
        
        vector<int>ans(n+1);
        for(int i=0;i<n;i++){
            int len=NSR[i]-NSL[i]-1;
            ans[len]=max(ans[len],arr[i]);
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=max(ans[i],ans[i+1]);
        }
        ans.erase(ans.begin());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        vector<int> res = ob.maxOfMins(arr);
        for (int i : res)
            cout << i << " ";
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends