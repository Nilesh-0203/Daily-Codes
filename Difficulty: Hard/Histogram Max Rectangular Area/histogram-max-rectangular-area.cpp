//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int n;
    vector<int> NSRF(vector<int>&heights){
        stack<int>st;
        st.push(n);
        vector<int>v(n);
        for(int i=n-1;i>=0;i--){
            while(st.top()!=n && heights[st.top()]>=heights[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    vector<int> NSLF(vector<int>&heights){
        stack<int>st;
        st.push(-1);
        vector<int>v(n);
        for(int i=0;i<n;i++){
            while(st.top()!=-1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            v[i]=st.top();
            st.push(i);
        }
        return v;
    }
    int getMaxArea(vector<int> &heights) {
        // Your code here
        n=heights.size();
        vector<int>NSR=NSRF(heights);
        vector<int>NSL=NSLF(heights);
        vector<int>width(n);
        for(int i=0;i<n;i++){
            width[i]=NSR[i]-NSL[i]-1;
        }
        int area=INT_MIN;
        for(int i=0;i<n;i++){
            area=max(area,heights[i]*width[i]);
        }
        return area;
    }
};





//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends