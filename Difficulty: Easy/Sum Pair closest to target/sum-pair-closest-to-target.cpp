//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        vector<int>ans;
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        while(i<j)
        {
            if(ans.size()==0)
            {
                ans.push_back(arr[i]);
                ans.push_back(arr[j]);
            }
            
            else if(arr[i]+arr[j]<=target)
            {
                if(abs(target-(arr[i]+arr[j]))==abs(target-(ans[0]+ans[1])))
                {
                    if(abs(arr[j]-arr[i])>abs(ans[0]-ans[1]))
                    {
                        ans[0]=arr[i];
                        ans[1]=arr[j];
                    }
                }
                
                else if(abs(target-(arr[i]+arr[j]))<abs(target-(ans[0]+ans[1])))
                {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                }
                
                i++;
            }
            
            else
            {
                if(abs(target-(arr[i]+arr[j]))==abs(target-(ans[0]+ans[1])))
                {
                    if(abs(arr[j]-arr[i])>abs(ans[0]-ans[1]))
                    {
                        ans[0]=arr[i];
                        ans[1]=arr[j];
                    }
                }
                
                else if(abs(target-(arr[i]+arr[j]))<abs(target-(ans[0]+ans[1])))
                {
                    ans[0]=arr[i];
                    ans[1]=arr[j];
                }
                
                j--;
                
            }
            
            
        }
        
        return ans;
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
        string ks;
        getline(cin, ks);
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends