//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &a, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &a[i]);
        }
    }

    template <class T>
    static void print(vector<T> &a) {
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
     long long maxTip(int n, int x, int y, vector<int> &a, vector<int> &b) {
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back({a[i]-b[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        
        long long s=0;
        
        for(int i=0;i<n;i++)
        {
            if(v[i].first>=0)
            {
                if(x!=0)
                {
                   s=s+a[v[i].second];
                   x--; 
                }
                else
                {
                s=s+b[v[i].second];
                y--;
                }
            }
            else
            {
                if(n-i<=y)
                {
                    s=s+b[v[i].second];
                    y--;
                }
                else{
                    s=s+a[v[i].second];
                    x--;
                }
            }
            
        }
        
        return s;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        vector<int> arr(n);
        Array::input(arr, n);

        vector<int> brr(n);
        Array::input(brr, n);

        Solution obj;
        long long res = obj.maxTip(n, x, y, arr, brr);

        cout << res << endl;
    }
}

// } Driver Code Ends