//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector<int> getNSER(int arr[],int n){
        vector<int>result(n);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                result[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()] > arr[i]){
                    st.pop();
                }
                result[i]=st.empty() ? n : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector<int> getNSEL(int arr[],int n){
        vector<int>result(n);
        stack<int>st;

        for(int i=0;i<n;i++){
            if(st.empty()){
                result[i]=-1;
            }
            else{
                while(!st.empty() && arr[st.top()] >= arr[i]){   // here we write = because of duplicates
                    st.pop();
                }
                result[i]=st.empty() ? -1 : st.top();
            }
            st.push(i);
        }
        return result;
    }
    vector <int> maxOfMin(int arr[], int N)
    {
        // Your code here
        int n=N;
        vector<int>NSEL=getNSEL(arr,n);
        vector<int>NSER=getNSER(arr,n);
        
        vector<int>ans(n+1);
        for(int i=0;i<n;i++){
            int len=NSER[i]-NSEL[i]-1;
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

    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        vector <int> res = ob.maxOfMin(a, n);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends