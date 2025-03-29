//{ Driver Code Starts
// Driver code
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b){
        if(a.second > b.second)
            return true;
        return false;
        
    }
    
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        vector<pair<int, int>> v;
        int n = deadline.size();
        int maxD = -1;
        for(int i=0;i<n;i++){
            v.push_back({deadline[i], profit[i]});
            maxD = max(maxD, deadline[i]);
            
        }
        
        set<int> slot;
        sort(v.begin(), v.end(), cmp);
        
        for(int i=0;i<=maxD;i++)
            slot.insert(i);
        
        int sum = 0;
        int count=0;
        
        for(int i=0;i<n;i++){
            int c = v[i].first;
            auto it = slot.lower_bound(c);
            
            if(it==slot.end())
                it--;
            if((*it)>c)
                it--;
            
            if(it!=slot.begin()){
                sum+=(v[i].second);
                count++;
                slot.erase(it);
            }
                
        }
        
        return {count, sum};    
        
        return {count, sum};
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> deadlines, profits;
        string temp;
        getline(cin, temp);
        int x;
        istringstream ss1(temp);
        while (ss1 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            profits.push_back(x);

        Solution obj;
        vector<int> ans = obj.jobSequencing(deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends